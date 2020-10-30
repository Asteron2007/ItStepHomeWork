﻿// HomeWork0011.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

template <class T>

class TMyStack
{
public:
	TMyStack() :size(0)
	{
		Head = NULL;
	}
	TMyStack(const TMyStack& Sender) : size(Sender.size)
	{
		Head = Sender.Head;
	}
	TMyStack(TMyStack&& Sender) : size(Sender.size)
	{
		Head = Sender.Head;
	}
	~TMyStack()
	{
		while (!empty())
		{
			pop();
		}
	}

	//void push(TMyItem& Item);
	void push(T Value)
	{
		TMyItem* newItem = new TMyItem;
		newItem->Next = Head;
		newItem->Value = Value;
		Head = newItem;
	}

	//TMyItem pop();
	T pop()
	{
		if (Head)
		{
			T Value = Head->Value;
			TMyItem* delItem = Head;
			Head = Head->Next;
			delete delItem;
			return Value;
		}
	}
	T peek()
	{
		return Head->Value;
	}
	bool empty()
	{
		TMyItem* tmpItem = Head;
		if (!tmpItem)
		{
			return true;
		}
		return false;
	}

	int getSize() const
	{
		return size;
	}

	void show()
	{
		TMyItem* tmpItem = Head;
		if (!tmpItem)
		{
			cout << "Stack is empty.\n";
			return;
		}
		while (tmpItem)
		{
			cout << tmpItem->Value << "\n";
			tmpItem = tmpItem->Next;
		}
	}

private:
	int size;
	struct TMyItem
	{
		T Value;
		TMyItem* Next;
	};
	TMyItem* Head;

};


int MyStrSearchCh(char* str1, const char s, int StartIndex = 0)
{
	size_t len1 = strlen(str1);
	size_t Pos = -1;

	for (size_t i = StartIndex; i < len1; i++)
	{
		if (str1[i] == s)
		{
			Pos = i;
			break;
		}
	}
	return Pos;
}

void DeleteSymbols(char* str, char Sym)
{
	int index = MyStrSearchCh(str, Sym);
	while (index > -1)
	{
		for (size_t i = index; i < strlen(str); i++)
		{
			str[i] = str[i + 1];
		}
		index = MyStrSearchCh(str, ' ', index);
	}


	//	return &*str1;
}

// Проверка корректности скобок
void CheckBrackets(const char* InstructionStr)
{
	TMyStack <char>* HeadCh = new TMyStack <char>;
	TMyStack <char>* HeadChTmp = new TMyStack <char>;

	//HeadCh->show();

	char instr[80];
	strcpy(instr, InstructionStr);
	//char opzstr[80] = "";

	cout << instr << '\n';

	//delete spaces
	DeleteSymbols(instr, ' ');
	cout << instr << '\n';
	bool isCorrectStr = false;
	char tmpChar;
	// push to stack
	for (size_t i = 0; i < strlen(instr); i++)
	{
		if ((instr[i] == '(') || (instr[i] == '{') || (instr[i] == '['))
		{
			HeadCh->push(instr[i]);
		}
		else if (instr[i] == ')')
		{
			isCorrectStr = false;
			if (!HeadCh->empty())
			{
				tmpChar = HeadCh->pop();
				if (tmpChar == '(')
				{
					isCorrectStr = true;
				}
				else
				{
					cout << "Error in string: ";
					for (size_t k = 0; k <= i; k++)
					{
						cout << instr[k];
					}
					cout << "\n";
					cout << "Bracket '(' is absent\n";
					cout << "Stack: ";
					HeadCh->show();
					break;
				}
			}
			else
			{
				cout << "Error in string: ";
				for (size_t k = 0; k <= i; k++)
				{
					cout << instr[k];
				}
				cout << "\n";
				cout << "Bracket '(' is absent\n";
				cout << "Stack: ";
				HeadCh->show();
				break;
			}
		}
		else if (instr[i] == '}')
		{
			isCorrectStr = false;
			if (!HeadCh->empty())
			{
				tmpChar = HeadCh->pop();
				if (tmpChar == '{')
				{
					isCorrectStr = true;
				}
				else
				{
					cout << "Error in string: ";
					for (size_t k = 0; k <= i; k++)
					{
						cout << instr[k];
					}
					cout << "\n";
					cout << "Bracket '{' is absent\n";
					cout << "Stack: ";
					HeadCh->show();
					break;
				}
			}
			else
			{
				cout << "Error in string: ";
				for (size_t k = 0; k <= i; k++)
				{
					cout << instr[k];
				}
				cout << "\n";
				cout << "Bracket '{' is absent\n";
				cout << "Stack: ";
				HeadCh->show();
				break;
			}
		}
		else if (instr[i] == ']')
		{
			isCorrectStr = false;
			if (!HeadCh->empty())
			{
				tmpChar = HeadCh->pop();
				if (tmpChar == '[')
				{
					isCorrectStr = true;
				}
				else
				{
					cout << "Error in string: ";
					for (size_t k = 0; k <= i; k++)
					{
						cout << instr[k];
					}
					cout << "\n";
					cout << "Bracket '[' is absent\n";
					cout << "Stack: ";
					HeadCh->show();
					break;
				}
			}
			else
			{
				cout << "Error in string: ";
				for (size_t k = 0; k <= i; k++)
				{
					cout << instr[k];
				}
				cout << "\n";
				cout << "Bracket '[' is absent\n";
				cout << "Stack: ";
				HeadCh->show();
				break;
			}
		}
	}

	if (!isCorrectStr)
	{
		cout << "Error in string: ";
		for (size_t k = 0; k < strlen(instr); k++)//<=i
		{
			cout << instr[k];
		}
		cout << "\n";
		cout << "Stack: ";
		HeadCh->show();
	}
	else
	{
		if (HeadCh->empty())
		{
			cout << "\n";
			cout << "String is correct...\n";
			cout << "Stack: ";
			HeadCh->show();
		}
		else
		{
			cout << "Error in string: ";
			for (size_t k = 0; k < strlen(instr); k++)//<=i
			{
				cout << instr[k];
			}
			cout << "\n";			
			cout << "Stack is not empty: ";
			HeadCh->show();
		}
	}
}

