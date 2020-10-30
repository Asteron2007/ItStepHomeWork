// HomeWork0011-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

template <class T>
struct TMyItem2
{
	T Value;
	TMyItem2* Next;
	TMyItem2* Prev;
};

template <class T>
struct TMyItem
{
	T Value;
	TMyItem* Next;
};

template <class T>
class TMyStack
{
public:
	TMyStack() :size(0)
	{
		Head = NULL;
	}
	TMyStack(const TMyStack& Sender) : size(Sender.size)
	{
		Head = Sender.Head;
	}
	TMyStack(TMyStack&& Sender) : size(Sender.size)
	{
		Head = Sender.Head;
	}
	~TMyStack()
	{
		while (!empty())
		{
			pop();
		}
	}

	//void push(TMyItem& Item);
	void push(T Value)
	{
		if (Value)
		{
			TMyItem<T>* newItem = new TMyItem<T>();
			newItem->Next = Head;
			newItem->Value = Value;
			Head = newItem;
		}
	}

	//TMyItem pop();
	T pop()
	{
		if (Head)
		{
			T Value = Head->Value;
			TMyItem<T>* delItem = Head;
			Head = Head->Next;
			delete delItem;
			return Value;
		}
		else
		{
			return NULL;
		}
	}
	T peek()
	{
		return Head->Value;
	}
	bool empty()
	{
		return !Head;
	}

	int getSize() const
	{
		size = 0;
		TMyItem* tmpItem = Head;
		if (!tmpItem)
		{
			cout << "Stack is empty.\n";
			return;
		}
		while (tmpItem)
		{
			size++;
			tmpItem = tmpItem->Next;
		}

		return size;
	}

	void show()
	{
		TMyItem<T>* tmpItem = Head;
		if (!tmpItem)
		{
			cout << "Stack is empty.\n";
			return;
		}
		while (tmpItem)
		{
			cout << tmpItem->Value << "\n";
			tmpItem = tmpItem->Next;
		}
	}
	TMyStack* Clone(TMyStack* FromStack = NULL, bool Unique = false)
	{
		TMyStack* tmpFromStack;
		if (FromStack)
		{
			tmpFromStack = FromStack;
		}
		else
		{
			tmpFromStack = this;
		}

		// выходной стек
		TMyStack* tmpStackClone = new TMyStack;

		TMyItem<T>* tmpItem = tmpFromStack->Head;
		if (!tmpItem)
		{			
			return tmpStackClone;
		}
		// временный стек с обратным порядком элементов
		TMyStack* tmpStackReverse = new TMyStack;

		while (tmpItem)
		{
			if ((!Unique) || (!tmpFromStack->isPresent(tmpItem->Value)))
			{
				tmpStackReverse->push(tmpItem->Value);
			}
			tmpItem = tmpItem->Next;
		}
	

		while (!tmpStackReverse->empty())
		{
			tmpStackClone->push(tmpStackReverse->pop());
		}

		delete tmpStackReverse;
		return tmpStackClone;
	}

	TMyStack* operator + (TMyStack* S1)
	{
		//TMyItem* tmpHead = NULL;
		TMyItem<T>* tmpItem = this->Head;

		TMyStack* tmpStack = Clone(S1);

		// выходной стек
		//TMyStack* tmpStackClone = new TMyStack;
		// временный стек с обратным порядком элементов
		TMyStack* tmpStackReverse = new TMyStack;

		while (tmpItem)
		{
			tmpStackReverse->push(tmpItem->Value);
			tmpItem = tmpItem->Next;
		}

		while (!tmpStackReverse->empty())
		{
			tmpStack->push(tmpStackReverse->pop());
		}

		delete tmpStackReverse;
		return tmpStack;
	}

	bool isPresent(T value)
	{
		TMyItem<T>* tmpItem = Head;
		if (!tmpItem)
		{			
			return false;
		}
		while (tmpItem)
		{
			if (tmpItem->Value == value) return true;
			tmpItem = tmpItem->Next;
		}
		return false;
	}

