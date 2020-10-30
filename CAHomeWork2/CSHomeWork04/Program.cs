using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSHomeWork04
{
    class Program
    {
// 1.Описать структуру Article, содержащую следующие
// поля: код товара; название товара; цену товара.
        struct TMyArticle
        {
            int ID;
            double Price;
            string Name;
            TMyArticleType ArticleType;
        }
//2.Описать структуру Client содержащую поля: код
//клиента; ФИО; адрес; телефон; количество заказов
//осуществленных клиентом; общая сумма заказов клиента.
        struct TMyClient
        {
            int ID;
            string Name;
            string Adress;
            string Phone;
            int TransactionsCount;
            int TotalSumm;
            TMyClientType ClientType;
        }  

//3.Описать структуру RequestItem содержащую поля:
//товар; количество единиц товара.
        struct TMyRequestItem
        {
            int Product;
            double Count;
        }
        //4.Описать структуру Request содержащую поля: код
        //заказа; клиент; дата заказа; перечень заказанных товаров;
        //сумма заказа(реализовать вычисляемым свойством).
        struct TMyRequest
        {
            int RequestID;
            int Client;
            DateTime RequestDate;
            int[] Products;
            TMyPayType PayType;
            public double Summ
            {
                get { return 0; }
                //set { return 0; }
            }

        }

        //5.Описать перечисление ArticleType определяющее
        //типы товаров, и добавить соответствующее поле
        //в структуру Article из задания №1.
        enum TMyArticleType
        {
            artOfficeSupplies,
            artHouseholdChemicals,
            artProducts,
            artClothes,
            artSportsportStock
        }

        //6.Описать перечисление ClientType определяющее
        //важность клиента, и добавить соответствующее поле
        //в структуру Client из задания №2.
        enum TMyClientType
        {
            ctNewClient,
            ctUsualClient,
            ctBlackListClient,
            ctPrivilegedClient,
            ctVitalClient
        }

        //7.Описать перечисление PayType определяющее форму
        //оплаты клиентом заказа, и добавить соответствующее
        //поле в структуру Request из задания №4.
        enum TMyPayType
        {
            CashPayment,
            CashlessPayment
        }


        //8.Придумать класс, описывающий студента.Предусмотреть в нем следующие моменты: фамилия, имя,
        //отчество, группа, возраст, массив(зубчатый) оценок по
        //программированию, администрированию и дизайну.
        //А также добавить методы по работе с перечисленными
        //данными: возможность установки/ получения оценки, получение среднего балла по заданному предмету,
        // распечатка данных о студенте.
        class TMyStudent
        {
            public TMyStudent()
            {
                Mark = new int[3][];
            }
            public TMyStudent(string Name, string Middlename, string Surname, int Group, int Age,
                int []ProgrammingMark, int[] AdministrationMark, int[] DesignMark)
            {
                this.Name = Name;
                this.Middlename = Middlename;
                this.Surname = Surname;
                this.Group = Group;
                this.Age = Age;
                Mark = new int[3][];

                for (int i = 0; i < Mark.Length; i++)
                {
                    int Len;
                    int[] tmpMark = null;
                    switch (i)
                    {
                        case 0:                            
                            Len= ProgrammingMark.Length;
                            tmpMark = ProgrammingMark;
                            break;
                        case 1:
                            Len = AdministrationMark.Length;
                            tmpMark = AdministrationMark;
                            break;
                        case 2:
                            Len = DesignMark.Length;
                            tmpMark = DesignMark;
                            break;
                        default:
                            Len = 0;
                            break;
                    }
                    Mark[i] = new int[Len];

                    for (int k = 0; k < Mark[i].Length; k++)
                    {
                        Mark[i][k] = tmpMark[k];
                    }
                }
            }

            ~TMyStudent()  // finalizer
            {
                // cleanup statements...
            }

            public string Name;
            public string Middlename;
            public string Surname;
            public int Group;
            public int Age;

            private int[][] Mark;

            public void AddProgrammingMark(int NewMark)
            {
                int[] tmpMark = Mark[0];
                Mark[0] = new int[Mark[0].Length + 1];               
                for (int i = 0; i < tmpMark.Length; i++)
                {
                    Mark[0][i] = tmpMark[i];
                }
                Mark[0][Mark[0].Length - 1] = NewMark;
            }
            public void AddAdministrationMark(int NewMark)
            {
                int[] tmpMark = Mark[1];
                Mark[1] = new int[Mark[1].Length + 1];
                for (int i = 0; i < tmpMark.Length; i++)
                {
                    Mark[1][i] = tmpMark[i];
                }
                Mark[1][Mark[1].Length - 1] = NewMark;
            }
            public void AddDesignMark(int NewMark)
            {
                int[] tmpMark = Mark[2];
                Mark[2] = new int[Mark[2].Length + 1];
                for (int i = 0; i < tmpMark.Length; i++)
                {
                    Mark[2][i] = tmpMark[i];
                }
                Mark[2][Mark[2].Length - 1] = NewMark;
            }

            public double GetAverageProgramingMark()
            {
                double tmpSumm = 0;
                for (int i = 0; i < Mark[0].Length; i++)
                {
                    tmpSumm += Mark[0][i];
                }
                if (Mark[0].Length == 0)
                    return 0;
                else
                    return tmpSumm / Mark[0].Length;
            }
            public double GetAverageAdministrationMark()
            {
                double tmpSumm = 0;
                for (int i = 0; i < Mark[1].Length; i++)
                {
                    tmpSumm += Mark[1][i];
                }
                if (Mark[1].Length == 0)
                    return 0;
                else
                    return tmpSumm / Mark[1].Length;
            }
            public double GetAverageDesignMark()
            {
                double tmpSumm = 0;
                for (int i = 0; i < Mark[2].Length; i++)
                {
                    tmpSumm += Mark[2][i];
                }
                if (Mark[2].Length == 0)
                    return 0;
                else
                    return tmpSumm / Mark[2].Length;
            }
            public void Print()
            {
                Console.WriteLine();
                Console.WriteLine("Name: {0}\nMiddlename: {1}\nSurname: {2}",
                    Name, Middlename, Surname);
                Console.WriteLine("Age: " + Age);
                Console.WriteLine("Group: " + Group);
                for (int i = 0; i < Mark.Length; i++)
                {
                    switch (i)
                    {
                        case 0:
                            Console.Write("Mark 'Programing' (Average = " + GetAverageProgramingMark()+ "): ");
                            break;
                        case 1:
                            Console.Write("Mark 'Administration' (Average = " + GetAverageAdministrationMark() + "): ");
                            break;
                        case 2:
                            Console.Write("Mark 'Design' (Average = " + GetAverageDesignMark() + "): ");
                            break;
                        default:
                            break;
                    }
                    
                    for (int k = 0; k < Mark[i].Length; k++)
                    {
                        Console.Write(Mark[i][k] + " ");
                    }
                    Console.WriteLine();
                }
            }


            public string Name1
            {
                get => Name;
                set => Name = value;
            }
            // TMyStudent
        }

        static void Main(string[] args)
        {
            int[] ProgrammingMark = { 1, 1, 1, 4 };
            int[] AdministrationMark = { 2, 2, 2, 2, 5 };
            int[] DesignMark = { 3, 3, 3 };
        
            TMyStudent student = new TMyStudent("Иван", "Петрович", "Сидоров", 700212, 20,
               ProgrammingMark, AdministrationMark, DesignMark);

            student.Print();
            student.AddProgrammingMark(5);
            student.AddDesignMark(3);
            student.AddAdministrationMark(5);
            student.Print();
            
            Console.ReadLine();
/*
 
9.Разработайте приложение «7 чудес света», где каждое
чудо будет представлено отдельным классом. Создайте дополнительный класс, содержащий точку входа.
Распределите приложение по файлам проекта и с помощью пространства имён обеспечьте возможность
взаимодействия классов.
10.Разработать приложение, в котором бы сравнивалось
население трёх столиц из разных стран. Причём страна бы обозначалась пространством имён, а город —
классом в данном пространстве.
*/
        }
    }
}
