// HomeWork0004.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cassert>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE

#define ESC "\x1b"
#define CSI "\x1b["



using namespace std;
void printXY(int X, int Y, char* str, int BackGroundColor, int TextColor);

template<class T>




class TMySmartPointer
{
public:
	TMySmartPointer(T* obj = NULL)
	{
		CopyCount = 0;
		ptr = obj;
	}
	TMySmartPointer(const TMySmartPointer& obj)
	{
		ptr = obj.ptr;
		CopyCount++;
	}

	~TMySmartPointer()
	{
		if (ptr != NULL && CopyCount == 0)
		{
			cout << "\n~Delete Object\n";
			//уничтожаем объект
			delete ptr;
		}
		//в противном случае(уничтожается копия)
		else
		{
			//уменьшаем счётчик
			CopyCount--;
			cout << "\n~Delete Copy\n";
		}
	}

	TMySmartPointer operator=(const TMySmartPointer& obj)
	{
		//создается копия - увеличиваем счётчик
		ptr = obj.ptr;
		CopyCount++;
		//возвращаем сам объект для ситуации a=b=c
		return *this;
	}

	T* operator->()
	{
		return ptr;
	}

	T& operator* ()
	{
		return *ptr;
	}
	operator T* ()
	{
		return ptr;
	}
private:
	T* ptr;
	int CopyCount;
};


class TMyString
{
public:
	TMyString(size_t len = 80)
	{
		pStr = (char*)malloc(sizeof(char) * len + 1);
		assert(pStr != NULL);
		//pStr[len] = '\0';		
		pStr[0] = '\0';
	}
	
	TMyString(const TMyString& Sender)
	{
		pStr = (char*)malloc(sizeof(char) * MyStrLen(Sender.pStr) + 1);
		assert(pStr != NULL);
		strcpy_s(pStr, MyStrLen(Sender.pStr) + 1, Sender.pStr);
	}
	TMyString(const char* Name)
	{
		pStr = (char*)malloc(sizeof(char) * ((MyStrLen(Name) + 1)));
		assert(pStr != NULL);
		strcpy_s(pStr, MyStrLen(Name) + 1, Name);
	}

	~TMyString()
	{
		if (pStr != NULL)
			free(pStr);
	}

	void setMyStr(const char* Name)
	{
		pStr = (char*)realloc(pStr, sizeof(char) * ((MyStrLen(pStr) + 1)));
		assert(pStr != NULL);
		strcpy_s(pStr, MyStrLen(Name) + 1, Name);
	}
	// длина строки
	int MyStrLen(const char* str)
	{
		if (str != NULL)
		{
			int TerminatorPos = 0;
			while (str[TerminatorPos] != '\0')
				TerminatorPos++;
			return TerminatorPos;
		}
		else
			return-1;
	}
	// длина строки
	int MyStrLen()
	{
		int TerminatorPos = 0;
		while (pStr[TerminatorPos] != '\0')
			TerminatorPos++;
		return TerminatorPos;
	}

	char& operator[] (const int index)
	{
		if (index < MyStrLen())
			return pStr[index];
		else
			return pStr[MyStrLen() - 1];
	}

	int operator()(const char sym)
	{
		for (int i = 0; i < MyStrLen(); i++)
		{
			if (pStr[i] == sym)
			{
				return i;
			}
		}
		return -1;
	}

	int toInt()
	{
		return MyStrLen();
	}

	TMyString& operator++()
	{
		int tmpLen = MyStrLen();
		pStr = (char*)realloc(pStr, sizeof(char) * (tmpLen + 2));
		assert(pStr != NULL);
		pStr[tmpLen] = ' ';
		pStr[tmpLen + 1] = '\0';
		return *this;
	}

	TMyString& operator--()
	{
		int tmpLen = MyStrLen();
		pStr = (char*)realloc(pStr, sizeof(char) * tmpLen);
		assert(pStr != NULL);
		pStr[tmpLen - 1] = '\0';
		return *this;
	}

