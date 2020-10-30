// HomeWork12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>
using namespace std;

const char CROSS = 'X';
const char ZERO = '0';
const char FREEFIELD = '_';
const int xN = 3; // размер поля крестики нолики
const int yN = 3; // размер поля крестики нолики
const int pxN = 4; // размер поля пятнашки
const int pyN = 4; // размер поля пятнашки
const int ChessxN = 8; // размер поля шахматы
const int ChessyN = 8; // размер поля шахматы
const int MatrixN = 5; // размер квадратной матрицы


// тип игры
enum Scenary
{
	CrossZeroGame,
	SeaFightGame
};

// шахматные фигуры
enum ChessFigure
{
	cfPawn,  // пешка
	cfKing,  // король
	cfQueen, // ферзь
	cfBishop,// слон
	cfKnight,// конь
	cfRook,  // ладья
};

// вычисление количества заданных символов в массиве
unsigned int CountElement(char(&OneDimmArr)[yN], char Key)
{
	unsigned int Count = 0;
	for (int i = 0; i < yN; i++)
	{
		if (OneDimmArr[i] == Key) Count++;
	}
	return Count;
}

// поиск первого элемента в одномерном массиве
unsigned int IndexOfElement(char(&OneDimmArr)[yN], char Key)
{
	for (int i = 0; i < yN; i++)
	{
		if (OneDimmArr[i] == Key) return i;
	}
	return yN ; // Если искомый ключ не найден
}

// очистка поля
void ClearField(char(&BField)[yN][xN], char FieldType)
{
	for (int i = 0; i < yN; i++)
	{
		for (int j = 0; j < xN; j++)
		{
			BField[i][j] = FieldType;
		}
	}
	return;
}

// инициализация поля пятнашки
void InitTagField(int(&BField)[pyN][pxN])
{
	//int tmpField[pyN][pxN] = { 1,2,3,4,5,0,7,8,6 };
	int tmp = pyN * pxN - 1;
	for (int i = 0; i < pyN; i++)
	{
		for (int j = 0; j < pxN; j++)
		{
			BField[i][j] = tmp--;
			//BField[i][j] = tmpField[i][j];// тест
		}
	}

	return;
}

// инициализация поля Шихматы
void InitChessField(int(&BField)[ChessyN][ChessxN], unsigned int X, unsigned int Y)
{
	for (int i = 0; i < ChessyN; i++)
	{
		for (int j = 0; j < ChessxN; j++)
		{
			BField[i][j] = 0;
		}
	}
	//if ((X > 0) && (X <= ChessxN) && (Y > 0) && (Y <= ChessyN))
	//	BField[Y - 1][X - 1] = 1;

	return;
}

// Выводим поле для крестики нолики
void DrawField(char(&BField)[yN][xN])
{
	// горизонтальная нумерация поля
	cout << "  ";
	for (int j = 0; j < xN; j++)
	{
		cout << j + 1 << " ";
	}

	for (int i = 0; i < yN; i++)
	{
		// вертикальная нумерация поля
		cout << "\n";
		cout << i + 1 << " ";

		// выводим поле
		for (int j = 0; j < xN; j++)
		{
			cout << BField[i][j] << " ";
		}
		cout << "\n";
	}
	return;
}

// Выводим поле для пятнашек
void DrawField(int(&BField)[pyN][pxN])
{
	// горизонтальная нумерация поля
	cout << "   |";
	for (int j = 0; j < pxN; j++)
	{
		if (j + 1 < 10)cout << " ";
		cout << j + 1 << " |";
	}
	cout << "\n";

	for (int i = 0; i < pyN; i++)
	{
		cout << "---+";
		for (int j = 0; j < pxN; j++)
		{
			cout << "---+";
		}
		cout << "\n";
		// вертикальная нумерация поля
		if (i + 1 < 10) cout << " ";
		cout << i + 1 << " |";

		// выводим значения поля
		for (int j = 0; j < pxN; j++)
		{
			if (BField[i][j] < 10) cout << " ";
			if (BField[i][j] == 0)
				cout << "  |";
			else cout << BField[i][j] << " |";
		}
		cout << "\n";
	}
	cout << "---+";
	for (int j = 0; j < pxN; j++)
	{
		cout << "---+";
	}
	cout << "\n";
	return;
}

