// HomeWork0010.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <windows.h>
#include <io.h>
#include <stdio.h>


using namespace std;


class TMyFileManager
{
public:
	TMyFileManager()
	{
		strcpy_s(source, "Lab.txt");
		strcpy_s(destination, "Lab-new.txt");
	}
	~TMyFileManager()
	{

	}

	void MyCreateFile()
	{
		FILE* ptrFile2 = fopen(source, "w");// C:\Users\Book\source\repos\CAHomeWork2

		if (ptrFile2 != NULL)
		{
			fclose(ptrFile2);
			cout << "File created\n";
		}

		cout << "\n";
		system("Pause");

	}

	void MyDeleteFile()
	{
		if (remove(source) != 0)
			cout << "Error!\n Couldn't remove file.	Check filename...\n";
		else
			cout << "File removed: " << source << "\n";
	}

	void MyRenameFile()
	{
		if (rename(source, destination) != 0)
			cout << "Error!\n Couldn't rename file.	Check old and new filename...\n\n";
		else
		{
			cout << "File: "<<source<<"\n";
			cout << "Renamed into file: " << source << "\n";
		}
	}

	void MyPrintFileToScreen()
	{
		const size_t strLen = 256;
		char str[strLen];
		
		FILE* ptrFile1 = fopen(source, "r");//fopen("c:/test/test.txt", "r");// C:\Users\Book\source\repos\CAHomeWork2
		
		if (ptrFile1 != NULL)
		{
			while (!feof(ptrFile1))
			{
				fgets(str, strLen, ptrFile1);
				cout << str;
			}

			fclose(ptrFile1);
		}
		cout << "\nOut complete\n";
		cout << "\n";
		system("Pause");
	}

	int setSource(char* source = NULL)
	{
		if (source == NULL)
		{
			cout << "\n";
			cout << "Enter file path and name: ";
			cin.getline(source, _MAX_PATH);
			if (_access(source, 00) == -1)
			{
				cout << "The file does not exist!";
				return 0;
			}
		}
		else
		{
			strcpy(this->source, source);
		}
	}

	int setDestination(char* destination = NULL)
	{
		if (destination == NULL)
		{
			char answer[20];
			cout << "\n";
			cout << "Enter new file path and name: ";
			cin.getline(destination, _MAX_PATH);
			if (_access(destination, 00) == 0) {
				cout << "The file is exist. Overrite it (1-Yes/2-No): ";

				cin.getline(answer, 20);
				if (!strcmp(answer, "2"))
				{
					cout << "Operation aborted\n";
					return 0;
				}
				else if (strcmp(answer, "1"))
				{
					cout << "Incorect operation\n";
					return 0;
				}
				if (_access(destination, 02) == -1)
				{
					cout << "File read/write error\n";
					return 0;
				}
			}
		}
		else
		{
			strcpy(this->destination, destination);
		}
	}

	bool MyCopyFile()//(const char* source, const char* destination)
	{
		const int size = 65536;
		FILE* src, * dest;
		// Open file
		if (!(src = fopen(source, "rb")))
		{
			return false;
		}
		//Получение дескриптора файла
		int handle = _fileno(src);
		char* data = new char[size];
		if (!data) 
		{
			return false;
		}
		if (!(dest = fopen(destination, "wb"))) 
		{
			delete[]data;
			return false;
		}
		int realsize;
		while (!feof(src)) 
		{
			realsize = fread(data, sizeof(char), size, src);
			fwrite(data, sizeof(char), realsize, dest);
		}
		delete[]data;
		fclose(src);
		fclose(dest);
		return true;
	}	

	void MyChangeDir()
	{
		
	}

