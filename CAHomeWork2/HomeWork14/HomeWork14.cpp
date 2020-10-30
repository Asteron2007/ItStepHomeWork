// HomeWork14.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <malloc.h>
#include <cassert> 

using namespace std;

typedef unsigned char BYTE;
typedef int INTARR[(CHAR_BIT << sizeof(size_t)) / sizeof(int)];


// разделяет статический массив на динамические (с положительными, нулевыми и отрицательными элементами)
// первый элемент массива - это количество элементов в соответсвующем динамическом массиве.
void SplitNegZeroPos(int* pArr, const size_t Len, int*& pNegArr, int*& pZeroArr, int*& pPosArr)
{
	for (size_t i = 0; i < Len; i++)
	{
		if (*(pArr + i) == 0)
		{
			pZeroArr = (int*)realloc(pZeroArr, (++ * pZeroArr + 1) * sizeof(int));
			assert(pZeroArr != NULL);
			*(pZeroArr + *(pZeroArr)) = *(pArr + i);
		}
		
		if (*(pArr + i) < 0)
		{
			pNegArr = (int*)realloc(pNegArr, (++ * pNegArr + 1) * sizeof(int));
			assert(pNegArr != NULL);
			*(pNegArr + *(pNegArr)) = *(pArr + i);
		}

		if (*(pArr + i) > 0)
		{
			pPosArr = (int*)realloc(pPosArr, (++ * pPosArr + 1) * sizeof(int));
			assert(pPosArr != NULL);
			*(pPosArr + *(pPosArr)) = *(pArr + i);
		}
	}
	return;
}

//Удаляет из динамического массива простые числа, и уменьшает объем выделенной памяти под него
void DeleteSimpleNumbers(int*& pArr, size_t &Len)
{
	bool isSimple = true;
	for (size_t i = Len-1; i !=0; i--)
	{
		isSimple = true;
		// определяем  является ли число простым
		for (size_t k = 2; k < (*pArr + i); k++)
		{
			if (*(pArr + i) % k == 0)
			{
				isSimple = false;
				break;
			}
		}

		if (isSimple)
		{
			// сокращаем массив на 1 элемент
			for (size_t j = i; j < Len - 1; j++)
			{
				*(pArr + j) = *(pArr + j + 1);
			}
			pArr = (int*)realloc(pArr, (--Len) * sizeof(int));
			assert(pArr != NULL);
		}
	}
	return;
}

// создание массива (первый элемент длина массива)
int* CreateArray(size_t NElements)
{
	if (NElements > 0)
	{
		BYTE* buf = (BYTE*)malloc(NElements * sizeof(int) + sizeof(size_t));
		assert(buf != NULL);
		size_t& len = reinterpret_cast<size_t&>(*(buf + 0));
		INTARR& arr = reinterpret_cast<INTARR&>(*(buf + sizeof(size_t)));
		len = NElements;
		return arr;
	}
	else return NULL;
}

// измененние размера массива
int* ResizeArray(int* arr, size_t NElements)
{
	if (arr != NULL)
	{
		if (NElements > 0)
		{
			BYTE* buf = reinterpret_cast<BYTE*>(arr) - sizeof(size_t);
			buf = (BYTE*)realloc(buf, NElements * sizeof(int) + sizeof(size_t));
			assert(buf != NULL);
			size_t& len = reinterpret_cast<size_t&>(*(buf + 0));
			len = NElements;
			INTARR& NewArr = reinterpret_cast<INTARR&>(*(buf + sizeof(size_t)));
			return NewArr;
		}
		else return 0;
	}
	else return NULL;
}

// получение размера массива
size_t SizeofArray(int* arr)
{
	if (arr != NULL)
	{
		size_t& len = *reinterpret_cast<size_t*>((reinterpret_cast<BYTE*>(arr) - sizeof(size_t)));
		return len;
	}
	else return 0;
}

