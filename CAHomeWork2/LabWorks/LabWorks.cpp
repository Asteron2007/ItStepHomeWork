// LabWorks.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <time.h>
#include <malloc.h>
#include <functional>
#include <string>

using namespace std;

typedef unsigned char BYTE;
typedef int INTARR[(CHAR_BIT << sizeof(size_t)) / sizeof(int)];

const unsigned int SortN = 100;
const unsigned int xN = 10;
const unsigned int yN = 5;

enum TShiftOrientation
{
	horizontal,
	vertical
};



void ShiftMatrix(int(&Arr)[yN][xN], TShiftOrientation ShiftOrientation, int(&ShiftVector)[xN > yN ? xN : yN])
{
	//собственно сам сдвиг на 1 элемент, если 
	int tmp = 0;
	int len1 = ShiftOrientation == horizontal ? xN : yN;
	int len2 = ShiftOrientation == horizontal ? yN : xN;
	switch (ShiftOrientation)
	{
	case vertical:
	{
		for (int i = 0; i < xN; i++)
		{
			if (ShiftVector[i] != 0)
			{
				if (ShiftVector[i] > 0)
				{
					tmp = Arr[sizeof(Arr) / sizeof(Arr[0]) - 1][i];
					for (int j = sizeof(Arr) / sizeof(Arr[0]) - 1; j > 0; j--)
					{
						Arr[j][i] = Arr[j-1][i];
					}
					Arr[0][i] = tmp;
				}
				else
				{
					tmp = Arr[0][i];
					for (int j = 0; j < sizeof(Arr) / sizeof(Arr[0]) - 1; j++)
					{
						Arr[j][i] = Arr[j + 1][i];
					}
					Arr[sizeof(Arr) / sizeof(Arr[0]) - 1][i] = tmp;
				}

			}

			// уменьшаем вектор сдвига

			if (ShiftVector[i] != 0)
			{
				ShiftVector[i] > 0 ? ShiftVector[i]-- : ShiftVector[i]++;
			}
		}

		for (int i = 0; i < xN; i++)
		{
			if (ShiftVector[i] != 0)
			{
				ShiftMatrix(Arr, ShiftOrientation, ShiftVector);
				break;
			}
		}
		break;
	}
	case horizontal:
	{
		for (int i = 0; i < yN; i++)
		{
			if (ShiftVector[i] != 0)
			{
				if (ShiftVector[i] > 0)
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

			// уменьшаем вектор сдвига

			if (ShiftVector[i] != 0)
			{
				ShiftVector[i] > 0 ? ShiftVector[i]-- : ShiftVector[i]++;
			}
		}

		for (int i = 0; i < yN; i++)
		{
			if (ShiftVector[i] != 0)
			{
				ShiftMatrix(Arr, ShiftOrientation, ShiftVector);
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

// функция принимающая массив переменной величины
//template <typename T, size_t N >
//void func(T(&arr)[N])
//{
//	size_t M = sizeof(arr) / sizeof(arr[0]);
//}

//1
void FindMinMax(int(&Numbers)[10])
{
	signed int MaxIndex = 0;
	signed int MinIndex = 0;

	for (unsigned int i = 0; i < sizeof(Numbers) / sizeof(Numbers[0]); i++)
	{
		if (Numbers[MaxIndex] < Numbers[i])
		{
			MaxIndex = i;
		}

		if (Numbers[MinIndex] > Numbers[i])
		{
			MinIndex = i;
		}
	}
	std::cout << "MaxIndex = " << MaxIndex << " Max Value = " << Numbers[MaxIndex] << "\n";
	std::cout << "MinIndex = " << MinIndex << " Min Value = " << Numbers[MinIndex] << "\n";

	return;
}

//2
//	typedef int INT10[10];
//	typedef const INT10& INT10_CFEF;
//	void Reverse(INT10_CFEF Numbers)
void Reverse(int (&Numbers)[10])
{
	int tmp = 0;
	for (unsigned int i = 0; i < (sizeof(Numbers) / sizeof(Numbers[0])) / 2; i++)
	{
		tmp = Numbers[i];
		Numbers[i] = Numbers[sizeof(Numbers) / sizeof(Numbers[0]) - 1 - i];
		Numbers[sizeof(Numbers) / sizeof(Numbers[0]) - 1 - i] = tmp;
	}
	return;
}

//3
unsigned int SimpleNumbersCount(int(&Numbers)[10])
{
	unsigned int Count = 0;
	for (unsigned int i = 0; i < (sizeof(Numbers) / sizeof(Numbers[0])) / 2; i++)
	{
	
	}

	return Count;
}

//4
void SortArr10(int(&Numbers)[10], int Size, bool SortByDecline = false)
{
	bool sorted = true;

	// Bubble best sort 
	for (int i = 0; i < Size; i++)
	{
		for (int j = i; j < Size; j++) // проверка отсортирован ли массив
		{
			if (Numbers[i] > Numbers[j])
			{
				sorted = false;
				break;
			}
			sorted = true;
		}

		if (!sorted)
		{
			for (int j = i; j < Size; j++)
			{
				if (SortByDecline)
				{
					if (Numbers[i] < Numbers[j])
					{
						unsigned int tmp = Numbers[i];
						Numbers[i] = Numbers[j];
						Numbers[j] = tmp;
					}
				}
				else
				{
					if (Numbers[i] > Numbers[j])
					{
						unsigned int tmp = Numbers[i];
						Numbers[i] = Numbers[j];
						Numbers[j] = tmp;
					}
				}
			}
		}		
	}
	return;
}


//5

//6

//7
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

//8

//9
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

//10
void FindMin10Elements(int(&Numbers)[100])
{
	signed int MaxIndex = 0;
	signed int MinIndex = 0;

	for (unsigned int i = 0; i < sizeof(Numbers) / sizeof(Numbers[0]); i++)
	{
		if (Numbers[MaxIndex] < Numbers[i])
		{
			MaxIndex = i;
		}

		if (Numbers[MinIndex] > Numbers[i])
		{
			MinIndex = i;
		}
	}
	std::cout << "MaxIndex = " << MaxIndex << " Max Value = " << Numbers[MaxIndex] << "\n";
	std::cout << "MinIndex = " << MinIndex << " Min Value = " << Numbers[MinIndex] << "\n";

	return;
}


//11
/*
double MaxVal(double(&Num_s)[100]);
double MaxVal(double(&Num_s)[100][100]);
double MaxVal(double(&Num_s)[100][100][100]);
int MaxVal(int a, int b);
*/

// overload functions

double MaxVal(double(&Num_s)[100])
{
	double MaxV = Num_s[0];
	for (int i = 1; i < (sizeof(Num_s) / sizeof(Num_s[0])); i++)
	{
		if (MaxV > Num_s[i]) MaxV = Num_s[i];
	}
	return MaxV;
}

double MaxVal(double(&Num_s)[100][100])
{
	double MaxV = MaxVal(Num_s[0]);
	double MaxVTmp = MaxV;

	for (int i = 1; i < (sizeof(Num_s) / sizeof(Num_s[0])); i++)
	{
		MaxVTmp = MaxVal(Num_s[i]);
		if (MaxV > MaxVTmp) MaxV = MaxVTmp;
	}
	return MaxV; 
}

double MaxVal(double(&Num_s)[100][100][100])
{
	double MaxV = MaxVal(Num_s[0]);
	double MaxVTmp = MaxV;

	for (int i = 1; i < (sizeof(Num_s) / sizeof(Num_s[0])); i++)
	{
		MaxVTmp = MaxVal(Num_s[i]);
		if (MaxV > MaxVTmp) MaxV = MaxVTmp;
	}
	return MaxV; 
}


int BinarySearch(unsigned int(&SortArr)[SortN], unsigned int Begin, unsigned int End, unsigned int Key)
{

	unsigned int MidIndex = (Begin + End) / 2;
	unsigned int CountAttempt = 1;
	if (Key > SortN - 1) return -1; //-неверный диапазон

	if (SortArr[MidIndex] != Key)
	{
		if (Key > SortArr[MidIndex])
		{
			return  BinarySearch(SortArr, MidIndex + 1, End, Key);
		}
		else
		{
			return  BinarySearch(SortArr, Begin, MidIndex - 1, Key);
		}

	}
	else return MidIndex;
}


int MaxVal(int a, int b)
{
	return a > b ? a : b;
}

int MaxVal(int a, int b, int c)
{
	return MaxVal(MaxVal(a, b), c);
}

	



// Create (size_t N) -> int*
// Destroy (int *arr) -> void
// Size (int *arr) -> size_t
// resize (int arr, size_t N) -> int*
int* CreateArray(size_t NElements)
{
	BYTE* buf = (BYTE*)malloc(NElements * sizeof(int) + sizeof(size_t));
	size_t& len = reinterpret_cast<size_t&>(*(buf + 0));
	INTARR& arr = reinterpret_cast<INTARR&>(*(buf + sizeof(size_t)));
	len = NElements;
	return arr;
}

int* ResizeArray(int* arr, size_t NElements)
{
	BYTE* buf = reinterpret_cast<BYTE*>(arr) - sizeof(size_t);
	buf = (BYTE*)realloc(buf, NElements * sizeof(int) + sizeof(size_t));
	size_t& len = reinterpret_cast<size_t&>(*(buf + 0));
	len = NElements;
	INTARR& NewArr = reinterpret_cast<INTARR&>(*(buf + sizeof(size_t)));
	return NewArr;
}

size_t SizeofArray(int* arr)
{
	size_t& len = *reinterpret_cast<size_t*>((reinterpret_cast<BYTE*>(arr) - sizeof(size_t)));
	return len;
}

void DestroyArray(int* arr)
{
	BYTE* buf = reinterpret_cast<BYTE*>(arr) - sizeof(size_t);
	free(buf);
	return;
}

void fff(int* arr) 
{
	size_t size = SizeofArray(arr);
	for (size_t i = 0; i < size; i++) 
	{
		arr[i] = rand();
		cout << arr[i]<<"\n";
	}
}

void OutArray(int* arr)
{
	size_t size = SizeofArray(arr);
	for (size_t i = 0; i < size; i++)
	{
		//arr[i] = rand();
		cout << arr[i] << "\n";
	}
}


void SumMultArray(int* arr, size_t* Count, int* Summ, int* Mult)
{
	*Summ = arr[0];
	*Mult = arr[0];
	if (*Count > 1)
	{
		for (size_t i = 1; i < *Count; i++)
		{
			*Summ += arr[i];
			*Mult *= arr[i];
		}
	}
	return;
}

//ФУНКЦИЯ НЕВЕРНАЯ надо исправить 
int* ArrayinArray(int* arr, size_t* Count)
{
	size_t index = 0;
	if (*Count > 1)
	{
		for (size_t i = 0; i < *Count; i++)
		{
			//*Summ += arr[i];
			//*Mult *= arr[i];
		}
	}
	return arr;
}

double Summ(double Val1, double Val2) 
{
	return Val1+Val2;
}

double Mult(double Val1, double Val2)
{
	return Val1 * Val2;
}

double Dec(double Val1, double Val2)
{
	return Val1 - Val2;
}

double Div(double Val1, double Val2)
{
	if (Val2 != 0)
		return Val1 / Val2;
	else return 0;
}

double Exit(double Val1, double Val2)
{
	return 0;
}

void SummC(int* pArrA, int* pArrB, int* pArrC, size_t Len)
{
	for (size_t i = 0; i < Len; i++)
	{
		*(pArrC + i) = *(pArrA + i) + *(pArrB + i);
	}
	return;
}

int MyStrLen(const char* str)
{
	int TerminatorPos = 0;
	while (str[TerminatorPos] != '\0')	
		TerminatorPos++;
	return TerminatorPos;
}

char *MyStrCopy(char * str1, char* str2)
{
	for (size_t i = 0; i <= MyStrLen(str2); i++)
	{
		str1[i] = str2[i];
	}
	return &*str1;
}

char* MyStrCat(char* str1, const char* str2)
{
	size_t len1 = MyStrLen(str1);
	for (size_t i = 0; i <= MyStrLen(str2); i++)
	{
		str1[len1+ i] = str2[i];
	}
	return &*str1;
}

int MyStrSearchCh(char* str1, const char s)
{
	size_t len1 = MyStrLen(str1);
	size_t Pos = -1;

	for (size_t i = 0; i <= len1; i++)
	{
		if (str1[i] == s)
		{
			Pos = i;
			break;
		}
	}
	return Pos;
}

int MyStrSearchStr(char* str1, const char* str2)
{
	size_t Pos = 0;
	size_t len1 = MyStrLen(str1);
	size_t len2 = MyStrLen(str2);
	if ((len1 > 0) && (len2 > 0))
	{
		bool Entry = false;
		size_t Index = 0; //MyStrSearchCh(str1, str2[0]);
		while ((!Entry) && (Index < len1))
		{
			Index += MyStrSearchCh(&str1[Index], str2[0]);
			Pos = Index;
			Entry = true;
			for (size_t i = 1; i < len2; i++)
			{
				if (str1[++Index] != str2[i])
				{
					Entry = false;
					break;
				}
			}
		}
		if (Entry) return Pos;
		else return -1;		
	}
	return -1;
}

// добавление строки к массиву строк
int MyInsertString(int *Arr, size_t IndexY, char* MyStr)
{

	return 0;
}

int main()
{
	system("chcp 1251");  // переходим на русский язык в консоли

	double Sum  = 1;
	double P = 1;
	for (size_t i = 2; i < 1001; i++)
	{
		P = P / i;
		Sum = Sum + P;

	}
	std::cout << Sum;
	system("Pause");



	{
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

	{
		//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

		size_t CountY = 5;
		//size_t CountX[CountY] = {2,3,4,5,3};

		char** pMyStr= (char**)malloc(sizeof(char*) * (CountY + 1));
		cout << "Size of pMyStr: " << sizeof(pMyStr) << "\n";
		
		char tmpStr[128] = "str0123";
		char* ptmpNewStr;

		for (size_t i = 0; i < CountY; i++)
		{
			cout << "Enter New string: ";
			cin >> tmpStr;
			//tmpStr =  "9";
			//*(pMyStr + i) = (char*)malloc(sizeof(char) * (MyStrLen(tmpStr) + 1));
			size_t len = (MyStrLen(tmpStr) + 1);
			pMyStr[i] = (char*)malloc(sizeof(char) * len);
			strcpy_s(pMyStr[i], len, tmpStr);
			(char*)pMyStr[i];
			tmpStr[0] = '\0';

			//pMyStr[i] = (char*)((char)i+"999798"); //(char*)tmpStr;
			//(int*)malloc(m * sizeof(int))

		}
		pMyStr[CountY] = NULL;

		size_t  Pos = 0;
			// Вывод элементов массива
		for (size_t i = 0; i < CountY + 1; i++)
		{
			if (*(pMyStr + i) != NULL)
			{
				ptmpNewStr = *(pMyStr + i);
				//ptmpNewStr = pMyStr[i];
				//cout << *(pMyStr+i);
				
				while (pMyStr[i][Pos] != '\0')
				{
					cout << pMyStr[i][Pos];
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

		// добавление строки к двумерному массиву в конец
		//InsertString(1);


		// Очистка памяти
		for (size_t i = 0; i < CountY + 1; i++)
			free(pMyStr[i]);   // освобождение памяти под строку
		free(pMyStr);


	}

	char MyStr[128] = "те кст еще слово. Больше слов, меньше дела! ... заметьте, не я это сказал.";

	char MyStrNew[128];

	char* MyStrNew22 = MyStrCopy(MyStrNew, MyStr);

	//string BestStr = "те кст еще слово. Больше слов, меньше дела! ... заметьте, не я это сказал.";
	char SearchStr[128];

	int ComaCount = 0;
	int DotCount = 0;
	int SeachCount = 0;
	cout << "Enter search string: ";
	cin >> SearchStr;
	
	
	char* tmpStr = strstr(MyStr, SearchStr);
	while (tmpStr != NULL)
	{
		++SeachCount;
		tmpStr = strstr((tmpStr + strlen(SearchStr)), SearchStr);
	}
	cout << SeachCount;

	//cout << "Enter string: ";
	//cin >> MyStr;
	cout << "\nYour string: ";
	cout << MyStr;
	cout << "\n";

	cout << "\nNew string: ";
	cout << MyStrNew;
	cout << "\n";

	cout << "\nNew string22: ";
	cout << MyStrNew22;
	cout << "\n";

	MyStrCat(MyStrNew, MyStr);
	cout << "\nNew string: ";
	cout << MyStrNew;
	cout << "\n";

	MyStr[0] = '\0';//{  }; //12341235123134512345234

	MyStrCat(MyStr, "12341235123134512345237");

	cout << "\nYour string: ";
	cout << MyStr;
	cout << "\n";
	cout << "Len: " << MyStrLen(MyStr) << '\n';

	cout << "Found '5' index: " << MyStrSearchCh(MyStr, '5') << '\n';

	

	unsigned int start_time = clock(); // начальное время
   // здесь должен быть фрагмент кода, время выполнения которого нужно измерить
	cout << "Found '373' index: " << MyStrSearchStr(MyStr, "373") << '\n';
	unsigned int end_time = clock(); // конечное время
	unsigned int search_time = end_time - start_time; // искомое время


	system("Pause");



	int TerminatorPos = 0;
	while (MyStr[TerminatorPos] != '\0')
	{
		if (MyStr[TerminatorPos] == ' ')
			 MyStr[TerminatorPos] = '\t';
		TerminatorPos++;
	}
	
	cout << "\nYour string: ";
	cout << MyStr;
	
	cout << "\n";
	system("Pause");




	int ArrA[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int ArrB[10] = { 10,11,12,13,14,15,16,17,18,19 };
	int ArrC[10];

	SummC(ArrA, ArrB, ArrC, 10);


	for (size_t i = 0; i < 10; i++)
	{
		cout << "ArrC[" << i << "] = " << ArrC[i] << "\n";
	}
	system("Pause");
	   	 
	typedef std::function<double(double, double)> calc_func;

	calc_func OpArr[5] = {
		[](double Val1, double Val2) -> double// exit
{
	return 0;
},  
	[](double Val1, double Val2) -> double// div
{
	if (Val2 != 0)
		return Val1 / Val2;
	else return 0;
},
[](double Val1, double Val2)-> double // dec
{
	return Val1 - Val2;
}
// 3
//4 не инициализированы пока



	};




	// calculator
	double A = 5.8;
	double B = 1.2;
	int Operator = 0;

	//double (*OpArr[5])(double, double) = { Exit, Div,Dec, Mult, Summ };

	do
	{
		try {
			cout << "A = " << A << " B = " << B << "\n";
			cout << "0. Exit\n";
			cout << "1. Div\n";
			cout << "2. Dec\n";
			cout << "3. Mult\n";
			cout << "4. Summ\n";

			cout << "Enter Operator: ";
			cin >> Operator;
			cout << OpArr[Operator](A, B) << "\n";
		}
		catch (std::exception exp) {
			std::cout << "Wrong choise!" << "\n";
		}

	} while (Operator != 0);
	// end calculator


	//ptr_t ptr = (size_t)malloc(sizeof(int) * 100);
	//int& third_element = reinterpret_cast<int&>(*(reinterpret_cast<BYTE*>(ptr) + 3 * sizeof(int)));
	
	
	size_t *lengthA = (size_t*)malloc(sizeof(size_t));
	size_t* lengthB = (size_t*)malloc(sizeof(size_t));
	int *pTmpArrA;
	int* pTmpArrB;
	int SummVal =0;
	int *MultVal =  (int*) malloc(sizeof(int));
	*MultVal = 0;
	*lengthA = 10;
	*lengthB = 3;
	
	//int(*qqq)[10] = (int(*)[10])malloc(sizeof(int) * 10);
	//(*qqq)[3]

	pTmpArrA = (int*)malloc(sizeof(int) * (*lengthA));
	pTmpArrB = (int*)malloc(sizeof(int) * (*lengthB));
	
	cout << "ArrB\n";
	for (size_t i = 0; i < *lengthB; i++)
	{
		pTmpArrA[i] = i + 6;
		cout << "arr[" << i << "] = " << pTmpArrA[i] << "  ";
	}
	cout << "\n";

	cout << "ArrA\n";
	for (size_t i = 0; i < *lengthA; i++)
	{
		pTmpArrA[i] = i+1;
		cout << "arr[" << i << "] = " << pTmpArrA[i] << "  ";
	}
	cout << "\n";
	cout << "length = " << lengthA<<"\n";
	cout << "SummVal = " << SummVal << "\n";
	cout << "MultVal = " << &MultVal << "\n";
	
	SumMultArray(pTmpArrA, (size_t*)lengthA, &SummVal, MultVal);
	for (size_t i = 0; i < *lengthA; i++)
	{
		cout << "arr[" << i << "] = " << pTmpArrA[i] << "\n";
	}
	cout <<"length = "<< lengthA << "\n";
	cout << "SummVal = " << SummVal << "\n";
	cout << "MultVal = " << *MultVal << "\n";
	cout << "*********************************************************************";






	cout << "Create array 10\n";
	int* NewArr = CreateArray(10);
	SizeofArray(NewArr);
	cout << "Load and out array 10\n";
	fff(NewArr);
	cout << "resize array 20\n";
	NewArr = ResizeArray(NewArr, 20);
	cout << "out array 20\n";
	OutArray(NewArr);
	cout << "Destroy array\n\n\n";
	DestroyArray(NewArr);



	int OriginalNumbers[10] = { 1,2,3,4,5,6,7,8,9,0 };

	const unsigned int N = 100;
	int IArray[N] = {};
	double DArray[100] = {};
	unsigned int SortArr[SortN];

	srand(time(NULL));
	std::cout << "Start program!\n";

	int a = -500;
	int b = -10;
	int* ptrA = &a;
	int* ptrB = &b;

	cout << "&a    = " << &a << endl;// адрес переменной var содержащийся в памяти, извлечённый операцией взятия адреса
	cout << "ptrA  = " << ptrA << endl;// адрес переменной var, является значением указателя ptrvar
	cout << "a     = " << a << endl; // значение в переменной var
	cout << "*ptrA = " << *ptrA << endl; // вывод значения содержащегося в переменной var через указатель, операцией разименования указателя

	if (*ptrA > * ptrB)
	{
		cout << "a = " << *ptrA;
	}
	else
	{
		cout << "b = " << *ptrB;
	}
	cout << "\nEnter a\n";
	cin >> a;

	if (*ptrA < 0)
	{
		cout << "a = " << *ptrA << " sign -\n";
	}
	else
	{
		cout << "a = " << *ptrA << " sign +\n";
	}

	int tmp = *ptrA;
	*ptrA = *ptrB;
	*ptrB = tmp;

	cout << "a     = " << a << endl; // значение в переменной var
	cout << "*ptrA = " << *ptrA << endl; // вывод значения содержащегося в переменной var через указатель, операцией разименования указателя
	cout << "b     = " << b << endl; // значение в переменной var
	cout << "*ptrB = " << *ptrB << endl; // вывод значения содержащегося в переменной var через указатель, операцией разименования указателя

	int arr[5] = { 5,1728,10,-1 };
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";

	int (*ptrArr)[5] = &arr;
	cout << "arr     = " << arr << endl; // адрес переменной arr
	cout << "ptrArr = " << ptrArr << endl; // адрес переменной arr через указатель
	
	cout << "*ptrArr[1] = " << (*ptrArr)[1]<< endl; // вывод значения содержащегося в переменной var через указатель, операцией разименования указателя
	cout << "*ptrArr[2] = " << *(*ptrArr + 2) << endl; // вывод значения содержащегося в переменной var через указатель, операцией разименования указателя
	cout << "*ptrArr[3] = " << *(*ptrArr + 3) << endl; // вывод значения содержащегося в переменной var через указатель, операцией разименования указателя
	cout << "*ptrArr[4] = " << *(*ptrArr + 4) << endl; // вывод значения содержащегося в переменной var через указатель, операцией разименования указателя
	cout << "*arr[1] = " << &arr[1] << endl; // вывод значения содержащегося в переменной var через указатель, операцией разименования указателя

	int tmpSumm = 0;
	for (int i = 0; i < 5; i++)
	{
		cout << "*ptrArr[" << i << "] = " << (*ptrArr)[i] << endl; // вывод значения содержащегося в переменной var через указатель, операцией разименования указателя
		tmpSumm += (*ptrArr)[i];
	}
	cout << "Summ from pointer" << tmpSumm;
	{
		size_t N = 0;
		cin >> N;
		int* arr = (int*)malloc(N * sizeof(int));
	//	assert(arr != NULL);
		for (size_t i = 0; i < N; i++)
		{
			arr[i] = rand();
		}

		
		

		



	
	}


	system("pause");











	for (int i = 0; i < N; i++)
	{
		IArray[i] = rand();
	}

	// циклический сдвиг
	int Arr[yN][xN];
	int shift[xN > yN ? xN : yN]= {1,-1,0,2,-2, 1,-1,0,2,-2 };
	int ShiftOrientation=0;
	
	for (int i = 0; i < sizeof(Arr) / sizeof(Arr[0]); i++)
	{
		for (int j = 0; j < sizeof(Arr[i]) / sizeof(Arr[i][0]); j++)
		{
			Arr[i][j] = rand() - RAND_MAX / 2;
			std::cout << Arr[i][j] << "\t";
		}
		std::cout << "\n";
	}

	cout << "Enter ShiftOrientation (1 - vertical, 2 - horisontal): ";
	cin >> ShiftOrientation;

	
	switch (ShiftOrientation)
	{
	case 1: // vertical
	{
		for (int i = 0; i < xN; i++)
		{
			cout << "Enter shift[" << i << "]: ";
			cout << shift[i] << "\n";

			//	cin >> shift[i];
		}
		ShiftMatrix(Arr, vertical, shift);
		break;
	}
	case 2: // horizontal
	{
		for (int i = 0; i < yN; i++)
		{
			cout << "Enter shift[" << i << "]: ";
			cout << shift[i] << "\n";
			//	cin >> shift[i];
		}
		ShiftMatrix(Arr, horizontal, shift);
		break;
	}
	default:
		break;
	}

	cout << "Shifted Matrix:\n";
	for (int i = 0; i < sizeof(Arr) / sizeof(Arr[0]); i++)
	{
		for (int j = 0; j < sizeof(Arr[i]) / sizeof(Arr[i][0]); j++)
		{			
			std::cout << Arr[i][j] << "\t";
		}
		std::cout << "\n";
	}

	system("Pause");


	// бинарный поиск
	for (int i = 0; i < SortN; i++)
	{
		SortArr[i] = i + 5;
		cout << SortArr[i]<<" ";
	}
	unsigned int IndexBin = BinarySearch(SortArr, 0, SortN - 1, 6);

	cout << "\n Key 76 by Binary search Index = " << IndexBin << "\n";



	std::cout << MaxVal(DArray);

	std::cout << MaxVal(1, 7) << "\n";

	std::cout << MaxVal(11, 7, -92) << "\n";



	

	std::cout << "Summ = " << SummRange(5, 5) << "\n"; 
	
	std::cout << "Summ = " << SummRange(3, 1) << "\n";
	std::cout << "Summ = " << SummRange(1, 3) << "\n";
	
	std::cout << "Summ = " << SummRange(4, 0) << "\n";
	std::cout << "Summ = " << SummRange(0, 4) << "\n";

	/*
	std::cout << Extent(2, 4) << "\n";
	std::cout << Extent(2.0, -4) << "\n";
	std::cout << Extent(3, 3) << "\n";

	for (unsigned int i = 0; i < sizeof(OriginalNumbers) / sizeof(OriginalNumbers[0]); i++)
	{
		std::cout << "Array original value = " << OriginalNumbers[i] << "\n";
	}
	SortArr10(OriginalNumbers, 10, true);
	for (unsigned int i = 0; i < sizeof(OriginalNumbers) / sizeof(OriginalNumbers[0]); i++)
	{
		std::cout << "Sorted Array = " << OriginalNumbers[i] << "\n";
	}
	   	  
	Reverse(OriginalNumbers);
	for (unsigned int i = 0; i < sizeof(OriginalNumbers) / sizeof(OriginalNumbers[0]); i++)
	{
		std::cout << "Array reverse value = " << OriginalNumbers[i] << "\n";
	}
	// 
	FindMinMax(OriginalNumbers);
	

	*/
	return 0;
}



