#include <iostream>
#include <string>
using namespace std;

const unsigned vol = 100;
//enum TGenre {
//    gNone = 0,
//    gAction = 1,
//    gDrama = 2,
//    gVestern = 3,
//    gComedy = 4,
//    gHorror = 5,
//    gOther = 6
//};
//enum TEditor {
//    eFellini = 0,
//    eRitchie = 1,
//    eStone = 2,
//    eAllen = 3,
//    eBrooks = 4,
//    eTarantino = 5,
//    eScorsese = 6
//};
//enum TCaption {
//    c101_dalmatian = 0,
//    c102_dalmatian = 1,
//    c103_dalmatian = 2,
//    c104_dalmatian = 3,
//    c105_dalmatian = 4,
//    c106_dalmatian = 5,
//    c107_dalmatian = 6
//};
const int GenreCount = 7;
char GenreCaptions[GenreCount][10] = {
    "Unknow",
    "Action",
    "Drama",
    "Western",
    "Comedy",
    "Horror",
    "Other"
};
const int EditorCount = 7;
char Editor_list[EditorCount][10] = {
    "Fellini",
    "Ritchie",
    "Stone",
    "Allen",
    "Brooks",
    "Tarantino",
    "Scorsese"
};
const int CaptionCount = 7;
char Caption_list[CaptionCount][14] = {
    "101 dalmatian",
    "102 dalmatian",
    "103 dalmatian",
    "104 dalmatian",
    "105 dalmatian",
    "106 dalmatian",
    "107 dalmatian"
};



struct tMovie {
    //TCaption Caption;
    char Caption[vol];
    //TEditor Editor;
    char Editor[vol];
    //TGenre Genre;
    char Genre[vol];
    int Rating;
    double Price;
    void RandomInit()
    {
        strcpy_s(Caption, Caption_list[rand() % CaptionCount]);
        cout << Caption;
        //Editor = (TEditor)(rand() % EditorCount);
        strcpy_s(Editor, Editor_list[rand() % EditorCount]);
        Rating = rand() % 10;
        Price = (float)rand() / 100;
        //Genre = (TGenre)(rand() % GenreCount);
        strcpy_s(Genre, GenreCaptions[rand() % GenreCount]);

    }
    void print()
    {
        cout << "Caption: " << Caption << "\n";
        //cout << "Genre:\t " << GenreCaptions[Genre] << "\n";
        cout << "Genre:\t " << Genre << "\n";
        //cout << "Editor:\t " << Editor_list[Editor] << "\n";
        cout << "Editor:\t " << Editor << "\n";
        cout << "Rating:\t " << Rating << "\n";
        cout << "Price:\t " << Price << "\n";
        cout << "----------------------------------------\n";
    }
};

const int MovieCount = 20;
struct MediaMarket
{
    tMovie Movie[MovieCount];
    tMovie* Init()
    {
        for (size_t i = 0; i < MovieCount; i++)
        {
            Movie[i].RandomInit();
        }
        return Movie;
    }////////Отсюда вернуть Movie
    void Print(int index = -1)
    {
        if ((index < 0) || (index >= MovieCount))
        {
            for (size_t i = 0; i < MovieCount; i++)
            {
                Movie[i].print();
            }
        }
        else
        {
            cout << "--------------- Film " << index + 1 << " ----------------\n";
            Movie[index].print();
        }

    }
};
void print_all(MediaMarket market)
{
    for (size_t i = 0; i < MovieCount; i++)
    {
        market.Print(i);
    }
}
int set_test()
{
    int t;
    system("cls");
    setlocale(LC_ALL, "rus");
    cout << "Выберите задачу:\n";
    cout << "1. Найти фильм по названию.\n";
    cout << "2. Найти фильм по жанру.\n";
    cout << "3. Найти фильм по режиссёру.\n";
    cout << "4. Самый популярный фильм в жанре.\n";
    cout << "5. Показать всю фильмотеку.\n";
    cout << "6. Пополнить фильмотеку.\n";
    cout << "7. Выход из фильмотеки.\n\n";
    cin >> t;
    return t;
}