// добавить элемент к массиву
int* AppendArray(int* arr, int Element)
{
	if (arr != NULL)
	{
		BYTE* buf = reinterpret_cast<BYTE*>(arr) - sizeof(size_t);
		buf = (BYTE*)realloc(buf, (SizeofArray(arr) + 1) * sizeof(int) + sizeof(size_t));
		assert(buf != NULL);
		size_t& len = reinterpret_cast<size_t&>(*(buf + 0));
		len++;
		INTARR& NewArr = reinterpret_cast<INTARR&>(*(buf + sizeof(size_t)));
		NewArr[len - 1] = Element;
		return NewArr;
	}
	else return NULL;
}

// удалить массив из памяти
void DestroyArray(int* arr)
{
	if (arr != NULL)
	{
		BYTE* buf = reinterpret_cast<BYTE*>(arr) - sizeof(size_t);
		free(buf);
	}
	return;
}

// печать массива на экран
void OutArray(int* arr)
{
	if (arr != NULL)
	{
		size_t size = SizeofArray(arr);
		for (size_t i = 0; i < size; i++)
		{
			cout << arr[i] << "  ";
		}
	}
	else cout << "Array = NULL";
}

// вставить элемент массива
int* InsertInArray(int* arr, size_t Index, int Element)
{
	if (arr != NULL)
	{
		if ((Index >= 0) && (Index <= SizeofArray(arr)))
		{
			BYTE* buf = reinterpret_cast<BYTE*>(arr) - sizeof(size_t);
			size_t& len = reinterpret_cast<size_t&>(*(buf + 0));
			len++; 
			buf = (BYTE*)realloc(buf, len * sizeof(int) + sizeof(size_t));
			assert(buf != NULL);
			INTARR& NewArr = reinterpret_cast<INTARR&>(*(buf + sizeof(size_t)));
			for (size_t i = len-1; i > Index; i--)
			{
				NewArr[i] = NewArr[i - 1];
			}
			NewArr[Index] = Element;
			return NewArr;
		}
		else return arr;
	}
	else return NULL;
}
//		+ Функция удаления элемента по указанному индексу
int* DeleteInArray(int* arr, size_t Index)
{
	if (arr != NULL)
	{
		if ((Index >= 0) && (Index <= SizeofArray(arr)))
		{
			BYTE* buf = reinterpret_cast<BYTE*>(arr) - sizeof(size_t);
			size_t& len = reinterpret_cast<size_t&>(*(buf + 0));
			len--;
			INTARR& NewArr = reinterpret_cast<INTARR&>(*(buf + sizeof(size_t)));
			for (size_t i = Index; i < len; i++)
			{
				NewArr[i] = NewArr[i + 1];
			}
			buf = (BYTE*)realloc(buf, len * sizeof(int) + sizeof(size_t));
			assert(buf != NULL);
			return NewArr;
		}
		else return arr;
	}
	else return NULL;	
}


