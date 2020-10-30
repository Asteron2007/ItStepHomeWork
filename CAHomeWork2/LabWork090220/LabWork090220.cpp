// LabWork090220.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>



using namespace std;

/*class IErrorLog
{
public:
	IErrorLog();
	~IErrorLog();
	virtual void WriteLog();
	virtual void WriteLog();
	virtual void WriteLog();
	virtual void WriteLog();

private:

};

IErrorLog::IErrorLog()
{
}

IErrorLog::~IErrorLog()
{
}


int MyFunc(int n, IErrorLog& log)
{
	if (n == 0)
	{
		log.WriteLog("Error");
		return 0;
	}
	else
	{
		return n * n;
	}
}



*/
//-------------------------------------


class Device
{
public:
	Device(int pow=0)
	{
		cout << "Device " << pow << "\n";
	}
	~Device() {};

private:

};

class Scaner : virtual public Device
{
public:
	Scaner(int pow, int scan): Device(pow)
	{
		cout << "Scaner " << scan <<" " <<pow << "\n";
	}
	~Scaner() {};

private:

};

class Printer : virtual public Device
{
public:
	Printer(int pow, int printer): Device(pow)
	{
		cout << "Printer " << printer << " " << pow << "\n";
	}
	~Printer() {};

private:

};

class Copier : public Printer, public Scaner
{
public:
	Copier(int pow, int printer, int scaner) :Printer(pow, printer), Scaner(pow, scaner), Device(pow)
	{
		cout << "Copier " << "copier" << " " << pow << "\n";
	}
	~Copier() {};

private:

};


int main()
{
	vector<int> vect;

	for (size_t i = 0; i < 5; i++)
	{
		vect.push_back(i + 1);
	}

	for (size_t i = 0; i < vect.size(); i++)
	{
		cout<< vect[i];
	}
	cout << "\n";

	deque<int> deq;
	for (size_t i = 0; i < 5; i++)
	{
		deq.push_back(i + 1);
		deq.push_front(10 - i);
	}

	for (size_t i = 0; i < deq.size(); i++)
	{
		cout << deq[i];
	}
	cout << "\n";

	vector<int>::const_iterator it;
	it =vect.begin();
	while (it!=vect.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << "\n";

	set<int> myset;

	myset.insert(11);
	myset.insert(121);
	myset.insert(411);
	myset.insert(7161);
	myset.insert(411);
	myset.insert(511);
	myset.insert(2);

	set<int>::iterator setit;
	setit = myset.begin();
	while (setit != myset.end())
	{
		cout << *setit << " ";
		setit++;
	}
	cout << "\n";

	map<string, string> mymap;
	mymap.insert(make_pair("name", "maxim"));
	mymap.insert(make_pair("age", "46"));
	mymap.insert(make_pair("adress", "tula"));
	mymap.insert(make_pair("prof", "IT"));

	map<string, string>::iterator mit;
	mit = mymap.begin();
	while (mit!=mymap.end())
	{
		cout << mit->first << " = " << mit->second << "\n";
		mit++;
	}







	//Copier copy(1, 2, 3);



//	FileErrorLog flog;
//	ScrErrorLog slog;

//	MyFunc(2, slog);
//	MyFunc(0, slog);
}