//распознавание математических формул
double CalculateAriphmetic(const char* InstructionStr)
{
	TMyStack <char>* HeadCh = new TMyStack <char>;
	TMyStack <double>* HeadDb = new TMyStack <double>;


	//HeadCh->show();
	//HeadDb->show();

	char instr[80];
	strcpy(instr, InstructionStr);
	//char instr[80] = "(( 6.10+5)*17. 17-(14+10.01))*1- 10.2";
	//char instr[80] = "5+ (6.10-5)*17"; 
	char opzstr[80] = "";

	cout << instr << '\n';
	//delete spaces
	DeleteSymbols(instr, ' ');
	cout << instr << '\n';
	bool isNum = false;
	// преобразование в обратную польскую запись
	for (size_t i = 0; i < strlen(instr); i++)
	{
		if (((instr[i] >= '0') && (instr[i] <= '9')) || (instr[i] == '.'))
		{
			isNum = true;
			int tmpLen = strlen(opzstr);
			opzstr[tmpLen] = instr[i];
			opzstr[tmpLen + 1] = '\0';

			//strcat_s(opzstr, &instr[i]+'\0');
		}
		else if (instr[i] == '(')
		{
			if (isNum)
			{
				int tmpLen = strlen(opzstr);
				opzstr[tmpLen] = '!';
				opzstr[tmpLen + 1] = '\0';
				isNum = false;
			}

			HeadCh->push(instr[i]);
		}
		else if ((instr[i] == '+') || (instr[i] == '-'))
		{
			if (isNum)
			{
				int tmpLen = strlen(opzstr);
				opzstr[tmpLen] = '!';
				opzstr[tmpLen + 1] = '\0';
				isNum = false;
			}

			char tmpChar;
			while (!HeadCh->empty())
			{
				tmpChar = HeadCh->pop();
				if (tmpChar != '(')
				{
					int tmpLen = strlen(opzstr);
					opzstr[tmpLen] = tmpChar;
					opzstr[tmpLen + 1] = '\0';

					//strcat_s(opzstr, &tmpChar);
				}
				else break;
			}

			HeadCh->push(instr[i]);
			//int tmpLen = strlen(opzstr);
			//opzstr[tmpLen] = instr[i];
			//opzstr[tmpLen + 1] = '\0';

			//strcat_s(opzstr, &instr[i]);
		}
		else if ((instr[i] == '*') || (instr[i] == '/'))
		{
			if (isNum)
			{
				int tmpLen = strlen(opzstr);
				opzstr[tmpLen] = '!';
				opzstr[tmpLen + 1] = '\0';
				isNum = false;
			}

			HeadCh->push(instr[i]);

			//int tmpLen = strlen(opzstr);
			//opzstr[tmpLen] = instr[i];
			//opzstr[tmpLen + 1] = '\0';
		}
		else if (instr[i] == ')')
		{
			if (isNum)
			{
				int tmpLen = strlen(opzstr);
				opzstr[tmpLen] = '!';
				opzstr[tmpLen + 1] = '\0';
				isNum = false;
			}

			char tmpChar;
			while (!HeadCh->empty())
			{
				tmpChar = HeadCh->pop();
				if (tmpChar != '(')
				{
					int tmpLen = strlen(opzstr);
					opzstr[tmpLen] = tmpChar;
					opzstr[tmpLen + 1] = '\0';

					//strcat_s(opzstr, &tmpChar);
				}
				else break;
			}
		}
		// +if number then into opzstr 
		// +if '(' to CHstack
		// if '+', '-' to opzstr to CHstack
		// if '*','/' to CHstack
		// if ')' from CHstack to till '(' from stack into opzstr
	}
	char tmpChar;
	while (!HeadCh->empty())
	{
		tmpChar = HeadCh->pop();
		if (tmpChar != '(')
		{
			int tmpLen = strlen(opzstr);
			opzstr[tmpLen] = tmpChar;
			opzstr[tmpLen + 1] = '\0';

			//strcat_s(opzstr, &tmpChar);
		}
		//else break;
	}
	// обратная польская запись
	cout << "обратная польская запись:\n";
	cout << opzstr << '\n';

	char* ptrEnd;
	//ptrEnd[0] = '\0';
	//strcpy_s(*ptrEnd, strlen(opzstr), opzstr);
	double val1, val2, res = 0;


	val1 = strtod(opzstr, &ptrEnd);
	HeadDb->push(val1);
	while (strlen(ptrEnd) > 0)
	{
		if (ptrEnd[0] == '!')
		{
			for (size_t i = 1; i < strlen(ptrEnd) + 1; i++)
				ptrEnd[i - 1] = ptrEnd[i];
		}
		else if (ptrEnd[0] >= '0' && ptrEnd[0] <= '0' || ptrEnd[0] >= '.')
		{
			val1 = strtod(ptrEnd, &ptrEnd);
			HeadDb->push(val1);
		}
		else
		{
			switch (ptrEnd[0])
			{
			case '+':
				val2 = HeadDb->pop();
				val1 = HeadDb->pop();
				res = val1 + val2;
				cout << "res = val1 + val2 = " << res << " = " << val1 << " + " << val2 << "\n";
				for (size_t i = 1; i < strlen(ptrEnd) + 1; i++)
					ptrEnd[i - 1] = ptrEnd[i];
				break;
			case '-':
				val2 = HeadDb->pop();
				val1 = HeadDb->pop();
				res = val1 - val2;
				cout << "res = val1 - val2 = " << res << " = " << val1 << " - " << val2 << "\n";

				for (size_t i = 1; i < strlen(ptrEnd) + 1; i++)
					ptrEnd[i - 1] = ptrEnd[i];
				break;
			case '*':
				val2 = HeadDb->pop();
				val1 = HeadDb->pop();
				res = val1 * val2;
				cout << "res = val1 * val2 = " << res << " = " << val1 << " * " << val2 << "\n";
				for (size_t i = 1; i < strlen(ptrEnd) + 1; i++)
					ptrEnd[i - 1] = ptrEnd[i];
				break;
			case '/':
				val2 = HeadDb->pop();
				val1 = HeadDb->pop();
				res = val1 / val2;
				cout << "res = val1 / val2 = " << res << " = " << val1 << " / " << val2 << "\n";
				for (size_t i = 1; i < strlen(ptrEnd) + 1; i++)
					ptrEnd[i - 1] = ptrEnd[i];
				break;
			default:
				cout << "Bad operator !\n";
				break;
			}
			HeadDb->push(res);
		}
	}

	cout << "Result = " << ((6.10 + 5) * 17.17 - (14 + 10.01)) * 1 - 10.2;
	cout << '\n';

	cout << "ResultFrom = " << HeadDb->peek();//pop();
	cout << '\n';
	return HeadDb->pop();
}