// Выводим поле для шахматишек
void DrawField(int(&BField)[ChessyN][ChessxN])
{
	// горизонтальная нумерация поля
	cout << "   |";
	for (int j = 0; j < ChessxN; j++)
	{
		if (j + 1 < 10)cout << " ";
		cout << j + 1 << " |";
	}
	cout << "\n";

	for (int i = 0; i < ChessyN; i++)
	{
		cout << "---+";
		for (int j = 0; j < ChessxN; j++)
		{
			cout << "---+";
		}
		cout << "\n";
		// вертикальная нумерация поля
		if (i + 1 < 10) cout << " ";
		cout << i + 1 << " |";

		// выводим значения поля
		for (int j = 0; j < ChessxN; j++)
		{
			if (BField[i][j] < 10) cout << " ";
			if (BField[i][j] == 0)
				cout << "  |";
			else cout << BField[i][j] << " |";
		}
		cout << "\n";
	}
	cout << "---+";
	for (int j = 0; j < ChessxN; j++)
	{
		cout << "---+";
	}
	cout << "\n";
	return;
}


// присваиваем значение ячейке в поле битвы
bool AssignField(char(&BField)[yN][xN], unsigned int X, unsigned int Y, char Value)
{
	if ((Y > 0) && (Y <= yN) && ((X > 0) && (X <= xN)))
	{
		if ((BField[Y - 1][X - 1] != CROSS) && (BField[Y - 1][X - 1] != ZERO))
		{
			BField[Y - 1][X - 1] = Value;
			return true;
		}
		else return false;
	}
	else return false;

}

// Ищем пустую ячейку в пятнашках
bool SearchFreeCell(int(&BField)[pyN][pxN], unsigned int(&X), unsigned int(&Y))
{
	for (int i = 0; i < pyN; i++)
	{
		for (int j = 0; j < pxN; j++)
		{
			if (BField[i][j] == 0)
			{
				X = j + 1;
				Y = i + 1;
				return true;
			}
		}
	}
	return false;
}

// Ищем пустую ячейку на шахматном поле
bool SearchFreeCell(int(&BField)[ChessyN][ChessxN], unsigned int(&X), unsigned int(&Y))
{
	for (int i = 0; i < ChessyN; i++)
	{
		for (int j = 0; j < ChessxN; j++)
		{
			if (BField[i][j] == 0)
			{
				X = j + 1;
				Y = i + 1;
				return true;
			}
		}
	}
	return false;
}

// перемещаем ячейку в поле битвы в пятнашках
bool MoveCell(int(&BField)[pyN][pxN], unsigned int X, unsigned int Y)
{
	if ((Y > 0) && (Y <= pyN) && ((X > 0) && (X <= pxN)))
	{
		unsigned int tmpx = 0;
		unsigned int tmpy = 0;
		if (SearchFreeCell(BField, tmpx, tmpy))
		{
			if (tmpx == X) //здесь ошибка
			{
				if (tmpy == Y + 1)
				{
					BField[Y][X - 1] = BField[Y - 1][X - 1];
					BField[Y - 1][X - 1] = 0;
					return true;
				}
				else if (tmpy == Y - 1)
				{
					BField[Y - 2][X - 1] = BField[Y - 1][X - 1];
					BField[Y - 1][X - 1] = 0;
					return true;
				}
			}
			if (tmpy == Y)
			{
				if (tmpx == X + 1)
				{
					BField[Y - 1][X] = BField[Y - 1][X - 1];
					BField[Y - 1][X - 1] = 0;
					return true;
				}
				else if (tmpx == X - 1)
				{
					BField[Y - 1][X - 2] = BField[Y - 1][X - 1];
					BField[Y - 1][X - 1] = 0;
					return true;
				}
			}
		}
		else return false;
	}
	else return false;
}


// поиск заданного ключа в мастрице
bool SearchKeyInMatrix(char(&BField)[yN][xN], unsigned int& X, unsigned int& Y, char Key)
{
	for (int i = 0; i < xN; i++)
	{
		for (int j = 0; j < yN; j++)
		{
			if (BField[j][i] == Key)
			{
				X = i;
				Y = j;
				return true;
			};
		}
	}
	return false;
}

