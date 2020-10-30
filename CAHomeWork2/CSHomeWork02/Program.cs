using System;

namespace CSHomeWork02
{
    public enum TMyColors
    {
        Red,
        Green,
        Black,
        Silver
    };

    public enum TMyVentType
    {
        Channel,
        Axial,
        Radial
    };

    public partial class TMyVent
    {
        static TMyVent()
        {
            Console.WriteLine("static ctor was called");
        }
        public TMyVent() : this(1, 220, TMyVentType.Channel, TMyColors.Silver, "CK100", 0)
        {
            Console.WriteLine("default ctor was called");
        }

        public TMyVent(double Current, double Voltage, TMyVentType VentType, TMyColors Color, string ModelName, int OwnerID)
        {
            this.Current = Current;
            this.Voltage = Voltage;
            this.VentType = VentType;
            this.Color = Color;
            this.ModelName = ModelName;
            this.OwnerID = OwnerID;
        }

        public double Current
        {
            get
            {
                return current;
            }

            set
            {
                current = value;
            }
        }

        public double Voltage
        {
            get
            {
                return voltage;
            }

            set
            {
                voltage = value;
            }
        }

        public TMyVentType GetVentType()
        {
            return VentType;
        }
        public void SetVentType(TMyVentType VentType)
        {
            this.VentType = VentType;
        }

        public TMyColors GetColor()
        {
            return Color;
        }
        public void SetColor(TMyColors Color)
        {
            this.Color = Color;
        }


        public string GetModelName()
        {
            return ModelName;
        }
        public void SetModelName(string ModelName)
        {
            this.ModelName = ModelName;
        }

        public int GetOwnerID()
        {
            return OwnerID;
        }
        public void SetOwnerID(ref int OwnerID)
        {
            this.OwnerID = OwnerID;
        }

        public void Show()
        {
            Console.Write(" Current = " + Current);
            Console.Write(" Voltage = " + Voltage);
            Console.Write(" VentType = " + VentType);
            Console.Write(" Color = " + Color);
            Console.Write(" ModelName = " + ModelName);
            Console.WriteLine(" OwnerID = " + OwnerID);
            Console.WriteLine(" Discount" + TMyVent.Discount + " Markup " + TMyVent.Markup);

        }
      //  public partial void Print();

        private double current;
        private double voltage;
        private TMyVentType VentType;
        private TMyColors Color;
        private string ModelName;
        private int OwnerID;

        public static double Discount = 10;//%
        public static double Markup = 15;//%
    }

    class Program
    {

        static void Main(string[] args)
        {
            TMyVent[] vents = new TMyVent[5];

            for (int i = 0; i < 5; i++)
            {
                vents[i] = new TMyVent();
                Console.WriteLine("Object " + i + " before");
                vents[i].Show();
                vents[i].Current = i * 2;
                vents[i].SetOwnerID(ref i);

                Console.WriteLine();
                Console.WriteLine("Object " + i + " after ");
                vents[i].Show();
            }

            Console.WriteLine("Object " + 0 + " after ");
            vents[0].Show();

            vents[0].Print();

            Console.ReadLine();
        }

        /* Задание 1. 
+1.1	Разработать один из классов, в соответствии с полученным вариантом.
+1.2	Реализовать не менее пяти закрытых полей (различных типов), представляющих основные характеристики рассматриваемого 
класса. 
+1.3	Создать не менее трех методов управления классом и методы доступа к его закрытым полям. 
+1.4	Создать метод, в который передаются аргументы по ссылке. 
+1.5	Создать не менее двух статических полей  (различных типов), представляющих общие характеристики объектов данного 
класса.  
+1.6	Обязательным требованием является реализация нескольких перегруженных конструкторов, аргументы которых определяются 
студентом, исходя из специфики реализуемого класса, а так же реализация конструктора по умолчанию.
+1.7	Создать статический конструктор.  
+1.8	Создать массив (не менее 5 элементов) объектов  созданного класса. 
+1.9	Создать дополнительный метод для данного класса в другом файле, используя ключевое слово partial.

Варианты (по выбору):
4.	бытовая техника (на выбор); вентилятор
    */




    }
}
