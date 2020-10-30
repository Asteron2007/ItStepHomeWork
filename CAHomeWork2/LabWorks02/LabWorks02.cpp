#include <iostream>
#include <malloc.h>
#include <cassert> 

#include <fstream>
#include <string>
#include <sstream>
#include <stdarg.h>

using namespace std;
template<class T>


/*
class Fraction
{
public:
	Fraction(int numerator = 0, int denominator = 1) 
	{
		this->denominator = denominator;
		this->numerator = numerator;
	}
	~Fraction();
	friend ostream& operator <<(ostream& out, const Fraction& f)
	{
//		out << f.numerator << "/" << f.denominator;
//		return &out;
	}
private:
	int numerator;
	int denominator;
};

Fraction::~Fraction()
{
}




class tStudent
{
private:
	char FIO[128] = "";
	char BirthDay[128] = "";
	char Phone[128] = "";
	char* pCity = NULL;
	char Land[128] = "";
	char CollegeName[128] = "";
	char CollegeCity[128] = "";
	char CollegeLand[128] = "";
	char CollegeGroupNumber[128] = "";


public:
	tStudent() 
	{
		pCity = (char*)malloc(sizeof(char) * 1);
		pCity[0] = '\0';
	}
	tStudent(const char* aFIO, const char* aBirthDay, const char* aPhone, const char* apCity, const char* aLand,
		const char* aCollegeName, const char* aCollegeCity, const char* aCollegeLand, const char* aCollegeGroupNumber)
	{
		setFIO(aFIO);
		//setBirthDay(aBirthDay);
		setPhone(aPhone);
		setCity(apCity);
		//setLand(aLand);
		//setCollegeName(aCollegeName);
		//setCollegeCity(aCollegeCity);
		//setCollegeLand(aCollegeLand);
		//setCollegeGroupNumber(aCollegeGroupNumber);
	}

	inline char* getFIO();
	void setFIO(const char * pFIO);
	inline char* getPhone() 
	{
		return Phone;
	};
	void setPhone(const char* pPhone) 
	{
		for (size_t i = 0; i < strlen(pPhone); i++)
		{
			if (((pPhone[i] < '0') || (pPhone[i] > '9')) &&
				((pPhone[i] != ')')) && (pPhone[i] != '(') && (pPhone[i] != '-') && (pPhone[i] != '+'))
			{
				cout << pPhone << " - Incorrect phone number!\n";
				break;
			}
		}
		strcpy_s(Phone, pPhone);
	};

	inline char* getCity()
	{
		return pCity;
	};
	void setCity(const char* pCityName) 
	{
		pCity = (char*)realloc(pCity, sizeof(char) * ((strlen(pCityName)+1)));
		assert(pCity != NULL);
		strcpy_s(pCity, strlen(pCityName)+1, pCityName);
	};




	void Display();

	~tStudent()
	{
		cout<<"Destructor";
		free(pCity);
	}
};

char* tStudent::getFIO()
{
	return FIO;
}

void tStudent::setFIO(const char*  pFIO)
{
	size_t len = strlen(pFIO);
	strcpy_s(FIO, pFIO);
}

//void tStudent::tStudent(const char* aFIO, const char* aBirthDay, const char* aPhone, const char* apCity, const char* aLand,
//	const char* aCollegeName, const char* aCollegeCity, const char* aCollegeLand, const char* aCollegeGroupNumber);

void tStudent::Display()
{
	cout << "\n"; 
	std::cout << "FIO: " << FIO << "\n";
	std::cout << "BirthDay: " << BirthDay << "\n";
	std::cout << "Phone: " << Phone << "\n";
	std::cout << "City: " << pCity << "\n";
	std::cout << "Land: " << Land << "\n";
	std::cout << "CollegeName: " << CollegeName << "\n";	
	std::cout << "CollegeCity: " << CollegeCity << "\n";
	std::cout << "CollegeLand: " << CollegeLand << "\n";
	std::cout << "CollegeGroupNumber: " << CollegeGroupNumber << "\n";
	cout << "\n";

}



class tPoint
{
private:
	double x;
	double y;
	double z;
	char* pFileName = NULL;
public:
	tPoint()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	tPoint(double X, double Y, double Z, const char* pFileName)
	{
		x = X;
		y = Y;
		z = Z;
		setFileName(pFileName);
	}

	void setFileName(const char* FileName)
	{
		pFileName = (char*)realloc(pFileName, sizeof(char) * ((strlen(FileName) + 1)));
		assert(pFileName != NULL);
		strcpy_s(pFileName, strlen(pFileName) + 1, pFileName);
	}

	inline char* getFileName()
	{
		return pFileName;
	};

	int SaveToFile() 
	{
		ifstream ptrFile("PointData.txt");// C:\Users\Book\source\repos\CAHomeWork2

		if (ptrFile.is_open())
		{
			string line;//Строчка текста
//fputs("Пример использования функции fopen\n \n \n", ptrFile); // записать строку в файл
//			fout(x, ptrFile);
			while (getline(ptrFile, line))
			{
				string name, surname;
				int age, money;
				istringstream iss(line);
				//За раз всё считаем
				iss >> surname >> name >> age >> money;

			}
		}
		else
		{
			cout << "File is not open\n" << endl;
		}
			//Выведем наши данные
		/*
			cout << "Данные из строчки:" << endl;
			cout << "\tФамилия: " << surname << endl;
			cout << "\tИмя: " << name << endl;
			cout << "\tВозраст: " << age << endl;
			cout << "\tДеньги: " << money << endl;

			fputs(x, ptrFile);
			fputs(y, ptrFile);
			fputs(z, ptrFile);
		


			fclose(ptrFile);

			
		return 0;
	}
	
	int LoadFromFile()
	{
		ifstream ptrFile("PointData.txt");// C:\Users\Book\source\repos\CAHomeWork2

		if (ptrFile.is_open())
		{
			string line;//Строчка текста
//fputs("Пример использования функции fopen\n \n \n", ptrFile); // записать строку в файл
//			fout(x, ptrFile);
			while (getline(ptrFile, line))
			{
				string name, surname;
				int age, money;
				istringstream iss(line);
				//За раз всё считаем
				iss >> surname >> name >> age >> money;

			}
		}
		else
		{
			cout << "File is not open\n" << endl;
		}
		//Выведем наши данные
		/*
		cout << "Данные из строчки:" << endl;
		cout << "\tФамилия: " << surname << endl;
		cout << "\tИмя: " << name << endl;
		cout << "\tВозраст: " << age << endl;
		cout << "\tДеньги: " << money << endl;

		fputs(x, ptrFile);
		fputs(y, ptrFile);
		fputs(z, ptrFile);



		fclose(ptrFile);

		return 0;
	
	}


	~tPoint()
	{
		free(pFileName);
		cout << "Destructor complete.";
	}


};

*/