	TMyStack* operator * (TMyStack* S1)
	{
		TMyItem<T>* tmpItem = this->Head;

		TMyStack* tmpStack = Clone(S1, true);

		// выходной стек
		//TMyStack* tmpStackClone = new TMyStack;
		// временный стек с обратным порядком элементов
		TMyStack* tmpStackReverse = new TMyStack;

		while (tmpItem)
		{
			if (!tmpStackReverse->isPresent(tmpItem->Value))
			{
				tmpStackReverse->push(tmpItem->Value);
			}
			tmpItem = tmpItem->Next;
		}

		while (!tmpStackReverse->empty())
		{
			tmpStack->push(tmpStackReverse->pop());
		}

		delete tmpStackReverse;
		return tmpStack;
	}

private:
	int size;
	
	TMyItem<T>* Head;

};

template <class T>
class TMyList2
{
public:
	TMyList2() : Head(NULL), Tail(NULL)
	{

	}
	TMyList2(const TMyList2& Sender) : size(Sender.size)
	{
		Head = Sender.Head;
	}
	TMyList2(TMyList2&& Sender) : size(Sender.size)
	{
		Head = Sender.Head;
	}
	~TMyList2()
	{
		while (!empty())
		{
			pop();
		}
	}


	void push(T Value)
	{
		if (Value)
		{
			TMyItem2<T>* newItem = new TMyItem2<T>();

			newItem->Next = Head;
			newItem->Value = Value;
			newItem->Prev = NULL;
			//Head->Prev = newItem;

			Head = newItem;
			_size++;
		}
	}

	T pop() 
	{
		if (Head)
		{
			T Value = Head->Value;
			TMyItem2<T>* delItem = Head;
			Head = Head->Next;
			if (Head) Head->Prev = NULL;
			delete delItem;
			_size--;
			return Value;
		}
		else
		{
			return NULL;
		}
	}

	T peak(int step = 1)// maybe pos/neg step from head
	{
		return Head->Value;
	}

	size_t size()
	{
		return _size;
	}
	bool empty()
	{
		return !Head; 
	}
	TMyList2& back() const
	{ 
		return *Tail; 
	}
	TMyList2& front() const
	{ 
		return *Head; 
	}

	void Show()
	{
		TMyItem2<T>* tmpItem = Head;
		if (!tmpItem)
		{
			cout << "Stack 2 is empty.\n";
			return;
		}
		while (tmpItem)
		{
			cout << tmpItem->Value << "\n";
			tmpItem = tmpItem->Next;
		}
	}



	TMyList2* Clone(TMyList2* FromStack = NULL, bool Unique = false)
	{
		TMyList2* tmpFromStack;
		if (FromStack)
		{
			tmpFromStack = FromStack;
		}
		else
		{
			tmpFromStack = this;
		}

		// выходной стек
		TMyList2* tmpStackClone = new TMyList2;

		TMyItem2<T>* tmpItem = tmpFromStack->Head;
		if (!tmpItem)
		{
			return tmpStackClone;
		}
		// временный стек с обратным порядком элементов
		TMyList2* tmpStackReverse = new TMyList2;

		while (tmpItem)
		{
			if ((!Unique) || (!tmpFromStack->isPresent(tmpItem->Value)))
			{
				tmpStackReverse->push(tmpItem->Value);
			}
			tmpItem = tmpItem->Next;
		}


		while (!tmpStackReverse->empty())
		{
			tmpStackClone->push(tmpStackReverse->pop());
		}

		delete tmpStackReverse;
		return tmpStackClone;
	}

	TMyList2* operator + (TMyList2* S1)
	{
		//TMyItem* tmpHead = NULL;
		TMyItem2<T>* tmpItem = this->Head;

		TMyList2* tmpStack = Clone(S1);

		// выходной стек
		// временный стек с обратным порядком элементов
		TMyList2* tmpStackReverse = new TMyList2;

		while (tmpItem)
		{
			tmpStackReverse->push(tmpItem->Value);
			tmpItem = tmpItem->Next;
		}

		while (!tmpStackReverse->empty())
		{
			tmpStack->push(tmpStackReverse->pop());
		}

		delete tmpStackReverse;
		return tmpStack;
	}

	bool isPresent(T value)
	{
		TMyItem2<T>* tmpItem = Head;
		if (!tmpItem)
		{
			return false;
		}
		while (tmpItem)
		{
			if (tmpItem->Value == value) return true;
			tmpItem = tmpItem->Next;
		}
		return false;
	}

