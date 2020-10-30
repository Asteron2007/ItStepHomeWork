// HomeWork0003.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cassert> 

using namespace std;

class TComplex
{
public:
	TComplex(double re = 0, double im = 0) 
	{
		this->re = re;
		this->im = im;
	}
	~TComplex()
	{

	}

	void Display()
	{
		cout << " " << re << " + " << im << "i ";
	}

	TComplex summ(const TComplex& A)
	{
		TComplex C;
		C.im = this->im + A.im;
		C.re = this->re + A.re;
		return C;
	}
	TComplex operator+(TComplex& A)
	{		
		TComplex tmp = this->summ(A);
		return tmp;
	}
	TComplex subt(const TComplex& A)
	{
		TComplex C;
		C.im = this->im - A.im;
		C.re = this->re - A.re;
		return C;
	}
	TComplex operator-(TComplex& A)
	{
		TComplex tmp = this->subt(A);
		return tmp;
	}
	TComplex mult(const TComplex& A)
	{
		TComplex C;
		C.im = this->im * A.re + this->re * A.im;
		C.re = this->re * A.re - this->im * A.im;
		return C;
	}
	TComplex operator*(TComplex& A)
	{
		TComplex tmp = this->mult(A);
		return tmp;
	}

	TComplex div(const TComplex& A)
	{
		TComplex C;
		if ((A.im == 0) || (A.re == 0))
		{
			cout << "Error! Division by zero";
			C.im = this->im;
			C.re = this->re;
		}
		else
		{
			C.im = (this->im * A.re - this->re * A.im) / (A.im * A.im + A.re * A.re);
			C.re = (this->re * A.re + this->im * A.im) / (A.im * A.im + A.re * A.re);
		}
		return C;
	}
	TComplex operator/(TComplex& A)
	{
		TComplex tmp = this->div(A);
		return tmp;
	}

private:
	double re;
	double im;

};




class TFraction
{
public:
	TFraction(int Numerator = 0, int Denominator = 1)
	{
		SetNumerator(Numerator);
		SetDenominator(Denominator);
	}
	TFraction(const TFraction& Sender)
	{
		SetNumerator(Sender.Numerator);
		SetDenominator(Sender.Denominator);
	}
	~TFraction();

	void Show();
	void SetNumerator(int Numerator);
	void SetDenominator(int Denominator);
	int GetDenominator() const;
	int GetNumerator() const;

	TFraction Div(const TFraction& Sender);
	TFraction Add(const TFraction& Sender);
	TFraction Mult(const TFraction& Sender);
	TFraction Sub(const TFraction& Sender);

	TFraction& operator++()
	{
		this->Numerator += this->Denominator;
		return *this;
	}

	TFraction& operator--()
	{
		this->Numerator -= this->Denominator;
		return *this;
	}
private:
	int Numerator;
	int Denominator;
};


TFraction::~TFraction()
{
}

void TFraction::Show()
{
	cout << Numerator << "/" << Denominator;
}

void TFraction::SetNumerator(int Numerator)
{
	this->Numerator = Numerator;
}

void TFraction::SetDenominator(int Denominator)
{
	if (Denominator != 0)
		this->Denominator = Denominator;
	else
		cout << "Division by zero";
}

int TFraction::GetDenominator() const
{
	return Denominator;
}

int TFraction::GetNumerator() const
{
	return Numerator;
}

TFraction TFraction::Div(const TFraction& Sender)
{
	TFraction tmp;
	tmp.Numerator = this->Numerator * Sender.Denominator;
	tmp.Denominator = this->Denominator * Sender.Numerator;
	return tmp;
}

TFraction operator /(TFraction A, TFraction B)
{
	TFraction tmp = A.Div(B);
	return tmp;
};

TFraction TFraction::Add(const TFraction& Sender)
{
	TFraction tmp;
	tmp.Numerator = this->Numerator * Sender.Denominator + this->Denominator * Sender.Numerator;
	tmp.Denominator = this->Denominator * Sender.Denominator;
	return tmp;
}

TFraction operator +(TFraction A, TFraction B)
{
	TFraction tmp = A.Add(B);
	return tmp;
};

TFraction TFraction::Mult(const TFraction& Sender)
{
	TFraction tmp;
	tmp.Numerator = this->Numerator * Sender.Numerator;
	tmp.Denominator = this->Denominator * Sender.Denominator;
	return tmp;
}
TFraction operator *(TFraction A, TFraction B)
{
	TFraction tmp = A.Mult(B);
	return tmp;
};

TFraction TFraction::Sub(const TFraction& Sender)
{
	TFraction tmp;
	tmp.Numerator = this->Numerator * Sender.Denominator - this->Denominator * Sender.Numerator;
	tmp.Denominator = this->Denominator * Sender.Denominator;
	return tmp;
}

