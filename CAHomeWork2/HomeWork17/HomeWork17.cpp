// HomeWork17.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>
#include <malloc.h>
#include <functional>
//#include <string>

using namespace std;

enum TShiftOrientation
{
	horizontal,
	vertical
};

// вставка столбца в матрицу
void InsertMatrixColumn(int**& pArr, size_t ColumnIndex, size_t& M, size_t& N, int* pColumn)
{
	if (ColumnIndex > N-1)
		ColumnIndex = N;
	N++;
	for (size_t i = 0; i < M; i++)
	{
		pArr[i] = (int*)realloc(pArr[i], sizeof(int) * (N));
		if (*(pArr + i) != NULL)
		{
			for (size_t j = N; j > ColumnIndex; j--)
			{
				pArr[i][j] = pArr[i][j - 1];
			}
			pArr[i][ColumnIndex] = pColumn[i];
		}
		else
			break;
	}
}

//  удаление столбца в матрице
void DeleteMatrixColumn(int**& pArr, size_t ColumnIndex,size_t &M, size_t &N)
{
	if (ColumnIndex < N)
	{
		N--;
		for (size_t i = 0; i < M; i++)
		{
			if (*(pArr + i) != NULL)
			{
				for (size_t j = ColumnIndex; j < N; j++)
				{
					pArr[i][j] = pArr[i][j + 1];
				}
			}
			else
				break;
			pArr[i] = (int*)realloc(pArr[i], sizeof(int) * (N));
		}
	}	
}


// сдвиг матрицы по произвольному вектору
void ShiftMatrix(int**& pArr, size_t M, size_t N, TShiftOrientation ShiftOrientation, int*& pShiftVector, size_t ShiftVectorLen)
{
	//собственно сам сдвиг на 1 элемент, если 
	int tmp = 0;
	switch (ShiftOrientation)
	{
	case vertical:
	{
		for (size_t i = 0; i < N; i++)
		{
			if (pShiftVector[i] != 0)
			{
				if (pShiftVector[i] > 0)
				{
					tmp = pArr[M - 1][i];
					for (size_t j = M - 1; j > 0; j--)
					{
						pArr[j][i] = pArr[j - 1][i];
					}
					pArr[0][i] = tmp;
				}
				else
				{
					tmp = pArr[0][i];
					for (size_t j = 0; j < M - 1; j++)
					{
						pArr[j][i] = pArr[j + 1][i];
					}
					pArr[M - 1][i] = tmp;
				}

			}

			// уменьшаем вектор сдвига
			if (pShiftVector[i] != 0)
			{
				pShiftVector[i] > 0 ? pShiftVector[i]-- : pShiftVector[i]++;
			}
		}

		for (size_t i = 0; i < ShiftVectorLen; i++)
		{
			if (pShiftVector[i] != 0)
			{
				ShiftMatrix(pArr, M, N, ShiftOrientation, pShiftVector, ShiftVectorLen);
				break;
			}
		}
		break;
	}
	case horizontal:
	{
		for (size_t i = 0; i < M; i++)
		{
			if (pShiftVector[i] != 0)
			{
				if (pShiftVector[i] > 0)
				{
					tmp = pArr[i][N - 1];
					for (size_t j = N - 1; j > 0; j--)
					{
						pArr[i][j] = pArr[i][j - 1];
					}
					pArr[i][0] = tmp;
				}
				else
				{
					tmp = pArr[i][0];
					for (size_t j = 0; j < N - 1; j++)
					{
						pArr[i][j] = pArr[i][j + 1];
					}
					pArr[i][N - 1] = tmp;
				}
			}

			// уменьшаем вектор сдвига

			if (pShiftVector[i] != 0)
			{
				pShiftVector[i] > 0 ? pShiftVector[i]-- : pShiftVector[i]++;
			}
		}

		for (size_t i = 0; i < ShiftVectorLen; i++)
		{
			if (pShiftVector[i] != 0)
			{
				ShiftMatrix(pArr, M, N, ShiftOrientation, pShiftVector, ShiftVectorLen);
				break;
			}
		}
		break;
	}
	default:
		break;
	}
	
	return;
}

// возвращает длину строки
size_t MyStrLen(const char* str)
{
	int TerminatorPos = 0;
	while (str[TerminatorPos] != '\0')
		TerminatorPos++;
	return TerminatorPos;
}

// копирует строку2 в строку1
char* MyStrCopy(char* str1, const char* str2)   //&??????
{
	for (size_t i = 0; i <= MyStrLen(str2); i++)
	{
		str1[i] = str2[i];
	}
	return &*str1;
}