// проверка упорядочены ли элементы в пятнашках
bool ArrayIsSorted(int(&BField)[pyN][pxN])
{
	int tmp = 0;
	for (int i = 0; i < pyN; i++)
	{
		for (int j = 0; j < pxN; j++)
		{
			//tmp++;
			if (++tmp < pxN*pyN)
			{
				if (BField[i][j] != tmp)
				{
					return false;
				}
			}
			else if (BField[j][i] == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	return false;
}
// проверка на наличие заполненных линий (диагонали, горизонтали и вертикали)
bool FullLine(char(&BField)[yN][xN], char Symbol)
{
	// горизонтальный массив
	for (int i = 0; i < yN; i++)
	{
		if (CountElement(BField[i], Symbol) == yN)
		{
			return true;
		}
	}

	char tmpOneDimmArr[yN];

	// вертикальный массив
	for (int i = 0; i < xN; i++)
	{
		for (int j = 0; j < yN; j++)
		{
			tmpOneDimmArr[j] = BField[j][i];
		}
		if (CountElement(tmpOneDimmArr, Symbol)==xN)
		{
			return true;
		}
	}

	// диагональные массивы
	for (int i = 0; i < xN; i++) // прямая диагональ 
	{
		tmpOneDimmArr[i] = BField[i][i];
	}
	if (CountElement(tmpOneDimmArr, Symbol) == xN)
	{
		return true;
	}
	for (int i = 0; i < xN; i++) // обратная диагональ 
	{
		tmpOneDimmArr[i] = BField[yN - 1 - i][i];
	}
	if (CountElement(tmpOneDimmArr, Symbol) == xN)
	{
		return true;
	}
	return false;
}

// вычисление оптимальной позиции игрока
bool AIMovement(int Scenary, char(&BField)[yN][xN], 
	unsigned int &X, unsigned int &Y, char PlayerSymbol, char EnemySymbol)
{
	switch (Scenary)// в зависимости от типа игры
	{
	case CrossZeroGame: 
	{
		// ищем количество и длину диагоналей и прямых линий по горизонтали в вертикали
		// определяем максимальное и его предотвращаем
		unsigned int MaxCountX = 0;
		unsigned int MaxCountY = 0;
		unsigned int MaxCountD = 0;
		unsigned int MaxIndexX = 0;
		unsigned int MaxIndexY = 0;
		unsigned int MaxIndexD = 0;
		unsigned int tmpMaxCountY = 0;
		unsigned int tmpMaxCountX = 0;
		unsigned int tmpMaxCountD = 0;
		char tmpOneDimmArr[yN];

		// горизонтальный массив
		for (int i = 0; i < yN; i++)
		{
			tmpMaxCountY = CountElement(BField[i], EnemySymbol);
			if (tmpMaxCountY > MaxCountY)
			{
				MaxCountY = tmpMaxCountY;
				MaxIndexY = i;
			}
		}

		// вертикальный массив
		for (int i = 0; i < xN; i++)
		{
			for (int j = 0; j < yN; j++)
			{
				tmpOneDimmArr[j] = BField[j][i];
			}
			tmpMaxCountX = CountElement(tmpOneDimmArr, EnemySymbol);
			if (tmpMaxCountX > MaxCountX)
			{
				MaxCountX = tmpMaxCountX;
				MaxIndexX = i;
			}
		}

		// диагональные массивы
		for (int i = 0; i < xN; i++) // прямая диагональ 
		{
			tmpOneDimmArr[i] = BField[i][i];
		}
		MaxCountD = CountElement(tmpOneDimmArr, EnemySymbol);
		//MaxIndexD = 0;
		for (int i = 0; i < xN; i++) // обратная диагональ 
		{
			tmpOneDimmArr[i] = BField[yN - 1 - i][i];
		}
		MaxCountD = CountElement(tmpOneDimmArr, EnemySymbol);
		if (tmpMaxCountD > MaxCountD)
		{
			tmpMaxCountD = MaxCountD;
			MaxIndexX++;
		}
		// времненные для тестирования
		//cout << MaxCountD << " indexD " << MaxIndexD << "\n";
		//cout << MaxCountX << " indexX " << MaxIndexX << "\n";
		//cout << MaxCountY << " indexY " << MaxIndexY << "\n";

		if ((MaxCountY >= MaxCountD) && (MaxCountY >= MaxCountX))
		{
			tmpMaxCountX = IndexOfElement(BField[MaxIndexY], FREEFIELD);
			if ((MaxIndexY >= 0) && (MaxIndexY < yN) && ((tmpMaxCountX >= 0) && (tmpMaxCountX < xN))
				&& (BField[MaxIndexY][tmpMaxCountX] == FREEFIELD))
			{
				Y = MaxIndexY + 1;
				X = tmpMaxCountX + 1;
				return true;
			}
		}

		if (MaxCountX >= MaxCountD)
		{
			for (int j = 0; j < xN; j++)
			{
				if (BField[j][MaxIndexX] == FREEFIELD)
				{
					tmpMaxCountY = j;
					break;
				}
			}
			if ((MaxIndexY >= 0) && (MaxIndexY < yN) && ((MaxCountX >= 0) && (MaxCountX < xN))
				&& (BField[tmpMaxCountY][MaxIndexX] == FREEFIELD))
			{
				Y = tmpMaxCountY + 1;
				X = MaxIndexX + 1;
				return true;
			}
		}


		switch (MaxIndexD)// диагональные массивы
		{
		case 0:
		{
			for (int i = 0; i < xN; i++) // прямая диагональ 
			{
				if (BField[i][i] == FREEFIELD)
				{
					X = i + 1;
					Y = i + 1;
					return true;
				}
			}
			break;
		}
		case 1:
		{
			for (int i = 0; i < xN; i++) // обратная диагональ 
			{
				if (BField[yN - 1 - i][i] == FREEFIELD)
				{
					X = i + 1;
					Y = yN - i;
					return true;
				}
			}
			break;
		}
		default:
			break;
		}
		// крайний случай поиск любой свободной ячейки
		if (SearchKeyInMatrix(BField, X, Y, FREEFIELD))
		{
			X++;
			Y++;
			return true;
		}		
	}

	// сценарий морской бой
	case SeaFightGame:
	{

		break;
	}
	default:
		break;
	}


	return false;
}
// для ускорения расчета Правило Варнсдорфа
// алгоритм обхода шахматной доски

// возможные ходы фигуры на шахматной доске 
int PossibleMovesChessFigure(int (&BField)[ChessyN][ChessxN], ChessFigure CFigure, int X, int Y, 
	int (&PossibleMoves)[ChessyN * ChessxN*2])
{
	// int PossibleMoves (массив смещения координат хода) 
	// X = PossibleMoves[i];
	// Y = PossibleMoves[i + 1];
	int count = 0;

	switch (CFigure)
	{
	case cfKnight:
	{
		int tmpPossibleMoves[] =
		{ -1,2,// dx, dy
			1,2,
			-1, -2,
			1,-2,
			2,1,
			2,-1,
			-2,1,
			-2,-1
		};
		
		int tmpX;
		int tmpY;
		for (size_t i = 0; i < sizeof(tmpPossibleMoves) / sizeof(tmpPossibleMoves[0]); i += 2)
		{
			tmpX = X + tmpPossibleMoves[i];
			tmpY = Y + tmpPossibleMoves[i + 1];
			if ((tmpX > 0) && (tmpX < ChessxN + 1) && (tmpY > 0) && (tmpY < ChessyN + 1))
				if ((BField[tmpY - 1][tmpX - 1]) == 0)
				{
					PossibleMoves[count*2] = tmpPossibleMoves[i];
					PossibleMoves[count*2 + 1] = tmpPossibleMoves[i + 1];
					count++;
				}
		}
		break;
	}
	case cfBishop:
	{
		// свой способ передвижения и свой массив передвижений
		break;
	}
	default:
		break;
	}
	
	return count;
}


bool MoveChessFigure(int(&BField)[ChessyN][ChessxN], ChessFigure CFigure, int Step, int X, int Y, bool(&TaskComplete))
{	
	if (TaskComplete)return true;

	if (BField[Y - 1][X - 1] == 0) BField[Y - 1][X - 1] = Step;
	else return false;
	unsigned int freeX = 0;
	unsigned int freeY = 0;
	int PossibleMoves[ChessyN * ChessxN*2];

	if ((Step == ChessyN * ChessxN) && (!SearchFreeCell(BField, freeX, freeY)))
	{
		TaskComplete = true;
		return true; //убедиться что нет не обойденных клеток
	}
	else
	{
		unsigned int tmpcount = PossibleMovesChessFigure(BField, CFigure, X, Y, PossibleMoves);
		if (tmpcount > 0)
		{
			for (size_t i = 0; i < tmpcount; i++)
			{
				if (MoveChessFigure(BField, CFigure, ++Step, X + PossibleMoves[i * 2],
					Y + PossibleMoves[i * 2 + 1], TaskComplete))// && TaskComplete)
					return true;
				else
				{
					Step--;
					BField[Y + PossibleMoves[i * 2 + 1] - 1][X + PossibleMoves[i * 2] - 1] = 0;
					//return false;
				}
			}
		}
		else
		{
			Step--;
			BField[Y - 1][X - 1] = 0;
			return false;
		}
	}
	return false;
}

// Возведение в степень
int Extent(int Value, int Ext)
{
	if (Ext == 0)
	{
		return 1;
	}
	else if (Ext > 0)
	{
		return Value * Extent(Value, --Ext);
	}
	else
	{
		return 1 / Value / Extent(Value, ++Ext);
	}
}


void NumToDigits(int Number, int(&Digits)[4])
{
	for (size_t i = 0; i < 4; i++)
	{
		Digits[4 - 1 - i] = ((Number / Extent(10, i) - (Number / Extent(10, i + 1) * 10))) % 10;
	}
	return;
}

bool SearchDublicateDigits(int Number)
{
	int Digits[4];
	NumToDigits(Number, Digits);

	for (size_t i = 0; i < 4 - 1; i++)
	{
		for (size_t j = i + 1; j < 4; j++)
		{
			if (Digits[i] == Digits[j]) return true;
		}
	}
	
	//Numbers[0] = Number / 1000;
	//Numbers[1] = (Number - Numbers[0] * 1000) / 100;
	//Numbers[2] = (Number - Numbers[0] * 1000 - Numbers[1] * 100) / 10;
	//Numbers[3] = (Number - Numbers[0] * 1000 - Numbers[1] * 100 - Numbers[2] * 10);
	return false;
}

// ищем дублирющиеся цифры в числе
bool SearchDublicateDigits(int Number, size_t (&CountDublicate))
{
	//char Numbers[4];
	int Digits[4];
	NumToDigits(Number, Digits);
	
	CountDublicate = 0;
	for (size_t i = 0; i < 4 - 1; i++)
	{
		for (size_t j = i + 1; j < 4; j++)
		{
			if (Digits[i] == Digits[j])
				CountDublicate++;
		}
	}

	return CountDublicate;
}
// сравнивает два числа, возвращает true, усли равны
bool CompareNumbers(int NumberA, int NumberB, size_t (&CountDublicateDigits), 
	size_t (&DublicateIndex)[4], size_t (&CountDublicateDigitsByIndex))
{
	int DigitsA[4];
	NumToDigits(NumberA, DigitsA);
	int DigitsB[4];
	NumToDigits(NumberB, DigitsB);

	CountDublicateDigits = 0;
	CountDublicateDigitsByIndex = 0;

	for (size_t i = 0; i < 4; i++)
	{
		if (DigitsA[i] == DigitsB[i])
		{
			DublicateIndex[i] = 1;
			CountDublicateDigitsByIndex++;
		}
		else DublicateIndex[i] = 0;
	}

	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			if ((DigitsA[i] == DigitsB[j] && (i != j)))
				CountDublicateDigits++;
		}
	}	
	
	return (NumberA==NumberB);
}

// игрок вводит число
int GetPlayerNumber()
{
	int tmpPlayerNumber = 0;
	cout << " Enter number (format [xxxx], dont dublicate digits, 9 - to Exit): ";
	cin >> tmpPlayerNumber;
	if (((tmpPlayerNumber < 1000) || (tmpPlayerNumber > 9999) || (SearchDublicateDigits(tmpPlayerNumber)))
		&& (tmpPlayerNumber != 9)) 
	{
		return GetPlayerNumber();
	}
	else return tmpPlayerNumber;

	/*while (((tmpPlayerNumber < 1000) || (tmpPlayerNumber > 9999) || (SearchDublicateDigits(tmpPlayerNumber)))
		&& (tmpPlayerNumber != 9))
	{
		cout << " Enter number (format [xxxx], dont dublicate digits, 9 - to Exit): ";
		cin >> tmpPlayerNumber;
	}*/
}

int FindDivider(int divider, int NumberA, int NumberB)
{
	int tmpDivider = divider; 
	
	if ((NumberA % tmpDivider == 0) && (NumberB % tmpDivider == 0))
	{
		return tmpDivider;
	}
	else
	{
		return FindDivider(--tmpDivider, NumberA, NumberB);
	}
}

void initMatrix(int(&Arr)[MatrixN][MatrixN])
{
	for (int i = 0; i < MatrixN; i++)
	{
		for (int j = 0; j < MatrixN; j++)
		{
			Arr[i][j] = rand();
		}
	}
	return;
}

void initMatrix(char(&Arr)[MatrixN][MatrixN])
{

	for (int i = 0; i < MatrixN; i++)
	{
		for (int j = 0; j < MatrixN; j++)
		{
			Arr[i][j] = (float)rand()/RAND_MAX*CHAR_MAX;
		}
	}
	return;
}

void initMatrix(double(&Arr)[MatrixN][MatrixN])
{
	for (int i = 0; i < MatrixN; i++)
	{
		for (int j = 0; j < MatrixN; j++)
		{
			Arr[i][j] = (double)rand()/100;
		}
	}
	return;
}

void outMatrix(int(&Arr)[MatrixN][MatrixN])
{
	for (int i = 0; i < MatrixN; i++)
	{
		for (int j = 0; j < MatrixN; j++)
		{
			cout << Arr[i][j] << "\t";
		}
		cout << "\n";
	}
	return;
}

void outMatrix(char(&Arr)[MatrixN][MatrixN])
{

	for (int i = 0; i < MatrixN; i++)
	{
		for (int j = 0; j < MatrixN; j++)
		{
			cout << Arr[i][j] << "\t";
		}
		cout << "\n";
	}
	return;
}

void outMatrix(double(&Arr)[MatrixN][MatrixN])
{
	for (int i = 0; i < MatrixN; i++)
	{
		for (int j = 0; j < MatrixN; j++)
		{
			cout << Arr[i][j] << "\t";
		}
		cout << "\n";
	}
	return;
}


int MaxDiagonalElement(int(&Arr)[MatrixN][MatrixN])
{
	int tmpval = Arr[0][0];
	for (int i = 1; i < MatrixN; i++)
	{
		if (Arr[i][i] > tmpval) tmpval = Arr[i][i];
	}
	return tmpval;
}

int MinDiagonalElement(int(&Arr)[MatrixN][MatrixN])
{
	int tmpval = Arr[0][0];
	for (int i = 1; i < MatrixN; i++)
	{
		if (Arr[i][i] < tmpval) tmpval = Arr[i][i];
	}
	return tmpval;
}

char MaxDiagonalElement(char(&Arr)[MatrixN][MatrixN])
{
	char tmpval = Arr[0][0];
	for (int i = 1; i < MatrixN; i++)
	{
		if (Arr[i][i] > tmpval) tmpval = Arr[i][i];
	}
	return tmpval;
}

char MinDiagonalElement(char(&Arr)[MatrixN][MatrixN])
{
	char tmpval = Arr[0][0];
	for (int i = 1; i < MatrixN; i++)
	{
		if (Arr[i][i] < tmpval) tmpval = Arr[i][i];
	}
	return tmpval;
}

double MaxDiagonalElement(double(&Arr)[MatrixN][MatrixN])
{
	double tmpval = Arr[0][0];
	for (int i = 1; i < MatrixN; i++)
	{
		if (Arr[i][i] > tmpval) tmpval = Arr[i][i];
	}
	return tmpval;
}

double MinDiagonalElement(double(&Arr)[MatrixN][MatrixN])
{
	double tmpval = Arr[0][0];
	for (int i = 1; i < MatrixN; i++)
	{
		if (Arr[i][i] < tmpval) tmpval = Arr[i][i];
	}
	return tmpval;
}

// сортировка одномерного массива
void SortArr(int(&Numbers)[MatrixN], int Size=MatrixN, bool SortByDecline = false)
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
						int tmp = Numbers[i];
						Numbers[i] = Numbers[j];
						Numbers[j] = tmp;
					}
				}
				else
				{
					if (Numbers[i] > Numbers[j])
					{
						int tmp = Numbers[i];
						Numbers[i] = Numbers[j];
						Numbers[j] = tmp;
					}
				}
			}
		}
	}
	return;
}

