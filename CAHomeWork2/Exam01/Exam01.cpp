// Exam01.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.



#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <map>
#include <unordered_map>
#

// regex_match(question, regex(".*hello*."));
//for (auto entry : database)
//{
//	auto expression = regex(".*" + entry.first + "*.");
//	if (regex_match(question, expression))
//	{
//		cout << entry.second;
//	}
//}

using namespace std;

const string ConfigFileName = "test.cfg";
const string TestFileName = "test.dat";

enum TMyWorkingModeEnum
{
	AdminMode = 1,
	TestMode = 2,
	RegisterNewUserMode = 3,
	ExitMode = 4,
	ShowResultMode = 5
};

const map<int, string> TMyTestsSectionList = {
	{10000, "Физика(раздел)"},
	{20000, "Математика(раздел)"},
	{30000, "BioLogic (Section)"},
	{40000, "BioLogic (Section)"},
	{50000, "Electric (Section)"},
	{60000, "Math (Section)"}

};

struct TMyTestSectionStruct
{
	int ID;
	string Name;
};

struct TMyTestStruct
{


};

struct TMyQuestStruct
{
	int ID;
	//int Section;

	string Notes;
	int Mark;
	int Answer;
	vector <string> Answers;

	TMyQuestStruct* PackStruct(int ID, string Notes, int Mark, int Answer, vector <string> Answers)
	{
		TMyQuestStruct* tmpQuest = new TMyQuestStruct();

		tmpQuest->ID = ID;
		tmpQuest->Notes = Notes;
		tmpQuest->Mark = Mark;
		tmpQuest->Answer = Answer;
		tmpQuest->Answers.assign(Answers.begin(), Answers.end());

		return tmpQuest;
	}
	void Show()
	{
		cout << ID << ". " << Notes << "\nMax mark = " << Mark << " (Answer = " << Answer << ")\n";
		int ind = 0;
		for (auto& i : Answers)
		{
			ind++;
			cout << " " << ind << ". " << i;
		}
		cout << "\n";
	
	}

};

struct TMyAdmin
{
	string Name;
	string Login;
	string Password;
	TMyAdmin(string Name = "", string Login = "", string Password = "")
	{
		this->Login = Login;
		this->Name = Name;
		this->Password = Password;
	}
	void LoadFromFile(ifstream& file)
	{
		if (file.is_open())
		{
			if (!file.eof())
			{
				file >> Name;
				file >> Login;
				file >> Password;
			}
		}
	}
	void SaveToFile(ofstream& file)
	{
		if (file.is_open())
		{
			file << Name << " ";
			file << Login << " ";
			file << Password << " ";
		}
	}
	void Show()
	{
		cout << "Admin: " << Name << " Login: " << Login << " Password: " << Password << "\n";
	}
};

struct TMyUser
{
	size_t ID;
	string Name;
	string Adress;
	string Phone;
	string Login;
	string Password;

	map<int, > TestResult;

	void LoadFromFile(ifstream& file)
	{
		if (file.is_open())
		{
			if (!file.eof())
			{
				file >> ID;
				file >> Name;
				file >> Login;
				file >> Password;
				file >> Adress;
				file >> Phone;
			}
		}
	}
	void SaveToFile(ofstream& file)
	{
		if (file.is_open())
		{
			file << ID << " ";
			file << Name << " ";
			file << Login << " ";
			file << Password << " ";
			file << Adress << " ";
			file << Phone << " ";
		}
	}
	void Show()
	{
		cout << "User: " << Name << " ID: " << ID << " Login: " << Login << " Password: " << Password
			<< " Adress: " << Adress << " Phone: " << Phone << "\n";
	}
};

