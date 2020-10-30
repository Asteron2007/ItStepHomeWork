// HomeWork0010-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cassert>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE

using namespace std;

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
		pStr = (char*)realloc(pStr, sizeof(char) * ((MyStrLen(Name) + 1)));
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

	// возвращает символ по индексу в строке
	char& operator[] (const int index)
	{
		if (index < MyStrLen())
			return pStr[index];
		else
			return pStr[MyStrLen() - 1];
	}

	// возвращает первый индекс искомого символа в строке
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

	// возвращает длину строки
	int toInt()
	{
		return MyStrLen();
	}

	// очистка строки
	void Clear()
	{
		setMyStr("");
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

	TMyString& operator+(const TMyString& str)
	{
		TMyString* tmpStr = new TMyString(this->pStr);
		tmpStr->MyStrCat(str.pStr);
		return *tmpStr;
	}
	
	TMyString& operator+= (const TMyString& str)
	{
		MyStrCat(str.pStr);
		return *this;
	}

	TMyString& operator= (const TMyString& str)
	{
		if (this == &str)
			return *this;
		setMyStr(str.pStr);
		return *this;
	}

	TMyString& operator= (const char* str)
	{
		setMyStr(str);
		return *this;
	}

	bool operator== (const TMyString& str)
	{
		if (this == &str)
			return true;
		return EqualsStr(this->pStr, str.pStr);
	}

	bool operator== (const char* str)
	{
		return EqualsStr(this->pStr, str);
	}

	bool operator!= (const TMyString& str)
	{
		if (this == &str)
			return !true;
		return !EqualsStr(this->pStr, str.pStr);
	}

	bool operator!= (const char* str)
	{
		return !EqualsStr(this->pStr, str);
	}

	bool EqualsStr(const char* str1, const char* str2)
	{
		size_t len1 = MyStrLen(str1);
		size_t len2 = MyStrLen(str2);

		if (len1 == len2)
		{
			for (size_t i = 0; i < len1; i++)
			{
				if (str1[i] != str2[i])
					return false;
			}
			return true;
		}
		else
			return false;		
	}

	void MyStrCat(const char* str2)
	{
		size_t len1 = MyStrLen();
		size_t len2 = MyStrLen(str2);
		pStr = (char*)realloc(pStr, sizeof(char) * (len1 + len2 + 1));
		assert(pStr != NULL);

		for (int i = 0; i <= len2; i++)
		{
			pStr[len1 + i] = str2[i];
		}
	}

	friend std::ostream& operator<< (std::ostream& out, const TMyString& str);
	friend std::istream& operator>> (std::istream& in, TMyString& str);

protected:
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

class TMyBitString : public TMyString
{
public:
	TMyBitString()
	{
		Clear();
	}

	TMyBitString(const char* Name)
	{
		setMyStr(Name);
	}

	TMyBitString(const TMyBitString& Sender)
	{
		setMyStr(Sender.pStr);
	}

	~TMyBitString()
	{

	}

	void setMyStr(const char* Name)
	{
		if (IsBitStr(Name))
			TMyString::setMyStr(Name);
		else
			Clear();
	}
	
	bool IsBitStr(const char* Name)
	{
		int len1 = MyStrLen(Name);
		for (size_t i = 0; i < len1; i++)
		{
			if ((Name[i] != '0') && (Name[i] != '1'))
				return false;
		}
		return true;
	}

private:

};




int main()
{

	/*
	Описать базовый класс «Строка».
Методы:
+1) конструктор без параметров;
+2) конструктор, принимающий в качестве параметра
C-строку (заканчивается нулевым байтом);
+3) конструктор копирования;
+4) оператор присваивания;
+5) получение длины строки;
+6) очистка строки (сделать строку пустой);
+7) деструктор;
+8) конкатенация строк (перегрузить операторы + и +=);
+9) проверка на равенство (= =) и на неравенство (!=).

Описать класс «Битовая строка» производный от класса «Строка».
(Строки данного класса могут содержать только символы ‘0’ и ‘1’). Если в основе инициализирующей строки
встретятся любые символы, отличные от допустимых, то
«Битовая строка» становится пустой. Содержимое строки
рассматривается как двоичное представление целого числа
со знаковым разрядом. Отрицательные числа хранятся
в дополнительном коде.
Методы:
+1) конструктор без параметров;
+2) конструктор, принимающий в качестве параметра
C-строку;
+3) конструктор копирования;
+4) оператор присваивания;
+4) деструктор;
5) изменение знака числа (перевод числа в дополнительный код);
5) изменение знака числа (перевод числа в дополнительный код);
8) сложение битовых строк (перегрузить операторы +
и +=);
+9) проверка на равенство (= =) и на неравенство (!=).

	*/

	{
		system("CLS");
		cout << "\nHomeWork #10-2 (class Strings)\n";

		TMyBitString bitstr1 = TMyBitString("1234");
		cout << "BitString init by constructor: ";
		cout << bitstr1;
		cout << "\n";
		bitstr1 = "1001";
		cout << "BitString init by constructor: ";
		cout << bitstr1;
		cout << "\n";



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
		str1.Clear();
		cout << "String cleared: " << str1;
		TMyString str2 = TMyString("=_+_+_=");
		TMyString str3 = TMyString("000000888888");
		cout << "\n";
		cout << "String str2: " << str2;

		cout << "\n";
		str1 = str2;
		cout << "String assigned str1=str2: " << str1;

		cout << "\n";
		str1.MyStrCat("--------------");
		cout << "String cat: " << str1;
		str1 = str3 + str2;
		cout << "\n";
		cout << "String str1 = str3 + str2: " << str1;
		str1 += str3;
		cout << "\n";
		cout << "String str3: " << str3;
		cout << "\n";
		cout << "String str1+=str3: " << str1;

		cout << "\n";
		cout <<"str1==str2 " <<(bool)(str1 != str2);
		str1 = "12345";
		cout << "\n";
		cout << "str1==12345 " << (bool)(str1 == "12345");


		cout << "\n";
		system("Pause");
	}

}
