// HomeWork0006.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>

using namespace std;

#define ESC "\x1b"
#define CSI "\x1b["



enum MySuit //масть
{
    Hearts, // — червы
    Diamonds,// — бубны
    Clubs,// — трефы
    Spades// — пики
};

enum MyCardName
{
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eigth,
    Nine,
    Ten,
    Jack,// — валет
    Queen,// — дама
    King,// — король
    Ace,// — туз
    Joker// — джокер
};


void printXY(int X, int Y, char* str, int BackGroundColor, int TextColor)
{
    std::cout << CSI << BackGroundColor << ";" << TextColor << "m";   // black background / blue text 94m
    std::cout << CSI << Y << ";" << X << "H";     // cursor position		
    cout << str;
    std::cout << CSI "0m";       // restore colors 
}

void printXY(int X, int Y, int val, int BackGroundColor, int TextColor)
{
    std::cout << CSI << BackGroundColor << ";" << TextColor << "m";   // black background / blue text 94m
    std::cout << CSI << Y << ";" << X << "H";     // cursor position		
    cout << val;
    std::cout << CSI "0m";       // restore colors 
}

void gotoXY(int X, int Y, int BackGroundColor, int TextColor)
{
    std::cout << CSI << BackGroundColor << ";" << TextColor << "m";   // black background / blue text 94m
    std::cout << CSI << Y << ";" << X << "H";     // cursor position     
}

void restoreColor()
{
    std::cout << CSI "0m";       // restore colors
}

class TMyCard
{
public:
    TMyCard(MySuit Suit = Hearts, MyCardName CardName = Two)// :Suit(Suit), CardName(CardName)
    {
        this->CardSuit = Suit;
        this->CardName = CardName;
        Owner = NULL;
        NextCard = NULL;
    }

    TMyCard(const TMyCard& Sender)
    {
        this->CardSuit = Sender.CardSuit;
        this->CardName = Sender.CardName;
        this->Owner = Sender.Owner;
        this->NextCard = Sender.NextCard;
    }

    TMyCard(TMyCard&& Sender)
    {
        this->CardSuit = Sender.CardSuit;
        this->CardName = Sender.CardName;
        this->Owner = Sender.Owner;
        this->NextCard = Sender.NextCard;
    }

    ~TMyCard()
    {

    }

    int CardValue()
    {
        switch (CardName)
        {
        case Two: 
            return 2;
            break;
        case Three:
            return 3;
            break;
        case Four:
            return 4;
            break;
        case Five:
            return 5;
            break;
        case Six:
            return 6;
            break;
        case Seven:
            return 7;
            break;
        case Eigth:
            return 8;
            break;
        case Nine:
            return 9;
            break;
        case Ten:
            return 10;
            break;
        case Jack:
            return 10;
            break;
        case Queen:
            return 10;
            break;
        case King:
            return 10;
            break;
        case Ace:
            return 11;
            break;
        case Joker:
            return  0;
            break;
        default:
            return 0;
            break;
        }
    }

    void Show(int x = 0, int y = 0)
    {
        const int CardHeight = 5;
        cout << ESC "(0";        // Enter Line drawing mode
        gotoXY(x, y, 15, 94);
        cout << "lqqqqqqqqqqqk";
        for (int i = 0; i < CardHeight; i++)
        {
            // in line drawing mode, \x78 -> \u2502 "Vertical Bar"
            gotoXY(x, y + i + 1, 15, 94);
            cout << "x           x";
        }
        gotoXY(x, y + CardHeight + 1, 15, 94);
        cout << "mqqqqqqqqqqqj";
        //	cout << "\n\nqwertyuiopasdfghjklzxcvbnm,./";
        // cout << (char)5;
        //cout << '\3';
        //cout << '\4';
        cout << ESC "(B";       // exit line drawing mode
       
        gotoXY(x + 2, y + 1, 15, 90 + CardSuit);
        switch (CardSuit)
        {
        case Hearts:// — червы
            cout << "Hearts";
            break;
        case Diamonds:// — бубны
            cout << "Diamonds";
            break;
        case  Clubs:// — трефы
            cout << "Clubs";
            break;
        case Spades:// — пики
            cout << "Spades";
            break;
        default:
            break;
        }                            

        switch (CardName)
        {
        case Jack:
            cout << " " << "Jack";
            break;
        case Queen:
            cout << " " << "Queen";
            break;
        case King:
            cout << " " << "King";
            break;
        case Ace:
            cout << " " << "Ace";
            break;
        case Joker:
            break;
        default:
            cout << " " << CardName + 2;
            break;
        }
        cout << "=" << CardValue();

        restoreColor();
    }

    void setOwner(TMyCard* newOwner)
    {
        this->Owner = newOwner;
    }

    TMyCard* getOwner()
    {
        return Owner;
    }

    void setNextCard(TMyCard* newCard)
    {
        this->NextCard = newCard;
    }

    TMyCard* getNextCard()
    {
        if (NextCard!=nullptr)
        {
            return NextCard;
        }
        else
        {
            return nullptr;
        }
    }

private:
    MySuit CardSuit;
    MyCardName CardName;
    TMyCard* Owner;
    TMyCard* NextCard;
};

