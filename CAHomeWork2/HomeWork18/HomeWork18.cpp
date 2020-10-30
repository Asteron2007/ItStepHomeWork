// HomeWork18.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS


#include <iostream>


using namespace std;


#define ESC "\x1b"
#define CSI "\x1b["

struct tComplex
{
	double re = 0;
	double im = 0;
	void Display()
	{
		cout << " " << re << " + " << im << "i ";
	}
//	char* asText()
//	{
//		char var[128];
//		sprintf(var, " %f + %fi ", re, im);
//		cout << var;
//		return &*var;
//	}
};

tComplex summ(tComplex A, tComplex B)
{
	tComplex C;
	C.im = A.im + B.im;
	C.re = A.re + B.re;
	return C;
}

tComplex subt(tComplex A, tComplex B)
{
	tComplex C;
	C.im = A.im - B.im;
	C.re = A.re - B.re;
	return C;
}
tComplex mult(tComplex A, tComplex B)
{
	tComplex C;
	C.im = A.im * B.re + A.re * B.im;
	C.re = A.re * B.re- A.im * B.im;
	return C;
}
tComplex div(tComplex A, tComplex B)
{
	tComplex C;
	if ((B.im == 0) || (B.re == 0))
	{
		cout << "Error! Division by zero";
		C.im = A.im;
		C.re = A.re;
	}
	else
	{
		C.im = (A.im * B.re - A.re * B.im) / (B.im * B.im + B.re * B.re);
		C.re = (A.re * B.re + A.im * B.im) / (B.im * B.im + B.re * B.re);
	}
	return C;
}

// добавление строки к массиву строк
int MyArrInsertString(char**& pArr, size_t& Len, size_t IndexY, char* MyStr)
{
	if ((IndexY >= 0) && (IndexY <= Len))
	{
		pArr = (char**)realloc(pArr, sizeof(char*) * (++Len));
		//		int TerminatorPos = Len;
		for (size_t i = Len - 1; (i >= IndexY) && (i < Len); i--)
		{
			pArr[i + 1] = pArr[i];
		}
		//динамическое выделение
		size_t lenstr = (strlen(MyStr) + 1);
		pArr[IndexY] = (char*)malloc(sizeof(char) * lenstr);
		//strcpy_s(pMyStr[i], len, tmpStr);
		strcpy_s(pArr[IndexY], lenstr, MyStr);
	}
	else
	{
		cout << "Invalid index < string length\n";
		return -1;
	}

	return 0;
}
int MyCompareStr(char* pArr1, char* pArr2)
{
	size_t Pos = 0;
	size_t Len1 = strlen(pArr1);
	size_t Len2 = strlen(pArr2);
	size_t Len = Len1 > Len2 ? Len2 : Len1;


	if ((pArr1 != NULL) && (pArr2 != NULL))
		for (size_t i = 0; i < Len; i++)
		{
			if (pArr1[i] == pArr2[i])
				continue;
			else if (pArr1[i] > pArr2[i])
				return 1;
			else
				return -1;
		}

	if (Len1 == Len2)
		return 0;
	else if (Len1 > Len2)
		return 1;
	else
		return -1;

	//return 0;
}
// 
void MyArrSort(char**& pArr, size_t Len)
{
	size_t  Pos = 0;
	char* ptmpStr = NULL;

	for (size_t i = 0; i < Len - 1; i++)
	{
		Pos = i;
		if (*(pArr + i) != NULL)
		{
			for (size_t j = i + 1; j < Len; j++)
			{
				if (*(pArr + j) != NULL)
				{
					if (MyCompareStr(pArr[Pos], pArr[j]) > 0)
					{
						Pos = j;
					}
				}
				else break;
			}
			char* ptmpStr = pArr[Pos];
			pArr[Pos] = pArr[i];
			pArr[i] = ptmpStr;
		}
		else
			break;
	}
	return;
}

void MyStrArrPrint(char**& pArr, size_t Len)
{
	size_t  Pos = 0; 
	for (size_t i = 0; i < Len; i++)
	{
		if (*(pArr + i) != NULL)
		{
			while (pArr[i][Pos] != '\0')
			{
				cout << pArr[i][Pos];
				Pos++;
			}
			Pos = 0;
			cout << "\n";
		}
		else
			break;
	}

	return;
}

void MyIntArrPrint(int**& pArr, size_t LenY, size_t LenX)
{
	for (size_t i = 0; i < LenY; i++)
	{
		if (*(pArr + i) != NULL)
		{
			for (size_t j = 0; j < LenX; j++)
				cout << pArr[i][j]<< "\t ";
			cout << "\n";
		}
		else
			break;
	}

	return;
}

