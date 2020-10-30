// HomeWork0002.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cassert> 
using namespace std;


//1.	Цифровой счетчик, это переменная с ограниченным
//диапазоном.Значение которой сбрасывается, когда
//ее целочисленное значение достигает определен -
//ного максимума(например, k принимает значения
//	в диапазоне от 0..100).В качестве примера такого
//	счетчика можно привести цифровые часы, счетчик
//	километража.Опишите класс такого счетчика.Обе -
//	спечьте возможность установления максимального
//	и минимального значений, увеличения счетчика на
//	1, возвращения текущего значения

class TMyCounter
{
public:
	TMyCounter(int Value = 0, int MinValue = 0, int MaxValue = 99)
	{
		SetMinValue(MinValue);
		SetMaxValue(MaxValue);
		SetValue(Value);
	};
	~TMyCounter()
	{

	};

	void SetMinValue(int NewValue)
	{
		if (NewValue <= MaxValue)
			MinValue = NewValue;
		return;
	};

	int GetMinValue()
	{
		return MinValue;
	};

	void SetMaxValue(int NewValue)
	{
		if (NewValue >= MinValue)
			MaxValue = NewValue;
		return;
	};

	int GetMaxValue()
	{
		return MaxValue;
	};

	void SetValue(int NewValue)
	{
		Value = NewValue;
		return;
	};

	int GetValue()
	{
		return Value;
	};

	void IncCounter(int Step = 1)
	{
		for (int i = 0; i < Step; i++)
		{
			if (Value < MaxValue)
				Value++;
			else
				Value = MinValue;
		}

		return;
	};

	void DecCounter(int Step = 1)
	{
		for (int i = 0; i < Step; i++)
		{
			if (Value > MinValue)
				Value--;
			else
				Value = MaxValue;
		}
		return;
	};

private:
	int Value = 0;
	int MinValue = 0;
	int MaxValue = 0;
};

//2.	Написать класс, описывающий группу студентов.Студент
	//	также реализуется с помощью соответствующего класса.
class TMyPeople //
{
public:
	TMyPeople();
	TMyPeople(char(&Name)[128], int BirthDay, int BirthMounth, int BirthYear);
	TMyPeople(const TMyPeople& Sender);
	~TMyPeople();
	void GetName(char(&Name)[128])
	{
		strcpy_s(Name, Name);
		return;
	}

	int GetBirthDay()
	{
		return BirthDay;
	}

	int GetBirthMounth()
	{
		return BirthMounth;
	}

	int GetBirthYear()
	{
		return BirthYear;
	}

	void SetBirthDay(int BirthDay)
	{
		this->BirthDay = BirthDay;
		return;
	}

	void SetBirthMounth(int BirthMounth)
	{
		this->BirthMounth = BirthMounth;
		return;
	}

	void SetBirthYear(int BirthYear)
	{
		this->BirthYear = BirthYear;
		return;
	}

	void SetName(const char Name[128])
	{
		strcpy_s(this->Name, Name);
		return;
	}

	void Show();
private:
	char Name[128];
	int BirthDay;
	int BirthMounth;
	int BirthYear;
};

TMyPeople::TMyPeople()
{
	SetName("NoName");
	SetBirthDay(1);
	SetBirthMounth(1);
	SetBirthYear(1);
}

TMyPeople::TMyPeople(char(&Name)[128], int BirthDay, int BirthMounth, int BirthYear)
{
	SetName(Name);
	//strcpy_s(this->Name, strlen(Name), Name);
	SetBirthDay(BirthDay);
	SetBirthMounth(BirthMounth);
	SetBirthYear(BirthYear);
}

TMyPeople::TMyPeople(const TMyPeople& Sender)
{
	SetName(Name);
	//strcpy_s(this->Name, strlen(Sender.pName), Sender.pName);
	SetBirthDay(Sender.BirthDay);
	SetBirthMounth(Sender.BirthMounth);
	SetBirthYear(Sender.BirthYear);
	//this->BirthDay = Sender.BirthDay;
	//this->BirthMounth = Sender.BirthMounth;
	//this->BirthYear = Sender.BirthYear;
}

TMyPeople::~TMyPeople()
{

}

void TMyPeople::Show()
{
	cout << Name << " " << BirthDay << "." << BirthMounth << "." << BirthYear << " ";
}