//— колода
class  TMyDeck
{
public:
    TMyDeck(bool Empty = true)
    {
        if (Empty)
        {
            Head = NULL;
        }
        else
        {
            Head = new TMyCard();
            for (int i = Hearts; i <= Spades; i++)
            {
                for (int k = Two; k < Joker; k++)// Jocker not used !!!!!!!
                {
                    TMyCard* tmpCard = new TMyCard((MySuit)i, (MyCardName)k);
                    tmpCard->setNextCard(Head);
                    //   tmpCard->setOwner();
                    Head = tmpCard;
                }
            }
        }
    }
    ~TMyDeck()
    {}
    
    void AddCard(TMyCard* Card)
    {
        if (Card)
        {
            TMyCard* tmp = Head;
            Head = Card;
            Head->setNextCard(tmp);
        }
    }

    TMyCard* GetCard()
    {        
        TMyCard* tmp = Head;
        if (Head)
        {
            Head = Head->getNextCard();
            tmp->setNextCard(NULL);
            return tmp;
        }
        else
            return NULL;
    }

    void Clear()
    {
        // нужно очистить память
        Head = NULL;       
    }

    void Show(int x, int y)
    {
        if (Head)
        {
            TMyCard* tmp = Head;
            int counter = 0;
            while (tmp)
            {
                tmp->Show(x + counter, y + counter);
                tmp = tmp->getNextCard();
                counter += 3;
            }
        }
    }

    int DecSumm()
    {
        int sum = 0;
        if (Head)
        {
            TMyCard* tmp = Head;
            while (tmp)
            {
                sum += tmp->CardValue();
                tmp = tmp->getNextCard();
            }
        }

        return sum;
    }

private:
    TMyCard* Head;
   // TMyCard* Head;

};

const int PlayerCount = 4; // with casino

// игровой стол
class TMyTable
{
public:
    TMyTable() 
    {
        Deck = new TMyDeck(false);
        Players = new TMyDeck[PlayerCount]; //4 игрока вместе с казино
        for (size_t i = 0; i < PlayerCount; i++)
        {
        //    Players[i] = NULL;
        }

    }
    ~TMyTable()
    {
        delete Deck;
        delete[] Players;
    }

    void Play()
    {
        bool playing = true;
        char ch;
        bool PlayersStatus[PlayerCount] = { 1,1,1,1 }; //0 - not play, 1 - play

        for (size_t i = 0; i < PlayerCount; i++)
        {
            Players[i].AddCard(Deck->GetCard());
        }
        for (size_t i = 0; i < PlayerCount; i++)
        {
            Players[i].AddCard(Deck->GetCard());
        }
    
        while (playing)
        {
            playing = false;
            for (size_t i = 0; i < PlayerCount; i++)
            {
                if (PlayersStatus[i])
                    playing = true;
            }

            for (size_t i = 0; i < PlayerCount; i++)
            {
                ShowTable();
                if (Players[i].DecSumm()>20)
                {
                    PlayersStatus[i] = false;
                    continue;
                }
                if (PlayersStatus[i])
                {
                    gotoXY(5, 40, 15, 94);
                    cout << "Player " << i << "\n" << "Do You need a card? ([Y]es, [N]o, [E]xit, ): ";

                    cin >> ch;
                    restoreColor();
                    switch (ch)
                    {
                    case 'Y':
                    case 'y':
                        Players[i].AddCard(Deck->GetCard());
                        break;
                    case 'N':
                    case 'n':
                        PlayersStatus[i] = false;
                        break;
                    case 'E':
                    case 'e':
                        playing = false;
                        break;
                    default:
                        break;
                    }

                    ShowTable();
                    if (Players[i].DecSumm() > 20)
                    {
                        PlayersStatus[i] = false;
                        continue;
                    }
                }

                if (!playing) break;
            }
        }

        }


    void ShowTable()
    {
        system("cls");
        for (size_t i = 0; i < PlayerCount; i++)
        {
            if (i == 0)
            {
                gotoXY(5 + 2 * 10, 2, 15, 92);
                cout << "Player " << i << " Casino = " << Players[i].DecSumm();
                restoreColor();
                Players[i].Show(5 + 2 * 10, 3);
            }
            else
            {
                gotoXY(5 + (i - 1) * 25, 16, 15, 92);
                cout << "Player " << i << " = " << Players[i].DecSumm();
                restoreColor();
                Players[i].Show(5 + (i-1) * 25, 17);

            }
        }     
    }

    void ShowResults()
    {
        system("cls");
        cout << "Results: \n";
        for (size_t i = 0; i < PlayerCount; i++)
        {
            if (i == 0)
            {
                cout << "Player " << i << " Casino = " << Players[i].DecSumm();
            }
            else
            {
                cout << "Player " << i << " = " << Players[i].DecSumm();
            }
            cout << "\n";
        }
        cout << "\n";
        system("Pause");
    }

private:
    TMyDeck* Deck;
    TMyDeck* Players;
    
};


int main()
{
    system("chcp 1251");  // переходим на русский язык в консоли
    setlocale(LC_ALL, "");
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN, 0);


// Неделя №6
//Задание 1.
//Написать программу, которая на основе классов реализует
//карточную игру Блэк-Джек.
    {
        system("CLS");
        cout << "\nHomeWork #6. Task #1 (Black Jack)\n";

        TMyTable Table1;
        Table1.Play();
        Table1.ShowResults();
       
    }
/*
Задание 2.
Написать класс, реализующий работу с комплексными
числами. Обязательно реализовать подсчет количества
объектов класса (используя статическую переменную-
член класса), а также статическую функцию, которая
показывает количество объектов.
Задание 3.
Реализуйте класс «умного указателя», а также код по тестированию
данного класса.
    
    */



}
