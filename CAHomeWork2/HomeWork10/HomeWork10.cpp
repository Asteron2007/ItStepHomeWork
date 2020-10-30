// HomeWork10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <windows.h>
#include <wchar.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctime> // содержит time()

bool OutCard(int CardValue, char CardSuit)
{
	if ((CardValue >= 2) && (CardValue <= 15) &&
		((CardSuit == 'd') || (CardSuit == 'D') ||
		(CardSuit == 'h') || (CardSuit == 'H') ||
			(CardSuit == 'S') || (CardSuit == 'S') ||
			(CardSuit == 'c') || (CardSuit == 'C')))
	{// корректная карта

		if ((CardValue >= 2) && (CardValue <= 10))
		{
			std::cout << "Card: " << CardValue;
		}
		else if (CardValue == 11) // туз
		{
			std::cout << "Card: T";
		}
		else if (CardValue == 12) // валет
		{
			std::cout << "Card: V";
		}
		else if (CardValue == 13) // дама
		{
			std::cout << "Card: D";
		}
		else if (CardValue == 14) // король
		{
			std::cout << "Card: K";
		}
		else if (CardValue == 15) // джокер
		{
			std::cout << "Card: J";
		}


		switch (CardSuit)
		{
		case 'd'://Diamonds
		case 'D'://Diamonds
			std::cout << " " << CardSuit << "\n";
			break;
		case 'H': //Hearts;
		case 'h': //Hearts;
			std::cout << " " << CardSuit << "\n";
			break;
		case 'S':// Spades
		case 's':// Spades
			std::cout << " " << CardSuit << "\n";
			break;
		case 'c': //Clubs
		case 'C': //Clubs
			std::cout << " " << CardSuit << "\n";
			break;
		default:
			break;
		}

		return true;
	}
	else
	{// некорректная карта
		std::cout << "Incorrect card or suit\n";
		return false;
	}

}

bool IsLuckyNumber6Digits(int Number)
{
	unsigned int Number1 = 0;   // число
	unsigned int Number2 = 0;   // число
	unsigned int Number3 = 0;   // число
	unsigned int Number4 = 0;   // число
	unsigned int Number5 = 0;   // число
	unsigned int Number6 = 0;   // число
	
	Number1 = Number / 100000;
	Number2 = (Number - Number1 * 100000) / 10000;
	Number3 = (Number - Number1 * 100000 - Number2 * 10000) / 1000;
	Number4 = (Number - Number1 * 100000 - Number2 * 10000 - Number3 * 1000) / 100;
	Number5 = (Number - Number1 * 100000 - Number2 * 10000 - Number3 * 1000 - Number4 * 100) / 10;
	Number6 = Number - Number1 * 100000 - Number2 * 10000 - Number3 * 1000 - Number4 * 100 - Number5 * 10;

	if ((Number1 + Number2 + Number3) == (Number4 + Number5 + Number6))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int SummRange(int StartA, int EndB)
{
	if ((StartA == EndB)) //|| ((StartA - EndB) == -1))
	{
		return StartA;
	}
	else if (StartA < EndB)
	{
		return StartA + SummRange(StartA + 1, EndB);//++
	}
	else
	{
		return StartA + SummRange(StartA - 1, EndB);//--
	}
}

double Extent(double Value, int Ext)
{
	if (Ext == 0)
	{
		return 1.0;
	}
	else if (Ext > 0)
	{
		return Value * Extent(Value, Ext - 1);
	}
	else
	{
		return 1.0 / Value *  Extent(Value, Ext + 1);

	}
}

void PerfectNumber(long long int BeginDiap, long long int EndDiap)
{
	const unsigned int N = 100000;
	unsigned int CountDivisors = 0;
	long long int SummDivisors = 0;

	long long int Divisors[N] = {};
	long long int Begin;
	long long int End;

	// проверка на то, что BeginDiap < EndDiap	
	if (BeginDiap < EndDiap)
	{
		Begin = BeginDiap;
		End = EndDiap;
	}
	else
	{
		Begin = EndDiap;
		End = BeginDiap;
	}

	for (long long int i = Begin; i < End; i++)
	{
		CountDivisors = 0; // вычисляем все делители
		SummDivisors = 0; // суммируем все делители
		for (long long int n = 1; n < i; n++)
		{
			if (i % n == 0)
			{
				Divisors[CountDivisors] = n;
				SummDivisors = SummDivisors + n;
				CountDivisors++;
			}
		}

		if (SummDivisors == i)
		{
			for (long long int n = 0; n < CountDivisors; n++)
			{
				std::cout << " + " << Divisors[n];
			}
			std::cout << " = " << i << "\n";
		}
	}
}
int main()
{
	std::cout << "Start Program...\n";
	system("chcp 1251");  // переходим на русский язык в консоли
	srand(time(NULL));

	
// Встреча №19
// Задание 1:
// Напишите программу, которая создает двухмерный массив и заполняет его по следующему принципу: 
// пользователь вводит число (например, 3) первый элемент массива принимает значение этого числа, 
// последующий элемент массива принимает значение этого числа умноженного на 2 (т.е. 6 для нашего примера),
// третий элемент массива предыдущий элемент умноженный на 2 (т.е. 6*2=12 для нашего примера). 
// Созданный массив вывести на экран.
	{
		std::cout << "\n\nMeeting 19. HomeWork #10. Task 1\n"; 
		long long int Arr[5][5] = {};
		long long int tmpVal = 0;
		std::cout << "Enter Number: ";
		std::cin >> tmpVal;

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if ((i > 0) || (j > 0))
				{
					tmpVal = tmpVal * 2;
				}
				Arr[i][j] = tmpVal;
				std::cout << Arr[i][j] << "\t";
			}
			std::cout << "\n";
		}

		system("Pause");
	}
