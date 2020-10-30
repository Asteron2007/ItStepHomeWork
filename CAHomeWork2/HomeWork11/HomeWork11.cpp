// HomeWork11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>

using namespace std;
const int Int_Size = sizeof(int);
const int Char_Size = sizeof(char);
const unsigned int SortN = 50;

// Возведение в степень
double Extent(double Value, int Ext)
{
	if (Ext == 0)
	{
		return 1.0;
	}
	else if (Ext > 0)
	{
		return Value * Extent(Value, --Ext);
	}
	else
	{
		return 1.0 / Value / Extent(Value, ++Ext);

	}
}

// Перевод из бинарной в десятичную систему (возможно сделать для long Long int)
int BinToDec(char(&BitArr)[8*Int_Size]) // signed
{
	// MIN_INT = -2147483647 - 1;
	// MAX_INT = 2147483647;
	// LLONG_MAX = 
	// LLONG_MIN =
	// Дополнительный код образуется из прямого путем инверсии бит и прибавления единицы :
	// Пример: -5 : 5 = 00000101, -5 = not(5) + 1 = 11111010 + 1 = 11111011
	int ArrLen = sizeof(BitArr) / sizeof(BitArr[0]);
	int Res = 0;
	
	if (BitArr[0] == 1)
	{
		for (int i = 1; i < ArrLen; i++)
		{
			Res += !(int)BitArr[i] * Extent(2, ArrLen - 1 - i);
		}
		Res = -1 * Res - 1;
	}
	else
	{
		for (int i = 1; i < ArrLen; i++)
		{
			Res += (int)BitArr[i] * Extent(2, ArrLen - 1 - i);
		}
	}	

	return Res;
}

int BinarySearch(unsigned int(&SortArr)[SortN], unsigned int Key)
{
	unsigned int Begin = 0;
	unsigned int End = SortN - 1;
	unsigned int MidIndex = (Begin + End) / 2;
	unsigned int CountAttempt = 1;
	if (Key > SortN - 1) return -1; //-неверный диапазон

	while (SortArr[MidIndex] != Key)
	{
		cout << "Count attempt: " << CountAttempt << " MidIndex: " << MidIndex << "\n";
		if (Key > SortArr[MidIndex])
		{
			Begin = MidIndex + 1;
		}
		else
		{
			End = MidIndex - 1;
		}
		MidIndex = (Begin + End) / 2;
		CountAttempt++;
	}
	cout << "Count attempt: " << CountAttempt << " MidIndex: " << MidIndex << "\n";
	return MidIndex;
}

int LineareSearch(unsigned int(&UnSortArr)[SortN], unsigned int Key)
{
	for (int i = 0; i < SortN; i++)
	{
		if (UnSortArr[i] == Key)
			return i;
	}
	return -1;
}

// подсчет отрицательных, положительных, нулевых элементов
void NegPosZeroCount(int(&NumbersArr)[SortN], unsigned int &ZeroCounter, 
	unsigned int &PositiveCounter, unsigned int &NegativeCounter)
{
	ZeroCounter = 0;
	NegativeCounter = 0;
	PositiveCounter = 0;

	for (int i = 0; i < SortN; i++)
	{
		if (NumbersArr[i] == 0)  ZeroCounter++;
		else if (NumbersArr[i] > 0)  PositiveCounter++;
		else if (NumbersArr[i] < 0) NegativeCounter++;
	}

	return;
}

// среднеарифметическое
double Mean(unsigned int(&UnSortArr)[SortN])
{
	double Res = 0.0;
	for (int i = 0; i < SortN; i++)
	{
		Res += (double)UnSortArr[i];
	}
	return Res/SortN;
}

// функция проверяющая высокосный год
bool LeapYear(signed int Year)
{
	return bool(!(Year % 4) - (!(Year % 100) * !!(Year % 400)));
}