double average(int count, ...)
{
	double sum = 0;
	va_list list;
	va_start(list, count);

	int i = 1;
	while (true)
	{
		int arg = va_arg(list, int);
		if (arg == -1)
			break;
		sum += arg;
		i++;
	}
	return sum;
}

/*class TMyItem
{
public:
	TMyItem(int Value=0) 
	{
		this->Value = Value;
	}
	
	~TMyItem()
	{
		delete Next;
	}
	void setValue(int Value) 
	{
		this->Value = Value;
	}

	void setNextItem(TMyItem* Item)
	{
		Next = Item;
	}

	int getValue() 
	{
		return Value;
	}
	
	TMyItem* getNext()
	{
		return Next;
	}
private:
	int Value;
	TMyItem* Next;
};*/

struct TMyItem
{
	int Value;
	TMyItem* Next;
};

class TMyStack
{
public:
	TMyStack():size(0)
	{
		Head = NULL;
	}
	TMyStack(const TMyStack& Sender) : size(Sender.size)
	{
		Head = Sender.Head;
	}
	TMyStack (TMyStack&& Sender) : size(Sender.size)
	{
		Head = Sender.Head;
	}
	~TMyStack();

	//void push(TMyItem& Item);
	void push(int Value);

	//TMyItem pop();
	int pop();
	
	bool empty();

	int getSize() const 
	{
		return size;
	}

	void show();

private:
	int size;
	TMyItem* Head;
};

TMyStack::~TMyStack()
{
}

void TMyStack::push(int Value)
{
	TMyItem* newItem = new TMyItem;
	newItem->Next = Head;
	newItem->Value = Value;

	Head = newItem;
}

int TMyStack::pop()
{
	if (Head)
	{
		int Value = Head->Value;
		TMyItem* delItem = Head;
		Head = Head->Next;
		delete delItem;
		return Value;
	}	
}

bool TMyStack::empty()
{
	TMyItem* tmpItem = Head;
	if (!tmpItem)
	{
		return true;
	}
}

void TMyStack::show()
{
	TMyItem* tmpItem = Head;
	if (!tmpItem)
	{
		cout << "Stack is empty.\n";
		return;
	}
	while (tmpItem)
	{
		cout << tmpItem->Value<<"\n";
		tmpItem = tmpItem->Next;
	}
}

int main()
{	
	/*
	Fraction&& rref = Fraction(5, 6);
	cout << rref << "\n";
	int x = 7;
	x = 12;
	cout << x << "\n";


	tStudent Student;
	//tStudent Student= tStudent();
	Student.Display();
	cout <<"\n\n"<< Student.getFIO()<<"\n\n";
	Student.setFIO("Anderson");
	Student.setPhone("8(910)554-4321");
	Student.setCity("Arkhangelsk");
	//cout << "\n\n";
	Student.Display();
	Student.setPhone("8(910)554!4321");
	Student.setCity("");
	Student.Display();
*/

	//cout << average(5, 10, 10, 20, 01, 5);

	TMyStack MyStack;
	MyStack.show();

	MyStack.push(5);
	MyStack.show();
	
	MyStack.push(25);
	MyStack.show();

	MyStack.push(35);
	MyStack.show();

	MyStack.push(45);
	MyStack.show();

	if (!MyStack.empty())
	{
		cout << "Pop " << MyStack.pop() << "\n";
	}
	MyStack.show();
	
	if (!MyStack.empty())
	{
		cout << "Pop " << MyStack.pop() << "\n";
		
	}
	MyStack.show();
	
	if (!MyStack.empty())
	{
		cout << "Pop " << MyStack.pop() << "\n";
	}
	MyStack.show();
	
	if (!MyStack.empty())
	{
		cout << "Pop " << MyStack.pop() << "\n";
	}
	MyStack.show();
	
	if (!MyStack.empty())
		cout << "Pop " << MyStack.pop() << "\n";
	
	//cout << "Pop " << MyStack.pop() << "\n";
	MyStack.show();
	cout << "\n";
	system("pause");
}