// добавление строки к массиву строк
int MyArrInsertString(char** &pArr, size_t &Len, size_t IndexY, char* MyStr)
{
	if ((IndexY >= 0) && (IndexY <= Len))
	{
		pArr = (char**)realloc(pArr, sizeof(char*) * (++Len));
		//		int TerminatorPos = Len;
		for (size_t i = Len-1; (i >= IndexY) && (i < Len); i--)
		{
			pArr[i + 1] = pArr[i];
		}
		//динамическое выделение
		size_t lenstr = (MyStrLen(MyStr) + 1);
		pArr[IndexY] = (char*)malloc(sizeof(char) * lenstr);
		//strcpy_s(pMyStr[i], len, tmpStr);
		MyStrCopy(pArr[IndexY], MyStr);
	}
	else
	{
		cout << "Invalid index < string length\n";
		return -1;
	}

	return 0;
}

// добавление 2 строки (телефонный справочник) к массиву строк
int MyArrInsert2String(char** &pArr,size_t &Len, size_t IndexY, char* MyStr1, char* MyStr2)
{
	int retCode = MyArrInsertString(pArr, Len, IndexY, MyStr1); // number
	if (retCode != 0) return retCode;
	retCode = MyArrInsertString(pArr, Len, IndexY + 1, MyStr2); // name	
	return retCode;
}

// удаление строки из массива строк
int MyArrDelString(char**& pArr, size_t& Len, size_t IndexY)
{
	if ((IndexY >= 0) && (IndexY < Len))
	{			
		//освобождение динамической памяти 
		free(pArr[IndexY]);
		for (size_t i = IndexY; i < Len; i++)
		{
			pArr[i] = pArr[i + 1];
		}
		pArr = (char**)realloc(pArr, sizeof(char*) * (--Len));
	}
	else
	{
		cout << "Invalid index < string length\n";
		return -1;
	}

	return 0;
}



/*
const size_t strLen = 128;
		char str[strLen];
		float f;

		FILE* ptrFile1 = fopen("Lab.txt", "r");// C:\Users\Book\source\repos\CAHomeWork2
		FILE* ptrFile2 = fopen("Lab-new.txt", "w");// C:\Users\Book\source\repos\CAHomeWork2

		if ((ptrFile1 != NULL) && (ptrFile2 != NULL))
		{
			fputs("Пример использования функции fopen\n \n \n", ptrFile2); // записать строку в файл
			while (!feof(ptrFile1))
			{
				fgets(str, strLen, ptrFile1);
				fputs(str, ptrFile2);
				cout << str;
			}

			fclose(ptrFile1);
			fclose(ptrFile2);

			//fprintf(pFile, "%f %s", 3.1416, "PI");
			//rewind(pFile);
			//fscanf(pFile, "%f", &f);
			//fscanf(pFile, "%s", str);
			//fclose(pFile);
			//printf("I have read: %f and %s \n", f, str);
		}
		cout << "Record complete\n";

		cout << "\n";
		system("Pause");
	}
*/



