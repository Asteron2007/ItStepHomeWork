// HomeWork0010-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

class TMyPoint
{
public:
	TMyPoint(int X = 0, int Y = 0)
	{
		setX(X);
		setY(Y);
		setName("Point");
	}
	~TMyPoint()
	{
	}
//protected:
	void setX(int X)
	{
		this->X = X;
	}
	int getX()
	{
		return this->X;
	}
	void setY(int Y)
	{
		this->Y = Y;
	}
	int getY()
	{
		return this->Y;
	}	
	void Show()
	{
		cout << "\n" << getName() << "\n";
		cout << "X = " << X << "; Y = " << Y << "\n";
	}
	void setName(const char* Name)
	{
		strcpy(FigureName, Name);
	}
	char* getName()
	{
		return FigureName;
	}
private:
	char FigureName[20];
	int X;
	int Y;

};

class TMyLine :public TMyPoint
{
public:
	TMyLine(int X = 0, int Y = 0, int DX = 0, int DY = 0) : TMyPoint(X, Y)
	{
		setDX(DX);
		setDY(DY);
		setName("Line");
	}
	~TMyLine()
	{

	}

//protected:
	void setDX(int DX)
	{
		this->DX = DX;
	}
	int getDX()
	{
		return this->DX;
	}
	void setDY(int DY)
	{
		this->DY = DY;
	}
	int getDY()
	{
		return this->DY;
	}	

	void Show()
	{
		//Show();
		cout << "\n" << getName() << "\n";
		cout << "X1 = " << getX() << " Y1 = " << getY() << "\n";
		cout << "X2 = " << getX() + getDX() << " Y2 = " << getY() + getDY() << "\n";
		//cout << "DX = " << DX << " DY = " << DY;
	}
private:
	int DX;
	int DY;
};

class TMyCircle:public TMyPoint
{
public:
	TMyCircle(int X = 0, int Y = 0, int R = 0) : TMyPoint(X, Y)
	{
		setR(R);
		setName("Circle");
	}
	~TMyCircle() 
	{
	}
	void Show()
	{
		//Show();
		cout << "\n" << getName() << "\n";
		cout << "X1 = " << getX() << " Y1 = " << getY() << "\n";
		cout << "R = " << getR() << "\n";
	}
//protected:
	void setR(int R)
	{
		this->R = R;
	}
	int getR()
	{
		return this->R;
	}
private:
	int R;
};

class TMyRectangle :public TMyLine
{
public:
	TMyRectangle(int X = 0, int Y = 0, int DX = 0, int DY = 0) : TMyLine(X, Y, DX, DY)
	{
		setName("Rectangle");
	}

	~TMyRectangle()
	{}

	void Show()
	{
		cout << "\n" << getName() << "\n";
		cout << "X1 = " << getX() << " Y1 = " << getY() << "\n";
		cout << "X2 = " << getX() + getDX() << " Y2 = " << getY() << "\n";
		cout << "X3 = " << getX() + getDX() << " Y3 = " << getY() + getDY() << "\n";
		cout << "X4 = " << getX() << " Y4 = " << getY() + getDY() << "\n";
	}
private:

};

class TMyCylinder: public TMyCircle
{
public:
	TMyCylinder(int X = 0, int Y = 0, int Radius = 0, int Height = 0) : TMyCircle(X, Y, Radius)
	{
		setName("Cylinder");
		setH(Height);
	}
	~TMyCylinder()
	{}
	void Show()
	{
		cout << "\n" << getName() << "\n";
		cout << "X = " << getX() << " Y = " << getY() << "\n";
		cout << "Radius = " << getR() << "\n";
		cout << "Height = " << getH() << "\n";
	}
//protected:
	void setH(int H)
	{
		this->H = H;
	}
	int getH()
	{
		return this->H;
	}
private:
	int H;
};

class TMyParallelogram : public TMyRectangle
{
public:
	TMyParallelogram(int X = 0, int Y = 0, int DX = 0, int DY = 0, int DZ = 0) : TMyRectangle(X, Y, DX, DY)
	{
		setName("Parallelogram");
		setDZ(DZ);
	
	}
	~TMyParallelogram()
	{}
	void Show()
	{
		cout << "\n"<< getName() << "\n";
		cout << "X1 = " << getX() << " Y1 = " << getY() << "\n";
		cout << "X2 = " << getX() + getDX() << " Y2 = " << getY() << "\n";
		cout << "X3 = " << getX() + getDX() << " Y3 = " << getY() + getDY() << "\n";
		cout << "X4 = " << getX() << " Y4 = " << getY() + getDY() << "\n";
		cout << "H = " << getDZ() << "\n";
	}
//protected:
	void setDZ(int DZ)
	{
		this->DZ = DZ; 
	}
	int getDZ()
	{
		return this->DZ;
	}
private:
	int DZ;

};




int main()
{
	system("CLS");

	TMyPoint point1(10, 20);
	point1.Show();

	TMyLine line1(10,20,50);
	line1.Show();

	TMyCircle circle1(1, 1, 300);
	circle1.Show();

	TMyRectangle rectangle1(10,11,2,5);
	rectangle1.Show();

	TMyCylinder cylinder1(10,1000,30,500);
	cylinder1.Show();

	TMyParallelogram parallelogram1(-1, -1, 30, 28, 1111);
	parallelogram1.Show();
	
	system("pause");

//Создать базовый точка и от него наследуйте линию, окружность, прямоугольник, затем цилиндр и параллелограмм.
//создать конструкторы и методы.

}
