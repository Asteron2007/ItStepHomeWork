using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using static System.Console;



namespace Lab111020
{
    //class MyString : String



    class Account
    {
        public delegate void AccountOperation(string Message);
        private event AccountOperation _notify = null;

        public event AccountOperation Notify
        {
            add
            {
                _notify += value;
            }
            remove
            {
                _notify -= value;
            }
        }


        //event Action<string> Notify;

        public double Sum { get; private set; }
        public Account(double sum = 0, AccountOperation op = null)
        {
            _notify += op;
            Sum = sum;
            _notify?.Invoke($"Acount create with {sum } RUR");
        }
        public void Put(double sum)
        {
            Sum += sum;
            //if (Notify != null)
            _notify?.Invoke($"Put {sum } RUR");
        }
        public void Take(double sum)
        {
            if (sum <= Sum)
            {
                Sum -= sum;
                _notify($"Take {sum } RUR");
            }

        }
    }

    class Program
    {
        /* static void ConsoleMessage(string message)
         {
             Console.WriteLine(message);
         }

         static int Sum(int[] array, Predicate<int> predicate)
         {
             int sum = 0;
             foreach (var item in array)
             {
                 if (predicate(item))
                 {
                     sum += item;
                 }
             }
             return sum;
         }
        */

        static void Main(string[] args)
        {
            DriveInfo[] drives = DriveInfo.GetDrives();

            foreach (var item in drives)
            {
                WriteLine("Name: " + item.Name);

                if (item.IsReady)
                {
                    WriteLine("Size: " + item.TotalSize);
                    WriteLine("Type: " + item.DriveType);
                    WriteLine("drive format: " + item.DriveFormat);
                    WriteLine();
                }

            }
            string path = @"c:\microsoft";
            string newPath = @"MMM";

            if (Directory.Exists(path))
            {
                Directory.CreateDirectory(path + @"\" + newPath);
                WriteLine("Directories:");
                string[] directories = Directory.GetDirectories(path);
                foreach (var dir in directories)
                    WriteLine(dir);
                WriteLine();
                WriteLine("files:");
                string[] files = Directory.GetFiles(path);
                foreach (var file in files)
                {
                    WriteLine(file);

                }

            }



            /*
                        int[] array = { 3, 4, 22, 1, 44, 5, 66 };
                        Console.WriteLine(Sum(array, (x) => x > 5));


                        Account myacc = new Account(1000, ConsoleMessage);
                        //myacc.Notify += ConsoleMessage; 
                        myacc.Notify += delegate (string message) { Console.WriteLine(message); };
                        Func<int, int, double> Add = (x, y) => x + y;
                        Action<int, int> AddVoid = (x, y) => Console.WriteLine(x + y);


                        //Console.WriteLine($"On account {myacc.Sum} RUR");
                        myacc.Put(500);
                        //Console.WriteLine($"On account {myacc.Sum} RUR");
                        myacc.Take(800);
                        //Console.WriteLine($"On account {myacc.Sum} RUR");
                        myacc.Take(1500);
                        //Console.WriteLine($"On account {myacc.Sum} RUR");
                        Console.ReadLine();

                        AddVoid(5, 7);
                        Console.WriteLine(Add(4, 4));
                        Console.ReadLine();
                    

              */
            ReadLine();
        }
    }
}