class TMyTestSystem
{
public:
	TMyTestSystem()
	{
		QuestionDataBase.clear();
		TMyQuestStruct tmpQuest;
		//		"Дискретная математика(конкретный тест)",
		vector<string> tmpAnswers({ "Ложь","Истина","Ложь" });
		QuestionDataBase.push_back(*tmpQuest.PackStruct(10011, "Вопрос по Дискретная математика 1", 5, 2, tmpAnswers));

		tmpAnswers = { "Истина","Ложь" };
		QuestionDataBase.push_back(*tmpQuest.PackStruct(10012, "Вопрос по Дискретная математика 2", 5, 1, tmpAnswers));
		
		tmpAnswers = { "Ложь","Истина","Ложь" };
		QuestionDataBase.push_back(*tmpQuest.PackStruct(10013, "Вопрос по Дискретная математика 3", 5, 2, tmpAnswers));
		
		tmpAnswers = { "Ложь","Ложь","Истина" };
		QuestionDataBase.push_back(*tmpQuest.PackStruct(10014, "Вопрос по Дискретная математика 4", 5, 3, tmpAnswers));
			//{115, "Вопрос по Дискретная математика 5", {"Ложь","Истина","Ложь"}, 5, 2},
			//{116, "Вопрос по Дискретная математика 6", {"Ложь","Истина","Ложь"}, 5, 2},
			//{117, "Вопрос по Дискретная математика 7", {"Ложь","Истина"}, 5, 2},
			//{118, "Вопрос по Дискретная математика 8", {"Ложь","Ложь","Ложь", "Истина"}, 5, 4},
			//		Математический анализ(конкретный тест).
			//{111, "Вопрос по Математический анализ 1", {"Ложь","Истина","Ложь"}, 5, 2},
			//{112, "Вопрос по Математический анализ 2", {"Истина","Ложь"}, 5, 1},
			//{113, "Вопрос по Математический анализ 3", {"Ложь","Истина","Ложь"}, 5, 2},
			//{114, "Вопрос по Математический анализ 4", {"Ложь","Ложь","Истина"}, 5, 3},
			//{115, "Вопрос по Математический анализ 5", {"Ложь","Истина","Ложь"}, 5, 2},
			//{116, "Вопрос по Математический анализ 6", {"Ложь","Истина","Ложь"}, 5, 2},
			//{117, "Вопрос по Математический анализ 7", {"Ложь","Истина"}, 5, 2},
			//{118, "Вопрос по Математический анализ 8", {"Ложь","Ложь","Ложь", "Истина"}, 5, 4}
		
			//◉◉Квантовая физика(конкретный тест);
			//◉◉Механика(конкретный тест).

		Work = false;
		Mode = ExitMode;

	}
	~TMyTestSystem()
	{

	}
	string CriptString(string str)
	{
		for (string::iterator str_iter(str.begin()); str_iter != str.end(); ++str_iter)
		{
			*str_iter = *str_iter + 10; // такая вот нехитрая систем шифрования
		}

		return str;
	}
	string DeCriptString(string str)
	{
		for (string::iterator str_iter(str.begin()); str_iter != str.end(); ++str_iter)
		{
			*str_iter = *str_iter - 10; // такая вот нехитрая система шифрования
		}

		return str;
	}
	void ShowTitle()
	{
		cout << "Test System v1.0\n";

	}
	void ShowMode()
	{
		switch (Mode)
		{
		case AdminMode:
			cout << "Admin mode...\n ";
			break;
		case TestMode:
			cout << "Test mode...\n ";
			break;
		case RegisterNewUserMode:
			cout << "Register new user mode...\n";
			break;
		default:
			break;
		}
	}
	void ShowUser()
	{
		ActiveUser.Show();
	}
	void ShowAdmin()
	{
		Admin.Show();
	}
	void SelectMode()
	{
		int tmpMode;
		ShowTitle();
		cout << "Select mode\n 1 - Admin\n 2 - Test\n 3 - Register new user\n 4 - Exit\n";
		cin >> tmpMode;
		Mode = (TMyWorkingModeEnum)tmpMode;
	}
	bool LoadConfig()
	{
		TMyUser* tmpUser = NULL;
		tmpUser = new TMyUser();
		ifstream file(ConfigFileName);
		if (file.is_open())
		{
			Admin.LoadFromFile(file);
			while (!file.eof())
			{
				tmpUser->LoadFromFile(file);
				ActiveUsers.push_back(*tmpUser);
			}

			//ActiveUser.Adress = tmpAdress;
			//ActiveUser.Login = Login;
			//ActiveUser.Name = tmpName;
			//ActiveUser.Password = Password;
			//ActiveUser.Phone = tmpPhone;

			return true;
		}
		else return false;
	}
	void SaveConfig()
	{
		ofstream file(ConfigFileName);

		Admin.SaveToFile(file);
		auto it = ActiveUsers.begin();
		while (it != ActiveUsers.end())
		{
			it->SaveToFile(file);
			++it;
		}

		file.close();
	}
	void RegisterAdmin()
	{
		cout << "\n";
		cout << "Enter login: ";
		cin >> Admin.Login;
		cout << "Enter password: ";
		cin >> Admin.Password;
		cout << "Enter Name: ";
		cin >> Admin.Name;
	}