	TMyString& operator+(const TMyString* str)
	{
		//надо дописать
		return *this;

	}
	// надо править
	/*char* MyStrCat(char* str1, const char* str2)
	{
		size_t len1 = MyStrLen(str1);
		for (size_t i = 0; i <= MyStrLen(str2); i++)
		{
			str1[len1 + i] = str2[i];
		}
		return &*str1;
	}*/

	friend std::ostream& operator<< (std::ostream& out, const TMyString& str);
	friend std::istream& operator>> (std::istream& in, TMyString& str);

private:
	char* pStr;
	const unsigned int MaxLen = 500;
};

std::ostream& operator<< (std::ostream& out, const TMyString& str)
{
	// Поскольку operator<< является другом класса TMyString, то мы имеем прямой доступ к членам TMyString
	out << str.pStr;
	return out;
}

std::istream& operator>>(std::istream& in, TMyString& str)
{
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max());
	//in >> str.pStr;
	in.getline(str.pStr, str.MaxLen);
	return in;
}

enum TOrientation
{
	Left,
	Right,
	Top,
	Bottom
};

struct TMyPoint
{
	int X; // координата X
	int Y; // координата Y
	int Status; // 0 повреждение, 1 исправно. Остальные значения можно использовать
	            // под цвет и тип точки для более сложных игр 
                // -1 неверные координаты   
};

class TMyBattleShip
{
public:
	TMyBattleShip(int StartX = 0, int StartY = 0, size_t ShipSize = 1, TOrientation Orientation = Right)
	{
		this->ShipSize = ShipSize;

		Pos = (TMyPoint*)malloc(sizeof(TMyPoint) * ShipSize);
		assert(Pos != NULL);
		
		switch (Orientation)
		{
		case Left:
			{
				for (size_t i = 0; i < ShipSize; i++)
				{
					Pos[i].X = StartX - i;
					Pos[i].Y = StartY;
					Pos[i].Status = 1;
				}
				break;
			}
		case Right:
			{
				for (size_t i = 0; i < ShipSize; i++)
				{
					Pos[i].X = StartX + i;
					Pos[i].Y = StartY;
					Pos[i].Status = 1;
				}
				break;
			}
		case Top:
			{
				for (size_t i = 0; i < ShipSize; i++)
				{
					Pos[i].X = StartX;
					Pos[i].Y = StartY - i;
					Pos[i].Status = 1;
				}
				break;
			}
		case Bottom:
			{
				for (size_t i = 0; i < ShipSize; i++)
				{
					Pos[i].X = StartX;
					Pos[i].Y = StartY + i;
					Pos[i].Status = 1;
				}
				break;
			}
		default:
			break;
		}
	}
	TMyBattleShip(const TMyBattleShip& Sender)
	{
		if (&Sender != nullptr)
		{
			this->ShipSize = Sender.ShipSize;

			Pos = (TMyPoint*)malloc(sizeof(TMyPoint) * this->ShipSize);
			assert(Pos != NULL);

			for (size_t i = 0; i < this->ShipSize; i++)
			{
				this->Pos[i].X = Sender.Pos[i].X;
				this->Pos[i].Y = Sender.Pos[i].Y;
				this->Pos[i].Status = Sender.Pos[i].Status;

				//this->Pos[i] = Sender.Pos[i];
			}
		}
	}

	~TMyBattleShip()
	{
		free(Pos);
	}

	int getStatus(int X, int Y) const
	{
		for (size_t i = 0; i < this->ShipSize; i++)
		{
			if (this->Pos[i].X == X && this->Pos[i].Y == Y)
				return this->Pos[i].Status;
		}
		return -1; // не существует такой точки
	}