// добавляет элемент к одномерному массиву
void MyArrAddElem(int*& pArr, size_t& Len, int Val)
{
	pArr = (int*)realloc(pArr, sizeof(int) * (++Len));
	pArr[Len - 1] = Val;
	return;
}


/*void MyUnique(pMyNewArr, LenNewArr, pMyArrA, LenAY, LenAX)
{
	for (size_t i = 0; i < LenAY; i++)
	{
		if (*(pMyArrA + i) != NULL)
		{
			for (size_t j = 0; j < LenAX; j++)
			{


				MyArrAddElem(pMyNewArr, LenNewArr, pMyArrA[i][j]);


			}
		}
		else
			break;
	}
}*/

bool MyIntArrFindElement(char** pArr, size_t LenY, size_t LenX, int Val, size_t& IndY, size_t& IndX,
	size_t StartY = 0, size_t StartX = 0)
{
	for (size_t i = StartY; i < LenY; i++)
		for (size_t j = StartX; j < LenX; j++)
			if (pArr[i][j] == Val)
			{
				IndY = i;
				IndX = j;
				return true;
			}

	return false;
}

// добавляет к одномерному массиву уникальные положительные и отрицательные элементы из двумерного массива
void MyAddUnique(int*& pNewArr, size_t& LenNewArr, int** pArr, size_t LenY, size_t LenX,
	bool Negatve = true, bool Positive = true)
{
	bool uniq = true;
	for (size_t i = 0; i < LenY; i++)
	{
		for (size_t j = 0; j < LenX; j++)
		{
			if (LenNewArr > 0)
			{
				for (size_t k = 0; k < LenNewArr; k++)
				{
					if (pArr[i][j] == pNewArr[k])
					{
						uniq = false;
						break;
					}

				}
			}
			if (uniq)
			{
				if (Positive && (pArr[i][j] >= 0))
				{
					pNewArr = (int*)realloc(pNewArr, sizeof(int) * (++LenNewArr));
					pNewArr[LenNewArr - 1] = pArr[i][j];
				}
				
				if (Negatve && (pArr[i][j] < 0))
				{
					pNewArr = (int*)realloc(pNewArr, sizeof(int) * (++LenNewArr));
					pNewArr[LenNewArr - 1] = pArr[i][j];
				}								
			}
			uniq = true;
		}
	}

	return;
}

// добавляет к одномерному массиву уникальные положительные и отрицательные элементы из одномерного массива
void MyAddEqual(int*& pNewArr, size_t& LenNewArr, int* pArr1, size_t LenArr1, int* pArr2, size_t LenArr2,
	bool Negatve = true, bool Positive = true)
{
	for (size_t i = 0; i < LenArr1; i++)
	{
		for (size_t j = 0; j < LenArr2; j++)
		{
			if (pArr1[i] == pArr2[j])
			{
				if (Positive && (pArr1[i] >= 0))
				{
					pNewArr = (int*)realloc(pNewArr, sizeof(int) * (++LenNewArr));
					pNewArr[LenNewArr - 1] = pArr1[i];
				}

				if (Negatve && (pArr1[i] < 0))
				{
					pNewArr = (int*)realloc(pNewArr, sizeof(int) * (++LenNewArr));
					pNewArr[LenNewArr - 1] = pArr1[i];
				}
			}
		}
	}	
	return;
}


