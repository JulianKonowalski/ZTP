////#include <iostream>
////#include <sstream>
////#include <fstream>
////#include <list>
////#include <vector>
////#include <queue>
////
////template <class T>
////class listGreater {
////public:
////	constexpr bool operator()(const std::list<T>& lhs, const std::list<T>& rhs) const {
////		return lhs.front().length() > rhs.front().length();
////	}
////};
////
////class Mikser : public std::priority_queue< std::list<std::string>, std::vector<std::list<std::string>>, listGreater<std::string> > {
////public:
////	Mikser() {}
////	Mikser(const std::string& path) { this->open(path); }
////	~Mikser() {}
////
////	void open(const std::string& path) {
////		std::ifstream stream(path, std::ifstream::in);
////		while (stream.good() && !stream.eof()) {
////			std::string line;
////			std::getline(stream, line);
////			if (line == "") { continue; }
////			std::istringstream stringStream(line);
////			std::list<std::string> tmpList;
////			std::string tmpString;
////			while (!stringStream.eof()) {
////				stringStream >> tmpString;
////				tmpList.push_back(tmpString);
////			}
////			tmpList.sort();
////			tmpList.reverse();
////			this->push(tmpList);
////		}
////	}
////
////	void write(const std::string& path) {
////		std::ofstream stream(path, std::ofstream::out | std::ofstream::trunc);
////		const size_t size = this->size();
////		for (int i = 0; i < size; ++i) {
////			auto& row = this->top();
////			for (auto& word : row) { stream << word << " "; }
////			this->pop();
////			stream << "\n";
////		}
////	}
////};
////
////int main(void) {
////	Mikser mikser("mistrz.txt");
////	mikser.write("processed.txt");
////	return 0;
////}
//
//#include <string>
//#include <queue>
//#include <iostream>
//#include <list>
//#include <fstream>
//#include <sstream>
//
//using namespace std;
//using list_string = list<string>;
//
//struct Comparator_ls
//{
//    constexpr bool operator() (const list_string& rhs, const list_string& lhs) const
//    {
//        return lhs.front().size() > rhs.front().size();
//    }
//};
//
//using queue_ls = priority_queue<list_string, deque<list_string>, Comparator_ls>;
//
//class Mixer;
//ostream& operator<<(ostream& os, const Mixer& q);
//
//class Mixer : queue_ls
//{
//public:
//    using queue_ls::c;
//    Mixer() = default;
//    Mixer(const char* filename);
//    void Open(const char* filename);
//    void Write(ostream& out = cout);
//    ~Mixer() = default;
//};
//
//
//inline Mixer::Mixer(const char* filename)
//{
//    Open(filename);
//}
//
//inline void Mixer::Open(const char* filename)
//{
//    ifstream file(filename);
//    list_string ls;
//    string line;
//    while (getline(file, line))
//    {
//        istringstream iss(line);
//        string word;
//        while (iss >> word)
//        {
//            ls.emplace_back(word);
//        }
//        if (!ls.empty())
//        {
//            ls.sort(greater());
//            push(ls);
//            cout << *this << '\n';
//            ls.clear();
//        }
//    }
//}
//
//inline void Mixer::Write(ostream& out)
//{
//
//}
//
//ostream& operator<<(ostream& os, const Mixer& q)
//{
//    for (const auto& list : q.c)
//    {
//        for (const auto& str : list)
//        {
//            os << str << ' ';
//        }
//        os << '\n';
//    }
//    return os;
//}
//
//int main(void) {
//    Mixer mixer("mistrz.txt");
//    return 0;
//}