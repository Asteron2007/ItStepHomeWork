using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSHomeWork01
{
    class Program
    {
        static void Main(string[] args)
        {

            //Задание 1. Написать программу, которая считывает символы с клавиатуры, пока не будет введена точка. 
            //Программа должна сосчитать количество введенных пользователем пробелов. 
            {
                ConsoleKeyInfo k;
                int SpaceCout = 0;
                Console.Write("Press any key ('.' - to Exit)");
                do
                {
                    k = Console.ReadKey(false);
                    if (k.KeyChar > ' ')
                        SpaceCout++;
                } while (k.KeyChar != '.');
                Console.WriteLine();
                Console.WriteLine("Spaces count = " + SpaceCout);
                Console.Write("Press Enter");
                Console.ReadLine();
            }
            //Задание 2. Ввести с клавиатуры номер трамвайного билета (6-значное число) и про-верить является ли 
            //данный билет счастливым (если на билете напечатано шестизначное число, и сумма первых трёх цифр равна 
            //сумме последних трёх, то этот билет считается счастливым).

            {
                int LeftSumm = 0;
                int RightSumm = 0;
                String ANumStr = "123321";
                Console.Write("Enter the number 6 digits: ");
                ANumStr = Console.ReadLine();

                char[] arr = ANumStr.ToCharArray();
                if (arr.Length == 6)
                {
                    for (int i = 0; i < 3; i++)
                    {
                        LeftSumm += arr[i] - '0';
                        RightSumm += arr[i + 3] - '0';
                    }
                }
                Console.WriteLine();
                if (RightSumm == LeftSumm)
                    Console.WriteLine(ANumStr + " - Is a lucky number");
                else
                    Console.WriteLine(ANumStr + " - Is not a lucky number");
                Console.Write("Press Enter");
                Console.ReadLine();
            }

            //Задание 3. Числовые значения символов нижнего регистра в коде ASCII отличаются от значений символов 
            //верхнего регистра на величину 32. Используя эту  информацию, написать программу, которая считывает с 
            //клавиатуры и конвертирует все символы нижнего регистра в символы верхнего регистра и наоборот.
            {
                ConsoleKeyInfo k;
                Char newkey;
                Console.Write("Press any key (ENTER - to Exit)");
                do
                {
                    k = Console.ReadKey(true);
                    newkey = k.KeyChar;
                    if (k.KeyChar>'a' && k.KeyChar<'z')
                    {
                        newkey = (char)(k.KeyChar - 32);
                        
                    }
                    Console.Write(newkey);
                } while (k.Key!=ConsoleKey.Enter);
                Console.WriteLine();
            }
            //Задание 4.  Даны целые положительные числа A и B (A < B). Вывести все целые числа от A до B включительно; 
            //каждое число должно выводиться на новой строке; при этом каждое число должно выводиться количество раз, 
            //равное его значению. Например: если А = 3, а В = 7, то программа должна сформировать в консоли следующий 
            //вывод:
            {
                int A = 3;
                int B = 8;
                Console.WriteLine("A = " + A + " B = " + B);

                for (int i = A; i <= B; i++)
                {
                    for (int k = 0; k< i; k++)
                    {
                        Console.Write(i);
                    }
                    Console.WriteLine();
                }
            }
            
            //Задание 5.  Дано целое число N (> 0), найти число, полученное при прочтении числа N справа налево.
            //Например, если было введено число 345,  то  программа должна вывести число 543.
            {
                int Num = 3456;
                string S = Num.ToString();
                string output = new string(S.ToCharArray().Reverse().ToArray());

                Console.WriteLine("Number: " + Num);
                Console.WriteLine("Reverse number: " + output);
                Console.WriteLine("Reverse number: " + new string(S.ToCharArray().Reverse().ToArray()));
                Console.Write("Press Enter");
                Console.ReadLine();
            }
        }
    }
}
