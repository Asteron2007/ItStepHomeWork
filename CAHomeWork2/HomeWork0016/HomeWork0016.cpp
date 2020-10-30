// HomeWork0016.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <ctime>


using namespace std;

int main()
{
    /* Неделя №16
         Задание 1.
         Написать программу формирования частотного словаря
         появления отдельных слов в некотором тексте.Обеспечить:
     1. Чтение исходного текста из файла;
     2. Вывод информации обо всех словах;
     3. Вывод информации о наиболее часто встречающемся слове;
     4. Запись результата в файл.
         При разработке программы использовать словарь типа  map.*/

    {
        ifstream RFile;
        string line, Word;

        map <string, int> WordMap;/* = { { "Mother", 37 },
                                    { "Father", 40 },///map явно инициализирована
                                    { "Brother", 15 },
                                    { "Sister", 20 },
                                    { "Sister", 19 } };*/
        map <string, int>::iterator  it, itMax;

        RFile.open("read0016.txt");
        if (RFile.is_open())
        {
            while (getline(RFile, line))
            {
                istringstream ss(line);
                while (ss >> Word)
                {
                    it = WordMap.find(Word);
                    if (it != WordMap.end())
                        it->second += 1;
                    else
                        WordMap.insert(pair<string, int>(Word, 1));
                }
            }
        }
        RFile.close();

        ofstream WFile("Write0016.txt");
        itMax = WordMap.begin();
        for (it = WordMap.begin(); it != WordMap.end(); ++it)
        {
            if (itMax->second < it->second)
                itMax = it;
            cout << it->first << " : " << it->second << endl;
            WFile << it->first << " : " << it->second << endl;
        }
        WFile << "This word is Frequerency word" << itMax->first << " : " << itMax->second << endl;

        WordMap.clear();

        WFile.close();

        cout << "Press enter...";
        cin >> Word;

    }

    /*
           Задание 2.
        Написать программу «Автоматизированная информаци -
        онная система ЖД вокзала».Система содержит : сведения
        об отправлении поездов дальнего следования.Для каждого
        поезда указываем : номер, время отправления, станцию
        назначения.Обеспечить :
        • Ввод данных в систему;
        • Вывод информации о всех поездах;
        • Вывод информации о запрашиваемом поезде;
        • Использовать контейнерный класс vector.
    */
    {
        struct TMyTrain
        {
            int Number;
            //time_t  StartTime;// число секунд с January 1,1970 (не заморачиваемся переводом )
            tm  StartTime;

            string DeliveryStation;

        };
        enum TMyAction
        {
            Exit = 0,
            Edit = 1,
            Add = 2,
            Show = 3,
            Save = 4,
            Load = 5,
        };
        bool Working = true;
        vector<TMyTrain> TrainList;
        int myAction = 0;
        string fName = "test.txt";
        ifstream RFile;
        ofstream WFile;
        string line, Word;


        while (Working)
        {
            cout << "\n\nTrain information system:\n" << Exit << " - Exit\n"
                << Edit << " - Edit\n"
                << Add << " - Add\n"
                << Show << " - Show\n"
                << Save << " - Save\n"
                << Load << " - Load\nEnter action:  ";
            cin >> myAction;

            TMyTrain tmpTrain;// = { 0, time(NULL), "" };
            vector<TMyTrain>::iterator it;
            //cout << ctime(&tmpTrain.StartTime) << "\n";

            switch (myAction)
            {
            case Exit:
                Working = false;
                break;
            case Edit:
                cout << "\nEnter train number to edit: ";
                cin >> tmpTrain.Number;

                for (it = TrainList.begin(); it != TrainList.end(); ++it)
                {
                    if (it->Number == tmpTrain.Number)
                    {
                        break;
                    }
                }
                cout << "\nEnter train start time (format HH MM SS): ";
                cin >> tmpTrain.StartTime.tm_hour >> tmpTrain.StartTime.tm_min >> tmpTrain.StartTime.tm_sec;
                cout << "\nEnter train delivery station: ";
                cin >> tmpTrain.DeliveryStation;
                it->StartTime = tmpTrain.StartTime;
                it->DeliveryStation = tmpTrain.DeliveryStation;

                break;
            case Add:
                cout << "\nEnter train number to add: ";
                cin >> tmpTrain.Number;
                cout << "\nEnter train start time (format HH MM SS): ";
                cin >> tmpTrain.StartTime.tm_hour >> tmpTrain.StartTime.tm_min >> tmpTrain.StartTime.tm_sec;
                cout << "\nEnter train delivery station: ";
                cin >> tmpTrain.DeliveryStation;
                TrainList.push_back(tmpTrain);

                break;
            case Show:
                cout << "\nTrain list:\n";
                if (TrainList.empty())
                    cout << "TrainList is empty";
                else
                    for (it = TrainList.begin(); it != TrainList.end(); ++it)
                    {
                        cout << "TrainNumber: " << it->Number;
                        cout << " StartTime: " << it->StartTime.tm_hour << ":" << it->StartTime.tm_min
                            << ":" << it->StartTime.tm_sec << "\n";
                        cout << "DeliveryStation: " << it->DeliveryStation << "\n\n";
                    }
                break;
            case Save:
                cout << "\nTrain list:\n";
                //cin >> fName;
                WFile.open(fName);

                for (it = TrainList.begin(); it != TrainList.end(); ++it)
                {
                    WFile << it->Number << "\n";
                    //WFile << it->StartTime << "\n";
                    WFile << it->StartTime.tm_hour << ":" << it->StartTime.tm_min
                        << ":" << it->StartTime.tm_sec << "\n";

                    WFile << it->DeliveryStation << "\n";
                }
                WFile.close();
                cout << "Save complete!";
                break;
            case Load:
                cout << "\nEnter file name:\n";
                //cin >> fName;

                RFile.open(fName);
                if (RFile.is_open())
                {
                    TrainList.clear();
                    do
                    {
                        if (getline(RFile, line))
                            tmpTrain.Number = stoi(line);
                        else break;

                        if (getline(RFile, line))
                        {
                            istringstream ss(line);
                            if (getline(ss, Word, ':'))
                                tmpTrain.StartTime.tm_hour = atoi(Word.c_str());
                            if (getline(ss, Word, ':'))
                                tmpTrain.StartTime.tm_min = atoi(Word.c_str());
                            if (ss >> Word)
                                tmpTrain.StartTime.tm_sec = atoi(Word.c_str());
                        }
                        else break;
                        if (getline(RFile, line))
                            tmpTrain.DeliveryStation = line;
                        else break;
                        TrainList.push_back(tmpTrain);
                    } while (!RFile.eof());

                    RFile.close();
                    cout << "Load complete!";
                }
                else
                    cout << "File not found!";
                break;
                /*

                time_t now = time(0);

   cout << "Number of sec since January 1,1970:" << now << endl;

   tm *ltm = localtime(&now);

   // print various components of tm structure.
   cout << "Year" << 1970 + ltm->tm_year<<endl;
   cout << "Month: "<< 1 + ltm->tm_mon<< endl;
   cout << "Day: "<<  ltm->tm_mday << endl;
   cout << "Time: "<< 1 + ltm->tm_hour << ":";
   cout << 1 + ltm->tm_min << ":";
   cout << 1 + ltm->tm_sec << endl;










                time_t tStart;
int yy, month, dd, hh, mm, ss;
struct tm whenStart = {0};
const char *zStart = startTime.c_str();

sscanf(zStart, "%d/%d/%d %d:%d:%d", &yy, &month, &dd, &hh, &mm, &ss);
whenStart.tm_year = yy - 1900;
whenStart.tm_mon = month - 1;
whenStart.tm_mday = dd;
whenStart.tm_hour = hh;
whenStart.tm_min = mm;
whenStart.tm_sec = ss;
whenStart.tm_isdst = -1;

tStart = mktime(&whenStart);
                */
            default:
                Working = false;
                break;
            }

        }

    }

    // реализовано в задании 2

    /*Домашнее задание №16 Задание 3.
Используя контейнер map реализовать программу — словарь. 
Основные возможности :
1. Поиск слова;
2. Добавление, удаление, редактирование слов;
3. Чтение и запись словаря в файл.
*/
   
    cout << "End of program" << std::endl;

}