	bool MyShowDir()
	{
		GetCurrentDirectory(sizeof(source), source);
		// Show current dirrectory
		_finddata_t find;
		char pathfind[MAX_PATH];
		strcpy(pathfind, source);
		strcat(pathfind, "\\*.*");
		char info[MAX_PATH];
		// Start search
		int result = _findfirst(pathfind, &find);
		cout << "File list:\n";
		int flag = result;
		if (flag == -1) 
		{
			cout<< "Directory does not exist.\n";
			return false;
		}
		while (flag != -1) {
			if (strcmp(find.name, ".") && strcmp(find.name, ".."))
			{
				// File or Dir
				find.attrib& _A_SUBDIR ? strcpy(info, " DIR ") :
					strcpy(info, " File ");
				cout << find.name << info;
				cout << "\n";
			}
			flag = _findnext(result, &find);
		}
		cout << source << info;
		cout << "\n";
		_findclose(result);
		return true;
	}

	void OutHelp()
	{
		cout << "\t\tFile manager v1.0\n";
		cout << "[00] Help\n";
		cout << "[01] Change directory - [chdir]\n";
		cout << "[02] Delete file - [delete]\n";
		cout << "[03] Rename file - [rename]\n";
		cout << "[04] Show files  - [dir]\n";
		cout << "[05] Create file - [create]\n";
		cout << "[06] Out file    - [out]\n";
		cout << "[07] Copy file	  - [copy]\n";
		//cout << "[08]  file   - [remove]\n";
		cout << "[09] Exit        - [exit]\n";
	}

	int StartFileManager()
	{
		bool Working = true;
		int command = 0;
		OutHelp();
		while (Working)
		{
			do
			{
				cin >> command;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(32767, '\n');
					cout << "Wrong choise!" << "\n";
				}
			} while (cin.fail());
		
			switch (command)
			{
			case 0:
				OutHelp();
				command = 0;
				break;
			case 1:
				setSource();
				MyChangeDir();
				break;
			case 2:
				setSource();
				MyDeleteFile();
				break;
			case 3:
				setSource();
				setDestination();
				MyRenameFile();
				break;
			case 4:
				MyShowDir();
				break;
			case 5:
				setSource();
				MyCreateFile();
				break;
			case 6:
				setSource();
				MyPrintFileToScreen();
				break;
			case 7:
				setSource();
				setDestination();
				MyCopyFile();
				break;
			case 9:
				Working = false;
				break;
			default:
				Working = false;
				break;
			}
		}
		return 0;
	}