int main()
{
	system("chcp 1251");  // переходим на русский язык в консоли
	
//Домашнее задание № 18
//Встреча №35
//Задание 1:
//Написать программу, которая дает пользователю ввести 5 фамилий студентов, а затем сортирует их по возрастанию.
	{
		system("CLS");
		cout << "\nHomeWork #18. Meting #35. Task #1\n";
		size_t CountY = 1; // размер массива
	
		char** pMyStrArr = (char**)malloc(sizeof(char*) * (CountY));
		char tmpStr[128];
		size_t ind = 0;
		size_t len = 0;
		CountY = 0;
		while (true)
		{
			cout << "Enter new Name (0 to exit): ";
			cin >> tmpStr;
			if (tmpStr[0] != '0')
			{
				MyArrInsertString(pMyStrArr, CountY, ind, tmpStr);
				ind++;
			}
			else break;
		}
		CountY = ind;
		
		size_t  Pos = 0;
		// Вывод элементов массива
		cout << "Print names list\n";
		MyStrArrPrint(pMyStrArr, CountY);
		
		MyArrSort(pMyStrArr, CountY);

		// Вывод элементов массива после сортировки
		cout << "Print names list after sort\n";
		MyStrArrPrint(pMyStrArr, CountY);
		
		// Очистка памяти
		cout << "Free memory\n";
		for (size_t i = 0; i < CountY; i++)
			free(pMyStrArr[i]);   // освобождение памяти из под строки
		free(pMyStrArr);

		cout << "\n";
		system("Pause");
	}

//Задание 2:
//Есть 3 двумерных массива A, B, C. Количество строк и столбцов для них вводит пользователь с клавиатуры для каждого из них.
//Реализуйте
// Создайте одномерный массив, который содержит общие значения для A, B, C
// Создайте одномерный массив, который содержит уникальные значения для A, B, C
// Создайте одномерный массив, который содержит общие значения для A и C
// Создайте одномерный массив, который содержит отрицательные значения для A, B, C без повторений
	{
		system("CLS");
		cout << "\nHomeWork #18. Meting #35. Task #2\n";

		size_t LenAY = 1; // размер массива
		size_t LenAX = 1;

		cout << "Enter array A length Y: ";
		cin >> LenAY;
		cout << "Enter array A length X: ";
		cin >> LenAX;

		int** pMyArrA = (int**)malloc(sizeof(int*) * (LenAY));
		for (size_t i = 0; i < LenAY; i++)
		{
			pMyArrA[i] = (int*)malloc(sizeof(int) * (LenAX));

			if (*(pMyArrA + i) != NULL)
			{
				for (size_t j = 0; j < LenAX; j++)
				{
					pMyArrA[i][j] = (rand()-RAND_MAX/2)/1000;
					cout << pMyArrA[i][j] << "\t ";
				}				
				cout << "\n";
			}
			else
				break;
		}
		
		size_t LenBY = 1; // размер массива
		size_t LenBX = 1;
		cout << "Enter array B length Y: ";
		cin >> LenBY;
		cout << "Enter array B length X: ";
		cin >> LenBX;

		int** pMyArrB = (int**)malloc(sizeof(int*) * (LenBY));
		for (size_t i = 0; i < LenBY; i++)
		{
			pMyArrB[i] = (int*)malloc(sizeof(int) * (LenBX));

			if (*(pMyArrB + i) != NULL)
			{
				for (size_t j = 0; j < LenBX; j++)
				{
					pMyArrB[i][j] = (rand() - RAND_MAX / 2) / 1000;
					cout << pMyArrB[i][j] << "\t ";
				}
				cout << "\n";
			}
			else
				break;
		}

		size_t LenCY = 1; // размер массива
		size_t LenCX = 1;
		cout << "Enter array C length Y: ";
		cin >> LenCY;
		cout << "Enter array C length X: ";
		cin >> LenCX;

		int** pMyArrC = (int**)malloc(sizeof(int*) * (LenCY));
		for (size_t i = 0; i < LenCY; i++)
		{
			pMyArrC[i] = (int*)malloc(sizeof(int) * (LenCX));

			if (*(pMyArrC + i) != NULL)
			{
				for (size_t j = 0; j < LenCX; j++)
				{
					pMyArrC[i][j] = (rand() - RAND_MAX / 2) / 1000;
					cout << pMyArrC[i][j] << "\t ";
				}
				cout << "\n";
			}
			else
				break;
		}

		size_t LenNewArr = 1;		
		int* pMyNewArr = (int*)malloc(sizeof(int) * (LenNewArr--));

		// Создайте одномерный массив, который содержит уникальные значения для A, B, C
		MyAddUnique(pMyNewArr, LenNewArr, pMyArrA, LenAY, LenAX);
		MyAddUnique(pMyNewArr, LenNewArr, pMyArrB, LenBY, LenBX);
		MyAddUnique(pMyNewArr, LenNewArr, pMyArrC, LenCY, LenCX);
		cout << "\nElements from А, В, С without repeat: ";
		for (size_t i = 0; i < LenNewArr; i++)
			cout << pMyNewArr[i] << "\t ";
		
		// Создайте одномерный массив, который содержит отрицательные значения для A, B, C без повторений
		LenNewArr = 0;
		pMyNewArr = (int*)realloc(pMyNewArr, sizeof(int) * (LenNewArr));
		MyAddUnique(pMyNewArr, LenNewArr, pMyArrA, LenAY, LenAX, true, false);
		MyAddUnique(pMyNewArr, LenNewArr, pMyArrB, LenBY, LenBX, true, false);
		MyAddUnique(pMyNewArr, LenNewArr, pMyArrC, LenCY, LenCX, true, false);
		cout << "\nNegative elements from А, В, С without repeat: ";
		for (size_t i = 0; i < LenNewArr; i++)
			cout << pMyNewArr[i] << "\t ";

		// Создайте одномерный массив, который содержит общие значения для A, B, C
		// Создайте одномерный массив, который содержит общие значения для A и C
		size_t tmpLenNewArr1 = 1;
		int* pMytmpNewArr1 = (int*)malloc(sizeof(int) * (tmpLenNewArr1--));
		size_t tmpLenNewArr2 = 1;
		int* pMytmpNewArr2 = (int*)malloc(sizeof(int) * (tmpLenNewArr2--));		
		LenNewArr = 0;
		pMyNewArr = (int*)realloc(pMyNewArr, sizeof(int) * (LenNewArr));

		MyAddUnique(pMytmpNewArr1, tmpLenNewArr1, pMyArrA, LenAY, LenAX);
		MyAddUnique(pMytmpNewArr2, tmpLenNewArr2, pMyArrC, LenCY, LenCX);

		MyAddEqual(pMyNewArr, LenNewArr, pMytmpNewArr1, tmpLenNewArr1, pMytmpNewArr2, tmpLenNewArr2);
			   
		cout << "\nEquals elements from А, С without repeat: ";
		for (size_t i = 0; i < LenNewArr; i++)
			cout << pMyNewArr[i] << "\t ";


		
		cout << "\n";
		system("Pause");







		// Очистка памяти
		cout << "Free memory\n";
		for (size_t i = 0; i < LenAY; i++)
			free(pMyArrA[i]);   // освобождение памяти из под строки
		free(pMyArrA);
		for (size_t i = 0; i < LenBY; i++)
			free(pMyArrB[i]);   // освобождение памяти из под строки
		free(pMyArrB);
		for (size_t i = 0; i < LenCY; i++)
			free(pMyArrC[i]);   // освобождение памяти из под строки
		free(pMyArrC);
		free(pMyNewArr);



		cout << "\n";
		system("Pause");

	}
	   	 
//Домашнее задание № 18 Встреча №36
//Задание 1:
//Создайте структуру, описывающую комплексное число.Реализуйте арифметические операции с комплексными числами :
//сумму, разность, умножение, деление.
	
	{
		system("CLS");
		cout << "\nHomeWork #18. Meting #36. Task #1\n";

		tComplex NumA;
		tComplex NumB;

		NumA.im = 5;
		NumA.re = 10;
		cout << "A =";
		NumA.Display();
		cout << "\n";
		//	cout <<"\n" << NumA.asText();
		
		NumB.im = 115;
		NumB.re = 210;
		cout << "B =";
		NumB.Display();
		cout << "\n";
		//	cout << "\n" << NumB.asText();


		tComplex NumC = summ(NumA, NumB);
		cout << "C = A + B = ";
		NumC.Display();
		cout << "\n";

		NumC = mult(NumA, NumB);
		cout << "C = A * B = ";
		NumC.Display();
		cout << "\n";

		NumC = subt(NumA, NumB);
		cout << "C = A - B = ";
		NumC.Display();
		cout << "\n";

		NumC = div(NumA, NumB);
		cout << "C = A / B = ";
		NumC.Display();
		cout << "\n";

		cout << "\n";
		system("Pause");
	}

//Задание 2:
//Реализовать структуру «Автомобиль» (длина, клиренс (высота посадки), объем двигателя, мощность двигателя, 
//диаметр колес, цвет, тип коробки передач). Создайте функции для задания значений, отображения значений, поиска значений.
	
	struct tAuto
	{
		//char Name[128];
		double Lenght = 5;
		double Clearance = 10;
		double Potencia = 1000;
		double Power = 1500;
		double WheelDiametr = 0;
		int Color = 0;
		int Transmission = 0;

		void Display()
		{
			std::cout << CSI "15;94m";   // black background / blue text	

			//cout << "Name: " << Name << "\n";
			cout << "Lenght: " << Lenght << "\n";
			cout << "Clearance: " << Clearance << "\n";
			cout << "Potencia:" << Potencia << "\n";
			cout << "Power: " << Power << "\n";
			cout << "WheelDiametr: " << WheelDiametr << "\n";

			cout << "Color: " << Color << "\n";

			cout << "Transmission: " << Transmission << "\n";
			std::cout << CSI "0m";       // restore colors 
		}
	};
	
	{
		system("CLS");
		cout << "\nHomeWork #18. Meting #36. Task #2\n";
		tAuto MyAuto;

		MyAuto.Color = 1;
		//MyAuto.Name = "dodge";
		MyAuto.Clearance = 20.0;
		MyAuto.Lenght = 10;

		MyAuto.Display();
		cout << "\n";
		system("Pause");

	}
	return 0;
}
