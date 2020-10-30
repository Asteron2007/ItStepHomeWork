// HomeWork13.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
#include <malloc.h>
#include <cassert> 

using namespace std;

int main()
{
//Домашнее задание № 13
//Встреча №25
//Задание 1:
//Используя два указателя на массив целых чисел, скопировать один массив в другой.
//Использовать в программе арифметику указателей для продвижения по массиву, а также
//оператор разыменования.
	{
		system("CLS");
		cout << "\nHomeWork #13. Meting #25. Task #1\n";
		const int M = 10;
		int ArrA[M];
		int ArrB[M];
		cout << "\nArray ArrA[M]: ";
		for (int i = 0; i < M; i++)
		{
			ArrA[i] = i + 100;
			cout << ArrA[i] << "  ";
		}

		int* pArrA = ArrA;
		int* pArrB = ArrB;
		cout << "\nArray pArrA[M]: ";
		for (int i = 0; i < M; i++)
		{
			cout << *(pArrA + i) << "  ";
		}
		cout << "\n";
		for (int i = 0; i < M; i++)
		{
			*(pArrB + i) = *(pArrA + i);
		}
		// ArrA
		cout << "\nChanged Array pArrA[M]: ";
		for (int i = 0; i < M; i++)
		{
			pArrA[i] = i + 200;
			cout << pArrA[i] << "  ";
		}
		cout << "\n";
		cout << "\n Array pArrB[M]: ";
		for (int i = 0; i < M; i++)
		{
			cout << *(pArrB + i) << "  ";

		}
		cout << "\n";
		system("pause");
	}


	//Задание 2:
//Используя указатель на массив целых чисел, изменить порядок следования элементов массива
//на противоположный.
//Использовать в программе арифметику указателей для продвижения по массиву, а также
//оператор разыменования.
	{
		system("CLS");
		cout << "\nHomeWork #13. Meting #25. Task #2\n";
		const int M = 10;
		int Arr[M];
		cout << "\nArray Arr[M]: ";
		for (int i = 0; i < M; i++)
		{
			Arr[i] = i;
			cout << Arr[i] << "  ";
		}
		
		int* pArr = Arr;
		cout << "\nArray pArr[M]: ";
		for (int i = 0; i < M; i++)
		{
			cout << *(pArr + i) << "  ";
		}
		cout << "\n";
		cout << "\ninvert Array pArr[M]: ";
		int tmp;
		for (int i = 0; i < M/2; i++)
		{
			tmp = pArr[i];
			pArr[i] = pArr[M - i - 1];
			pArr[M - i - 1] = tmp;
		//	cout << *(pArr + i) << "  ";
		}
		for (int i = 0; i < M ; i++)
		{
			cout << *(pArr + i) << "  ";

		}
		cout << "\n";
		system("pause");
	}


//Задание 3:
//Используя два указателя на массивы целых чисел, скопировать один массив в другой так, чтобы
//во втором массиве элементы находились в обратном порядке.
//Использовать в программе арифметику указателей для продвижения по массиву, а также
//оператор разыменования.
	{
		system("CLS");
		cout << "\nHomeWork #13. Meting #25. Task #3\n";
		
		size_t M = 10;
		
		int* pArrA = (int*)malloc(M * sizeof(int));
		assert(pArrA != NULL);

		cout << "\nArray A[M]: ";
		for (size_t i = 0; i < M; i++)
		{
			pArrA[i] = i;// rand();
			cout << pArrA[i] << "  ";
		}

		cout << "\nArray B[M]: ";
		int* pArrB = (int*)malloc(M * sizeof(int));
		assert(pArrB != NULL);
		
		typedef unsigned char BYTE;
		using SKEY = struct { BYTE tag[sizeof(int)]; };
		for (size_t i = 0; i < M ; i++)
		{
			*(reinterpret_cast<SKEY*>(pArrB) + i) = *(reinterpret_cast<SKEY*>(pArrA) + M - i - 1);
		}
		
		for (size_t i = 0; i < M; i++)
		{
			cout << pArrB[i] << "  ";
		}

		cout << "\n";
		system("pause");
	}


//Домашнее задание № 13
//Встреча №26
//Задание 1:
//Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). Необходимо создать третий
//массив минимально возможного размера, в котором нужно собрать элементы массива A,
//которые не включаются в массив B, без повторений.

	{
		system("CLS");
		cout << "\nHomeWork #13. Meting #26. Task #1\n";
		size_t M = 0;
		size_t N = 0;

		cout << "Enter size array A[M]: ";
		cin >> M;
		cout << "Enter size array B[N]: ";
		cin >> N;

		int* pArrA = (int*)malloc(M * sizeof(int));
		assert(pArrA != NULL);

		cout << "\nArray A[M]: ";
		for (size_t i = 0; i < M; i++)
		{
			pArrA[i] = i;// rand();
			pArrA[1] = 0;
			cout << pArrA[i] << "  ";
		}

		cout << "\nArray B[N]: ";
		int* pArrB = (int*)malloc(N * sizeof(int));
		assert(pArrB != NULL);
		for (size_t i = 0; i < N; i++)
		{
			pArrB[i] = i;//rand();
			pArrB[2] = 3;
			cout << pArrB[i] << "  ";
		}

		cout << "\n";

		bool isUnique = true;
		size_t LenArr3 = 0;
		int* pArr3 = (int*)malloc(LenArr3 * sizeof(int)); // создаем 3-й массив в размером 1 элемент
		assert(pArr3 != NULL);

		for (size_t i = 0; i < M ; i++)
		{
			isUnique = true;
			for (size_t k = i + 1; k < M + N; k++)
			{
				if (k < M)
				{
					if (pArrA[i] == pArrA[k])
					{
						isUnique = false;
						break;
					}
				}
				else
				{
					if (pArrA[i] == pArrB[k - M])
					{
						isUnique = false;
						break;
					}
				}

			}// for k
			if (isUnique)
			{
				pArr3 = (int*)realloc(pArr3, (++LenArr3) * sizeof(int));
				assert(pArr3 != NULL); pArr3[LenArr3 - 1] = pArrA[i];


			}

		}// for i

		// выводим массив 3
		cout << "\nArray3[" << LenArr3 << "]: ";
		for (size_t i = 0; i < LenArr3; i++)
		{
			cout << pArr3[i] << "  ";
		}
		cout << "\n";
		system("pause");
	}
//Задание 2:
//Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). Необходимо создать третий
//массив минимально возможного размера, в котором нужно собрать элементы массивов A и B,
//которые не являются общими для них, без повторений.
	{
		system("CLS");
		cout << "\nHomeWork #13. Meting #26. Task #2\n";
		size_t M = 0;
		size_t N = 0;
		
		cout << "Enter size array A[M]: ";
		cin >> M;
		cout << "Enter size array B[N]: ";
		cin >> N;

		int* pArrA = (int*)malloc(M * sizeof(int));
		assert(pArrA != NULL);

		cout << "\nArray A[M]: ";
		for (size_t i = 0; i < M; i++)
		{
			pArrA[i] = i;// rand();
			pArrA[1] = 0; 
			cout << pArrA[i] << "  ";
		}		

		cout << "\nArray B[N]: ";
		int* pArrB = (int*)malloc(N * sizeof(int));
		assert(pArrB != NULL);
		for (size_t i = 0; i < N; i++)
		{
			pArrB[i] = i;//rand();
			pArrB[2] = 3; 
			cout << pArrB[i]<<"  ";			
		}
		
		cout << "\n";

		bool isUnique = true;
		size_t LenArr3 = 1; 
		int* pArr3 = (int*)malloc(LenArr3 * sizeof(int)); // создаем 3-й массив в размером 1 элемент
		assert(pArr3 != NULL); 		

		for (size_t i = 0; i < M + N; i++)
		{
			isUnique = true;
			for (size_t k = i + 1; k < M + N; k++)
			{
				if (i < M)
				{
					if (k < M)
					{
						if (pArrA[i] == pArrA[k])
						{
							isUnique = false;
							break;
						}
					}
					else
					{
						if (pArrA[i] == pArrB[k - M ])
						{
							isUnique = false;
							break;
						}
					}
				}
				else// if (i >= M)
				{
					if (pArrB[i - M] == pArrB[k - M])
					{
						isUnique = false;
						break;
					}
				}
			}// for k
			if (isUnique)
			{
				if (i < M)
				{
					pArr3[LenArr3 - 1] = pArrA[i];
				}
				else
				{
					pArr3[LenArr3 - 1] = pArrB[i - M];
				}
				if (i < M + N - 1)
				{
					pArr3 = (int*)realloc(pArr3, (++LenArr3) * sizeof(int));
					assert(pArr3 != NULL);
				}
			}

		}// for i
		
		// выводим массив 3
		cout << "\nArray3["<< LenArr3<<"]: ";		
		for (size_t i = 0; i < LenArr3; i++)
		{
			cout << pArr3[i] << "  ";
		}
		cout << "\n";
		system("pause");
	}

	return 0;
}
