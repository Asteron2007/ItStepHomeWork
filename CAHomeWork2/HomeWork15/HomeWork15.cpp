// HomeWork15.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <malloc.h>
#include <cassert> 
#include <functional>


using namespace std;

// Длина строки
int MyStrLen(const unsigned char* str)
{
	int TerminatorPos = 0;
	while (str[TerminatorPos] != '\0')
		TerminatorPos++;
	return TerminatorPos;
}

// удаляет символ по индексу
int MyStrDeleteSymbol(unsigned char(& MyStr)[128], size_t Index)
{
	// проверим не выходит ли index за длину строки
	if (Index >= 0)
	{
		for (size_t i = 0; i <= Index; i++)
		{
			if ((MyStr[i] == '\0'))
			{
				cout << "Invalid index < string length\n";
				return -1;
			}
		}
	}
	else
	{
		cout << "Invalid index < 0\n";
		return -1;
	}

	int TerminatorPos = Index;
	while (MyStr[TerminatorPos] != '\0')
	{
		MyStr[TerminatorPos] = MyStr[TerminatorPos + 1];
		if ((MyStr[TerminatorPos] == '\0'))
			break;
		TerminatorPos++;
	}

	return 0;
}

// вставляет символ по индексу
int MyStrInsertSymbol(unsigned char(&MyStr)[128], size_t Index, char Symbol)
{
	size_t Len = MyStrLen(MyStr);
	if ((Index >= 0) && (Index <= Len))
	{
		//		int TerminatorPos = Len;
		for (size_t i = Len; (i >= Index) && (i <= Len); i--)
		{
			MyStr[i + 1] = MyStr[i];
		}
		MyStr[Index] = Symbol;
	}
	else
	{
		cout << "Invalid index < string length\n";
		return -1;
	}

	return 0;
}



// удаляет первое вхождение искомого символа (или все вхожденя если флаг == true)
int MyStrDeleteSymbol(unsigned char(&MyStr)[128],  char Symbol, bool AllSymbols)
{
	int TerminatorPos = 0;
	//int Index = 0;
	while (MyStr[TerminatorPos] != '\0')
	{
		if ((MyStr[TerminatorPos] == Symbol))
		{
			//Index = TerminatorPos;
			while (MyStr[TerminatorPos] != '\0')
			{
				MyStr[TerminatorPos] = MyStr[TerminatorPos + 1];
				if ((MyStr[TerminatorPos] == '\0'))
					break;
				TerminatorPos++;
			}
			if (AllSymbols)
			{
				MyStrDeleteSymbol(MyStr, Symbol, true);
			}

			break;
		}
		TerminatorPos++;
	}
	return 0;
}

double Action(double* pArrA, size_t SizeA, double* pArrB, size_t SizeB, 
	double (*pfunc)(double* pArrA, size_t SizeA, double* pArrB, size_t SizeB))
{	
	return pfunc(pArrA, SizeA, pArrB, SizeB);
}


