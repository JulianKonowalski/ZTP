///* ==========================
//   (c) WMP.SNŚ UKSW, 2015
//========================== */
//#include<iostream>
//#include<fstream>
//#include<string>
//#include<limits>
//#include<exception>
//
//using namespace std;
//
//class _Bazowe_Cechy {
//public:
//	// pola statyczne stałe - dla stałych wartości całkowitych
//	static const bool _jest_liczba = false;
//	static const bool _nalezy_do_przedzialu = false;
//	static const bool _jest_liczba_calkowita = false;
//};
//
//template<typename T>
//class _Cechy : public _Bazowe_Cechy {
//public:
//	// metody statyczne - dla wartości innych typów niż liczby całkowite
//	static const T _dolna_granica() { return T(); };
//	static const T _gorna_granica() { return T(); };
//};
//
//template<typename T>
//class Cechy : public _Cechy<T> {
//};
//
//class przyspieszenie {
//	double a;
//public:
//	przyspieszenie(double acc = 0) : a(acc) {};
//	double operator()() const { return a; };
//	przyspieszenie& operator=(double acc) { a = acc; return *this; };
//	bool operator<(const przyspieszenie& p) const { return (a < p.a); };
//	friend ostream& operator<<(ostream& os, const przyspieszenie&);
//};
//ostream& operator<<(ostream& os, const przyspieszenie& p) { return os << p.a; };
//
//template<>
//class Cechy<przyspieszenie> : public _Cechy<przyspieszenie> {
//public:
//	static const bool _jest_liczba = true;
//};
//
//class temperatura_wody {
//	double t;
//public:
//	temperatura_wody(double temp = 50) : t(temp) {};
//	double operator()() const { return t; };
//	temperatura_wody& operator=(double temp) { t = temp; return *this; };
//	bool operator<(const temperatura_wody& tw) const { return (t < tw.t); };
//	friend ostream& operator<<(ostream& os, const temperatura_wody&);
//};
//ostream& operator<<(ostream& os, const temperatura_wody& tw) { return os << tw.t; };
//
//template<>
//class Cechy<temperatura_wody> : public _Cechy<temperatura_wody> {
//public:
//	static const bool _jest_liczba = true;
//	static const bool _nalezy_do_przedzialu = true;
//	static const temperatura_wody _dolna_granica() { return temperatura_wody(0); };
//	static const temperatura_wody _gorna_granica() { return temperatura_wody(100); };
//};
//
//class kostka_do_gry {
//	int n;
//public:
//	kostka_do_gry(int num = 1) : n(num) {};
//	int operator()() const { return n; };
//	kostka_do_gry& operator=(int num) { n = num; return *this; };
//	bool operator<(const kostka_do_gry& k) const { return (n < k.n); };
//	friend ostream& operator<<(ostream& os, const kostka_do_gry&);
//};
//ostream& operator<<(ostream& os, const kostka_do_gry& k) { return os << k.n; };
//
//template<>
//class Cechy<kostka_do_gry> : public _Cechy<kostka_do_gry> {
//public:
//	static const bool _jest_liczba = true;
//	static const bool _nalezy_do_przedzialu = true;
//	static const bool _jest_liczba_calkowita = true;
//	static const kostka_do_gry _dolna_granica() { return kostka_do_gry(1); };
//	static const kostka_do_gry _gorna_granica() { return kostka_do_gry(6); };
//};
//
//
///* -- NOWY KOD -- */
//class numerKolnierzykaKoszuli {
//	int n;
//public:
//	numerKolnierzykaKoszuli(int num = 40) : n(num) {};
//	int operator()() const { return n; };
//	numerKolnierzykaKoszuli& operator=(int num) { n = num; return *this; };
//	bool operator<(const numerKolnierzykaKoszuli& k) const { return (n < k.n); };
//	friend ostream& operator<<(ostream& os, const numerKolnierzykaKoszuli&);
//};
//ostream& operator<<(ostream& os, const numerKolnierzykaKoszuli& k) { return os << k.n; };
//
//template<>
//class Cechy<numerKolnierzykaKoszuli> : public _Cechy<numerKolnierzykaKoszuli> {
//public:
//	static const bool _jest_liczba = true;
//	static const bool _nalezy_do_przedzialu = true;
//	static const bool _jest_liczba_calkowita = true;
//	static const numerKolnierzykaKoszuli _dolna_granica() { return numerKolnierzykaKoszuli(38); }; //idk czy to dobre rozmiary xD
//	static const numerKolnierzykaKoszuli _gorna_granica() { return numerKolnierzykaKoszuli(45); };
//};
///* -- NOWY KOD -- */
//
//class Przepelnienie : public exception {
//	char opis[100];
//public:
//	Przepelnienie(const char* o) { strcpy_s(opis, o); }
//	const char* what() const throw() { return opis; };
//};
//class BrakDanych : public exception {
//	char opis[100];
//public:
//	BrakDanych(const char* o) { strcpy_s(opis, o); }
//	const char* what() const throw() { return opis; };
//};
//
//template<typename T, int rozmiar, typename CechyT = Cechy<T>>
//class SzablonStosu {
//	T stos[rozmiar];
//	int top;
//public:
//	int zajetosc() { return top; };
//	SzablonStosu() : top(0) {}
//	void push(const T& i) {
//		if (top == rozmiar)
//			throw Przepelnienie(typeid(i).name());
//		stos[top++] = i;
//	}
//	void push(int i) {
//		if (top == rozmiar)
//			throw Przepelnienie(typeid(i).name());
//
//		// walidacja wartości przekazanej do zapisu
//		if (CechyT::_jest_liczba && CechyT::_jest_liczba_calkowita) {
//			if (CechyT::_nalezy_do_przedzialu) {
//				if (!(T(i) < CechyT::_dolna_granica()) && !(CechyT::_gorna_granica() < T(i)))
//					stos[top++] = i;
//			}
//			else
//				stos[top++] = i;
//		}
//	}
//	void push(double i) {
//		if (top == rozmiar)
//			throw Przepelnienie(typeid(i).name());
//
//		// walidacja wartości przekazanej do zapisu
//		if (CechyT::_jest_liczba && !CechyT::_jest_liczba_calkowita) {
//			if (CechyT::_nalezy_do_przedzialu) {
//				if (!(T(i) < CechyT::_dolna_granica()) && !(CechyT::_gorna_granica() < T(i)))
//					stos[top++] = i;
//			}
//			else
//				stos[top++] = i;
//		}
//	}
//	T pop() {
//		if (top == 0)
//			throw BrakDanych(typeid(stos[0]).name());
//
//		return stos[--top];
//	}
//	template<typename U1, int r, typename U2>
//	friend ostream& operator<<(ostream& os, const SzablonStosu<U1, r, U2>&);
//};
//template<typename U1, int r, typename U2>
//ostream& operator<<(ostream& os, const SzablonStosu<U1, r, U2>& S)
//{
//	for (int i = 0; i < S.top; i++) cout << S.stos[i] << endl;
//	return os;
//};
//
//int main() {
//	SzablonStosu<string, 5> K1;
//	SzablonStosu<przyspieszenie, 10> K2;
//	SzablonStosu<temperatura_wody, 10> K3;
//	SzablonStosu<kostka_do_gry, 10> K4;
//	SzablonStosu<numerKolnierzykaKoszuli, 10> K5;
//
//	// zapełnianie stosów K1, K2, K3 i K4:
//	ifstream fi("qv-lab4.txt");
//	string s;
//	try {
//		K1.push("Henryk");
//		K1.push("Sienkiewicz");
//		while (fi) {
//			fi >> s;
//			K1.push(s);
//			fi.seekg(ios::beg);
//			fi.clear();
//			cout << '*';
//		};
//	}
//	catch (Przepelnienie& e) {
//		cout << "K1 gotowy: " << e.what() << endl;
//	};
//	cout << "Danych na stosie K1: " << K1.zajetosc() << endl << endl;
//
//	K2.push(przyspieszenie());
//	K2.push(przyspieszenie(5.0));
//	K2.push(10);	// uwaga: nie akceptujemy przyspieszenia jako liczby całkowitej
//	K2.push(10.0);
//	cout << K2;
//	cout << "Danych na stosie K2: " << K2.zajetosc() << endl << endl;
//
//	K3.push(temperatura_wody());
//	K3.push(temperatura_wody(36.6));
//	K3.push(71.2);
//	K3.push(112.1); // uwaga: nie akceptujemy wartości spoza przedziału
//	cout << K3;
//	cout << "Danych na stosie K3: " << K3.zajetosc() << endl << endl;
//
//	K4.push(kostka_do_gry(3));
//	K4.push(kostka_do_gry());
//	K4.push(6);
//	K4.push(10); // uwaga: nie akceptujemy wartości spoza przedziału
//	cout << K4;
//	cout << "Danych na stosie K4: " << K4.zajetosc() << endl << endl;
//
//	K5.push(numerKolnierzykaKoszuli());
//	K5.push(numerKolnierzykaKoszuli(41));
//	K5.push(69.69); //sa tylko rozmiary calkowite
//	K5.push(10); //wartosc poza przedzialem
//	cout << K5;
//	cout << "Danych na stosie K5: " << K5.zajetosc() << endl << endl;
//
//	// opróżnianie stosów
//	try {
//		while (true)
//			K1.pop();
//	}
//	catch (BrakDanych& e) {
//		cout << "K1 pusty: " << e.what() << endl;
//	}
//	try {
//		while (true)
//			K2.pop();
//	}
//	catch (BrakDanych& e) {
//		cout << "K2 pusty: " << e.what() << endl;
//	}
//	try {
//		while (true)
//			K3.pop();
//	}
//	catch (BrakDanych& e) {
//		cout << "K3 pusty: " << e.what() << endl;
//	}
//	try {
//		while (true)
//			K4.pop();
//	}
//	catch (BrakDanych& e) {
//		cout << "K4 pusty: " << e.what() << endl;
//	}
//	try {
//		while (true)
//			K5.pop();
//	}
//	catch (BrakDanych& e) {
//		cout << "K5 pusty: " << e.what() << endl;
//	}
//
//	system("pause");
//	return 0;
//}