	void RegisterNewUser()
	{
		string Password;
		string Login;
		TMyAdmin* tmpAdmin = NULL;
		TMyUser* tmpUser = NULL;
		string tmpName;
		string tmpAdress;
		string tmpPhone;

		bool Unique = false;
		while (!Unique)
		{
			auto it = ActiveUsers.begin();
			cout << "\n";
			cout << "Enter login: ";
			cin >> Login;
			while (it != ActiveUsers.end())
			{
				if (it->Login == Login)
				{
					Unique = false;
					break;
				}
				++it;
			}
			Unique = true;
		}




		cout << "Enter password: ";
		cin >> Password;
		cout << "Enter Name: ";
		cin >> tmpName;
		cout << "Enter Adress: ";
		cin >> tmpAdress;
		cout << "Enter Phone: ";
		cin >> tmpPhone;

		srand(time(0));
		Unique = false;
		size_t ID = 0;
		while (!Unique)
		{
			auto it = ActiveUsers.begin();
			ID = rand();

			while (it != ActiveUsers.end())
			{
				if (it->ID == ID)
				{
					Unique = false;
					break;
				}
				++it;
			}
			Unique = true;
		}

		ActiveUser.Adress = tmpAdress;
		ActiveUser.Login = Login;
		ActiveUser.Name = tmpName;
		ActiveUser.Password = Password;
		ActiveUser.Phone = tmpPhone;
		ActiveUser.ID = ID;

		ActiveUsers.push_back(ActiveUser);

	}
	void TestUser()
	{
		//LoadTest();TestFileName
		ShowTitle();
		ShowMode();
		cout << "Section list:\n";
		for (auto& i : TMyTestsSectionList)
		{
			cout << i.first<<" " ;
			cout << i.second;
			cout << "\n";
		}

		int Mark = 0;
		int Answer = 0;
		int Count = 0;
		for (auto& i : QuestionDataBase)
		{
			Count++;
			i.Show();
			cin >> Answer;
			if (Answer == i.Answer)
			{
				cout << "Right\n";
				Mark += i.Mark;
			}
			else
			{
				cout << "Error\n";
			}
		}

		cout << "Your summary mark (mean): " << Mark << "(" << (float)Mark / Count << ")";
		cout << "\n";
	}

