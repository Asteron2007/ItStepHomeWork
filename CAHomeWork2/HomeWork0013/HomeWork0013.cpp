// HomeWork0013.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include<fstream>



using namespace std;


class TMyEquation
{
public:
	TMyEquation(int KoefsCount = 2)
	{
		_KoefsCount = KoefsCount;
		_Koefs = new double[GetKoefsCount() + 1];
	}

	~TMyEquation()
	{
		delete _Roots;
		delete _Koefs;
	}

	int GetKoefsCount()
	{
		return _KoefsCount;
	}

	int GetRootsCount()
	{
		return _RootsCount;
	}
	void SetKoef()
	{
		cout << "Enter koeffitients: \n";
		for (int i = GetKoefsCount(); i >= 0; i--)
		{
			cout << "Enter koeffitient [" << i << "]: ";
			cin >> _Koefs[i];
		}
	}

	virtual double* GetRoots() = 0;


protected:
	double* _Roots;
	int _RootsCount;
	double* _Koefs;
	int _KoefsCount;


};




class TMyLinearEquation : public TMyEquation
{
public:
	TMyLinearEquation() : TMyEquation(1) { }
	~TMyLinearEquation()  {	}//: ~TMyEquation()

	virtual double* GetRoots() override
	{
		cout << "\n";
		cout << _Koefs[1] << " * x + " << _Koefs[0] << " = 0\n";
		cout << "x = " << -_Koefs[0] / _Koefs[1] << "\n";
		_RootsCount = 1;
		_Roots = new double[GetRootsCount()];
		_Roots[0] = -_Koefs[0] / _Koefs[1];
		return  _Roots;
	}

};

class TMySquareEquation : public TMyEquation
{
public:
	TMySquareEquation() : TMyEquation(2) { }
	~TMySquareEquation() {	}//: ~TMyEquation()

	virtual double* GetRoots() override
	{
		double discr = _Koefs[1]* _Koefs[1] - 4* _Koefs[2]*_Koefs[0]; //b ^ 2 - 4 * a * c
		cout << "\n";
		cout << _Koefs[2] << " * x^2 + " << _Koefs[1] << " * x + " << _Koefs[0] << " = 0\n";

		if (discr>0)
		{
			_RootsCount = 2;
			_Roots = new double[GetRootsCount()];
			_Roots[0] = (-_Koefs[1] + sqrt(discr)) / (2 * _Koefs[2]); //x1 = (-b + КОРЕНЬ(D)) / (2 * a);
			_Roots[1] = (-_Koefs[1] - sqrt(discr)) / (2 * _Koefs[2]);//x2 = (-b - КОРЕНЬ(D)) / (2 * a).
			cout << "x1 = " << _Roots[0] << "\n";
			cout << "x2 = " << _Roots[1] << "\n";
		}
		else if (discr == 0)
		{
			_RootsCount = 1;
			_Roots = new double[GetRootsCount()];
			_Roots[0] = -_Koefs[1] / (2 * _Koefs[2]); //x1 = -b / (2 * a);
			cout << "x1 = " << _Roots[0] << "\n";			
		}
		else
		{
			_RootsCount = 0;
			_Roots = new double[GetRootsCount()];
			cout << "Square Equation have no roots!\n";

		}

		
		
		return  _Roots;
	}

};


class TMyShape
{
public:
	virtual void Show() = 0;
	virtual TMyShape* Load(ifstream& inf) = 0;
	virtual void Save(ofstream& outf) = 0;

private:

};

class TMySquare : public TMyShape
{

public:
	TMySquare(double X, double Y, double Len)
	{
		this->X = X;
		this->Y = Y;
		this->Len = Len;
	}
	virtual void Show() override
	{
		cout << "Square (" << "X = " << X << ", Y = " << Y << ", Len = " << Len << ")\n";

	}
	virtual TMyShape* Load(ifstream& inf) override
	{
		inf.read((char*)&*this, sizeof(TMySquare));
		//this->Show();
		return this;
	}
	virtual void Save(ofstream& outf) override
	{
		char ch = 'S';
		outf.write((char*)&ch, sizeof(ch));
		outf.write((char*)&*this, sizeof(*this));
	}
	double X;
	double Y;
	double Len;
};

class TMyRectangle : public TMyShape
{
public:
	TMyRectangle(double X, double Y, double LenX, double LenY)
	{
		this->X = X;
		this->Y = Y;
		this->LenX = LenX;
		this->LenY = LenY;
	}
	virtual void Show() override
	{
		cout << "Rectangle (" << "X = " << X << ", Y = " << Y << ", LenX = " << LenX << ", LenY = " << LenY << ")\n";
	}
	virtual TMyShape* Load(ifstream& inf) override
	{
		inf.read((char*)&*this, sizeof(TMyRectangle));
		//this->Show();
		return this;
	}
	virtual void Save(ofstream& outf) override
	{
		char ch = 'R';
		outf.write((char*)&ch, sizeof(ch));
		outf.write((char*)&*this, sizeof(*this));
	}
	
	double X;
	double Y;
	double LenX;
	double LenY;
};

class TMyCircle : public TMyShape
{
public:
	TMyCircle(double X, double Y, double Radius)
	{
		this->X = X;
		this->Y = Y;
		this->Radius = Radius;
	}

	TMyCircle(const TMyCircle& ref_circle)
	{
		this->X = ref_circle.X;
		this->Y = ref_circle.Y;
		this->Radius = ref_circle.Radius;
	}