int main()
{
	system("chcp 1251");  // переходим на русский язык в консоли
	
//	Домашнее задание № 15
//Встреча №29
//Домашнее задание
//Написать программу, которая содержит функцию Action, принимающую в качестве аргумента, 
//	указатели на два массива (А и В) и размеры массивов, а также указатель на функцию.
//Пользователю отображается меню, в котором он может выбрать max,min,avg. 
//Если выбран max - передается указатель на функцию, которая ищет максимум,
//если выбран min - передается указатель на функцию, которая ищет минимум, 
//если выбран avg - передается указатель на функцию, которая ищет среднее.
//Возвращаемое значение функции Action результат выбора пользователя max, min, avg.
	{
		system("CLS");
		cout << "\nHomeWork #15. Meting #29. Task #1\n";
		int Operator = 0;

		// вариант1 организовываем через лямбда функцию
		typedef std::function<double(double* pArrA, size_t SizeA, double* pArrB, size_t SizeB)> calc_func;

		calc_func OpArr[4] = {
			[](double* pArrA, size_t SizeA, double* pArrB, size_t SizeB) -> double// exit
		{

			return 0;
		},
			[](double* pArrA, size_t SizeA, double* pArrB, size_t SizeB) -> double// max+
		{
			double tmpMax = pArrA[0];
			for (size_t i = 1; i < SizeA; i++)
		{
				if (tmpMax < pArrA[i]) tmpMax = pArrA[i];
		}
			for (size_t i = 0; i < SizeB; i++)
			{
				if (tmpMax < pArrB[i]) tmpMax = pArrB[i];
			}
			return tmpMax;
		},
			[](double* pArrA, size_t SizeA, double* pArrB, size_t SizeB)-> double // min+
		{
			double tmpMin = pArrA[0];
			for (size_t i = 1; i < SizeA; i++)
		{
				if (tmpMin > pArrA[i]) tmpMin = pArrA[i];
		}
			for (size_t i = 0; i < SizeB; i++)
			{
				if (tmpMin > pArrB[i]) tmpMin = pArrB[i];
			}
			return tmpMin;
		},
			[](double* pArrA, size_t SizeA, double* pArrB, size_t SizeB)-> double // avg
		{
			double tmpAvg = pArrA[0];
			for (size_t i = 1; i < SizeA; i++)
		{
				tmpAvg += pArrA[i];				
		}
			for (size_t i = 0; i < SizeB; i++)
			{
				tmpAvg += pArrB[i];
			}
			return tmpAvg / (SizeA + SizeB);
		}
		};

		const size_t SizeA = 4;
		double* pArrA;
		double ArrA[SizeA] = { 4,6,0,7 };
		
		const size_t SizeB = 5;
		double* pArrB;
		double ArrB[SizeB] = { 3,10,9,1,8 };
		cout << "ArrA: "; 
		for (size_t i = 0; i < SizeA; i++)
		{
			cout << ArrA[i] << "  ";
		}
		cout << "\n";
		cout << "ArrB: ";
		for (size_t i = 0; i < SizeB; i++)
		{
			cout << ArrB[i] << "  ";
		}
		cout << "\n";

		do
		{
			try {
				cout << "Array manipulation:\n";
				cout << "  0. Exit\n";
				cout << "  1. max\n";
				cout << "  2. min\n";
				cout << "  3. avg\n";
				
				cout << "Enter Operator: ";
				cin >> Operator;
				cout << "Result: " << OpArr[Operator](ArrA, SizeA,  ArrB, SizeB) << "\n";
			}
			catch (std::exception exp)
			{
				std::cout << "Wrong choise!" << "\n";
			}

		} while (Operator != 0);


		cout << "\n";
		system("pause");
	}

//Домашнее задание № 15
//Встреча №30
//Задание 1:
//Написать функцию, которая удаляет из строки символ с заданным номером.
	{
		system("CLS");
		cout << "\nHomeWork #15. Meting #30. Task #1\n";

		unsigned char MyStr[128] = "67890.,., .абвгдеёжзийклмнопрстуфхцчшщьъыэюя. 12345. qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM.,.,";

		cout << "Original string: " << MyStr << "\n";

		MyStrDeleteSymbol(MyStr, 0);
		
		cout << "Changed string: " << MyStr << "\n";

		cout << "\n";
		system("pause");
	}

// Задание 2:
// Написать функцию, которая удаляет из строки все вхождения в нее заданного символа.
	{
		system("CLS");
		cout << "\nHomeWork #15. Meting #30. Task #2\n";

		unsigned char MyStr[128] = "67890.,., .абвгдеёжзийклмнопрстуфхцчшщьъыэюя. 12345. qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM.,.,";

		cout << "Original string: " << MyStr << "\n";

		MyStrDeleteSymbol(MyStr, '.', true);

		cout << "Changed string: " << MyStr << "\n";

		cout << "\n";
		system("pause");
	}
	//Задание 3:
//Написать функцию, которая вставляет в строку в указанную позицию заданный символ.
	{
		system("CLS");
		cout << "\nHomeWork #15. Meting #30. Task #3\n";

		unsigned char MyStr[128] = "123";//"67890.,., .абв QWERTY.,.,";

		cout << "Original string: " << MyStr << "\n";
		
		MyStrInsertSymbol(MyStr, 2, '!');

		cout << "Changed string: " << MyStr << "\n";

		cout << "\n";
		system("pause");
	}

//Задание 4:
	//Написать программу, которая заменяет все символы точки "." в строке, введенной пользователем,
	//на символы восклицательного знака "!".
	{
		system("CLS");
		cout << "\nHomeWork #15. Meting #30. Task #4\n";

		unsigned char MyStr[128] = "67890.,., .абвгдеёжзийклмнопрстуфхцчшщьъыэюя. 12345. qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM.,.,";
		unsigned char MyOldChar = '.';
		unsigned char MyNewChar = '!';

		cout << "Enter string: ";
		cin >> MyStr;
		
		int TerminatorPos = 0;
		while (MyStr[TerminatorPos] != '\0')
		{
			if ((MyStr[TerminatorPos] == MyOldChar))
				(MyStr[TerminatorPos] = MyNewChar);

			TerminatorPos++;
		}

		cout << "Changed string: " << MyStr << "\n";

		cout << "\n";
		system("pause");
	}
	
	//Задание 5:
	//Пользователь вводит строку символов и искомый символ, посчитать сколько раз он встречается в строке.
	{
		system("CLS");
		cout << "\nHomeWork #15. Meting #30. Task #5\n";

		unsigned char MyStr[128] = "67890 абвгдеёжзийклмнопрстуфхцчшщьъыэюя 12345 qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
		unsigned char MyChar = ' ';
		cout << "Enter string: ";
		cin >> MyStr;
		cout << "Enter char: ";
		cin >> MyChar;

		int SymbolCount = 0;

		int TerminatorPos = 0;
		while (MyStr[TerminatorPos] != '\0')
		{
			if ((MyStr[TerminatorPos] == MyChar))
				SymbolCount++;

			TerminatorPos++;
		}

		cout << "Symbol count in string: " << SymbolCount << "\n";

		cout << "\n";
		system("pause");
	}

//Задание 6:
//Пользователь вводит строку. Определить количество букв, количество цифр и количество остальных символов, присутствующих в строке.
//Рекомендации:
//Для проверки, что символ является числом, не обязательно сравнивать его со всеми 10-ю цифрами, 
// достаточно сравнить код символа с диапазоном кодов цифр. Код символа 0 – 48, 1 – 49, 2 – 50 …. 9 – 57.

	{
		system("CLS");
		cout << "\nHomeWork #15. Meting #30. Task #6\n";

		unsigned char MyStr[128] = "67890 абвгдеёжзийклмнопрстуфхцчшщьъыэюя 12345 qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
		cout << "Enter string: ";
		cin >> MyStr;

		int DigitCount = 0;
		int SymbolCount = 0;
		int LetterCount = 0;


		int TerminatorPos = 0;
		while (MyStr[TerminatorPos] != '\0')
		{   //проверка на цифры
			if ((MyStr[TerminatorPos] > 47) && (MyStr[TerminatorPos] < 58))
				DigitCount++;
			else if (((MyStr[TerminatorPos] > 64) && (MyStr[TerminatorPos] < 91)) ||
				((MyStr[TerminatorPos] > 96) && (MyStr[TerminatorPos] < 123)) ||
				((MyStr[TerminatorPos] > 191) && (MyStr[TerminatorPos] <= 255)) ||
				(MyStr[TerminatorPos] == 168) || (MyStr[TerminatorPos] == 184))
				LetterCount++;
			else SymbolCount++;

			TerminatorPos++;
		}

		cout << "Digits count in string: " << DigitCount << "\n";
		cout << "Symbols count in string: " << SymbolCount << "\n";
		cout << "Letters count in string: " << LetterCount << "\n";

		cout << "\n";
		system("pause");
	}
	return 0;
}