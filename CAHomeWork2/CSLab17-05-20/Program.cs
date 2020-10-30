using System;

namespace CSLab17_05_20
{

    


    public abstract class TMyUnit
    {
        public TMyUnit(string Name = "")
        {
            if (Name != "")
                this.Name = Name;
            else
                this.Name = "Unit";
        }
        protected string name;
        protected string status;
        protected double posX;
        protected double posY;
        protected double posZ;
        public abstract void Show();
        public abstract double PosX { get; set; }
        public abstract double PosY { get; set; }
        public abstract double PosZ { get; set; }
        public abstract string Name { get; set; }
        public abstract string Status { get; set; }

    }


    public class TMyBuild : TMyUnit
    {
        public TMyBuild(string Name = "")  
        {
            if (Name != "")
                this.Name = Name;
            else
                this.Name = "TMyBuild";
        }
        public override void Show() 
        {
            Console.WriteLine(Name);
        }
        public override double PosX { get; set; }
        public override double PosY { get; set; }
        public override double PosZ { get; set; }
        public override string Name { get; set; }
        public override string Status { get; set; }
    }

    public class TMyHuman: TMyUnit
    {
        public TMyHuman()
        {
            if (Name != "")
                this.Name = Name;
            else
                Name = "TMyHuman";
        }
        public override void Show()
        {
            Console.WriteLine(Name);
        }
        public override double PosX { get; set; }
        public override double PosY { get; set; }
        public override double PosZ { get; set; }
        public override string Name { get; set; }
        public override string Status { get; set; }
        public string HumanType { get; set; }
    }

    public class TMyWarrior: TMyHuman
    {
        public TMyWarrior(string Weapon = "")
        {
            if (Name != "")
                this.Name = Name;
            else
                Name = "TMyWarrior";
            HumanType = "Warrior";
            this.Weapon = Weapon;
        }
        public override void Show()
        {
            Console.WriteLine(Name);
            Console.WriteLine(HumanType);
        }

        public string Weapon { get; set; }
    }

    public class TMyCivil: TMyHuman
    {

        public TMyCivil(string Profession = "")
        {
            if (Name != "")
                this.Name = Name;
            else
                Name = "TMyCivil";
            HumanType = "Civil";
            this.Profession = Profession;
        }
        public override void Show()
        {
            Console.WriteLine(Name);
            Console.WriteLine(HumanType);
        }
        public string Profession { get; set; }
    }

    class BakroteException : Exception
    {
        public double Sum { get; set; }
        public BakroteException(string message, double sum = 0) : base(message)
        {
            Sum = sum;
        }

    }

    public class TMyMoney
    {
        private double _money;
        public double Money 
        {
            get 
            {
                return _money;
            }
            set
            {
                if (value < 0)
                    throw new BakroteException("Bankrote", value);
                else _money = value;
            }
        }
        public TMyMoney(double Sum=0)
        {
            Money = Sum;    
        }
        public static TMyMoney operator +(TMyMoney M1, TMyMoney M2)
        {
            return new TMyMoney { Money = M1.Money + M2.Money };
        }
        
        public static TMyMoney operator -(TMyMoney M1, TMyMoney M2)
        {
            return new TMyMoney { Money = M1.Money - M2.Money };
        }

        public static TMyMoney operator *(TMyMoney M1, TMyMoney M2)
        {
            return new TMyMoney { Money = M1.Money * M2.Money };
        }
        
        public static TMyMoney operator /(TMyMoney M1, TMyMoney M2)
        {
            return new TMyMoney { Money = M1.Money / M2.Money };
        }

        public static implicit operator TMyMoney(int value)
        {
            return new TMyMoney((double)value);
        }
        public static explicit operator int(TMyMoney money)
        {
            return (int)money.Money;
        }

        public static implicit operator TMyMoney(double value)
        {
            return new TMyMoney(value);
        }
        public static explicit operator double(TMyMoney money)
        {
            return money.Money;
        }
    }



    class Program
    {
        static void Main(string[] args)
        {

            TMyMoney IvanCash = new TMyMoney(100);
            TMyMoney AliceCash = new TMyMoney(120);
            try
            {
                Console.WriteLine((IvanCash + AliceCash).Money);
                Console.WriteLine((IvanCash + 11111111).Money);
                Console.WriteLine((IvanCash + 111.9999).Money);
                Console.WriteLine(IvanCash );

                Console.WriteLine((IvanCash - AliceCash).Money);


            }
            catch (BakroteException bex)
            {
                Console.WriteLine($"Ошибка: {bex.Message}");
                Console.WriteLine($"Некорректное значение: {bex.Sum}");
            }



            Console.ReadLine();


            TMyBuild Storage = new TMyBuild();
            TMyBuild Storage2 = new TMyBuild("Storage");
            TMyCivil Peter = new TMyCivil("Forester");
            TMyWarrior Ivan = new TMyWarrior("Mini Gun");

            Storage.Show();
            Storage2.Show();
            Peter.Show();
            Ivan.Show();
            }
    }
}