	void ShowUserList()
	{
		cout << "\n";
		cout << "User list:\n";
		auto it = ActiveUsers.begin();
		while (it != ActiveUsers.end())
		{
			it->Show();
			cout << "\n";
			++it;
		}
	}
	void Working()
	{

	}
	void Authorization()
	{
		string Password;
		string Login;
		//TMyAdmin* tmpAdmin = NULL;
		//TMyUser* tmpUser = NULL;

		if ((Mode == AdminMode) || (Mode == TestMode) || (Mode == RegisterNewUserMode))
			Work = true;
		else
		{
			cout << "Wrong choice.";
			cout << "\n";
			Work = false;
			return;
		}

		ifstream file(ConfigFileName);
		if (file.is_open() && (Admin.Login != ""))
		{
			ShowTitle();

			switch (Mode)
			{
			case AdminMode:
				ShowMode();
				cout << "Enter login: ";
				cin >> Login;
				cout << "Enter password: ";
				cin >> Password;
				if ((Admin.Login == Login) && (Admin.Password == Password))
				{
					Work = true;
				}
				else
				{
					cout << "Wrong Login or Password!";
					cout << "\n";
					Work = false;
					return;
				}

				ShowUserList();
				break;
			case TestMode:
				ShowMode();
				cout << "Enter login: ";
				cin >> Login;
				cout << "Enter password: ";
				cin >> Password;
				TestUser();

				Work = true;
				break;

			case RegisterNewUserMode:
				ShowMode();
				RegisterNewUser();
				Work = true;
				SaveConfig();
				break;

			default:
				cout << "Wrong choice";
				Work = false;
				return;
				break;
			}
			file.close();
		}
		else // File not exist or Admin login is empty(first run)
		{
			file.close();
			ShowTitle();

			switch (Mode)
			{
			case AdminMode:
				RegisterAdmin();
				break;
			case TestMode:
				break;
			case RegisterNewUserMode:
				RegisterNewUser();
				break;
			default:
				break;
			}
			SaveConfig();
		}


	}
	void ShowResult()
	{
	}
	void NewTest()
	{
		ShowTitle();
		ShowMode();

			//List 

			//for (auto it = TestsList.begin(); it != TestsList.end(); ++it)
			{
			//	cout << it->ID << ": " << it->Name << "\n";;
			}

	}
	void Run()
	{
		//		SelectMode();
		LoadConfig();
		//		Authorization();
		do
		{
			SelectMode();
			Authorization();
			//ShowTitle();
			//ShowMode();
			ShowAdmin();
			ShowUser();

		} while (Work);

		SaveConfig();
	}

private:
	TMyAdmin Admin;
	TMyUser ActiveUser;
	vector<TMyUser> ActiveUsers;
	//vector< TMyTestStruct> TestsList;
	vector<TMyQuestStruct> QuestionDataBase;


	TMyWorkingModeEnum Mode;
	bool Work;
};


int main()
{
	system("chcp 1251");  // переходим на русский язык в консоли
    /*
	Второе задание
Реализовать полнофункциональную систему тестирования.
В системе должны быть 2 режима: Администратор и Тестируемый.
Описание режима работа для Тестируемого (в дальнейшем Гость).
■■ Для входа в систему Гость должен зарегистрироваться. Данная проце-
дура выполняется один раз, при дальнейших входах в систему доступ
идет по логину и паролю.
■■При регистрации нужно указывать ФИО, домашний адрес, телефон.
■■ Важно, чтобы логины для пользователей были уникальными.
■■После входа Гость имеет возможность просмотреть свои предыдущие
результаты тестирования, сдать новое тестирование.
■■ Тестирование может осуществляться по различным категориям зна-
ний. Например:
• Математика (раздел):
◉◉Дискретная математика (конкретный тест);
◉◉Математический анализ (конкретный тест).
• Физика (раздел):
◉◉Квантовая физика (конкретный тест);
◉◉Механика (конкретный тест).
■■После сдачи теста Гость видит результат тестирования, количество
правильно отвеченных вопросов, процент правильных ответов и по-
лученную оценку.
■■ Студент имеет возможность прервать тестирование и продолжить его
тогда, когда ему это будет удобно.
■■Оценивание нужно вести на основании 12-ти балльной системы, при-
вязанной к количеству вопросов теста.
■■Пароли и логины Гостей хранятся в зашифрованном виде.
Описание режима работа для Администратора (в дальнейшем Админ).
■■ В системе может быть только один Админ, логин и пароль Админа за-
дается при первом входе в программу.
■■ В дальнейшем пароль и логин можно изменить (но данную возмож-
ность имеет только Админ).
■■Пароль и логин необходимо хранить только в зашифрованном виде.
■■При работе с системой Админ имеет следующие возможности:
• управление пользователями – создание, удаление, модификация
пользователей;
• просмотр статистики – просмотр результатов тестирования в об-
щем по категориям, по конкретным тестам, по конкретным пользо-
вателям. Результаты просмотра статистики можно вывести в файл;
• управление тестированием – Админ имеет возможность добавлять
категории, тесты, вопросы к тестам, задавать правильные и непра-
вильные ответы, импортировать и экспортировать категории и те-
сты с вопросами из файла (и в файл).
При выполнении задания необходимо в полной мере использовать аппарат
ООП и STL.
Код должен быть читабельным, хорошо прокомментированным, и ис-
пользовать единую систему именования идентификаторов.
	*/
	TMyTestSystem TestSystem;
	TestSystem.Run();

   
}