int DaysBetweenDates(unsigned int sDD, unsigned int sMM, signed int sYY,
					 unsigned int eDD, unsigned int eMM, signed int eYY)
{
	signed int CountStartDay = 0;      // Дата начала в днях относительно нуля
	signed int CountEndDay = 0;        // Конечная дата в днях относительно нуля
		
	// считаем сколько дней прошло с 00 до первой даты
	signed int Year = sYY < 0 ? sYY + 1 : sYY;          // временная переменная текущий полный год (при отрицательном +1)
	// это если год положительный а если отрицательный
	unsigned int Mounth = sYY < 0 ? 12 - sMM + 1 : sMM - 1;  // временная переменная текущий полных месяцев 
	//Mounth = Mounth == 0 ? 1 : Mounth;
	signed int DayCountMM = 0;      // количество дней в полных месяцах
	switch (Mounth)                 // былоб неплохо применить функцию
	{ // для наглядности, но можно было бы и просуммировать все дни по месяцам в виде константы
	case 1: DayCountMM = 31; break;
	case 2: DayCountMM = 31 + 28 + LeapYear(Year); break;
	case 3: DayCountMM = 31 + 28 + LeapYear(Year) + 31;	break;
	case 4: DayCountMM = 31 + 28 + LeapYear(Year) + 31 + 30; break;
	case 5: DayCountMM = 31 + 28 + LeapYear(Year) + 31 + 30 + 31; break;
	case 6: DayCountMM = 31 + 28 + LeapYear(Year) + 31 + 30 + 31 + 30; break;
	case 7: DayCountMM = 31 + 28 + LeapYear(Year) + 31 + 30 + 31 + 30 + 31; break;
	case 8: DayCountMM = 31 + 28 + LeapYear(Year) + 31 + 30 + 31 + 30 + 31 + 31; break;
	case 9: DayCountMM = 31 + 28 + LeapYear(Year) + 31 + 30 + 31 + 30 + 31 + 31 + 30; break;
	case 10: DayCountMM = 31 + 28 + LeapYear(Year) + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31; break;
	case 11: DayCountMM = 31 + 28 + LeapYear(Year) + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30; break;
	case 12: DayCountMM = 31 + 28 + LeapYear(Year) + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31; break;
	default: DayCountMM = 0; break;
	} // отрицательные года и месяца
	unsigned int MaxDayCountMM = 0;  // Максимальное количество дней в месяце
			//  проверка по максимальному количеству дней в месяцах
	if (sYY < 0) CountStartDay = sDD + Year * 365 + Year / 4 - Year / 100 + Year / 400 - DayCountMM;
	else CountStartDay = sDD + Year * 365 + Year / 4 - Year / 100 + Year / 400 + DayCountMM;

	Year = eYY < 0 ? eYY + 1 : eYY;          // временная переменная текущий полный год при отрицательном +1 
	Mounth = eYY < 0 ? 12 - eMM + 1 : eMM - 1;    // временная переменная текущий месяц
	//Mounth = Mounth == 0 ? 1 : Mounth;
	DayCountMM = 0;      // количество дней в месяцах
	switch (Mounth)             // былоб неплохо применить функцию
	{ // для наглядности, но можно было бы и просуммировать все дни по месяцам в виде константы
	case 1: DayCountMM = 31; break;
	case 2: DayCountMM = 31 + 28 + LeapYear(Year); break;
	case 3: DayCountMM = 31 + 28 + LeapYear(Year) + 31;	break;
	case 4: DayCountMM = 31 + 28 + LeapYear(Year) + 31 + 30; break;
	case 5: DayCountMM = 31 + 28 + LeapYear(Year) + 31 + 30 + 31; break;
	case 6: DayCountMM = 31 + 28 + LeapYear(Year) + 31 + 30 + 31 + 30; break;
	case 7: DayCountMM = 31 + 28 + LeapYear(Year) + 31 + 30 + 31 + 30 + 31; break;
	case 8: DayCountMM = 31 + 28 + LeapYear(Year) + 31 + 30 + 31 + 30 + 31 + 31; break;
	case 9: DayCountMM = 31 + 28 + LeapYear(Year) + 31 + 30 + 31 + 30 + 31 + 31 + 30; break;
	case 10: DayCountMM = 31 + 28 + LeapYear(Year) + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31; break;
	case 11: DayCountMM = 31 + 28 + LeapYear(Year) + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30; break;
	case 12: DayCountMM = 31 + 28 + LeapYear(Year) + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31; break;
	default: DayCountMM = 0; break;
	} // отрицательные года и месяца

	if (eYY < 0) CountEndDay = eDD + Year * 365 + Year / 4 - Year / 100 + Year / 400 - DayCountMM;
	else CountEndDay = eDD + Year * 365 + Year / 4 - Year / 100 + Year / 400 + DayCountMM;


	return CountEndDay - CountStartDay;
}