	int setStatus(int X, int Y, int Status) 
	{
		for (size_t i = 0; i < this->ShipSize; i++)
		{
			if (this->Pos[i].X == X && this->Pos[i].Y == Y)
			{
				this->Pos[i].Status = Status;
				return this->Pos[i].Status;
			}
		}
		return -1; // не существует такой точки
	}
	void Show(int StartX, int StartY, int FieldSize, int BackGroundColor, int TextColor)
	{
		char Frame[4] = " + ";  //d
		char DamageFrame[4] = " X ";  //d
		unsigned color = 90; //94

		
		for (size_t i = 0; i < ShipSize; i++)
		{
			if (Pos[i].Status == 1)
				printXY(StartX + Pos[i].X * 3, StartY + Pos[i].Y, Frame, BackGroundColor, TextColor);
			else//frame damade 'X';
				printXY(StartX + Pos[i].X * 3, StartY + Pos[i].Y, DamageFrame, BackGroundColor, TextColor);
		}
	}
	bool InOrder()
	{
		for (size_t i = 0; i < ShipSize; i++)
		{
			if (Pos[i].Status == 1)
				return true;
		}
		return false;
	}

	void ShowPoints()
	{
		char outChar[80] = "";
		char tmpChar[80] = "";

		for (size_t i = 0; i < this->ShipSize; i++)
		{
			strcat(outChar, " X = ");
			itoa(this->Pos[i].X, tmpChar, 10);
			strcat(outChar, tmpChar);
			strcat(outChar, " Y = ");
			itoa(this->Pos[i].Y, tmpChar, 10);
			strcat(outChar, tmpChar);
			strcat(outChar, " Status = ");
			itoa(this->Pos[i].Status, tmpChar, 10);
			strcat(outChar, tmpChar);
			strcat(outChar, "\n");
			
			printXY(40, 2 + i, tmpChar, 15, 90);

		}
	}

private:
	size_t ShipSize;
	TMyPoint* Pos;	
};

class TMyBattleField
{
public:
	TMyBattleField(size_t FieldSize = 10)
	{
		this->FieldSize = FieldSize;
		this->BattleField = new int*[FieldSize];
		for (size_t i = 0; i < FieldSize; i++)
		{
			BattleField[i] = new int[FieldSize];
		}

		for (size_t i = 0; i < this->FieldSize; i++)
		{
			for (size_t j = 0; j < this->FieldSize; j++)
			{
				this->BattleField[i][j] = 0;
			}
		}
	}

	~TMyBattleField()
	{
		for (size_t i = 0; i < FieldSize; i++)
		{
			delete[] BattleField[i];
		}
		delete[] BattleField;

		delete[] Player;
		delete[] AIPlayer;
	}

	TMyBattleShip* putBattleShip(size_t ShipSize)
	{
		size_t X = 0;
		size_t Y = 0;
		TOrientation Orientation;
		bool FreeCell;
		do
		{
			FreeCell = true;
			X = rand() % FieldSize;
			Y = rand() % FieldSize;
			Orientation = (TOrientation)(rand() % 4);

			switch (Orientation)
			{
			case Left:
			{
				for (size_t i = 0; i < ShipSize; i++)
				{
					if ((X - i - 1 >= 0) && (Y - 1 >= 0) && (Y + 1 < FieldSize) && (X < FieldSize))
					{
						if ((X - i < FieldSize) && (Y < FieldSize))
							//if (BattleField[Y][X - i] != 0 || BattleField[Y][X - i - 1] != 0 ||
						//	BattleField[Y + 1][X - i] != 0 || BattleField[Y - 1][X - i] != 0)
						{
							FreeCell = false;
							break;
						}
					}
					else
					{
						FreeCell = false;
						break;
					}				
				}
				if (FreeCell)
				{
					for (size_t i = 0; i < ShipSize; i++)
					{
						BattleField[Y][X - i] = 1;
					}
				}
				break;
			}
			case Right:
			{
				for (size_t i = 0; i < ShipSize; i++)
				{
					if ((X + i < FieldSize) && (Y < FieldSize))
					{
						if (BattleField[Y][X + i] != 0)
						{
							FreeCell = false;
							break;
						}
					}
					else
					{
						FreeCell = false;
						break;
					}
				}
				if (FreeCell)
				{
					for (size_t i = 0; i < ShipSize; i++)
					{
						BattleField[Y][X + i] = 1;
					}
				}
				break;
			}
			case Top:
			{
				for (size_t i = 0; i < ShipSize; i++)
				{					
						if ((Y - i >= 0) && (Y -i< FieldSize) && (X < FieldSize))
						{
							if (BattleField[Y - i][X] != 0)
							{
								FreeCell = false;
								break;
							}
						}
						else
						{
							FreeCell = false;
							break;
						}
				}
				if (FreeCell)
				{
					for (size_t i = 0; i < ShipSize; i++)
					{
						BattleField[Y-i][X] = 1;
					}
				}
				break;
			}
			case Bottom:
			{
				for (size_t i = 0; i < ShipSize; i++)
				{
					if ((Y + i < FieldSize) && (X < FieldSize))
					{
						if (BattleField[Y + i][X] != 0)
						{
							FreeCell = false;
							break;
						}
					}
					else
					{
						FreeCell = false;
						break;
					}
				}
				if (FreeCell)
				{
					for (size_t i = 0; i < ShipSize; i++)
					{
						BattleField[Y + i][X] = 1;
					}
				}
				break;
			}
			default:
				break;
			}


		} while (!FreeCell);

		TMyBattleShip* tmp = new TMyBattleShip(X, Y, ShipSize, Orientation);
		//tmp->ShowPoints();
		
		return tmp;
	}

