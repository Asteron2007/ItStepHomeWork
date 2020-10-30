using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSHomeWork6
{

    class TMyRangeOfArray <T>
    {
        private int lowIndex;
        private int hiIndex;
        public int LowIndex 
        {
            get
            {
                return lowIndex;
            }
            set
            {
                if (value > hiIndex)
                {
                    lowIndex = hiIndex;
                    hiIndex = value;
                }
                else
                {
                    lowIndex = value;
                }
            } 
        }
        public int HiIndex
        {
            get
            {
                return hiIndex;
            }
            set
            {
                if (value < lowIndex)
                {
                    hiIndex = lowIndex;
                    lowIndex = value;
                }
                else
                {
                    hiIndex = value;
                }
            }
        }
        public int Length { get { return this.HiIndex - this.LowIndex; } }

        //object[] data;
        T[] data;
        public TMyRangeOfArray(int LowIndex, int HiIndex)
        {
            this.HiIndex = HiIndex;
            this.LowIndex = LowIndex;
            data = new T[this.Length];
        }
        // индексатор
        public T this[int index]
        {
            get
            {
                if ((index >= LowIndex) && (index < HiIndex))
                {
                    return data[index - LowIndex];
                }
                else
                {
                    throw new Exception("Array out of range");
                }
            }
            set
            {
                if ((index >= LowIndex) && (index < HiIndex))
                {
                    data[index - LowIndex] = value;
                }
                else
                {
                    throw new Exception("Array out of range");
                }
            }
        }
    }


    class Program
    {
        static void Main(string[] args)
        {
            TMyRangeOfArray<int> arr = new TMyRangeOfArray<int>(2, 16);
            Console.WriteLine("arr.LowIndex = " + arr.LowIndex + " arr.HiIndex = " + arr.HiIndex);
            for (int i = arr.LowIndex; i < arr.LowIndex + arr.Length; i++)
            {
                try
                {
                    arr[i] = i * i;
                    Console.WriteLine("arr[" + i + "] = " + arr[i]);
                }
                catch (Exception ex)
                {
                    Console.WriteLine(ex.Message);
                    break;
                }
            }


            TMyRangeOfArray<double> arr2 = new TMyRangeOfArray<double>(7, 1);
            Console.WriteLine("\n\narr2.LowIndex = " + arr2.LowIndex + " arr2.HiIndex = " + arr2.HiIndex);
            for (int i = arr2.LowIndex; i < arr2.HiIndex+6; i++)
            {
                try
                {
                    arr2[i] = i + i * 0.36;
                    Console.WriteLine("arr2[" + i + "] = " + arr2[i]);
                }
                catch (Exception ex)
                {
                    Console.WriteLine(ex.Message);
                    break;
                }                
            }
            Console.ReadLine();

        }
    }
}