class TMyGroup
{
public:
	//	TMyGroup();
	TMyGroup(const int GroupNumber = 1)
	{
		SetGroupNumber(GroupNumber);
	}
	~TMyGroup();
	void AddStudent(TMyPeople& Student);
	void DelStudent(size_t Index);
	void InsStudent(size_t Index, TMyPeople& Student);
	void Show();
	void SetGroupNumber(int GroupNumber);
	int GetGroupNumber() const;
private:
	const size_t LimitStudentsCount = 30;
	int GroupNumber;
	size_t StudentCount = 0;
	TMyPeople Students[30];
};


TMyGroup::~TMyGroup()
{

}

void TMyGroup::AddStudent(TMyPeople& Student)
{
	InsStudent(StudentCount, Student);
	return;
}

void TMyGroup::DelStudent(size_t Index)
{
	if ((StudentCount > 0) && ((Index > 0) && (Index < StudentCount)))
	{
		--StudentCount;
		for (size_t i = Index; i < StudentCount; i++)
			Students[i] = Students[i + 1];
	}
	return;
}

void TMyGroup::InsStudent(size_t Index, TMyPeople& Student)
{
	if (StudentCount >= LimitStudentsCount)
	{
		cout << "Max count limit" << LimitStudentsCount << " reached\n";
		return;
	}
	if (Index < 0)
		Index = 0;

	if ((StudentCount == 0) || (Index >= StudentCount))
	{
		Index = StudentCount;
		Students[Index] = Student;
		StudentCount++;
		return;
	}
	else
	{
		for (size_t i = StudentCount - 1; i >= Index; i--)
		{
			Students[i + 1] = Students[i];
		}
		Students[Index] = Student;
		StudentCount++;
		return;
	}

	return;
}

void TMyGroup::Show()
{
	cout << "Group number: " << GroupNumber << "\n";
	for (size_t i = 0; i < StudentCount; i++)
	{
		cout << i + 1 << ". ";
		Students[i].Show();
		cout << "\n";
	}
}

void TMyGroup::SetGroupNumber(int GroupNumber)
{
	this->GroupNumber = GroupNumber;
	return;
}

int TMyGroup::GetGroupNumber()const
{
	return GroupNumber;
}

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

//Задание 2.
	//Создайте приложение «Телефонная книга».Необходимо
	//хранить данные об абоненте(ФИО, домашний телефон,
	//	рабочий телефон, мобильный телефон, дополнительная
	//	информация о контакте) внутри соответствующего класса.
	//Наполните класс переменными - членами, функциями -
	//членами, конструкторами, inline - функциями - членами,
	//используйте инициализаторы, реализуйте деструктор.
	//Обязательно необходимо выделять динамически память под
	//ФИО.Предоставьте пользователю возможность добавлять
	//новых абонентов, удалять абонентов, искать абонентов
	//по ФИО, показывать всех абонентов.
class TMyPhoneRec
{
public:
	TMyPhoneRec();
	TMyPhoneRec(const TMyPhoneRec& Sender);
	~TMyPhoneRec();

	TMyPhoneRec& operator=(const TMyPhoneRec&);


	void Show();
	void SetName(const char* Name);
	void SetHomePhone(const char* HomePhone);
	void SetWorkPhone(const char* WorkPhone);
	void SetCellPhone(const char* CellPhone);
	void SetNotes(const char* Notes);
	char* GetName() const;
	char* GetHomePhone() const;
	char* GetWorkPhone() const;
	char* GetCellPhone() const;
	char* GetNotes() const;

private:
	char* pName;
	char* HomePhone;
	char* WorkPhone;
	char* CellPhone;
	char* Notes;

};

TMyPhoneRec::TMyPhoneRec()
{
	pName = (char*)malloc(sizeof(char) * 1);
	pName[0] = '\0';
	HomePhone = (char*)malloc(sizeof(char) * 1);
	HomePhone[0] = '\0';
	WorkPhone = (char*)malloc(sizeof(char) * 1);
	WorkPhone[0] = '\0';
	CellPhone = (char*)malloc(sizeof(char) * 1);
	CellPhone[0] = '\0';
	Notes = (char*)malloc(sizeof(char) * 1);
	Notes[0] = '\0';
}