	void InitBattleField()
	{

		Player = new TMyBattleShip[10]; //[10] кораблей
		Player[0] = *putBattleShip(4); // 1 корабль — ряд из 4 клеток(«четырёхпалубный»; линкор)
	//	Player[0].ShowPoints();
		for (size_t i = 1; i < 3; i++) // 2 корабля — ряд из 3 клеток(«трёхпалубные»; крейсера)
		{
			Player[i] = *putBattleShip(3);
			//Player[i].ShowPoints();
		}
		for (size_t i = 3; i < 6; i++) // 3 корабля — ряд из 2 клеток(«двухпалубные»; эсминцы)
		{
			Player[i] = *putBattleShip(2);
			//Player[i].ShowPoints();
		}
		for (size_t i = 6; i < 10; i++) // 4 корабля — 1 клетка(«однопалубные»; торпедные катера)
		{
			Player[i] = *putBattleShip(1);
			//Player[i].ShowPoints();
		}
			
		AIPlayer = new TMyBattleShip[10]; //[10] кораблей
		AIPlayer[0] = *putBattleShip(4); // 1 корабль — ряд из 4 клеток(«четырёхпалубный»; линкор)
		for (size_t i = 1; i < 3; i++) // 2 корабля — ряд из 3 клеток(«трёхпалубные»; крейсера)
			AIPlayer[i] = *putBattleShip(3);
		for (size_t i = 3; i < 6; i++) // 3 корабля — ряд из 2 клеток(«двухпалубные»; эсминцы)
			AIPlayer[i] = *putBattleShip(2);
		for (size_t i = 6; i < 10; i++) // 4 корабля — 1 клетка(«однопалубные»; торпедные катера)
			AIPlayer[i] = *putBattleShip(1);
	}
	

