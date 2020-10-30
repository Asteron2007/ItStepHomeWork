// HomeWork09.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <windows.h>
#include <wchar.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctime> // содержит time()

int main()
{

	std::cout << "Start Program...\n";
	system("chcp 1251");  // переходим на русский язык в консоли


//	Встреча №18
// Задание 1:
// Написать программу, реализующую сортировку массива методом усовершенствованной сортировки пузырьковым методом. 
// Усовершенствование состоит в том, что бы анализировать количество перестановок на каждом шагу, 
// если это количество равно нулю, то продолжать сортировку нет смысла – массив отсортирован.

	{// Сортировка методом улучшенного пузырька
		const unsigned int N = 20;
		signed int A[N] = {};// { 10, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
		bool sorted = true;

		srand(time(NULL));
		std::cout << "Meeting 18. HomeWork #1. Bubble best sort ";
		std::cout << "\nOriginal array: \n";
		for (int i = 0; i < N; i++)
		{
			A[i] = rand() - RAND_MAX / 2;
			std::cout << A[i] << ", ";
		}
		//system("pause");
		for (int i = 0; i < N; i++)
		{
			for (int j = i; j < N; j++) // проверка отсортирован ли массив
			{
				if (A[i] > A[j])
				{
					sorted = false;
					break;
				}
				sorted = true;
			}

			if (!sorted)
			{
				for (int j = i; j < N; j++)
				{
					if (A[i] > A[j])
					{
						unsigned int tmp = A[i];
						A[i] = A[j];
						A[j] = tmp;
					}
				}
			}
			else
			{
				std::cout << "\nSorted after i = " << i << "\n";
				break;
			}
		}
		// Выводим отсорированный массив
		std::cout << "\nSorted array: \n";
		for (int i = 0; i < N; i++)
		{
			std::cout << A[i] << ", ";
		}
		std::cout << "\n";
		system("pause");
	}



	//Задание 2:
	//Есть стопка оладий различного радиуса. Единственная операция проводимая с ними - между любыми двумя суем лопатку 
	//и меняем порядок оладий над лопаткой на обратный. Необходимо за минимальное количество операций таких отсортировать
	//снизу вверх по убыванию радиуса
	{
		const unsigned int N = 20;
		signed int A[N] = { 10, 2, 3, 4, 5, 6, 7, 8, 29, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

		srand(time(NULL));
		std::cout << "\n\nMeeting 18. HomeWork #2. ALLADII";
		std::cout << "\nOriginal array: \n";
		for (int i = 0; i < N; i++)
		{
			// при тестировании закомментировать
			A[i] = rand();
			std::cout << A[i] << ", ";
		}
		//system("pause");
		// Сортирова методом аладий 
		signed int MaxIndex = 0;
		unsigned int tmp;
		for (int i = 0; i < N - 1; i++)
		{
			MaxIndex = i;
			for (int j = i; j < N; j++) // поиск самого максимального элемента в оставшемся массиве
			{
				if (A[MaxIndex] < A[j]) MaxIndex = j;
			}

			if (MaxIndex == i) continue;

			for (int j = MaxIndex; j < (MaxIndex + (N - MaxIndex) / 2); j++) // переворачиваем аладьи над лопаткой
			{
				tmp = A[j];
				A[j] = A[N - 1 - (j - MaxIndex)];
				A[N - 1 - (j - MaxIndex)] = tmp;
			}


			// Выводим перевернуиый массив на i-м шаге
			std::cout << "\n array on step after max Val i =  " << i << "\n";
			for (int j = 0; j < N; j++)
			{
				std::cout << A[j] << ", ";
			}

			for (int j = i; j < (i + (N - i) / 2); j++) // переворачиваем аладьи над лопаткой MaxIndex=i
			{
				tmp = A[j];
				A[j] = A[N - 1 - (j - i)];
				A[N - 1 - (j - i)] = tmp;
			}

			// Выводим отсорированный массив на i-м шаге
			std::cout << "\n array on step =  " << i << "\n";
			for (int j = 0; j < N; j++)
			{
				std::cout << A[j] << ", ";
			}
		}
		// Выводим отсорированный массив
		std::cout << "\nSorted array: \n";
		for (int i = 0; i < N; i++)
		{
			std::cout << A[i] << ", ";
		}
		std::cout << "\n";
		system("pause");
	}




	// Meeting 17. HomeWork. ICQ 
	// Написать программу «справочник». Создать два одномерных массива. Один массив хранит номера ICQ, второй – телефонные номера. Реализовать меню для пользователя:
	//  - Отсортировать по номерам ICQ
	//	- Отсортировать по номерам телефона
	//	- Вывести список пользователей
	//	- Выход



	{
		const unsigned int N = 10;
		unsigned long long int PhoneNumber[N] = {};
		unsigned long long int ICQNumber[N] = {};

		// заполняем массив
		srand(time(NULL));

		std::cout << "Meeting 17. HomeWork. ICQ\n";
		std::cout << "Array initilization...\n";
		for (int i = 0; i < N; i++)
		{
			do
			{
				PhoneNumber[i] = rand() * 100000 + rand();
			} while ((PhoneNumber[i] < 1000000000) || (PhoneNumber[i] >= 99999999999));

			do
			{
				ICQNumber[i] = rand() * 100000 + rand();
			} while ((ICQNumber[i] < 1000000000) || (ICQNumber[i] >= 99999999999));

			std::cout << "| Index: " << i << " | ICQNumber: " << ICQNumber[i] << " | PhoneNumber: " << PhoneNumber[i] << " |\n";
		}
		std::cout << "\n";


		bool exit = false;
		int MenuItem = 0;
		while (!exit)
		{
			std::cout << "0. Exit\n";
			std::cout << "1. Print numbers\n";
			std::cout << "2. Sort by ICQNumbers\n";
			std::cout << "3. Sort by PhoneNumbers\n\n";

			std::cout << "Enter menu item: ";
			std::cin >> MenuItem;
			switch (MenuItem)
			{
			case 0: //"0. Exit\n";		
			{
				exit = true;
				break;
			}
			case 1: //"1. Print numbers\n";
			{
				for (int i = 0; i < N; i++)
				{
					std::cout << "| Index: " << i << " | ICQNumber: " << ICQNumber[i] << " | PhoneNumber: " << PhoneNumber[i] << " |\n";
				}
				break;
			}
			case 2: //"2. Sort by ICQNumbers\n";
			{// методом пузырька

				for (int i = 0; i < N; i++)
				{
					for (int j = i; j < N; j++)
					{
						if (ICQNumber[i] > ICQNumber[j])
						{
							unsigned long long int tmp = ICQNumber[i];
							ICQNumber[i] = ICQNumber[j];
							ICQNumber[j] = tmp;

							tmp = PhoneNumber[i];
							PhoneNumber[i] = PhoneNumber[j];
							PhoneNumber[j] = tmp;
						}
					}
				}
				break;
			}
			case 3: //"3. Sort by PhoneNumbers\n\n";
			{// методом пузырька
				for (int i = 0; i < N; i++)
				{
					for (int j = i; j < N; j++)
					{
						if (PhoneNumber[i] > PhoneNumber[j])
						{
							unsigned long long int tmp = ICQNumber[i];
							ICQNumber[i] = ICQNumber[j];
							ICQNumber[j] = tmp;

							tmp = PhoneNumber[i];
							PhoneNumber[i] = PhoneNumber[j];
							PhoneNumber[j] = tmp;
						}
					}
				}


				break;
			}
			default:
				break;
			}
			std::cout << "\n";
			system("pause");
			system("cls");
		}
		std::cout << "\n";
		system("pause");




	}
	return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
