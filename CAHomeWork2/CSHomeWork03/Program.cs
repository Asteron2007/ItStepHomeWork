using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSHomeWork03
{
    class Program
    {
        //sort method Bubble
        static void SortArr(int[] pArray)
        {
            int k;
            for (int i = 0; i < pArray.Length; i++)
            {
                k = i;
                for (int j = i; j < pArray.Length; j++)
                {
                    if (pArray[k] > pArray[j])
                        k = j;
                }
                if (k != i)
                {
                    int tmp = pArray[i];
                    pArray[i] = pArray[k];
                    pArray[k] = tmp;
                }
            }
        }

        //sort method Bubble
        static void SortArr(double[] pArray)
        {
            int k;
            for (int i = 0; i < pArray.Length; i++)
            {
                k = i;
                for (int j = i; j < pArray.Length; j++)
                {
                    if (pArray[k] > pArray[j])
                        k = j;
                }
                if (k != i)
                {
                    double tmp = pArray[i];
                    pArray[i] = pArray[k];
                    pArray[k] = tmp;
                }
            }
        }


        static void Main(string[] args)
        { 
            // Упражнение
//Напишите консольную программу, в которую пользователь вводит с клавиатуры два числа. 
//А программа сранивает два введенных числа и выводит на консоль результат сравнения (два числа равны, 
//первое число больше второго или первое число меньше второго).
            
            Console.Write("Enter number A: ");
            double A = Convert.ToDouble(Console.ReadLine());
            Console.Write("Enter number B: ");
            double B = Convert.ToDouble(Console.ReadLine());

            if (A == B)
                Console.WriteLine("Number A = B");
            else
            if (A > B)
                Console.WriteLine("Number A greatest that B");
            else
                Console.WriteLine("Number A less that B");

            //Упражнение
            //В банке в зависимости от суммы вклада начисляемый процент по вкладу может отличаться. 
            //Напишите консольную программу, в которую пользователь вводит сумму вклада. 
            //Если сумма вклада меньше 100, то начисляется 5%. Если сумма вклада от 100 до 200, то начисляется 7%. 
            //Если сумма вклада больше 200, то начисляется 10%. 
            //В конце программа должна выводить сумму вклада с начисленными процентами.
            //Для получения вводимого с клавиатуры числа используйте выражение Convert.ToDouble(Console.ReadLine())

            Console.Write("\nEnter deposit: ");
            double Deposit = Convert.ToDouble(Console.ReadLine());
            double percent = 0;
            if (Deposit < 100)
                percent = 5;
            else if (Deposit < 200)
                percent = 7;
            else
                percent = 10;

            Console.WriteLine("Deposit with " + percent + "% = " + (Deposit * (1 + percent / 100)));
            Console.Write("\nPress enter: ");
            Console.ReadLine();


            //Упражнение
            //Напишите программу, которая выводит на консоль таблицу умножения
            Console.WriteLine("\nMultiplication table");
            for (int i = 1; i < 10; i++)
            {
                for (int j = 1; j < 10; j++)
                {
                    Console.WriteLine(i + " x " + j + " = " + (i * j));
                }
                Console.WriteLine("");
            }


            //Упражнение
            //напишите программу сортировки массива (любой на выбор)
            int[] intarr = { 10, 1001, 500, 3, 22, 10 };
            Console.Write("\nUnsorted intarr: ");
            for (int i = 0; i < intarr.Length; i++)
            {
                Console.Write(intarr[i]+" ");
            }

            SortArr(intarr);

            Console.Write("\nUnsorted intarr: ");
            for (int i = 0; i < intarr.Length; i++)
            {
                Console.Write(intarr[i] + " ");
            }
            Console.Write("\nPress enter: ");
            Console.ReadLine();

            //дополнительно - создайте зубчатый массив и отсортируйте каждую строку.
            double[][] doubleArr = new double[5][];
            doubleArr[0] = new double[4];
            doubleArr[1] = new double[6];
            doubleArr[2] = new double[3];
            doubleArr[3] = new double[4];
            doubleArr[4] = new double[7];

            // init array
            Random rnd = new Random();
            Console.Write("\nUnsorted doubleArr: ");
            for (int j = 0; j < doubleArr.Length; j++)
            {
                Console.WriteLine();
                for (int i = 0; i < doubleArr[j].Length; i++)
                {
                    doubleArr[j][i] = rnd.NextDouble();
                    Console.Write("{0:f4}\t", doubleArr[j][i]);
                }

            }


            // out sorted array
            Console.Write("\nSorted doubleArr: ");
            for (int j = 0; j < doubleArr.Length; j++)
            {
                Console.WriteLine();
                SortArr(doubleArr[j]);
                for (int i = 0; i < doubleArr[j].Length; i++)
                    Console.Write("{0:f4}\t", doubleArr[j][i]);
            }

            Console.Write("\nPress enter: ");
            Console.ReadLine();
        }
    }
}