int main()
{
	srand(time(NULL));	

		//Встреча №21
		//Домашнее задание
		//Задание 1 :
		//Написать функцию, которая принимает две даты(т.е.функция принимает шесть параметров) и 
		//вычисляет разность в днях между этими датами.Для решения этой задачи необходимо также написать функцию,
		//которая определяет, является ли год високосным.
	{
		std::cout << "\nHomeWork #11. Meting #21. Task #1\n";

		unsigned int sDD = 32;   // День старт
		unsigned int sMM = 15;   // Месяц старт
		signed int sYY = 0;      // Год старт
		unsigned int eDD = 32;   // День окончание
		unsigned int eMM = 15;   // Месяц окончание
		signed int eYY = 0;      // Год окончание
		bool CorrectDate = false; // флаг коррекнатая ли дата

		cout << "LeapYear 1996 " << 365 + LeapYear(1996) << "\n";
		cout << "LeapYear 1201 " << 365 + LeapYear(1201) << "\n";
		cout << "LeapYear 1600 " << 365 + LeapYear(1600) << "\n";
		cout << "LeapYear 1900 " << 365 + LeapYear(1900) << "\n";


		// нужно бы сделать проверку на неверный тип введенных данных - но не является предметом задания
		std::cout << "Enter Start Year (YY): ";
		std::cin >> sYY;
		while (!CorrectDate)
		{
			std::cout << "Enter Start Mouth (MM): ";
			std::cin >> sMM;
			if ((sMM > 12) || (sMM < 1))
			{
				CorrectDate = false;
			}
			else CorrectDate = true;

		} // закончили проверку на корректность месяца в первой дате
		CorrectDate = false;
		while (!CorrectDate)
		{
			std::cout << "Enter Start Day (MM): ";
			std::cin >> sDD;
			signed int Year = sYY < 0 ? sYY + 1 : sYY;  // временная переменная текущий полный год при отрицательном +1

			unsigned int MaxDayCountMM = 0;  // Максимальное количество дней в месяце
			//  проверка по максимальному количеству дней в месяцах
			switch (sMM)                     // былоб неплохо применить функцию
			{
			case 1: MaxDayCountMM = 31; break;
			case 2: MaxDayCountMM = 28 + LeapYear(Year); break;
			case 3: MaxDayCountMM = 31; break;
			case 4: MaxDayCountMM = 30; break;
			case 5: MaxDayCountMM = 31; break;
			case 6: MaxDayCountMM = 30; break;
			case 7: MaxDayCountMM = 31; break;
			case 8: MaxDayCountMM = 31; break;
			case 9: MaxDayCountMM = 30; break;
			case 10: MaxDayCountMM = 31; break;
			case 11: MaxDayCountMM = 30; break;
			case 12: MaxDayCountMM = 31; break;
			default: MaxDayCountMM = 0;	break;
			}
			if ((sDD > MaxDayCountMM) || (sDD < 1)) CorrectDate = false;
			else CorrectDate = true;
		} // закончили проверку на корректкность дня в первой дате


		std::cout << "Enter End Year (YY): ";
		std::cin >> eYY;
		CorrectDate = false;
		while (!CorrectDate)
		{
			std::cout << "Enter End Mouth (MM): ";
			std::cin >> eMM;
			if ((eMM > 12) || (eMM < 1))
			{
				CorrectDate = false;
			}
			else CorrectDate = true;
		} // закончили проверку на корректкность месяца во второй дате
		CorrectDate = false;
		while (!CorrectDate)
		{
			std::cout << "Enter End Day (MM): ";
			std::cin >> eDD;
			signed int Year = eYY < 0 ? eYY + 1 : eYY;          // временная переменная текущий полный год при отрицательном +1

			unsigned int MaxDayCountMM = 0;  // Максимальное количество дней в месяце
			//  проверка по максимальному количеству дней в месяцах
			switch (eMM)                     // былоб неплохо применить функцию
			{
			case 1: MaxDayCountMM = 31; break;
			case 2: MaxDayCountMM = 28 + LeapYear(Year); break;
			case 3: MaxDayCountMM = 31; break;
			case 4: MaxDayCountMM = 30; break;
			case 5: MaxDayCountMM = 31; break;
			case 6: MaxDayCountMM = 30; break;
			case 7: MaxDayCountMM = 31; break;
			case 8: MaxDayCountMM = 31; break;
			case 9: MaxDayCountMM = 30; break;
			case 10: MaxDayCountMM = 31; break;
			case 11: MaxDayCountMM = 30; break;
			case 12: MaxDayCountMM = 31; break;
			default: MaxDayCountMM = 0;	break;
			}
			if ((eDD > MaxDayCountMM) || (eDD < 1)) CorrectDate = false;
			else CorrectDate = true;
		} // закончили проверку на корректность дня во второй дате

		cout << "Days delta: " << DaysBetweenDates(sDD, sMM, sYY, eDD, eMM, eYY) << "\n";

		system("pause");
	}
	//Задание 2 :
		//Написать функцию, определяющую среднее арифметическое элементов передаваемого ей массива.
	{
		std::cout << "\nHomeWork #11. Meting #21. Task #2\n";
		unsigned int UnSortedArray[SortN] = { };
		unsigned int Key = 0;
		for (int i = 0; i < SortN; i++)
		{
			UnSortedArray[i] = rand();
			cout << UnSortedArray[i] << " ";
		}
		cout << "\nMean: " << Mean(UnSortedArray) << "\n";

		system("pause");
	}
		//Задание 3 :
		//Написать функцию, определяющую количество положительных, отрицательных и нулевых элементов передаваемого ей массива.
	{
		std::cout << "\nHomeWork #11. Meting #21. Task #3\n";
		int NumArray[SortN] = { };
		unsigned int ZeroCount = 0;
		unsigned int NegCount = 0;
		unsigned int PosCount = 0;

		for (int i = 0; i < SortN; i++)
		{
			NumArray[i] = rand() - RAND_MAX / 2;
			cout << NumArray[i] << " ";
		}
		NegPosZeroCount(NumArray, ZeroCount, PosCount, NegCount);
		cout << "\nNegative Count: " << NegCount << "\n";
		cout << "Zero Count: " << ZeroCount << "\n";
		cout << "Positive Count: " << PosCount << "\n";

		system("pause");
	}



		//Домашнее задание № 11
		//Встреча №22
		//Задание 1 :
		//Написать функцию, реализующую алгоритм линейного поиска заданного ключа в одномерном
		//массиве.
	{
		std::cout << "\nHomeWork #11. Meting #22. Task #1\n";
		unsigned int UnSortedArray[SortN] = { };
		unsigned int Key = 0;
		for (int i = 0; i < SortN; i++)
		{
			UnSortedArray[i] = rand();
			cout << UnSortedArray[i] << " ";
		}
		cout << "\n Enter Key: ";
		cin >> Key;
		cout << "Lineare search index: " << LineareSearch(UnSortedArray, Key) << "\n";

		system("pause");
	}

		
		//Задание 2 :
		//Написать функцию, реализующую алгоритм бинарного поиска заданного ключа в одномерном
		//массиве.
	{
		std::cout << "\nHomeWork #11. Meting #22. Task #2\n";
		unsigned int SortedArray[SortN] = { };
		for (int i = 0; i < SortN; i++)
		{
			SortedArray[i] = i;
			cout << SortedArray[i] << " ";
		}
		cout << "\n";
		cout << "Binary search index: " << BinarySearch(SortedArray, 110) << "\n";

		system("pause");
	}

		// Задание 3 :
		// Написать функцию для перевода числа, записанного в двоичном виде, в десятичное
		// представление.
	{
		char BitArray[8 * Int_Size] = { 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,0,1,1 }; //-5
		//char BitArray[8 * Int_Size] = { 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0, 0,0,0,0,0,1,0,1 }; // 5


		std::cout << "\nHomeWork #11. Meting #22. Task #3\n";

		int tmp;
		// Заполняем бинарный массив произвольными значениями
		//for (int i = 0; i < sizeof(BitArray) / sizeof(BitArray[0]); i++)
		//{
		//	tmp = rand();
		//	BitArray[i] = tmp > RAND_MAX / 2 ?  1: 0;
		//}

		
		// выводим бинарный массив
		for (int i = 0; i < sizeof(BitArray) / sizeof(BitArray[0]); i++)
		{
			cout << (int)BitArray[i];
			if ((i + 1) % 8 == 0) cout << " ";
		}
		cout << "\n";
		// выводим результа перевода в десятичную систему
		cout << BinToDec(BitArray) << "\n";
		system("pause");
	}
}