	TMyList2* operator * (TMyList2* S1)
	{
		TMyItem2<T>* tmpItem = this->Head;

		TMyList2* tmpStack = Clone(S1, true);

		// выходной стек
		//TMyStack* tmpStackClone = new TMyStack;
		// временный стек с обратным порядком элементов
		TMyList2* tmpStackReverse = new TMyList2;

		while (tmpItem)
		{
			if (!tmpStackReverse->isPresent(tmpItem->Value))
			{
				tmpStackReverse->push(tmpItem->Value);
			}
			tmpItem = tmpItem->Next;
		}

		while (!tmpStackReverse->empty())
		{
			tmpStack->push(tmpStackReverse->pop());
		}

		delete tmpStackReverse;
		return tmpStack;
	}




private:
	size_t _size;
	//TMyItem2<T>* ;
	TMyItem2<T>* Head;
	TMyItem2<T>* Tail;

};




int main()
{
	//Реализуйте стек в виде односвязного списка.Требуется реализовать типичные операции по работе со стеком.
	//При переполнении стека нужно увеличивать его размер.

	//В существующий класс односвязного списка добавить :
	//операцию клонирования списка(функция должна возвращать адрес головы клонированного списка), 
	//перегрузить оператор + (оператор должен возвращать адрес головы нового списка, 
	//содержащего элементы обоих списков для которых вызывался оператор), перегрузить оператор* 
	//(оператор должен возвращать адрес головы нового списка, 
	//содержащего только общие элементы обоих списков для которых вызывался оператор).

	TMyStack <char>* HeadCh = new TMyStack <char>();

	HeadCh->push('A');
	HeadCh->push('1');
	HeadCh->push('B');
	HeadCh->push('2');
	HeadCh->push('D');
	HeadCh->push('3');

	cout << "\n";
	HeadCh->show();
	cout << "\n";
	TMyStack <char>* tmpHeadCh = HeadCh->Clone();

	HeadCh->push('+');
	HeadCh->push('N');

	TMyStack <char>* SummHeadCh = (*HeadCh + tmpHeadCh); // +HeadCh;

	delete HeadCh;
	tmpHeadCh->show();
	
	cout << "----------- After + operator: --------------\n";
	SummHeadCh->show();
	cout << "\n";

	TMyStack <char>* StCh1 = new TMyStack<char>(); 
	StCh1->push('5');
	StCh1->push('4');
	StCh1->push('3');

	TMyStack <char>* StCh2 = new TMyStack <char>();
	StCh1->push('5');
	StCh1->push('1');
	StCh1->push('3');

	
	cout << "----------- After * operator: --------------\n";
	StCh1 = (*StCh1 * StCh2);
	StCh1->show();
	cout << "\n";
	


	TMyStack <double>* HeadDb = new TMyStack <double>;
	HeadDb->push(1.9);
	HeadDb->push(2.00);
	HeadDb->push(3.999);
	HeadDb->push(4.7);
	HeadDb->push(5);
	HeadDb->push(622);
	HeadDb->push(755);

	HeadDb->show();
	cout << "\n";
	HeadDb->Clone()->show();
	cout << "\n";	
	delete HeadDb;

	//Реализовать шаблонный класс «Очередь» на основе двусвязного списка.
	//В существующий класс двусвязного списка добавить :
	//операцию клонирования списка(функция должна возвращать адрес головы клонированного списка), 
	//перегрузить оператор + (оператор должен возвращать адрес головы нового списка, 
	//содержащего элементы обоих списков для которых вызывался оператор), перегрузить оператор* 
	//(оператор должен возвращать адрес головы нового списка, содержащего только общие элементы 
	//обоих списков длякоторых вызывался оператор).
	
	
	TMyList2<int>* list2 = new TMyList2<int>();
	list2->push(1);
	list2->push(2);
	list2->push(3);
	list2->push(4);
	list2->push(5);

	cout << "Clone: \n";
	list2->Clone()->Show();

	list2->pop();
	list2->pop();
	list2->push(6);
	list2->push(7);
	cout << "List2 afer push and pop: \n";
	
	list2->Show();

	TMyList2 <int>* L2 = (*list2 + list2);
	cout << "operator + : \n";
	L2->Show();

	//delete L2;
	L2->push(10);
	L2->push(100);

	L2 = (*L2 * list2);
	cout << "operator * : \n";
	L2->Show();



	cout << "List2: ";
	while (!list2->empty())
	{
		cout << list2->pop() << ", ";
	}
	cout << "\n";
	list2->Show();
	
	
	
}