void SortArr(char(&Numbers)[MatrixN], int Size = MatrixN, bool SortByDecline = false)
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
						char tmp = Numbers[i];
						Numbers[i] = Numbers[j];
						Numbers[j] = tmp;
					}
				}
				else
				{
					if (Numbers[i] > Numbers[j])
					{
						char tmp = Numbers[i];
						Numbers[i] = Numbers[j];
						Numbers[j] = tmp;
					}
				}
			}
		}
	}
	return;
}

void SortArr(double(&Numbers)[MatrixN], int Size = MatrixN, bool SortByDecline = false)
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
						double tmp = Numbers[i];
						Numbers[i] = Numbers[j];
						Numbers[j] = tmp;
					}
				}
				else
				{
					if (Numbers[i] > Numbers[j])
					{
						double tmp = Numbers[i];
						Numbers[i] = Numbers[j];
						Numbers[j] = tmp;
					}
				}
			}
		}
	}
	return;
}

void SortByRows(int(&Arr)[MatrixN][MatrixN], bool SortByDecline = false)
{
	for (int i = 0; i < MatrixN; i++)
	{
		SortArr(Arr[i], MatrixN, SortByDecline);
	}
	return;
}

void SortByRows(char(&Arr)[MatrixN][MatrixN], bool SortByDecline = false)
{
	for (int i = 0; i < MatrixN; i++)
	{
		SortArr(Arr[i], MatrixN, SortByDecline);
	}
	return;
}
void SortByRows(double(&Arr)[MatrixN][MatrixN], bool SortByDecline = false)
{
	for (int i = 0; i < MatrixN; i++)
	{
		SortArr(Arr[i], MatrixN, SortByDecline);
	}
	return;
}