	virtual void Show() override
	{
		cout << "Circle (" << "X = " << X << ", Y = " << Y << ", Radius = " << Radius << ")\n";
	}
	virtual TMyShape* Load(ifstream& inf) override
	{
		//TMyCircle* ShapeTmp = new TMyCircle(1, 5, 10);
		//TMyCircle _ShapeTmp = TMyCircle(10, 50, 100);
		inf.read((char*)&*this, sizeof(TMyCircle));
		//this->Show();
		return this;
	}
	virtual void Save(ofstream& outf) override
	{
		char ch = 'C';
		outf.write((char*)&ch, sizeof(ch));
		outf.write((char*)&*this, sizeof(*this));
	}
	double X;
	double Y;
	double Radius;
};

class TMyEllipse : public TMyShape
{
public:
	TMyEllipse(double X, double Y, double LenX, double LenY)
	{
		this->X = X;
		this->Y = Y;
		this->LenX = LenX;
		this->LenY = LenY;
	}
	virtual void Show() override
	{
		cout << "Ellipse (" << "X = " << X << ", Y = " << Y << ", LenX = " << LenX << ", LenY = " << LenY << ")\n";

	}
	virtual TMyShape* Load(ifstream& inf) override
	{
		inf.read((char*)&*this, sizeof(TMyEllipse));
		//this->Show();
		return this;
	}
	virtual void Save(ofstream& outf) override
	{
		char ch = 'E';
		outf.write((char*)&ch, sizeof(ch));
		outf.write((char*)&*this, sizeof(*this));
	}
	double X;
	double Y;
	double LenX;
	double LenY;
};


int main()
{
	//Задание 2.
	//	Создайте абстрактный класс Shape для рисования плоских
	//	фигур.Определите виртуальные методы :
	//• Show() — вывод на экран информации о фигуре,
	//	• Save() — сохранение фигуры в файл,
	//	• Load() — считывание фигуры из файла.
	//	Определите производные классы :
	//• Square — квадрат, который характеризуется коорди -
	//	натами левого верхнего угла и длиной стороны;
	//• Rectangle — прямоугольник с заданными координатами
	//	верхнего левого угла и размерами;
	//• Circle — окружность с заданными координатами цен -
	//	тра и радиусом;
	//• Ellipse — эллипс с заданными координатами верхне -
	//	го угла описанного вокруг него прямоугольника со
	//	сторонами, параллельными осям координат, и раз -
	//	мерами этого прямоугольника.
	//	Создайте массив фигур, сохраните фигуры в файл, загру -
	//	зите в другой массив и отобразите информацию о каждой
	//	из фигур.

	cout << "Task 2\n";

	TMyShape* Shapes[8];
	TMyShape* LoadedShapes[8];


	Shapes[0] = new TMyRectangle(100, 5, 50, 86);
	Shapes[1] = new TMyCircle(215, 151, 100);
	Shapes[2] = new TMySquare(255, 250, 159);
	Shapes[3] = new TMyEllipse(120, 425, 130, 9930);

	Shapes[4] = new TMyRectangle(1, 1, 50, 50);
	Shapes[5] = new TMyCircle(5, 5, 500);
	Shapes[6] = new TMySquare(25, 25, 150);
	Shapes[7] = new TMyEllipse(7, 8, 9, 10);

	//TMyShape* CirclePtr = new TMyCircle(3, 4, 50);
	string FileName = "Shapes.txt";
	//cout << "Basic shape: ";
	//CirclePtr->Show();*/

	//ofstream outF(FileName, ofstream::app);
	ofstream outF(FileName);
	cout << "\ Shapes array: " << "\n";
	for (int i = 0; i < 8; i++)
	{
		Shapes[i]->Show();
		if (outF) Shapes[i]->Save(outF);
		else cout << "File open error: " << FileName << "\n";	
		
		cout << " - saved \n";
	}	
	outF.close();

	ifstream inF(FileName);
	char ch = ' ';
	int i = 0;
	
	while (!inF.eof())
	{		
		inF.read((char*)&ch, sizeof(ch));
		if (!inF.eof())
		{
			cout << "Figure N " << i << " "; 
			switch (ch)
			{
			case 'C':
				//ShapeTmp->Show();
				LoadedShapes[i] = new TMyCircle(0, 0, 0);
				if (inF)  LoadedShapes[i]->Load(inF);
				else cout << "File open error: " << FileName << endl;
				LoadedShapes[i]->Show();
				i++;
				break;
			case 'R':
				//ShapeTmp->Show();
				LoadedShapes[i] = new TMyRectangle(0, 0, 0, 0);
				if (inF)  LoadedShapes[i]->Load(inF);
				else cout << "File open error: " << FileName << endl;
				LoadedShapes[i]->Show();
				i++;
				break;
			case 'S':
				//ShapeTmp->Show();
				LoadedShapes[i] = new TMySquare(0, 0, 0);
				if (inF)  LoadedShapes[i]->Load(inF);
				else cout << "File open error: " << FileName << endl;
				LoadedShapes[i]->Show();
				i++;
				break;
			case 'E':
				//ShapeTmp->Show();
				LoadedShapes[i] = new TMyEllipse(0, 0, 0, 0);
				if (inF)  LoadedShapes[i]->Load(inF);
				else cout << "File open error: " << FileName << endl;
				LoadedShapes[i]->Show();
				i++;
				break;
			default:
				break;
			}
		}
	}
	inF.close();
	
	



	//Задание 1.
	//	Создать абстрактный базовый класс с виртуальной
	//	функцией — корни уравнения. Создать производные
	//	классы : класс линейных уравнений и класс квадратных
	//	уравнений.Определить функцию вычисления корней уравнений.
	cout << "\n";
	cout << "Task 1\n";

	TMySquareEquation SquareEQ;
	SquareEQ.SetKoef();
	SquareEQ.GetRoots();
	cout << "\n";

	TMyLinearEquation LinearEQ;
	LinearEQ.SetKoef();
	LinearEQ.GetRoots();
	cout << "\n";


	
}