// Задание 2:
// Напишите программу, которая создает двухмерный массив и заполняет его по следующему принципу:
	// пользователь вводит число (например, 3) первый элемент массива принимает значение этого числа, 
	// последующий элемент массива принимает значение этого числа + 1 (т.е. 4 для нашего примера), 
	//третий элемент массива предыдущий элемент + 1 (т.е. 5 для нашего примера). Созданный массив вывести на экран.
{
		std::cout << "\n\nMeeting 19. HomeWork #10. Task 2\n";
		long long int Arr[10][10] = {};
		long long int tmpVal = 0;
		std::cout << "Enter Number: ";
		std::cin >> tmpVal;

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if ((i > 0) || (j > 0))
				{
					tmpVal = tmpVal + 1;
				}
				Arr[i][j] = tmpVal;
				std::cout << Arr[i][j] << "\t";
			}
			std::cout << "\n";
		}

		system("Pause");
	}
//Задание 3:
//Создайте двухмерный массив. Заполните его случайными числами и покажите на экран. 
//Пользователь выбирает количество сдвигов и положение (влево, вправо, вверх, вниз).
//Выполнить сдвиг массива и показать на экран полученный результат. Сдвиг циклический.
//Например, если мы имеем следующий массив
//1 2 0 4 5 3
//4 5 3 9 0 1
//и пользователь выбрал сдвиг на 2 разряда вправо, то мы получим
//5 3 1 2 0 4
//0 1 4 5 3 9
{
	std::cout << "\n\nMeeting 19. HomeWork #10. Task 3\n";
	int Arr[5][5] = {};
	int shift = 0;
	int tmp = 0;
	
	for (int i = 0; i < sizeof(Arr) / sizeof(Arr[0]); i++)
	{
		for (int j = 0; j < sizeof(Arr[i]) / sizeof(Arr[i][0]); j++)
		{
			Arr[i][j] = rand();
			std::cout << Arr[i][j] << "\t";
		}
		std::cout << "\n";
	}

	std::cout << "Enter shift: ";
	std::cin >> shift;
	int count = shift < 0 ? -1 * shift :  shift;
	if (shift != 0)
	{
		for (int x = 0; x < count; x++)
		{
			for (int i = 0; i < sizeof(Arr) / sizeof(Arr[0]); i++)
			{
				if (shift > 0)
				{
					tmp = Arr[i][sizeof(Arr[i]) / sizeof(Arr[i][0]) - 1];
					for (int j = sizeof(Arr[i]) / sizeof(Arr[i][0]) - 1; j > 0; j--)
					{
						Arr[i][j] = Arr[i][j - 1];
					}
					Arr[i][0] = tmp;
				}
				else
				{
					tmp = Arr[i][0];
					for (int j = 0; j < sizeof(Arr[i]) / sizeof(Arr[i][0]) - 1; j++)
					{
						//if (j<0)
						Arr[i][j] = Arr[i][j + 1];

					}
					Arr[i][sizeof(Arr[i]) / sizeof(Arr[i][0]) - 1] = tmp;
				}

			}
		}
	}
	for (int i = 0; i < sizeof(Arr) / sizeof(Arr[0]); i++)
	{
		for (int j = 0; j < sizeof(Arr[i]) / sizeof(Arr[i][0]); j++)
		{			
			std::cout << Arr[i][j] << "\t";
		}
		std::cout << "\n";
	}

	system("Pause");
}



	// Встреча №20
	// Задание 1:
	// Написать функцию, которая принимает два параметра: основание степени и показатель степени, и вычисляет степень числа на основе полученных данных.
	{
		std::cout << "\n\nMeeting 20. HomeWork #10. Extent\n";
		std::cout << "Extent(2, 4) = " << Extent(2, 4) << "\n";
		std::cout << "Extent(2.0, -4) = " << Extent(2.0, -4) << "\n";
		std::cout << "Extent(3, 3) = " << Extent(3, 3) << "\n";
		std::cout << "Extent(3, -3) = " << Extent(3, -3) << "\n";
		system("Pause");
	}
	// Задание 2:
	// Написать функцию, которая получает в качестве параметров 2 целых числа и возвращает сумму чисел из диапазона между ними.
	{
		std::cout << "\n\nMeeting 20. HomeWork #10. Summ\n";
		std::cout << "Summ [5, 5] = " << SummRange(5, 5) << "\n";

		std::cout << "Summ [3, 1] = " << SummRange(3, 1) << "\n";
		std::cout << "Summ [1, 3] = " << SummRange(1, 3) << "\n";

		std::cout << "Summ [4, 0] = " << SummRange(4, 0) << "\n";
		std::cout << "Summ [0, 4] = " << SummRange(0, 4) << "\n";
		system("Pause");
	}

	// Задание 3:
	// Число называется совершенным, если сумма всех его делителей равна ему самому. Напишите функцию поиска таких чисел во введенном интервале.
	{
		std::cout << "\n\nMeeting 20. HomeWork #10. Perfect numbers\n";
		std::cout << "Perfect numbers [1 - 8200]\n";
		PerfectNumber(1, 8200);

		system("Pause");
	}
	//Задание 4:
	//Написать функцию, выводящую на экран переданную ей игральную карту.
	{
		std::cout << "\n\nMeeting 20. HomeWork #10. OutCard\n";
		OutCard(9, 'H');
		OutCard(15, 'c');
		OutCard(11, 'h');
		OutCard(1, 'yuhh');


		system("Pause");
	}
	// Задание 5:
	// Написать функцию, которая определяет, является ли «счастливым» шестизначное число

	{
		std::cout << "\n\nMeeting 20. HomeWork #10. Lucky Number\n";

		unsigned int Number = 0;    // число
		std::cout << "\nEnter number (6 digits): ";
		std::cin >> Number;

		if ((Number < 100000) && (Number >= 1000000))
		{
			std::cout << Number << " - is incorrect (not 6 digits)";
		}
		else
		{
			if (IsLuckyNumber6Digits(Number))
			{
				std::cout << Number << " is a lucky number!\n";
			}
			else
			{
				std::cout << Number << " is not a lucky number!\n";
			}
		}
		system("pause");
	}
	return 0;
}