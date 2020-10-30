// HomeWork0001.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
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
	int Value=0;
	int MinValue=0;
	int MaxValue=0;
};

//2.	Написать класс, описывающий группу студентов.Студент
	//	также реализуется с помощью соответствующего класса.
class TMyPeople //
{
public:
	TMyPeople();
	TMyPeople(char(&Name)[128], int BirthDay, int BirthMounth, int BirthYear);
	TMyPeople(const TMyPeople &Sender);
	~TMyPeople();
	void GetName(char(& Name)[128])
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
		this->BirthMounth=BirthMounth;
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

void TMyGroup::AddStudent(TMyPeople &Student)
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
			Students[i] = Students[i+1];
	}
	return;
}

void TMyGroup::InsStudent(size_t Index, TMyPeople& Student)
{
	if (StudentCount >= LimitStudentsCount)
	{
		cout<<"Max count limit"<<LimitStudentsCount <<" reached\n";
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
	TFraction(const TFraction &Sender)
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

	TFraction Div(const TFraction &Sender);
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

TFraction TFraction::Add(const TFraction& Sender)
{
	TFraction tmp;
	tmp.Numerator = this->Numerator * Sender.Denominator + this->Denominator * Sender.Numerator;
	tmp.Denominator = this->Denominator * Sender.Denominator;
	return tmp;
}

TFraction TFraction::Mult(const TFraction& Sender)
{
	TFraction tmp;
	tmp.Numerator = this->Numerator * Sender.Numerator;
	tmp.Denominator = this->Denominator * Sender.Denominator;
	return tmp;
}

TFraction TFraction::Sub(const TFraction& Sender)
{
	TFraction tmp;
	tmp.Numerator = this->Numerator * Sender.Denominator - this->Denominator * Sender.Numerator;
	tmp.Denominator = this->Denominator * Sender.Denominator;
	return tmp;
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


	return 0;
}