	void ShowBattleField()
	{
		system("CLS");

		unsigned int x = 5;
		unsigned int y = 5;

		unsigned int x1 = 42;
		unsigned int y1 = 5;

		char frame = 100;  //d
	//	unsigned color = 94;

		cout << ESC "(0";        // Enter Line drawing mode
		cout << CSI "0;0H"; // Move to 0x0
		cout << "lqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqwqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqk\n";
		for (int i = 0; i < 15; i++)
		{
			// in line drawing mode, \x78 -> \u2502 "Vertical Bar"
			cout << "x                                    x                                    x\n";
		}
		cout << "mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqvqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj\n";
		//	cout << "\n\nqwertyuiopasdfghjklzxcvbnm,./";
		cout << ESC "(B";       // exit line drawing mode
		{
			char tmpChar[80] = "Player#1";
			printXY(10, 16, tmpChar, 15, PlayerColor);
		}
		{
			char tmpChar[80] = "AI Player";
			printXY(50, 16, tmpChar, 15, AIPlayerColor);
		}


		char tmpChar[80] = "   Sea fight (Ver. 1.0) ";//[16]
		//	char* p;
		printXY(5, 2, tmpChar, 15, 91);

		std::cout << CSI << y - 1 << ";" << x << "H";     // cursor position		
		// горизонтальная нумерация поля
		for (size_t j = 0; j < FieldSize; j++)
		{
			cout << " " << j + 1 << " ";
		}

		std::cout << CSI << y - 1 << ";" << x1 << "H";     // cursor position		
		// горизонтальная нумерация поля
		for (size_t j = 0; j < FieldSize; j++)
		{
			cout << " " << j + 1 << " ";
		}

		for (size_t i = 0; i < FieldSize; i++)
		{
			itoa(i + 1, tmpChar, 10);
			printXY(x - 2, y + i, tmpChar, 15, 90);
			printXY(x1 - 2, y + i, tmpChar, 15, 90);
		}

		// out BattleField
		for (size_t i = 0; i < this->FieldSize; i++)
		{
			for (size_t j = 0; j < this->FieldSize; j++)
			{
				if (this->BattleField[i][j] == 0 || this->BattleField[i][j] == 1)
					tmpChar[0] = '\0';
				else
				{
					tmpChar[0] = (char)this->BattleField[i][j];
					tmpChar[1] = '\0';
				}
				//	if (tmpChar[0]=(char)this->BattleField[i][j] == 86 || this->BattleField[i][j] == 1)
				//		tmpChar[0] = '\0';
				
				//itoa((char)this->BattleField[i][j], tmpChar, 10);
				//printXY(x + 70 + j, y + i, tmpChar, 15, 94);

				printXY(x + (j * 3) + 1, y + i, tmpChar, 15, PlayerColor);
			}
		}
	
		
		for (size_t i = 0; i < this->ShipsCount; i++)
			Player[i].Show(x, y, FieldSize, 15, PlayerColor);

		for (size_t i = 0; i < this->ShipsCount; i++)
			AIPlayer[i].Show(x1, y, FieldSize, 15, AIPlayerColor);
	}

	bool CheckInOrderShips(TMyBattleShip *Ships, size_t ShipsCount)
	{
		for (size_t i = 0; i < ShipsCount; i++)
			if (Ships[i].InOrder())
				return true;
		return false;
	}
	bool CheckSelfShips(TMyBattleShip* Ships, size_t ShipsCount, unsigned int x, unsigned int y)
	{
		for (size_t i = 0; i < ShipsCount; i++)
			if (Ships[i].getStatus(x, y)>-1)
				return true;
		return false;
	}