int set_var(int t, MediaMarket market, tMovie* Movie)
{
    char fn[vol];
    int c = 0;
    if (t == 1)
    {
        cout << "Введите название фильма: ";
        cin.get();
        cin.getline(fn, vol);
        for (size_t i = 0; i < MovieCount; i++)
        {
            if (!strcmp(fn, market.Movie[i].Caption))
            {
                market.Print(i);
                c++;
            }
        }
        if (c == 0)
        {
            cout << "Фильма такого жанра в фильмотеке нет.\n";
        }
    }
    if (t == 2)
    {
        cout << "Введите жанр фильма: ";
        cin.get();
        cin.getline(fn, vol);
        for (size_t i = 0; i < MovieCount; i++)
        {
            if (!strcmp(fn, market.Movie[i].Genre))
            {
                market.Print(i);
                c++;
            }
        }
        if (c == 0)
        {
            cout << "Фильма такого жанра в фильмотеке нет.\n";
        }
    }
    if (t == 3)
    {
        cout << "Введите режиссёра фильма: ";
        cin.get();
        cin.getline(fn, vol);
        for (size_t i = 0; i < MovieCount; i++)
        {
            if (!strcmp(fn, market.Movie[i].Editor))
            {
                market.Print(i);
                c++;
            }
        }
        if (c == 0)
        {
            cout << "Фильма такого режиссёра в фильмотеке нет.\n";
        }
    }
    if (t == 4)
    {
        double r = 0;
        double fr; //желаемый рейтинг
        c = 0;
        int k = 0, m = 0, d = 0;
        const char mm[3][10] = { " фильм "," Фильма "," фильмов " };
        cout << "Введите жанр фильма для поиска самого популярного: ";
        cin.get();
        cin.getline(fn, vol);
        cout << "Введите минимальный желаемый рейтинг: "; cin >> fr;

        for (size_t i = 0; i < MovieCount; i++)
        {
            if (!strcmp(fn, market.Movie[i].Genre))
            {
                c = i;
                k++;
            }
        }
        r = market.Movie[c].Rating;
        if (k == 0)
        {
            cout << "Фильма такого жанра в фильмотеке нет.\n";
        }
        if (k == 1)
        {
            cout << "В фильмотеке только один фильма такого жанра.\n";
            market.Print(c);

        }
        if (k > 1)
        {
            k = 0;
            for (size_t i = 0; i < MovieCount; i++)
            {
                if ((!strcmp(fn, market.Movie[i].Genre)))
                {
                    k++;
                    if ((market.Movie[i].Rating >= fr))
                    {
                        d++;
                        market.Print(i);
                    }
                }

            }
            if (k > d)
            {
                if ((k - d) == 1)
                {
                    cout << "В фильмотеке ещё " << k - d << mm[0] << "жанра " << fn << ", но с более низким рейтингом.\n";
                }
                if (((k - d) > 1) && ((k - d) < 5))
                {
                    cout << "В фильмотеке ещё " << k - d << mm[1] << "жанра " << fn << ", но с более низким рейтингом.\n";
                }
                if (((k - d) >= 5))
                {
                    cout << "В фильмотеке ещё " << k - d << mm[2] << "жанра " << fn << ", но с более низким рейтингом.\n";
                }


            }
        }


    }
    if (t == 5)
    {
        print_all(market);
    }

    if (t == 6)
    {
        tMovie* MovieAdd = new tMovie[MovieCount + 1];
        for (size_t i = 0; i < MovieCount; i++)
        {
            MovieAdd[i] = Movie[i];
        }
        cout << "Вводим данные нового фильма фильмотеки:\n";
        cout << "Введите название фильма: ";
        cin.get();
        cin.getline(MovieAdd[MovieCount].Caption, vol);
        //cin.get();
        cout << "Введите режиссера фильма: ";
        //cin.get();
        cin.getline(MovieAdd[MovieCount].Editor, vol);
        cout << "Введите жанр фильма: ";
        //cin.get();
        cin.getline(MovieAdd[MovieCount].Genre, vol);
        cout << "Введите рейтинг фильма: ";
        cin >> MovieAdd[MovieCount].Rating;
        cout << "Введите стоимость фильма: ";
        cin >> MovieAdd[MovieCount].Price;
        cin.get();
        setlocale(LC_ALL, "rus");
        cout << "Название: " << MovieAdd[MovieCount].Caption << "\n";
        //cout << "Genre:\t " << GenreCaptions[Genre] << "\n";
        cout << "Жанр:\t " << MovieAdd[MovieCount].Genre << "\n";
        //cout << "Editor:\t " << Editor_list[Editor] << "\n";
        cout << "Режиссёр:\t " << MovieAdd[MovieCount].Editor << "\n";
        cout << "Рейтинг:\t " << MovieAdd[MovieCount].Rating << "\n";
        cout << "Стоимость:\t " << MovieAdd[MovieCount].Price << "\n";
        cout << "----------------------------------------\n";
    }
    if (t == 7)
    {
        return 0;
    }
}
//struct name {
//    char regicer[vol];
//    char films[vol];
//    int god;
//    int dollar;
//};
//name lenta[40];

int main()
{
    setlocale(LC_ALL, "rus");
    MediaMarket market;
    tMovie* MovieAdd = market.Init();

    //market.Init();

    do
    {
        set_var(set_test(), market, MovieAdd);
        system("pause");
    } while (set_test() != 7);

    return 0;
}