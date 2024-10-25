#pragma warning (disable : 4244)

#include <iostream>
#include <stdexcept>
#include <stdlib.h>

#define MAX_NUM 10.0
#define NUM_OF_ELEMENTS 50

enum mode { MIN, MAX };

/* STACK & ITERATOR */
template <typename T>
class Stack {

	friend class StackIterator;
	class Node;

	//for convenience
	using pointer = Node*;
	using reference = T&;

	public:

		class StackIterator {

			public:

				StackIterator(pointer containerStart) : m_current(containerStart), m_index(0) {}

				reference operator*(void) const { return m_current->m_value; }
				pointer operator->(void) { return m_current; }
				StackIterator& operator++(void) {
					m_current = m_current->m_next;
					++m_index;
					return *this;
				}
				StackIterator operator++(int) {
					StackIterator tmp = *this;
					++(*this);
					++m_index;
					return tmp;
				}

				friend bool operator==(const StackIterator& iter1, const StackIterator& iter2) { return iter1.m_current == iter2.m_current; }
				friend bool operator!=(const StackIterator& iter1, const StackIterator& iter2) { return iter1.m_current != iter2.m_current; }

				int getIndex(void) { return m_index; }

			private:

				pointer m_current;
				int m_index;
		};

		Stack() : m_begin(nullptr), m_end(nullptr), m_size(0) {}
		StackIterator begin() { return StackIterator(m_begin); }
		StackIterator end() { return StackIterator(nullptr); }
		size_t getSize(void) { return m_size; }
		void push(const T value);
		void pop(void);
		T top(void);

	private:

		struct Node {
			T m_value;
			Node* m_next;
		};

		pointer m_begin; //top of the stack
		pointer m_end; //bottom of the stack
		size_t m_size;
};

template <typename T>
void Stack<T>::push(const T value) {
	m_begin = new Node{ value, m_begin };
	m_end = m_end != nullptr ? m_end : m_begin;
	++m_size;
}

template <typename T>
void Stack<T>::pop(void) { //doesn't throw if stackSize == 0
	pointer tmp = m_end;
	m_end = m_end->m_next;
	--m_size;
	delete tmp;
}

template <typename T>
T Stack<T>::top(void) { //throws runtime_error if stackSize == 0
	if (!m_end) { throw std::runtime_error("Tried to draw from an empty stack!"); }
	return m_end->m_value;
}

/* UTILITY */
template <typename T>
void fillStack(Stack<T>& stack, int numElements) {
	srand(time(NULL));
	for (int i = 0; i < numElements; ++i) {
		stack.push(double(rand()) / RAND_MAX * MAX_NUM);
	}
}

template <typename T>
T* getArray(Stack<T> stack) {
	T* valueArray = new T[stack.getSize()];
	typename Stack<T>::StackIterator it(stack.begin());
	for (it; it != stack.end(); ++it) { valueArray[it.getIndex()] = *it; }
	return valueArray;
}

template <typename T>
void sortArray(T* valueArray, int size) { //plain bubble sort
	for (int i = 0; i < size - 2; ++i) {
		bool swapped = false;
		for (int j = 0; j < size - i - 2; ++j) {
			if (valueArray[j] > valueArray[j + 1]) {
				T tmp = valueArray[j + 1];
				valueArray[j + 1] = valueArray[j];
				valueArray[j] = tmp;
				swapped = true;
			}
		}
		if (!swapped) { break; }
	}
}

/* PROCESSING FUNCTIONS */
template <typename T>
T minMax(Stack<T>& stack, int mode) {
	T searchedValue = stack.top();
	switch (mode) {
	case MIN:
		for (auto currentValue : stack) {
			searchedValue = searchedValue > currentValue ? currentValue : searchedValue;
		}
		break;
	case MAX:
		for (auto currentValue : stack) {
			searchedValue = searchedValue < currentValue ? currentValue : searchedValue;
		}
		break;
	}
	return searchedValue;
}

template <typename T>
T median(Stack<T> stack) { //too lazy to implement an algo
	T medianValue, *valueArray = getArray(stack);
	size_t arraySize = stack.getSize();
	sortArray(valueArray, arraySize);
	if (arraySize % 2 == 0) {
		medianValue = (valueArray[arraySize / 2] + valueArray[(arraySize + 1) / 2]) / 2.0; //avg of 2 middle elements
	} else {
		medianValue = valueArray[arraySize / 2];
	}
	delete[] valueArray;
	return medianValue;
}

template <typename T>
T avg(Stack<T>& stack) {
	T avg = 0;
	for (auto value : stack) { avg += value / (double)stack.getSize(); }
	return avg;
}

/* MAIN */
int main(void) {
	Stack<double> stack;
	fillStack(stack, NUM_OF_ELEMENTS);
	std::cout << "Minimum value stored in the stack: " << minMax(stack, MIN) << "\n";
	std::cout << "Maximum value stored in the stack: " << minMax(stack, MAX) << "\n";
	std::cout << "Median value stored in the stack:  " << median(stack) << "\n";
	std::cout << "Average value stored in the stack: " << avg(stack) << "\n";	
	return 0;
}