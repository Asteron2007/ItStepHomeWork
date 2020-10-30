// HomeWork0010-3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

template <typename T1, typename T2> class TMyBase
{
public:
    TMyBase(T1 value1 = NULL, T2 value2 = NULL)
    {
        this->value1 = value1;
        this->value2 = value2;
    }
    ~TMyBase()
    {
    }
    void setvalue1(T1 value1)
    {
        this->value1 = value1;
    }
    void setvalue2(T2 value2)
    {
        this->value2 = value2;
    }
    T1 getvalue1()
    {
        return this->value1;
    }
    T2 getvalue2()
    {
        return this->value2;
    }

    void Show()
    {
        cout << "value1 = " << value1 << '(' << typeid(value1).name() << ")\n";
        cout << "value2 = " << value2 << '(' << typeid(value2).name() << ")\n";
    }

    friend std::ostream& operator<< (std::ostream& out,  TMyBase<T1, T2>& mybase)
    {     
        return out << "value1 = " << mybase.getvalue1() <<
            " value2 = " << mybase.getvalue2() << '(' << typeid(mybase).name() << ')';
    }
private:

protected:
    T1 value1;
    T2 value2;
};

template <typename T1, typename T2, typename T3, typename T4>
class TMyChild : public TMyBase <T1, T2>
{
public:
    TMyChild(T1 value1=NULL, T2 value2 = NULL, T3 value3 = NULL, T4 value4 = NULL) : TMyBase<T1,T2>(value1, value2)
    {
        this->value3 = value3;
        this->value4 = value4;
    }
    ~TMyChild()
    {}
    void setvalue3(T3 value3)
    {
        this->value3 = value3;
    }
    void setvalue4(T4 value4)
    {
        this->value4 = value4;
    }
    T3 getvalue3()
    {
        return this->value3;
    }
    T4 getvalue4()
    {
        return this->value4;
    }
    void Show()
    {
        TMyBase<T1, T2>::Show();
        cout << "value3 = " << value3 << '(' << typeid(value3).name() << ")\n";
        cout << "value4 = " << value4 << '(' << typeid(value4).name() << ")\n";
    }
   
 //   template <typename T1, typename T2, typename T3, typename T4>
    friend std::ostream& operator<< (std::ostream& out, TMyChild<T1, T2, T3, T4>& mychild)
    {
        //out <<' ' << static_cast<TMyBase<T1,T2>>(mychild);
       // out << "value1 = " << reinterpret_cast<TMyBase<T1, T2>>(mychild).getvalue1() <<
       //     " value2 = " << reinterpret_cast<TMyBase<T1, T2>>(mychild).getvalue2() ;
        TMyBase<T1, T2> tmpbase = mychild;
            
      //  out << tmpbase.getvalue1(); // почему не работает????


        //------------------------------------------------------------------------------------
        //
        //не понимаю как перегрузить оператор вывода потомком !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        //не могу понять почему не видит функции родителя
        //mychild.getvalue1()
        //mychild.getvalue2()
        //Как запустить перегруженный оператор вывода у родителя из потомка
        //
        //
        //
        //
        return (out << "value1 = " //<< tmpbase.getvalue1()
            << " value2 = " //<< mychild.getvalue2()
            << " value3 = " << mychild.getvalue3() <<
            " value4 = " << mychild.getvalue4() << '(' << typeid(mychild).name() << ')');
    }
private:
protected:
    T3 value3;
    T4 value4;
};

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class TMyChild2: public TMyChild <T1, T2, T3, T4>
{
public:
    TMyChild2(T1 value1, T2 value2, T3 value3, T4 value4, T5 value5, T6 value6) :
        TMyChild<T1,T2,T3,T4>(value1, value2, value3, value4)
    {
        this->value5 = value5;
        this->value6 = value6;
    }
    ~TMyChild2() 
    {}
    void Show()
    {
        TMyChild<T1, T2, T3, T4>::Show();
        cout << "value5 = " << value5 << '(' << typeid(value5).name() << ")\n";
        cout << "value6 = " << value6 << '(' << typeid(value6).name() << ")\n";
    }
private:
protected:
    T5 value5;
    T6 value6;    
};




int main()
{
    /*
    Используя механизм шаблонного наследования создайте
иерархию классов. Базовый класс под названием base
имеет следующие переменные-члены:
1. T1 value1; // некоторое значение;
2. T2 value2; // некоторое значение.
Потомок под названием child содержит дополнительные
переменные-члены:
1. T3 value3;
2. T4 value4.
Потомок под названием child2 добавляет такие
переменные-члены:
1. T5 value5;
2. T6 value6.
Каждый класс имеет необходимый набор конструкторов,
деструкторов, функций-членов для работы со структурой
класса.
В main протестировать работу класса.
    */
    TMyBase <int, double> base1 = TMyBase<int, double>(6, 8.7);
    base1.Show();
    cout << '\n';

    TMyChild <TMyBase<int, double>, double, char, bool> child1 = 
        TMyChild<TMyBase<int, double>, double, char,bool>(base1, 2.3, 'f', false);
    child1.Show();
    cout << '\n';
    
    TMyChild2<TMyChild<TMyBase<int, double>, double, char, bool>, double, char, bool, char, string> child2 =
        TMyChild2<TMyChild<TMyBase<int, double>, double, char, bool>, double, char, bool, char, string>
        (child1, 1, 'P', true, 'Y', "new string");
    child2.Show();
    cout << '\n';
}
