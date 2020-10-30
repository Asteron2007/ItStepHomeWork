using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSLab23_02_2020
{
    public class MyClass
    {
        public readonly int Var = 10;
        public readonly int[] arr = { 1, 2, 3 };

        public static int sum;


        private int namefield1;
        private double namefield2;

        public void Method1()
        {
            Console.WriteLine($"{namefield1}");
            Console.WriteLine("F1={0}, F2={1}", namefield1, namefield2);
        }
        public void Print()
        {
            Console.WriteLine($"{namefield1}");
            Console.WriteLine("F1={0}, F2={1}", namefield1, namefield2);
        }
    }


    class Program
    {
        unsafe struct Item
        {
            public int Val;
            public double Temp;
            public Item* Next;
        }

        struct Dimension 
        {
            private double heigth;
            private double width;

            public Dimension(double h, double w) 
            {
                heigth = h;
                width = w;
            }

            public void Print()
            {
                Console.WriteLine("heigth: " + heigth + " width: " + width);
            }

        }


        public static void PrintHello()
        {
            Console.Title = "Max";
            Console.ForegroundColor = ConsoleColor.Green;
            Console.BackgroundColor = ConsoleColor.Gray;
            Console.WriteLine("__Hello World!!!");
        }

        public static void PrintArray(string text, int[] arr)
        {
            Console.Write(text + ": ");
            for (int i = 0; i < arr.Length; i++)
            {
                Console.Write(arr[i] + " ");
            }

            foreach (int item in arr)
            {
                Console.Write(item + " ");
            }


            Console.WriteLine();
        }


        static void Main(string[] args)
        {
            MyClass testclass1 = new MyClass();
            testclass1.Method1();


            Dimension dim = new Dimension(4, 5);

            dim.Print();


            Item i = new Item();
            Console.WriteLine($"{ i.Val}{i.Temp}");


            int[] array = { 1, 2, 3, 4, 45657, 9 };

            PrintArray("array", array);




            int ttt = int.Parse("776");
            Console.WriteLine(ttt);




            PrintHello();

            Console.WriteLine("Hello\rTes");


            string str1, str2;
            str1 = "Hello";
            str2 = "World!";
            Console.Write(str1);
            Console.WriteLine(" " + str2);
            int x = 10;
            //x = x + str1;
            str2 = x + str2;
            Console.WriteLine(str2);

            int? n = null;//0xFF 0xFD
            x = n ?? 500;
            Console.WriteLine("x = " + x);


            System.Decimal devined = decimal.One;
            Console.WriteLine(devined);
            decimal devisor = 3;
            devined = devined / devisor;
            Console.WriteLine(devined);
            devined = devined * devisor;
            Console.WriteLine(devined);
            Console.WriteLine(Math.Round(devined / devisor * devisor));

            double doubleDevided = 1;
            System.Double doubleDevisor = 3;
            Console.WriteLine(doubleDevided / doubleDevisor * doubleDevisor);
            Console.WriteLine(1.0 / 3.0*3);




            // double.

            Console.Write("Enter Name: ");
            string name;
            name = Console.ReadLine();
            if (name == "")
                Console.WriteLine("Hello");
            else
                Console.WriteLine("Hello " + name);
            Console.ReadLine();


        }
    }
       

}
