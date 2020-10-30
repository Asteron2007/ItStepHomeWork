// HomeWork16.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>

using namespace std;

/*int main()
{
	const int& v = ([]() -> int { int q = 0; return q; })();

	int* pInt = const_cast<int*>(&v);
	*pInt = 9;

	cout << "pInt: " << *pInt;
	return 0;
}
*/


void main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int* b = new int[3];
	*b = 10;
	*(b + 1) = 12;
	*(b + 2) = 14;
	b = a;
	//delete[] b;
}