int main()
{
	system("chcp 1251");  // переходим на русский язык в консоли
	   	
	//	Домашнее задание № 12
	//	Встреча №23
	//	Задание 1 :
	//	Написать перегруженные функции(int, double, char) для выполнения следующих задач :
	// +Инициализация квадратной матрицы;
	// +Вывод матрицы на экран;
	// +Определение максимального и минимального элемента на главной диагонали матрицы;
	// Сортировка элементов по возрастанию отдельно для каждой строки матрицы.
	{
		system("CLS");
		cout << "\nHomeWork #12. Meting #23. Task #1\n";
		cout << "\n Matrix function\n";

		int intMatrix[MatrixN][MatrixN];
		char charMatrix[MatrixN][MatrixN];
		double doubleMatrix[MatrixN][MatrixN];


		initMatrix(intMatrix);
		initMatrix(charMatrix);
		initMatrix(doubleMatrix);

		cout << "\nint Matrix\n";
		outMatrix(intMatrix);
		cout << "Max diagonal element: " << MaxDiagonalElement(intMatrix) << "\n";
		cout << "Min diagonal element: " << MinDiagonalElement(intMatrix) << "\n";

		cout << "\nchar Matrix\n";
		outMatrix(charMatrix);
		cout << "Max diagonal element: " << MaxDiagonalElement(charMatrix) << "\n";
		cout << "Min diagonal element: " << MinDiagonalElement(charMatrix) << "\n";
		cout << "\ndouble Matrix\n";
		outMatrix(doubleMatrix);
		cout << "Max diagonal element: " << MaxDiagonalElement(doubleMatrix) << "\n";
		cout << "Min diagonal element: " << MinDiagonalElement(doubleMatrix) << "\n";

		cout << "\nSorted int Matrix\n";
		SortByRows(intMatrix);
		outMatrix(intMatrix);
		cout << "\nSorted char Matrix\n";
		SortByRows(charMatrix);
		outMatrix(charMatrix);
		cout << "\nSorted double Matrix\n";
		SortByRows(doubleMatrix);
		outMatrix(doubleMatrix);

		system("Pause");
	}

	
	//Задание 2:
	//Написать рекурсивную функцию нахождения наибольшего общего делителя двух целых чисел.
	{
		system("CLS");
		cout << "\nHomeWork #12. Meting #23. Task #2\n";
		cout << "\n divider (version 1.0)\n";
		int NumberA = 0;
		int NumberB = 0;
		cout << "Enter Number A: ";
		cin >> NumberA;
		cout << "Enter Number B: ";
		cin >> NumberB;
		if (NumberA > NumberB)
			cout << "Max Divider = " << FindDivider(NumberB, NumberA, NumberB) << "\n";
		else cout << "Max Divider = " << FindDivider(NumberA, NumberA, NumberB) << "\n";

		system("Pause");
	}
		//Задание 3:
		//Написать игру «Быки и коровы».Программа "загадывает" четырёхзначное число и играющий должен угадать его.
		//После ввода пользователем числа программа сообщает, сколько цифр числа угадано(быки) и сколько цифр угадано 
		//и стоит на нужном месте(коровы).После отгадывания числа на экран необходимо вывести количество сделанных 
		//пользователем попыток.В программе необходимо использовать рекурсию.
	{
		int SecretNumber = 0;
		int PlayerNumber = 0;
		size_t AttemptCount = 0;
		size_t BullsCount = 0;
		size_t CowsCount = 0;
		size_t Digits[4];

		bool Play = true;
		while (Play)
		{
			AttemptCount = 0;
			system("CLS");
			cout << "\nHomeWork #12. Meting #23. Task #3\n";
			cout << "\n bulls and cows (version 1.0)\n";
			// загадываем число
			while ((SecretNumber < 1000) || (SecretNumber > 9999) || (SearchDublicateDigits(SecretNumber)))
			{
				SecretNumber = rand();
			}

			do
			{
				AttemptCount++;
				// игрок вводит число
				PlayerNumber = GetPlayerNumber();// рекурсия
				
				if (PlayerNumber == 9)
				{
					cout << "Exit. ";
					Play = false;
					break;
				}

				CompareNumbers(SecretNumber, PlayerNumber, CowsCount, Digits, BullsCount);
				cout << "Attemp count: " << AttemptCount << "  CowsCount: " << CowsCount <<
					"  BullsCount: " << BullsCount << "\n";

				if (PlayerNumber == SecretNumber)
				{
					cout << "You WIN! Attempt count: " << AttemptCount << "\n";
					system("Pause");
					Play = false;
				}
			} while (Play);

			if (PlayerNumber == 9) break;
			Play = true;
		}
		system("Pause");
	}

		//Домашнее задание № 12
		
		//Встреча №24
		//Задание 1 :
		//Дана шахматная доска размером 8х8 и шахматный конь.
		//Программа должна запросить у пользователя координаты клетки поля и поставить туда коня.
		//Задача программы найти и вывести путь коня, при котором он обойдет все клетки доски,
		//становясь в каждую клетку только один раз. 
		//(Так как процесс отыскания пути для разных начальных клеток может затянуться, 
		//то рекомендуется сначала опробовать задачу на поле размером 6х6).
		// В программе необходимо использовать рекурсию.
	{
		bool Play = true;
		int BattleField[ChessyN][ChessxN];
		unsigned int x = 0;
		unsigned int y = 0;
		bool TaskComplete = false;
		// инициализация игрового поля
		InitChessField(BattleField, 1, 1);

		system("CLS");
		cout << "\nHomeWork #12. Meting #24. Task #1\n";
		cout << "\n Chess (version 1.0)\n";

		// выводим поле
		DrawField(BattleField);
		MoveChessFigure(BattleField, cfKnight, 1, 1, 1, TaskComplete);
		
		cout << "\n\n After Calculation\n";
		DrawField(BattleField);

		system("Pause");
	}

		// Задание 2 :
		// Написать игру "Пятнашки".	
	{
		bool Play = true;
		int BattleField[pyN][pxN];
		unsigned int x = 0;
		unsigned int y = 0;

		// инициализация игрового поля
		InitTagField(BattleField);

		while (Play)
		{
			system("CLS");
			cout << "\nHomeWork #12. Meting #24. Task #2\n";
			cout << "\n ПЯТНАШКИ (version 1.0)\n";

			// выводим поле
			DrawField(BattleField);

			// проверяем собраны ли пятнашки 
			if (ArrayIsSorted(BattleField)) // собраны ли пятнашки
			{
				Play = false;
				cout << "You win!!!\n";
				continue;
			}

			// ход человека
			// запрашиваем координаты/ проверяем на правильность (свободная ячейка)
			do
			{
				cout << "Player#1 move: Enter position X (or '0' to Exit): ";
				cin >> x;
				if (x == 0)
				{
					Play = false;
					break;
				}
				else if ((x > 0) && (x <= pxN))
				{
					break;
				}
			} while (true);
			if (!Play) continue;

			do
			{
				cout << "Player#1 move: Enter position Y (or '0' to Exit): ";
				cin >> y;
				if (y == 0)
				{
					Play = false;
					break;
				}
				else if ((y > 0) && (y <= pyN))
				{
					break;
				}

			} while (true);
			if (!Play) continue;

			if (MoveCell(BattleField, x, y)) continue;//break;//заново запросить координаты
			else break; //continue;				
		}
		system("Pause");
	}

		// Задание 3 :
		// Написать игру "Крестики-нолики".
	{

		bool Play = true;
		char BattleField[yN][xN];
		unsigned int x = 0;
		unsigned int y = 0;		
		
		// очистка поля
		ClearField(BattleField, FREEFIELD);

		while (Play)
		{
			system("CLS");
			cout << "\nHomeWork #12. Meting #24. Task #3\n";
			cout << "\n Cross & Zeros (version 1.0)\n";
			
			// выводим поле
			DrawField(BattleField);

			// ход человека
			do // запрашиваем координаты/ проверяем на правильность (свободная ячейка)
			{
				do
				{
					cout << "Player#1 move: Enter Cross position X (or '0' to Exit): ";
					cin >> x;
					if (x == 0)
					{
						Play = false;
						break;
					}
					else if ((x > 0) && (x <= xN))
					{
						break;
					}
				} while (true);
				if (!Play) continue;

				do
				{
					cout << "Player#1 move: Enter Cross position Y (or '0' to Exit): ";
					cin >> y;
					if (y == 0)
					{
						Play = false;
						break;
					}
					else if ((y > 0) && (y <= yN))
					{
						break;
					}

				} while (true);
				if (!Play) continue;

				if (AssignField(BattleField, x, y, CROSS)) break;
				else continue;

			} while (true);		//заново запросить координаты
			

			// проверяем есть ли полностью заполненые ряды 
			system("CLS");
			cout << "\nHomeWork #12. Meting #24. Task #3\n";
			cout << "\n Cross & Zeros (version 1.0)\n";

			// выводим поле
			DrawField(BattleField); 
			
			if (FullLine(BattleField, CROSS)) // заполнены крестиками
			{
				Play = false;
				cout << "You win!!!\n";
				continue;
			}
			else if (FullLine(BattleField, ZERO)) // заполнены ноликами
			{
				Play = false;
				cout << "Comp win!!!\n";
				continue;
			}			

			// AI Movement
			do
			{
				if (AIMovement(CrossZeroGame, BattleField, x, y, ZERO, CROSS))
				{
					system("Pause");
					if (AssignField(BattleField, x, y, ZERO)) break;
					else continue;
				}
				else
				{
					Play = false;
					// Ничья
					cout << "Drawn game!!!\n";
					break;
				}
			} while (true);		//заново запросить координаты

			// проверяем есть ли полностью заполненые ряды 
			if (FullLine(BattleField, CROSS)) // заполнены крестиками
			{
				Play = false;
				cout << "You win!!!\n";
				continue;
			}
			else if (FullLine(BattleField, ZERO)) // заполнены ноликами
			{
				Play = false;
				cout << "Comp win!!!\n";
				continue;
			}
			system("CLS");
			cout << "\nHomeWork #12. Meting #24. Task #3\n";
			cout << "\n Cross & Zeros (version 1.0)\n";

			// выводим поле
			DrawField(BattleField);
		}

		system("Pause");
	}
	

	return 0;


}