TMyPhoneRec::TMyPhoneRec(const TMyPhoneRec& Sender)
{
	if (&Sender != nullptr) 
	{
		pName = (char*)malloc(sizeof(char) * 1);
		pName[0] = '\0';
		HomePhone = (char*)malloc(sizeof(char) * 1);
		HomePhone[0] = '\0';
		WorkPhone = (char*)malloc(sizeof(char) * 1);
		WorkPhone[0] = '\0';
		CellPhone = (char*)malloc(sizeof(char) * 1);
		CellPhone[0] = '\0';
		Notes = (char*)malloc(sizeof(char) * 1);
		Notes[0] = '\0';

		SetName(Sender.GetName());
		SetHomePhone(Sender.GetHomePhone());
		SetWorkPhone(Sender.GetWorkPhone());
		SetCellPhone(Sender.GetCellPhone());
		SetNotes(Sender.GetNotes());
	}
}

TMyPhoneRec::~TMyPhoneRec()
{
	free(pName);
	free(HomePhone);
	free(WorkPhone);
	free(CellPhone);
	free(Notes);
}

TMyPhoneRec& TMyPhoneRec::operator=(const TMyPhoneRec& Sender)
{

	if (this == &Sender)
		return *this;
	
	pName = (char*)malloc(sizeof(char) * 1);
	pName[0] = '\0';
	HomePhone = (char*)malloc(sizeof(char) * 1);
	HomePhone[0] = '\0';
	WorkPhone = (char*)malloc(sizeof(char) * 1);
	WorkPhone[0] = '\0';
	CellPhone = (char*)malloc(sizeof(char) * 1);
	CellPhone[0] = '\0';
	Notes = (char*)malloc(sizeof(char) * 1);
	Notes[0] = '\0';

	SetName(Sender.GetName());
	SetHomePhone(Sender.GetHomePhone());
	SetWorkPhone(Sender.GetWorkPhone());
	SetCellPhone(Sender.GetCellPhone());
	SetNotes(Sender.GetNotes()); 
	
	return *this;

}

void TMyPhoneRec::Show()
{
	cout << "Name: " << pName;
	cout << "\tHomePhone: " << HomePhone;
	cout << "\tWorkPhone: " << WorkPhone;
	cout << "\tCellPhone: " << CellPhone;
	cout << "\nNotes: " << Notes;
	cout << "\n";
}

void TMyPhoneRec::SetName(const char* Name)
{
	pName = (char*)realloc(pName, sizeof(char) * ((strlen(Name) + 1)));
	assert(pName != NULL);
	strcpy_s(pName, strlen(Name) + 1, Name);
}

void TMyPhoneRec::SetHomePhone(const char* HomePhone)
{
	this->HomePhone = (char*)realloc(this->HomePhone, sizeof(char) * ((strlen(HomePhone) + 1)));
	assert(this->HomePhone != NULL);
	strcpy_s(this->HomePhone, strlen(HomePhone) + 1, HomePhone);
}

void TMyPhoneRec::SetWorkPhone(const char* WorkPhone)
{
	this->WorkPhone = (char*)realloc(this->WorkPhone, sizeof(char) * ((strlen(WorkPhone) + 1)));
	assert(this->WorkPhone != NULL);
	strcpy_s(this->WorkPhone, strlen(WorkPhone) + 1, WorkPhone);
}

void TMyPhoneRec::SetCellPhone(const char* CellPhone)
{
	this->CellPhone = (char*)realloc(this->CellPhone, sizeof(char) * ((strlen(CellPhone) + 1)));
	assert(this->CellPhone != NULL);
	strcpy_s(this->CellPhone, strlen(CellPhone) + 1, CellPhone);
}

void TMyPhoneRec::SetNotes(const char* Notes)
{
	this->Notes = (char*)realloc(this->Notes, sizeof(char) * ((strlen(Notes) + 1)));
	assert(this->Notes != NULL);
	strcpy_s(this->Notes, strlen(Notes) + 1, Notes);
}

char* TMyPhoneRec::GetName() const
{
	return this->pName;
}

char* TMyPhoneRec::GetHomePhone() const
{
	return this->HomePhone;
}

char* TMyPhoneRec::GetWorkPhone() const
{
	return this->WorkPhone;
}

char* TMyPhoneRec::GetCellPhone() const
{
	return this->CellPhone;
}

char* TMyPhoneRec::GetNotes() const
{
	return this->Notes;
}

class TMyPhoneBook
{
public:
	TMyPhoneBook();
	~TMyPhoneBook();

	void AddRec(const TMyPhoneRec& PhoneRec);
	void DelRec(size_t Index);
	void InsRec(size_t Index, const TMyPhoneRec& PhoneRec);
	
