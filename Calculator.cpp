#include <iostream>

using namespace std;

int add(int a, int b);
int subtract(int a, int b);
int divide(int a, int b);
int multiply(int a, int b);
int (*PointerToOperation(char sign))(int, int);

int main()
{
	cout << "Witaj! Wprowadz znak wykonywanego dzialania: ";
	char sign;
	cin >> sign;
	int(*wsk) (int, int) = PointerToOperation(sign);
	if (wsk == nullptr) {
		return 0;
	}
	else {
		cout << "Podaj liczby na ktorych ma zostac wykonane dzialanie: ";
		int a, b;
		cin >> a >> b;
		int total = (*wsk)(a, b);
		cout << " Twoj wynik to " << total << endl;
	}

	return 0;
}

int add(int a, int b) {
	return a + b;
}
int subtract(int a, int b) {
	return a - b;
}
int divide(int a, int b) {
	return a / b;
}
int multiply(int a, int b) {
	return a * b;
}
int (*PointerToOperation(char sign))(int, int) {
	switch (sign) {
	case '+':
		return &add;
	case '-':
		return &subtract;
	case '*':
		return &multiply;
	case '/':
		return &divide;
	default:
		cout << "Nie ma takiej opcji! " << endl;
		return nullptr;
	}

}