	bool PlayGame()
	{
		bool Play = true;
		unsigned int x = 0;
		unsigned int y = 0;

		while (Play)
		{
			ShowBattleField();

			do
			{
				char message[100] = "Player#1 move: Enter position X (or '0' to Exit): ";
				printXY(3, 18, message, 15, PlayerColor);
				cin >> x;
				if (x == 0)
				{
					Play = false;
					break;
				}
				else if ((x > 0) && (x <= FieldSize))
				{
					break;
				}
			} while (true);
			if (!Play)
				break;

			do
			{
				char message[100] = "Player#1 move: Enter position Y (or '0' to Exit): ";
				printXY(3, 18, message, 15, PlayerColor);
				cin >> y;
				if (y == 0)
				{
					Play = false;
					break;
				}
				else if ((y > 0) && (y <= FieldSize))
				{
					break;
				}
			} while (true);
			if (!Play)
				break;

			BattleField[y - 1][x - 1] = (char)'V';
			for (size_t i = 0; i < this->ShipsCount; i++)
				Player[i].setStatus(x - 1, y - 1, (char)'V');
			for (size_t i = 0; i < this->ShipsCount; i++)
				AIPlayer[i].setStatus(x - 1, y - 1, (char)'V');

			if (!CheckInOrderShips(Player, ShipsCount))
			{
				char message[100] = "Computer WIN!!!";
				printXY(5, 20, message, 15, AIPlayerColor);
				Play = false;
			}
			if (!CheckInOrderShips(AIPlayer, ShipsCount))
			{
				char message[100] = "Human WIN!!!";
				printXY(5, 20, message, 15, PlayerColor);
				Play = false;
			}
			// AI PlayerMove
			//std::cout << "Player CPU move: Enter position X (or '0' to Exit): ";
			//std::cout << "Player CPU move: Enter position Y (or '0' to Exit): ";

			do
			{
				x = rand() % FieldSize;
				y = rand() % FieldSize;
			} while (BattleField[y][x] == 0 && CheckSelfShips(AIPlayer, ShipsCount, x, y));
			BattleField[y][x] = (char)'V';
			for (size_t i = 0; i < this->ShipsCount; i++)
				Player[i].setStatus(x, y, (char)'V');
			for (size_t i = 0; i < this->ShipsCount; i++)
				AIPlayer[i].setStatus(x, y, (char)'V');
			if (!CheckInOrderShips(Player, ShipsCount))
			{
				char message[100] = "Computer WIN!!!";
				printXY(5, 20, message, 15, AIPlayerColor);
				Play = false;
			}
			if (!CheckInOrderShips(AIPlayer, ShipsCount))
			{	
				char message[100] = "Human WIN!!!";
				printXY(5, 20, message, 15, PlayerColor);
				Play = false;
			}
		}
		return false;
	}

private:
	int** BattleField;
	size_t FieldSize;
	TMyBattleShip* Player; //[10] кораблей
	TMyBattleShip* AIPlayer;//[10] кораблей
	const size_t ShipsCount = 10;
	int PlayerColor = 94;
	int AIPlayerColor = 92;

};


void printXY(int X, int Y, char* str, int BackGroundColor, int TextColor)
{
	std::cout << CSI << BackGroundColor << ";" << TextColor << "m";   // black background / blue text 94m
	std::cout << CSI << Y << ";" << X << "H";     // cursor position		
	cout << str;
	std::cout << CSI "0m";       // restore colors 
}




/*
Задание 1.
Добавить в уже существующий класс String конструктор переноса, оператор присваивания переноса.

Задание 2.
Реализуйте класс «умного указателя», а также код по тестированию данного класса.

Задание 3.
Начинаем продумывать в рамках ООП игры "Морской бой" и "Жизнь"
Для начала общие классы, поля и методы.
*/
int main()
{
	srand(time(NULL));
	{
		system("CLS");
		cout << "\nHomeWork #3. Task #3 (class Sea fight)\n";
		TMyBattleField SeaFightField;
		SeaFightField.InitBattleField();
		SeaFightField.PlayGame();


		cout << "\n";
		system("Pause");
	}


	{
		system("CLS");
		cout << "\nHomeWork #3. Task #2 (class SmartPointer)\n";
		
		TMySmartPointer<TMyString> tmpstr(new TMyString("New string"));
	
		cout << *tmpstr;

		cout << "\n";
		system("Pause");
	}

	{
		system("CLS");
		cout << "\nHomeWork #3. Task #1 (class Strings)\n";
			   		 	  
		TMyString str1 = TMyString("Hello!");
		cout << "String init by constructor: ";
		cout << str1;
		cout << "\n";
		cout << str1[0] << str1[4] << str1[4444];
		cout << "\n";
		cout << "Index char 'e': " << str1('e');
		cout << "\n";
		cout << "Decrement: " << --str1;
		cout << ". Len: " << str1.MyStrLen();
		cout << "\n";
		cout << "Decrement: " << --str1;
		cout << ". Len: " << str1.MyStrLen();
		cout << "\n";
		cout << "Increment: " << ++str1;
		cout << ". Len: " << str1.MyStrLen();
		cout << "\n";
		cout << "Increment: " << ++str1;
		cout << ". Len: " << str1.MyStrLen();
		cout << "\n";
		cout << "Increment: " << ++str1;
		cout << ". Len: " << str1.MyStrLen();
		cout << "\n";


		cout << "Enter new string: ";
		cin >> str1;
		cout << "New string from user: ";
		cout << str1;

		cout << "\n";
		system("Pause");
	}


}