	void Show();

private:
	const size_t LimitRecCount = 500;
	TMyPhoneRec* Records;
	size_t RecCount;
};

TMyPhoneBook::TMyPhoneBook()
{
	RecCount = 0;
	//Records = (TMyPhoneRec*)malloc(sizeof(TMyPhoneRec) * RecCount);
	//assert(Records != NULL);

	//Динамическое выделение памяти под массив
	//объектов типа Point
	Records = new TMyPhoneRec[RecCount+1];
	//проверка, выделилась ли память
	//и выход, если не выделилась
	if (!Records) exit(0);
}

TMyPhoneBook::~TMyPhoneBook()
{
	//free(Records);
	delete[]Records;
	RecCount = 0;
}

void TMyPhoneBook::AddRec(const TMyPhoneRec& PhoneRec)
{
	InsRec(RecCount, PhoneRec);
	return;
}

void TMyPhoneBook::DelRec(size_t Index)
{	
	if ((RecCount > 0) && ((Index >= 0) && (Index < RecCount)))
	{
		--RecCount;
		for (size_t i = Index; i < RecCount; i++)
			Records[i] = Records[i + 1];
		//	Records = (TMyPhoneRec*)realloc(Records, sizeof(TMyPhoneRec) * RecCount);
		TMyPhoneRec* tmp = new TMyPhoneRec[RecCount + 1];

		for (size_t i = 0; i < RecCount; i++)
			tmp[i] = Records[i];
		
		delete[]Records;
		Records = tmp;
	}
	return;
}

void TMyPhoneBook::InsRec(size_t Index, const TMyPhoneRec& PhoneRec)
{
	if (&PhoneRec != nullptr)
	{	
		if (RecCount >= LimitRecCount)
		{
			cout << "Max count limit" << LimitRecCount << " reached\n";
			return;
		}
		if (Index < 0)
			Index = 0;

		if ((RecCount == 0) || (Index >= RecCount))
		{
			
			RecCount++;
			TMyPhoneRec* tmp = new TMyPhoneRec[RecCount + 1];

			for (size_t i = 0; i < RecCount; i++)
				tmp[i] = Records[i];

			delete[]Records;
			Records = tmp;
			Index = RecCount-1;

			Records[Index] = PhoneRec;
			return;
		}
		else
		{
			RecCount++;
			//Records = (TMyPhoneRec*)realloc(Records, sizeof(TMyPhoneRec) * (RecCount));
			TMyPhoneRec* tmp = new TMyPhoneRec[RecCount + 1];

			for (size_t i = 0; i < RecCount; i++)
				tmp[i] = Records[i];

			delete[]Records;
			Records = tmp;
			
			for (size_t i = RecCount - 1; i > Index; i--)
			{
				if (RecCount > i)
					Records[i] = Records[i-1];
				else
					break;			
			}
			
			Records[Index] = PhoneRec;

			return;
		}

		return;
	}
}

void TMyPhoneBook::Show()
{
	for (size_t i = 0; i < RecCount; i++)
	{
		cout << "Index [" << i << "]:\t";
		Records[i].Show();
	}
}



//Создайте программу, имитирующую многоквартирный
//дом.Необходимо иметь классы «Человек», «Квартира»,
//«Дом».Класс «Квартира» содержит динамический массив
//объектов класса «Человек».Класс «Дом» содержит массив
//объектов класса «Квартира».
class TFlat
{
public:
	TFlat();
	TFlat(const TFlat& People);
	~TFlat();
	void SetNumber(int Num);
private:
	char* Num;
	TMyPeople* Peoples;
	size_t PeopleCount;
};

TFlat::TFlat()
{
	PeopleCount = 0;
}

TFlat::TFlat(const TFlat& People)
{
}

TFlat::~TFlat()
{
	for (size_t i = 0; i < PeopleCount; i++)
	{
	//	free Peoples[i];
	}
}

void TFlat::SetNumber(int Num)
{

}