int main()
{
	system("chcp 1251");  // переходим на русский язык в консоли

	
//	Домашнее задание № 14
//		Встреча №27
//		Задание :
//	Написать следующие функции для работы с динамическим массивом :
//		? Функция распределения динамической памяти
		{
		system("CLS");
		cout << "\nHomeWork #14. Meting #27. Task #1\n";

		size_t N = 20;
		//+Функция инициализации динамического массива
		int* pArrA = CreateArray(N); // создаем массив в размером N элементов
		assert(pArrA != NULL);

		// инициализируем исходный массив
		cout << "\nИсходный массив: ";
		for (size_t i = 0; i < N; i++)
		{
			pArrA[i] = i;
			//cout << pArrA[i] << "  ";
		}

		//+Функция печати динамического массива
		OutArray(pArrA);
		cout << "\n";

		cout << "\nДобавлен элемент 100 в массив: ";
		//+Функция добавления элемента в конец массива
		pArrA = AppendArray(pArrA, 100);
		OutArray(pArrA);
		cout << "\n";

		cout << "\nВставлен элемент 200 в массив index=6: ";
		//	+ Функция вставки элемента по указанному индексу
		pArrA = InsertInArray(pArrA, 6, 200);
		OutArray(pArrA);
		
		cout << "\nВставлен элемент 999 в массив index=0: ";
		//	+ Функция вставки элемента по указанному индексу
		pArrA = InsertInArray(pArrA, 0, 999);
		OutArray(pArrA); 
		
		cout << "\n";
		cout << "\nУдален элемент в массиве index=2: ";
		//	+ Функция удаления элемента по указанному индексу
		pArrA = DeleteInArray(pArrA, 2);
		OutArray(pArrA);

		cout << "\nУдален элемент в массиве index=21: ";
		//	+ Функция удаления элемента по указанному индексу
		pArrA = DeleteInArray(pArrA, 21);
		OutArray(pArrA);

		//+ Функция удаления динамического массива
		DestroyArray(pArrA);
		cout << "\nМассив удален!";

		cout << "\n";
		system("pause");
	}




//		Домашнее задание № 14
//		Встреча №28
//		Задание 1 :
//		Написать функцию, которая получает указатель на динамический массив и его размер.
//      Функция должна удалить из массива все простые числа и вернуть указатель на новый динамический массив.
	{
		system("CLS");
		cout << "\nHomeWork #14. Meting #28. Task #1\n";

		size_t N = 20;
		int* pArrA = (int*)malloc(N * sizeof(int)); // создаем массив в размером N элементов
		assert(pArrA != NULL);
		
		// выводим исходный массив
		cout << "Исходный массив: ";
		for (size_t i = 0; i < N; i++)
		{
			pArrA[i] = i + 10;
			cout << pArrA[i] << "  ";
		}
		cout << "\n";

		DeleteSimpleNumbers(pArrA, N);

		// выводим массив без простых чисел
		cout << "Массив без простых чисел: ";
		for (size_t i = 0; i < N; i++)
		{
			cout << pArrA[i] << "  ";
		}
		cout << "\n";

		free(pArrA);
		
		cout << "\n";
		system("pause");
	}

	   	 
//Задание 2 :
//Написать функцию, которая получает указатель на статический массив и его размер.
//Функция распределяет положительные, отрицательные и нулевые элементы в отдельные динамические массивы.
	{	
		system("CLS");
		cout << "\nHomeWork #14. Meting #28. Task #2\n";

		const size_t N = 10;
		int ArrA[N] = { -1,2,-3,0,-5,6,-7,8,0,10 };
		int* pZeroArr = (int*)malloc(1 * sizeof(int)); // создаем массив в размером 1 элемент
		assert(pZeroArr != NULL);
		int* pNegArr = (int*)malloc(1 * sizeof(int)); // создаем массив в размером 1 элемент
		assert(pNegArr != NULL);
		int* pPosArr = (int*)malloc(1 * sizeof(int)); // создаем массив в размером 1 элемент
		assert(pPosArr != NULL);
		
		*pNegArr = 0; // первый элемент - количество элементов 
		*pZeroArr = 0; // первый элемент - количество элементов
		*pPosArr = 0; // первый элемент - количество элементов

		
		// выводим исходный массив
		cout << "Исходный массив: ";
		for (size_t i = 0; i < N; i++)
		{
			cout << ArrA[i] << "  ";
		}
		cout << "\n";
		
		SplitNegZeroPos(ArrA, N, pNegArr, pZeroArr, pPosArr);

        // выводим массив с нулевыми элементами
		cout << "Нулевые элементы: "; 
		for (size_t i = 0; i < *pZeroArr; i++)
		{
			cout << *(pZeroArr + 1 + i) << "  ";
		}
		cout << "\n";
		
		// выводим массив с отрицательными элементами
		cout << "Отрицательные элементы: "; 
		for (size_t i = 0; i < *pNegArr; i++)
		{
			cout << *(pNegArr + 1 + i) << "  ";
		}
		cout << "\n";

		// выводим массив с положительными элементами		
		cout << "Положительные элементы: ";
		for (size_t i = 0; i < *pPosArr; i++)
		{
			cout << *(pPosArr + 1 + i) << "  ";
		}
		cout << "\n";

		free(pZeroArr);
		free(pNegArr);
		free(pPosArr);

		cout << "\n";
		system("pause");
	}
	return 0;
}
