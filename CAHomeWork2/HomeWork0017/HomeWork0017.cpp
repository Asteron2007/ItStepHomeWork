// HomeWork0017.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


struct TMyCarStruct
{
	string Name;
	unsigned int Year;
	unsigned int EngineVolume;
 	int Price;
};

enum TMyCarParam { CarName, CarYear, CarEngineVolume, CarPrice };

class ICarInterface
{
protected:
	ICarInterface()
	{
	}

	virtual  ~ICarInterface()
	{}
public:
	virtual void DeleteRec(string Name, TMyCarParam SearchParam = CarName) = 0;
	virtual void AddRec(TMyCarStruct Car) = 0;
	virtual void Show() = 0;
	virtual void Sort(TMyCarParam SortParam) = 0;
	virtual	vector <TMyCarStruct>::iterator Search(vector <TMyCarStruct>::iterator _beg, vector <TMyCarStruct>::iterator _end,
		TMyCarStruct Car, TMyCarParam SearchParam = CarName) = 0;
};

struct TMyCarCompare
{
private:
	TMyCarStruct car;
	TMyCarParam CompareParam;
public:
	TMyCarCompare(TMyCarStruct car, TMyCarParam CompareParam = CarName) : car(car) { this->CompareParam = CompareParam; }
	bool operator () (const TMyCarStruct& car1) const
	{
		switch (CompareParam)
		{
		case CarName:
			return car1.Name == car.Name;
			break;
		case CarYear:
			return car1.Year == car.Year;
			break;
		case CarEngineVolume:
			return car1.EngineVolume == car.EngineVolume;
			break;
		case CarPrice:
			return car1.Price == car.Price;
			break;
		default:
			return false;
			break;
		}
	}
};

bool CarCompare(const TMyCarStruct& car1, const TMyCarStruct& car2, TMyCarParam CompareParam = CarName)
{
	switch (CompareParam)
	{
	case CarName:
		return car1.Name == car2.Name;
		break;
	case CarYear:
		return car1.Year == car2.Year;
		break;
	case CarEngineVolume:
		return car1.EngineVolume == car2.EngineVolume;
		break;
	case CarPrice:
		return car1.Price == car2.Price;
		break;
	default:
		return false;
		break;
	}
}

bool SortCarsByNameASC(const TMyCarStruct& car1, const TMyCarStruct& car2)
{	
	return (car1.Name < car2.Name);
}

bool SortCarsByYearASC(const TMyCarStruct& car1, const TMyCarStruct& car2)
{
	return (car1.Year < car2.Year);
}

bool SortCarsByPriceASC(const TMyCarStruct& car1, const TMyCarStruct& car2)
{
	return (car1.Price < car2.Price);
}

bool SortCarsByEngineVolumeASC(const TMyCarStruct& car1, const TMyCarStruct& car2)
{
	return (car1.EngineVolume < car2.EngineVolume);
}


class TMyCarsDB : public ICarInterface
{
public:
	TMyCarsDB()
	{
	}

	~TMyCarsDB()
	{

	}

	void DeleteRec(string Name, TMyCarParam SearchParam = CarName)
	{
		TMyCarStruct tmpCar;
		if (SearchParam == CarName)
		{
			tmpCar.Name = Name;

			auto iter = Search(CarsDB.begin(), CarsDB.end(), tmpCar, CarName);
			if (iter != CarsDB.end())
				CarsDB.erase(iter);
		}		
	}

	void AddRec(TMyCarStruct Car)
	{
		CarsDB.push_back(Car);
	}
	void Show()
	{
		for (TMyCarStruct Car : CarsDB)
			cout << "Name: " << Car.Name << ", Year: " << Car.Year <<
			", EngineVolume: " << Car.EngineVolume << ", Price: " << Car.Price << "\n";
	}
	void Sort(TMyCarParam SortParam)
	{
		switch (SortParam)
		{
		case CarName:
			sort(CarsDB.begin(), CarsDB.end(), SortCarsByNameASC);
			break;
		case CarYear:
			sort(CarsDB.begin(), CarsDB.end(), SortCarsByYearASC);
			break;
		case CarEngineVolume:
			sort(CarsDB.begin(), CarsDB.end(), SortCarsByEngineVolumeASC);
			break;
		case CarPrice:
			sort(CarsDB.begin(), CarsDB.end(), SortCarsByPriceASC);
			break;
		default:
			break;
		}
	}
	vector <TMyCarStruct>::iterator Search(vector <TMyCarStruct>::iterator _beg, vector <TMyCarStruct>::iterator _end,
		TMyCarStruct Car, TMyCarParam SearchParam = CarName)
	{
		auto iter = _beg;

		iter = find_if(_beg, _end, TMyCarCompare(Car, SearchParam));

		//while (iter != _end)//CarsDB.end())    
		//{
		//	if (iter->Name == Name)
		//		return iter;
		//	++iter;            
		//}

		return iter;//&(*iter);
	}