TFraction operator -(TFraction A, TFraction B)
{
	TFraction tmp = A.Sub(B);
	return tmp;
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

	TMyString(const char* Name)
	{
		pStr = (char*)malloc(sizeof(char) * ((MyStrLen(Name) + 1)));
		assert(pStr != NULL);
		strcpy_s(pStr, MyStrLen(Name) + 1, Name);		
	}

	~TMyString()
	{
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
			return pStr[MyStrLen()-1];
	}

	int operator()(const char sym)
	{
		for (size_t i = 0; i < MyStrLen(); i++)
		{
			if (pStr[i]==sym)
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
		pStr[tmpLen-1] = '\0';
		return *this;
	}
	
	TMyString& operator+(const TMyString* str)
	{
		//надо дописать
		return *this;

	}
	// надо править
	char* MyStrCat(char* str1, const char* str2)
	{
		size_t len1 = MyStrLen(str1);
		for (size_t i = 0; i <= MyStrLen(str2); i++)
		{
			str1[len1 + i] = str2[i];
		}
		return &*str1;
	}

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


int main()
{
   /*
   Задание 1.
Создайте программу, имитирующую многоквартирный дом. Необходимо иметь классы «Человек», «Квартира», «Дом». Класс «Квартира» содержит динамический массив объектов класса «Человек». Класс «Дом» содержит массив объектов класса «Квартира».
Каждый из классов содержит переменные-члены и функции-члены, которые необходимы для предметной области класса. Обращаем ваше внимание, что память под строковые значения выделяется динамически. Например, для ФИО в классе «Человек». Не забывайте обеспечить классы различными конструкторами (конструктор копирования обязателен), деструкторами. В main протестировать работу полученного набора классов.

Задание 2.
Разработать класс String, который в дальнейшем будет использоваться для работы со строками. Класс должен содержать:
•	 Конструктор по умолчанию, позволяющий создать строку длиной 80 символов;
•	 Конструктор, позволяющий создавать строку произвольного размера;
•	 Конструктор, который создаёт строку и инициализирует её строкой, полученной от пользователя.
•	 Необходимо создать деструктор, а также использовать механизмы делегирования конструкторов, если это возможно.
•	 Класс должен содержать методы для ввода строк с клавиатуры и вывода строк на экран.

Тема: Перегрузка операторов
Задание 1.
Создайте класс Дробь (или используйте уже ранее созданный вами).
Используя перегрузку операторов реализуйте для него арифметические операции для работы с дробями
(операции +, -, *, /).

Задание 2.
Создайте класс Complex (комплексное число) или используйте уже созданный вами класс. 
Создайте перегруженные операторы для реализации арифметических операций для по работе с комплексными числами 
(операции +, -, *, /).



Задание 1.
В ранее созданный класс String добавьте перегрузку [], (), преобразования типа к int 
¦ [] — возвращает элемент по указанному индексу;
¦ () — ищет символ в строке, если символ есть возвращает индекс, если нет -1.
Преобразование к int возвращает длину строки 
Реализуйте операцию инкеремента. Она должна увеличивать длину строки на единицу. Новый символ заполняется пробелом.
Реализуйте операцию декремента. Она должна уменьшать длину строки на единицу.
Задание 2.
В уже существующий класс Дробь добавьте перегрузку инкремента и декремента.
   */
	{
		system("CLS");
		cout << "\nHomeWork #3. Task #1 (class Complex)\n";

		TComplex A(4, 6);
		TComplex B(1, 5);
		cout << "A = "; A.Display();
		cout << "\n";
		cout << "B = "; B.Display();
		cout << "\n";

		TComplex C = A + B;
		cout << "C = A + B = "; C.Display();
		cout << "\n";
		C = A - B;
		cout << "C = A - B = "; C.Display();
		cout << "\n";

		C = A / B;
		cout << "C = A / B = "; C.Display();
		cout << "\n";

		C = A * B;
		cout << "C = A * B = "; C.Display();
		cout << "\n";

		cout << "\n";
		system("Pause");
	}

	{
		system("CLS");
		cout << "\nHomeWork #3. Task #1 (class Fraction)\n";

		TFraction A(5, 7);
		TFraction B;
		B.SetNumerator(6);
		B.SetDenominator(8);
		cout << "\n";
		A.Show(); cout << " + "; B.Show();  cout << " = ";
		TFraction C = A.Add(B);
		C.Show();
		cout << "\n";
		A.Show(); cout << " + "; B.Show();  cout << " = ";
		C = A + B;
		C.Show();
		cout << "\n";

		C = A.Sub(B);
		A.Show(); cout << " - "; B.Show();  cout << " = "; C.Show();
		cout << "\n";
		C = A - B;
		A.Show(); cout << " - "; B.Show();  cout << " = "; C.Show();
		cout << "\n";

		C = A.Mult(B);
		A.Show(); cout << " * "; B.Show();  cout << " = "; C.Show();
		cout << "\n";
		C = A * B;
		A.Show(); cout << " * "; B.Show();  cout << " = "; C.Show();
		cout << "\n";
		
		C = A.Div(B);
		A.Show(); cout << " / "; B.Show();  cout << " = "; C.Show();
		cout << "\n";
		C = A / B;
		A.Show(); cout << " / "; B.Show();  cout << " = "; C.Show();
		cout << "\n";
		
		A.Show(); cout << "++ = "; (++A).Show();
		cout << "\n";
		
		A.Show(); cout << "-- = "; (--A).Show();
		cout << "\n";

		cout << "\n";
		system("Pause");
	}
	
	
	{
		system("CLS");
		cout << "\nHomeWork #3. Task #2 (class Strings)\n";

		TMyString str1 = TMyString("Hello!");		
		cout << "String init by constructor: ";
		cout << str1;
		cout << "\n";
		cout << str1[0]<<str1[4]<<str1[4444];
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