private:
	char source[_MAX_PATH];//MAX_PATH - length
	char destination[_MAX_PATH];
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	//Задание 1.
	//Дан текстовый файл. Удалить из него последнюю строку.
	//Результат записать в другой файл.
	{
		const size_t strLen = 256;
		char str[strLen];

		FILE* ptrFile1 = fopen("./test/lab1.txt", "r");// C:\Users\Book\source\repos\CAHomeWork2
		FILE* ptrFile2 = fopen("./test/Labnew.txt", "w");// C:\Users\Book\source\repos\CAHomeWork2

		if ((ptrFile1 != NULL) && (ptrFile2 != NULL))
		{
			while (!feof(ptrFile1))
			{
				fgets(str, strLen, ptrFile1);
				if (!feof(ptrFile1))
					fputs(str, ptrFile2);
				//cout << str;
			}

			fclose(ptrFile1);
			fclose(ptrFile2);
			cout << "Record complete\n";
		}
		else
			cout << "Record error\n";

		cout << "\n";
		system("Pause");
	}

	//Задание 2.
	//Дан текстовый файл. Найти длину самой длинной строки.
	{
		const size_t strLen = 256;
		char str[strLen];
		size_t MaxStrLen = 0;

		FILE* ptrFile1 = fopen("./test/lab1.txt", "r");// C:\Users\Book\source\repos\CAHomeWork2

		if (ptrFile1 != NULL)
		{
			while (!feof(ptrFile1))
			{
				fgets(str, strLen, ptrFile1);
				if (strlen(str) > MaxStrLen)
					MaxStrLen = strlen(str);
			}

			fclose(ptrFile1);
			cout << "Maximum string length is " << MaxStrLen << " symbols.\n";
		}
		else
			cout << "File open error.\n";

		cout << "\n";
		system("Pause");
	}


	//Задание 3.
	//Дан текстовый файл. Посчитать сколько раз в нем встречается
	//заданное пользователем слово.
	{
		const size_t StrLen = 256;
		char str[StrLen];
		char SearchStr[StrLen] = "if";
		size_t CountSubStr = 0;
		char* IndexStr;
		FILE* ptrFile1 = fopen("./test/lab1.txt", "r");// C:\Users\Book\source\repos\CAHomeWork2

		if (ptrFile1 != NULL)
		{
			while (!feof(ptrFile1))
			{
				fgets(str, StrLen, ptrFile1);
				IndexStr = strstr(str, SearchStr);
				while (IndexStr != NULL)
				{
					CountSubStr++;
					IndexStr = strstr((IndexStr + strlen(SearchStr)), SearchStr);
				}
			}

			fclose(ptrFile1);
			if (CountSubStr == 0)
				cout << "SubString not found.\n";
			else
				cout << "SubString count = " << CountSubStr << "\n";
		}
		else
			cout << "File open error.\n";
		cout << "\n";
		system("Pause");
	}


	
	//Задание 4.
	//Дан текстовый файл. Найти и заменить в нем заданное
	//слово. Что искать и на что заменять определяется пользователем.
	{
		const size_t MaxStrLen = 256;
		char str[MaxStrLen];
		char NewStr[MaxStrLen];
		char SearchStr[MaxStrLen] = "if";
		char ReplaceStr[MaxStrLen] = "REPLACEif";
		char FileName1[] = "./test/lab1.txt";
		char FileNametmp[] = "./test/Lab1.tmp";

		char* IndexStr;
		FILE* ptrFile1 = fopen(FileName1, "r");// C:\Users\Book\source\repos\CAHomeWork2
		FILE* ptrFile2 = fopen(FileNametmp, "w");// C:\Users\Book\source\repos\CAHomeWork2

		if ((ptrFile1 != NULL) && (ptrFile2 != NULL))
		{
			while (!feof(ptrFile1))
			{
				fgets(str, MaxStrLen, ptrFile1);
				
				IndexStr = strstr(str, SearchStr);
				strcpy(NewStr, str);
				while (IndexStr != NULL)
				{
				
					NewStr[IndexStr - str] = '\0';
					strcat(NewStr, ReplaceStr);
					strcat(NewStr, str + (IndexStr - str) + strlen(SearchStr));
					strcpy(str, NewStr);
					IndexStr = strstr((IndexStr + strlen(ReplaceStr)), SearchStr);					
				}	
				fputs(str, ptrFile2);
			}

			fclose(ptrFile1);
			fclose(ptrFile2);	
			TMyFileManager MyFileManager1;
			MyFileManager1.setSource(FileName1);
			MyFileManager1.MyDeleteFile();
			MyFileManager1.setSource(FileNametmp);
			MyFileManager1.setDestination(FileName1);
			MyFileManager1.MyRenameFile();
			cout << "SubString replaced complete.\n";
		}
		else
			cout << "File open error.\n";
		cout << "\n";
		system("Pause");
	}

	//	Задание 5.
	//Создайте программу «Простейший файловый менеджер»:
	
	TMyFileManager MyFileManager1;
	MyFileManager1.StartFileManager();

	//1. Создание нового файла в текущем каталоге;
		//MyFileManager1.MyCreateFile();

	//2. Удаление файла из текущего каталога;
		//MyFileManager1.MyDeleteFile();

	//3. Переименование файла в текущем каталоге;
		//MyFileManager1.MyRenameFile();

	//4. Перемещение файла из текущего каталога в указанный
	//пользователем каталог;
		//MyFileManager1.MyRemoveFile();

	//5. Вывод содержимого указанного пользователем файла
	//из текущего каталога на экран.
		//MyFileManager1.MyPrintFileToScreen();


	   	
	if (!MyFileManager1.MyCopyFile())//(source, destination))
	{
		cout << "File read/write error\n";
	}

}
