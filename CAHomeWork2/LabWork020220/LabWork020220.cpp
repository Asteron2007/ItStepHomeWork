// LabWork020220.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class Parent
{
public:
protected:
	int Val;
public:
	Parent(int v = 0) : Val(v) {};
	~Parent() 
	{
		cout << "Destruct Parent\n";
	}
	virtual int getValue()
	{
		return Val;
	}
	virtual const char* getName()
	{
		return "Parent\n";
	}

};


class Child :public Parent
{
protected:
	int y;
public:
	Child(int v): Parent(v)	{}
	~Child() 
	{}
	virtual int getValue()
	{
		return Val*2;
	}
	virtual const char* getName()
	{
		return "Child\n";
	}
private:

};


int main()
{
	Child ch(7);	
	cout << ch.getName() << " "<< ch.getValue();

	Child& chs = ch;
	cout << chs.getName() << " " << chs.getValue();

	Child* chp = &ch;
	cout << chp->getName() << " " << chp->getValue();

	Parent* par = &ch;
	cout << par->getName() << " " << par->getValue();

}