	TMyCarStruct* FindCarBy(string Name, TMyCarParam SearchParam = CarName)
	{
		TMyCarStruct tmpCar;
		if (SearchParam == CarName)
		{
			tmpCar.Name = Name;

			auto iter = Search(CarsDB.begin(), CarsDB.end(), tmpCar, CarName);
			if (iter != CarsDB.end())
			{
				cout << "Name: " << iter->Name << ", Year: " << iter->Year <<
					", EngineVolume: " << iter->EngineVolume << ", Price: " << iter->Price << "\n";
				return &(*iter);
			}
			else return NULL;
		}
		else return NULL;
	}

	TMyCarStruct* FindCarBy(int Param, TMyCarParam SearchParam = CarYear)
	{
		TMyCarStruct tmpCar;
		switch (SearchParam)
		{
		case CarYear:
			tmpCar.Year = Param;
			break;
		case CarEngineVolume:
			tmpCar.EngineVolume = Param;
			break;
		case CarPrice:
			tmpCar.Price = Param;
			break;
		default:
			return NULL;
			break;
		};

		auto iter = Search(CarsDB.begin(), CarsDB.end(), tmpCar, SearchParam);
		if (iter != CarsDB.end())
		{
			cout << "Name: " << iter->Name << ", Year: " << iter->Year <<
				", EngineVolume: " << iter->EngineVolume << ", Price: " << iter->Price << "\n";
			return &(*iter);
		}
		else return NULL;
	}


private:
	vector <TMyCarStruct> CarsDB;
};





class TMyVectorStatistic
{
public:
	TMyVectorStatistic() : Min(std::numeric_limits<int>::max()),
		Max(std::numeric_limits<int>::min()),
		Count(0)
	{

	}
	~TMyVectorStatistic()
	{

	}
	

	int getMin() const
	{
		return Min;
	}

	int getMax() const
	{
		return Max;
	}

	void operator()(int Value)
	{
		if (Value < Min) {
			Min = Value;
		}
		if (Value >Max) {
			Max = Value;
		}

		++Count;
	}
private:
	int Min;
	int Max;
	int Count;
};

struct TMySortClassASC
{
	bool operator() (int i, int j)
	{
		return (i < j);
	}
} SortObjectASC;

//struct TMySortClassDESC
//{
//	bool operator() (int i, int j)
//	{
//		return (i > j);
//	}
//} SortObjectDESC;

bool SortObjectDESC(int i, int j)
{
	return (i > j);
}

template <class T>
class MultValue
{
private:
	T Factor;   
public:
	MultValue(const T& value) : Factor(value)
	{

	}

	T operator( ) (T& elem) const
	{
		return elem * Factor;
	}
};

template <class T>
class AddValue
{
private:
	T Factor;
public:
	AddValue(const T& value) : Factor(value)
	{

	}

	T operator( ) (T& elem) const
	{
		return elem + Factor;
	}
};

template <class T>
class DecValue
{
private:
	T Factor;
public:
	DecValue(const T& value) : Factor(value)
	{

	}

	T operator( ) (T& elem) const
	{
		return elem - Factor;
	}
};