int main()
{
	system("chcp 1251");  // переходим на русский язык в консоли
	
//	Задание 1.
//	Есть строка символов, признаком конца, которой является «; ».В строке могут быть фигурные, круглые, 
//	квадратные скобки.Скобки могут быть открывающими и закрывающими.
//	Необходимо проверить корректность расстановки скобок.
//	При этом необходимо, чтобы выполнились следующие правила :
//1. Каждая открывающая скобка должна иметь справа такую же закрывающую.Обратное также должно быть верно.
//2. Открывающие и закрывающие пары скобок разных типов должны быть правильно расположены по отношению друг к другу.
//	 Пример правильной строки : ({ x - y - z }*[x + 2y] - (z + 4x));
//	 Пример неправильной строки : ([x - y - z}*[x + 2y) - {z + 4x)].
//Если все правила соблюдены выведите информационное сообщение о корректности строки, 
//	иначе покажите строку до места возникновения первой ошибки.

	// Проверка скобок
	char BracketStr[80] = "({x-y-z}*[x+2y]-(z+4x))";
	char IncorrectBracketStr[80] = "([x-y-z}*[x+2y)-{z+4x)]";
	CheckBrackets(BracketStr);
	CheckBrackets(IncorrectBracketStr);

	//распознавание математических формул
	char instr[80] = "(( 6.10+5)*17. 17-(14+10.01))*1- 10.2";
	CalculateAriphmetic(instr);



}
