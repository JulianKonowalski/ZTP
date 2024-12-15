//#include <algorithm>
//#include <iostream>
//#include <stdlib.h>
//#include <vector>
//#include <functional>
//
//double getRandomDouble(double min, double max) {
//	double value =	(rand() / (double)RAND_MAX) * (max - min) + min;
//	return value;
//}
//
//int loadInt(void) {
//	int value;
//	std::cout << "Prosze podac liczbe calkowita: ";
//	std::cin >> value;
//	return value;
//}
//
//std::vector<double> operator*(const std::vector<double>& lhs, const std::vector<double>& rhs) {
//	std::vector<double> result(lhs.size());
//	std::transform(lhs.begin(), lhs.end(), rhs.begin(), result.begin(), std::multiplies<double>());
//	return result;
//}
//
//std::vector<double> operator*(const std::vector<double>& vec, const double& scalar){
//	std::vector<double> result(vec.size());
//	std::vector<double> tmp(vec.size(), scalar);
//	std::transform(vec.begin(), vec.end(), tmp.begin(), result.begin(), std::multiplies<double>());
//	return result;
//}
//
//std::vector<double> operator*(const double& scalar, const std::vector<double> vec) {
//	return vec * scalar;
//}
//
//std::vector<double> operator+(const std::vector<double>& lhs, const std::vector<double>& rhs) {
//	std::vector<double> result(lhs.size());
//	std::transform(lhs.begin(), lhs.end(), rhs.begin(), result.begin(), std::plus<double>());
//	return result;
//}
//
//std::vector<double> operator-(const std::vector<double>& lhs, const std::vector<double>& rhs) {
//	std::vector<double> result(lhs.size());
//	std::transform(lhs.begin(), lhs.end(), rhs.begin(), result.begin(), std::minus<double>());
//	return result;
//}
//
//std::ostream& operator<<(std::ostream& stream, const std::vector<double>& vector) {
//	for(const auto& value : vector) { stream << value << " "; }
//	return stream;
//}
//
//int main(void) {
//	srand((unsigned)time(nullptr));
//	
//	const int dimension = loadInt();
//
//	std::vector<double>A(dimension);
//	std::vector<double>B(dimension, 1.0);
//
//	std::generate(A.begin(), A.end(), []() { return getRandomDouble(-10.0, 10.0); });
//
//	std::vector<double> D = A * B;
//	std::vector<double> C = 3 * B + D;
//	D = 3 * (A + B) - (A * B);
//
//	return 0;
//}