int main()
{
	/*
	Домашнее задание №17
	Задание 1.
	Создайте приложение для работы автосалона. Необходимо
	хранить информацию о продаваемых автомобилях (на-
	звание, год выпуска, объем двигателя, цену). Реализуйте
	интерфейс для добавления данных, удаления данных,
	отображения данных, сортировке данных по различным
	параметрам, поиску данных по различным параметрам.
	При реализации используйте контейнеры, функторы
	и алгоритмы.
	*/
	cout << "Task 1\n";

	TMyCarsDB Cars;
	TMyCarStruct Car;
	Car.Name = "Homda";
	Car.Year = 1997;
	Car.EngineVolume = 2000;
	Car.Price = 10000;
	Cars.AddRec(Car);
	Car.Name = "BMW";
	Car.Year = 2007;
	Car.EngineVolume = 5000;
	Car.Price = 20000;
	Cars.AddRec(Car);
	Car.Name = "Hover";
	Car.Year = 2017;
	Car.EngineVolume = 2000;
	Car.Price = 12000;
	Cars.AddRec(Car);
	Car.Name = "BMW";
	Car.Year = 2017;
	Car.EngineVolume = 3000;
	Car.Price = 15000;
	Cars.AddRec(Car);
	Car.Name = "Opel";
	Car.Year = 2007;
	Car.EngineVolume = 1500;
	Car.Price = 8000;
	Cars.AddRec(Car);
	Cars.Show();
	cout << "Sort cars by name: \n";
	Cars.Sort(CarYear);
	Cars.Show();




	cout << "Find car 'BMW': \n";
	Cars.FindCarBy("BMW", CarName);
	cout << "Find car by year '2017': \n";
	Cars.FindCarBy(2017, CarYear);
	cout << "Find car by Price '15000USD': \n";
	Cars.FindCarBy(15000, CarPrice);


	cout << "Delete car 'Hover': \n";
	Cars.DeleteRec("Hover", CarName);
	Cars.Show();


	/*
	Задание 2.
	В контейнере типа vector хранится набор целых чисел.
	Создайте функторы для решения следующих задач:
	+1. Поиск минимального значения;
	+2. Поиск максимального значения;
	+3. Сортировка данных по убыванию;
	+4. Сортировка данных по возрастанию;
	+5. Увеличение значений в контейнере на заданную константу;
	+6. Уменьшение значений в контейнере на заданную константу;
	+7. Удаление элементов из контейнера равных искомому значению.
	Не забывайте использовать алгоритмы там, где это необходимо.
	*/
	cout << "Task 2\n";
	vector<int> Numbers;
	//	std::vector<int> vec = { 1, -2, 3, -4, -5, 6, 7, 8 };
	Numbers.push_back(5);
	Numbers.push_back(3);
	Numbers.push_back(10);
	Numbers.push_back(1);
	Numbers.push_back(10);
	Numbers.push_back(11);
	Numbers.push_back(10);
	Numbers.push_back(-121);

	for (int n : Numbers)
		cout << n << "\t";
	cout << "\n";


	TMyVectorStatistic stat;
	stat = std::for_each(Numbers.begin(), Numbers.end(), stat);

	std::cout << "Minimum: " << stat.getMin() << "\n"
		<< "Maximum: " << stat.getMax() << "\n";

	cout << "Sort by ASC:\n";
	sort(Numbers.begin(), Numbers.end(), SortObjectASC);
	for (int n : Numbers)
		cout << n << "\t";
	cout << "\n";

	cout << "Sort by DESC:\n";
	sort(Numbers.begin(), Numbers.end(), SortObjectDESC);
	for (int n : Numbers)
		cout << n << "\t";
	cout << "\n";


	cout << "Add Value 7 to all elements:\n";
	transform(Numbers.begin(), Numbers.end(), Numbers.begin(), AddValue<int>(7));
	for (int n : Numbers)
		cout << n << "\t";
	cout << "\n";

	cout << "Dec Value 177 from all elements:\n";
	transform(Numbers.begin(), Numbers.end(), Numbers.begin(), DecValue<int>(177));
	for (int n : Numbers)
		cout << n << "\t";
	cout << "\n";


	int RemoveElement = -160;
	cout << "Remove element (" << RemoveElement << "):\n";
	Numbers.erase(remove(Numbers.begin(), Numbers.end(), RemoveElement), Numbers.end());
	for (int n : Numbers)
		cout << n << "\t";
	cout << "\n";

	






//Задание 3.
//Измените функторы из первого задания в шаблонные
//классы-функторов. Проверьте работу полученного ре-
//шения на разных контейнерах с разным содержимым.





}