int main()
{
	system("chcp 1251");  // переходим на русский язык в консоли

	{
		system("CLS");
		cout << "\nHomeWork #17. Meting #33. Task #1 and 2\n";
		size_t M = 10; // columns count M
		size_t N = 8; // rows count N

		int** pArr = (int**)malloc(sizeof(int*) * (M));

		cout << "Init Array\n";
		for (size_t i = 0; i < M; i++)
		{
			pArr[i] = (int*)malloc(sizeof(int) * N);
			if (*(pArr + i) != NULL)
			{
				for (size_t j = 0; j < N; j++)
				{
					pArr[i][j] = rand();
					cout << pArr[i][j] << "\t ";
				}
			}
			else
				break;
			cout << "\n";
		}
		cout << "\n";
		int ColumnIndex = 0;
		cout << "Enter Column to insert: ";
		cin >> ColumnIndex;
		//Домашнее задание № 17
		//Встреча №33
		//Задание 1:
		//Написать функцию, добавляющую столбец двухмерному массиву в указанную позицию.
		int* pVector = (int*)malloc(sizeof(int) * M);
		for (size_t i = 0; i < M; i++)
		{
			pVector[i] = i*10;
		}
		InsertMatrixColumn(pArr, ColumnIndex, M, N, pVector);
	
		// Выводим массив после вставки
		cout << "\n";
		cout << "Matrix after insert:\n";
		for (size_t i = 0; i < M; i++)
		{
			if (*(pArr + i) != NULL)
			{
				for (size_t j = 0; j < N; j++)
				{
					cout << pArr[i][j] << "\t ";
				}
			}
			else
				break;
			cout << "\n";
		}

		cout << "Enter Column to delete: ";
		cin >> ColumnIndex;		

		//Задание 2:
		//Написать функцию, удаляющую столбец двухмерного массива по указанному номеру.
		DeleteMatrixColumn(pArr, ColumnIndex, M, N);
		
		// Выводим массив после удаления
		cout << "\n";
		cout << "Matrix after delete:\n";
		for (size_t i = 0; i < M; i++)
		{
			if (*(pArr + i) != NULL)
			{
				for (size_t j = 0; j < N; j++)
				{
					cout << pArr[i][j] << "\t ";
				}
			}
			else
				break;
			cout << "\n";
		}
		
		// Очистка памяти
		cout << "Free memory\n";
		for (size_t i = 0; i < M; i++)
			free(pArr[i]);   // освобождение памяти
		free(pArr);
		free(pVector);
		cout << "\n";
		system("Pause");
	}
//Задание 3:
//Дана матрица порядка MxN (M строк, N столбцов). Необходимо заполнить ее значениями и написать функцию, 
//осуществляющую циклический сдвиг строк и/или столбцов массива указанное количество раз и в указанную сторону.
	{
		system("CLS");
		cout << "\nHomeWork #17. Meting #33. Task #3\n";
		size_t M = 10; // columns count M
		size_t N = 8; // rows count N

		int** pArr = (int**)malloc(sizeof(int*) * (M));

		cout << "Init Array\n";
		for (size_t i = 0; i < M; i++)
		{
			pArr[i] = (int*)malloc(sizeof(int) * N);
			if (*(pArr + i) != NULL)
			{
				for (size_t j = 0; j < N; j++)
				{
					pArr[i][j] = rand();
					cout << pArr[i][j] << "\t ";
				}
			}
			else
				break;
			cout << "\n";
		}
				
		int tmpVal = 0; 
		int ShiftOrientation = 0;

		cout << "Enter ShiftOrientation (1 - vertical, 2 - horisontal): ";
		cin >> ShiftOrientation;
		
		size_t ShiftVectorLen = 0;
		int* pShiftVector=NULL;

		switch (ShiftOrientation)
		{
		case 1: // vertical
		{
			ShiftVectorLen = N;
			pShiftVector = (int*)malloc(sizeof(int) * ShiftVectorLen); // 
			for (size_t i = 0; i < ShiftVectorLen; i++)
			{
				cout << "Enter shift[" << i << "]: ";
				cin >> pShiftVector[i];
				//cout << ShiftVector[i] << "\n";
			}
			ShiftMatrix(pArr, M, N, vertical, pShiftVector, ShiftVectorLen);
			break;
		}
		case 2: // horizontal
		{
			ShiftVectorLen = M;
			pShiftVector = (int*)malloc(sizeof(int) * ShiftVectorLen); // 
			for (size_t i = 0; i < ShiftVectorLen; i++)
			{
				cout << "Enter shift[" << i << "]: ";
				cin >> pShiftVector[i];
				//cout << pShiftVector[i] << "\n";
			}
			ShiftMatrix(pArr, M, N, horizontal, pShiftVector, ShiftVectorLen);
			break;
		}
		default:
			break;
		}

		cout << "\n"; 
		cout << "Shifted Matrix:\n";
		for (size_t i = 0; i < M; i++)
		{
			if (*(pArr + i) != NULL)
			{
				for (size_t j = 0; j < N; j++)
				{
					cout << pArr[i][j] << "\t ";
				}
			}
			else
				break;
			cout << "\n";
		}

		// Очистка памяти
		cout << "Free memory\n";
		for (size_t i = 0; i < M; i++)
			free(pArr[i]);   // освобождение памяти
		free(pArr);
		free(pShiftVector);
		cout << "\n";
		system("Pause");
	}


//Домашнее задание № 17
//Встреча №34
//Задание 1:
//Транспонирование матрицы – это операция, после которой столбцы прежней матрицы становятся строками, 
//а строки столбцами. Напишите функцию транспонирования матрицы.
	{
		system("CLS");
		cout << "\nHomeWork #17. Meting #34. Task #2\n";
		size_t CountY = 10; // размер массива Y
		size_t CountX = 10; // размер массива X

		int** pArr = (int**)malloc(sizeof(int*) * (CountY));

		cout << "Init Array\n";
		for (size_t i = 0; i < CountY; i++)
		{
			pArr[i] = (int*)malloc(sizeof(int) * CountX);
			if (*(pArr + i) != NULL)
			{
				for (size_t j = 0; j < CountX; j++)
				{
					pArr[i][j] = rand();
					cout << pArr[i][j] << "\t ";
				}
			}
			else
				break;
			cout << "\n";
		}
		cout << "\n";
		system("Pause");
		int tmpVal = 0;
		cout << "Transposed matrix\n";
		for (size_t i = 1; i < CountY; i++)
		{
			if (*(pArr + i) != NULL)
			{
				for (size_t j = 0; j <= i; j++)
				{
					tmpVal = pArr[i][j];
					pArr[i][j] = pArr[j][i];
					pArr[j][i] = tmpVal;
				}
			}
			else
				break;
		}
		cout << "\n";
		cout << "Out transposed matrix\n";
		for (size_t i = 0; i < CountY; i++)
		{
			if (*(pArr + i) != NULL)
			{
				for (size_t j = 0; j < CountX; j++)
				{
					cout << pArr[i][j] << "\t ";
				}
			}
			else
				break;
			cout << "\n";
		}

		cout << "\n";
		system("Pause");

		// Очистка памяти
		cout << "Free memory\n";
		for (size_t i = 0; i < CountY; i++)
			free(pArr[i]);   // освобождение памяти
		free(pArr);
		cout << "\n";
		system("Pause");
	}
//Задание 2:
//Создайте динамический массив, хранящий в первой строке имя, а во второй - телефон. 
//Организуйте поиск по имени и по номеру телефона и возможность ввода и изменения данных.
	
	{
		system("CLS");
		cout << "\nHomeWork #17. Meting #34. Task #2\n"; 
		
		size_t CountY = 1; // размер массива
		//	char* ptmpNewStr;

		char** pMyStrArr = (char**)malloc(sizeof(char*) * (CountY));
		char tmpStr[128];
		size_t ind = 0;
		size_t len = 0;
		CountY = 0;
		while (true)
		{
			cout << "Enter new phone (0 to exit): ";
			cin >> tmpStr;
			if (tmpStr[0] != '0')
			{
				MyArrInsertString(pMyStrArr, CountY, ind, tmpStr);
				/*len = (MyStrLen(tmpStr) + 1);
				pMyStrArr[ind] = (char*)malloc(sizeof(char) * len);
				//strcpy_s(pMyStr[i], len, tmpStr);
				MyStrCopy(pMyStrArr[ind], tmpStr);
				tmpStr[0] = '\0';
				*/
				ind++;

				cout << "Enter new name: ";
				cin >> tmpStr;
				MyArrInsertString(pMyStrArr, CountY, ind, tmpStr);
				/*len = (MyStrLen(tmpStr) + 1);
				pMyStrArr[ind] = (char*)malloc(sizeof(char) * len);
				MyStrCopy(pMyStrArr[ind], tmpStr);
				tmpStr[0] = '\0';
				*/
				ind++;
			}
			else break;
		}
		CountY = ind;
		//pMyStr[CountY] = NULL;

		size_t  Pos = 0;
		// Вывод элементов массива
		cout << "Выводим телефонный справочник номеров\n";
		for (size_t i = 0; i < CountY; i++)
		{
			if (*(pMyStrArr + i) != NULL)
			{
				//ptmpNewStr = *(pMyStrArr + i);
				//ptmpNewStr = pMyStr[i];
				//cout << *(pMyStr+i);

				while (pMyStrArr[i][Pos] != '\0')
				{
					cout << pMyStrArr[i][Pos];
					Pos++;
				}
				Pos = 0;
				//cout << *ptmpNewStr;
				cout << "\n";
			}
			else
				break;
		}
		cout << "\n";
		system("Pause");

		char tmpStrNumber[128];
		char tmpStrName[128];
		
		MyStrCopy(tmpStrNumber, "89109990001");
		MyStrCopy(tmpStrName, "Ivanov");
		// добавление строки к двумерному массиву в 
		MyArrInsert2String(pMyStrArr, CountY, 2, tmpStrNumber, tmpStrName);

		cout << "Выводим телефонный справочник после добавления номеров\n";		
 		Pos = 0;
		// Вывод элементов массива
		for (size_t i = 0; i < CountY; i++)
		{
			if (*(pMyStrArr + i) != NULL)
			{
				//ptmpNewStr = *(pMyStrArr + i);
				//ptmpNewStr = pMyStr[i];
				//cout << *(pMyStr+i);

				while (pMyStrArr[i][Pos] != '\0')
				{
					cout << pMyStrArr[i][Pos];
					Pos++;
				}
				Pos = 0;
				//cout << *ptmpNewStr;
				cout << "\n";
			}
			else
				break;
		}

		MyArrDelString(pMyStrArr, CountY, 0);
		cout << "Выводим телефонный справочник после удаления номеров\n";
		Pos = 0;
		// Вывод элементов массива
		for (size_t i = 0; i < CountY; i++)
		{
			if (*(pMyStrArr + i) != NULL)
			{
				while (pMyStrArr[i][Pos] != '\0')
				{
					cout << pMyStrArr[i][Pos];
					Pos++;
				}
				Pos = 0;
				cout << "\n";
			}
			else
				break;
		}

		cout << "\n";
		system("Pause");

		// Очистка памяти
		cout << "Free memory\n";
		for (size_t i = 0; i < CountY; i++)
			free(pMyStrArr[i]);   // освобождение памяти из под строки
		free(pMyStrArr);
		cout << "\n";
		system("Pause");
	}

	return 0;
}