int main()
{
	system("chcp 1251");  // переходим на русский язык в консоли

	{
		system("CLS");
		cout << "\nHomeWork #1. Task #1 (COUNTER)\n";

		TMyCounter counter100 = TMyCounter();

		TMyCounter counter60 = TMyCounter(0, 0, 59);

		for (int i = 0; i < counter100.GetMaxValue() * 2 + 10; i++)
		{
			cout << "Counter100.GetValue(): " << counter100.GetValue() << "\n";
			counter100.IncCounter();
		}

		for (int i = 0; i < counter60.GetMaxValue() * 2 + 10; i++)
		{
			cout << "Counter60.GetValue(): " << counter60.GetValue() << "\n";
			counter60.IncCounter(7);
		}

		for (int i = 0; i < counter60.GetMaxValue() * 2 + 10; i++)
		{
			cout << "Counter60.GetValue(): " << counter60.GetValue() << "\n";
			counter60.DecCounter(2);
		}

		cout << "\n";
		system("Pause");
	}

	//2.	Написать класс, описывающий группу студентов.Студент
	//	также реализуется с помощью соответствующего класса.
	{
		system("CLS");
		cout << "\nHomeWork #1. Task #2 (CLASS and STUDENT)\n";

		TMyGroup Group;
		TMyPeople Student;

		Student.SetName("Ivanov");
		Student.SetBirthDay(1);
		Student.SetBirthMounth(03);
		Student.SetBirthYear(1980);
		cout << "Add new student\n";
		Group.AddStudent(Student);
		Group.Show();

		Student.SetName("Sidoroff");
		Student.SetBirthDay(2);
		Student.SetBirthMounth(04);
		Student.SetBirthYear(1981);
		cout << "Add new student\n";
		Group.AddStudent(Student);
		Group.Show();

		Student.SetName("Trifonov");
		Student.SetBirthDay(3);
		Student.SetBirthMounth(02);
		Student.SetBirthYear(1982);
		cout << "Add new student\n";
		Group.AddStudent(Student);
		Group.Show();

		Student.SetName("Borisov");
		Student.SetBirthDay(4);
		Student.SetBirthMounth(02);
		Student.SetBirthYear(1982);
		cout << "Insert student by index 1 \n";
		Group.InsStudent(1, Student);
		Group.Show();

		cout << "Delete student by index 2 \n";
		Group.DelStudent(2);
		Group.Show();

		cout << "\n";
		system("Pause");
	}

	//Задание 1.
	//	Реализуйте класс Дробь.Необходимо хранить числитель
	//	и знаменатель в качестве переменных - членов.Реализуйте
	//	функции - члены для ввода данных в переменные - члены,
	//	для выполнения арифметических операций(сложение,
	//		вычитание, умножение, деление, и т.д.).

	{
		system("CLS");
		cout << "\nHomeWork #1. Task #3 (FRACTION)\n";

		TFraction A(5, 7);
		TFraction B;
		B.SetNumerator(6);
		B.SetDenominator(8);
		cout << "\n";
		A.Show(); cout << " + "; B.Show();  cout << " = ";
		TFraction C = A.Add(B);
		C.Show();
		cout << "\n";
		C = A.Sub(B);
		A.Show(); cout << " - "; B.Show();  cout << " = "; C.Show();
		cout << "\n";
		C = A.Mult(B);
		A.Show(); cout << " * "; B.Show();  cout << " = "; C.Show();
		cout << "\n";
		C = A.Div(B);
		A.Show(); cout << " / "; B.Show();  cout << " = "; C.Show();

		cout << "\n";
		system("Pause");
	}


	//Задание 2.
	//Создайте приложение «Телефонная книга».Необходимо
	//хранить данные об абоненте(ФИО, домашний телефон,
	//	рабочий телефон, мобильный телефон, дополнительная
	//	информация о контакте) внутри соответствующего класса.
	//Наполните класс переменными - членами, функциями -
	//членами, конструкторами, inline - функциями - членами,
	//используйте инициализаторы, реализуйте деструктор.
	//Обязательно необходимо выделять динамически память под
	//ФИО.Предоставьте пользователю возможность добавлять
	//новых абонентов, удалять абонентов, искать абонентов
	//по ФИО, показывать всех абонентов.

	{
		system("CLS");
		cout << "\nHomeWork #1. Task #4 (Phone book)\n";

		TMyPhoneRec tmpPhoneRec;
		TMyPhoneBook PhoneBook;
		
		cout << "Add new rec\n";
		tmpPhoneRec.SetHomePhone("4-23-40");
		tmpPhoneRec.SetName("Alisa");
		tmpPhoneRec.SetCellPhone("89105544321");
		tmpPhoneRec.SetNotes("It's my friend1");
		tmpPhoneRec.SetWorkPhone("4-17-73");
		PhoneBook.AddRec(tmpPhoneRec);
		PhoneBook.Show();
		cout << "\n";

		cout << "Insert new rec (index[0])\n";
		tmpPhoneRec.SetHomePhone("+7 4-23-40");
		tmpPhoneRec.SetName("Galina 2");
		tmpPhoneRec.SetCellPhone("+79105544321");
		tmpPhoneRec.SetNotes("It's my new friend2");
		tmpPhoneRec.SetWorkPhone("+7 4-17-73");
		PhoneBook.InsRec(0, tmpPhoneRec);
		PhoneBook.Show();
		cout << "\n";

		cout << "Insert new rec (index[1])\n";
		tmpPhoneRec.SetHomePhone("+1 4-23-40");
		tmpPhoneRec.SetName("Galina New");
		tmpPhoneRec.SetCellPhone("+19105544321");
		tmpPhoneRec.SetNotes("It's my new friend3");
		tmpPhoneRec.SetWorkPhone("+1 4-17-73");
		PhoneBook.InsRec(1, tmpPhoneRec);
		PhoneBook.Show();
		cout << "\n";

		cout << "Add new rec\n";
		tmpPhoneRec.SetHomePhone("+1 4-23-40");
		tmpPhoneRec.SetName("Marina New");
		tmpPhoneRec.SetCellPhone("+19105544321");
		tmpPhoneRec.SetNotes("It's my new friend4");
		tmpPhoneRec.SetWorkPhone("+1 4-17-73");
		PhoneBook.AddRec(tmpPhoneRec);
		PhoneBook.Show();
		cout << "\n";

		cout << "Delete rec (index[4])\n";
		PhoneBook.DelRec(4);
		PhoneBook.Show();
		cout << "\n";

		cout << "Delete rec (index[0])\n";
		PhoneBook.DelRec(0);
		PhoneBook.Show();
		cout << "\n";

		cout << "Delete rec (index[1])\n";
		PhoneBook.DelRec(1);
		PhoneBook.Show();
		cout << "\n";

		cout << "\n";
		system("Pause");
	}

	/*
	Задание 1.
		Создайте программу, имитирующую многоквартирный
		дом.Необходимо иметь классы «Человек», «Квартира»,
		«Дом».Класс «Квартира» содержит динамический массив
		объектов класса «Человек».Класс «Дом» содержит массив
		объектов класса «Квартира».
		Каждый из классов содержит переменные - члены и функ -
		ции - члены, которые необходимы для предметной области
		класса.Обращаем ваше внимание, что память под стро -
		ковые значения выделяется динамически.Например, для
		ФИО в классе «Человек».Не забывайте обеспечить классы
		различными конструкторами(конструктор копирования
			обязателен), деструкторами.В main протестировать ра -
		боту полученного набора классов.
		Задание 2.
		Разработать класс Reservoir(водоем).Класс должен обяза -
		тельно иметь поле «название».Класс должен содержать :
	конструктор по умолчанию, конструктор с параметрами,
		при необходимости реализовать деструктор и конструк -
		тор копирования.
		Добавить методы для :
	1. Определения приблизительного объема(ширина *
		длина * максимальная глубина);
	Домашнее задание №2 2. Определения площади водной поверхности;
	3. Метод для проверки относятся ли водоемы к одному
		типу(море - море; бассейн - пруд);
	4. Для сравнения площади водной поверхности водоемов
		одного типа;
	5. Для копирования объектов;
	6. Остальные методы на усмотрение разработчика(ме -
		тоды set и get).
		Написать интерфейс для работы с классом.Реализовать
		динамический массив объектов класса с возможностью
		добавления, удаления объектов из массива.
	*/

	//Задание 3.
	//	Разработать класс String, который в дальнейшем будет
	//	использоваться для работы со строками.Класс должен
	//	содержать :
	//• Конструктор по умолчанию, позволяющий создать
	//	строку длиной 80 символов;
	//• Конструктор, позволяющий создавать строку произ -
	//	вольного размера;
	//• Конструктор, который создаёт строку и инициализи -
	//	рует её строкой, полученной от пользователя.
	//	• Необходимо создать деструктор, а также использовать
	//	механизмы делегирования конструкторов, если это
	//	возможно.
	//	• Класс должен содержать методы для ввода строк с кла -
	//	виатуры и вывода строк на экран.
		
	{
		system("CLS");
		cout << "\nHomeWork #1. Task #3 (class Strings)\n";



		cout << "\n";
		system("Pause");
	}

	return 0;
}
