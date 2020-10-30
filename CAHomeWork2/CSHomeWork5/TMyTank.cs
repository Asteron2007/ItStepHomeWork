using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSHomeWork5
{
    class TMyTank
    {
        public TMyTank(string TankName = "")
        {
            var rand = new Random((int)DateTime.Now.Ticks);
            this.TankName = TankName;
            this.TankArmor = rand.Next(0, 101);
            this.TankAmo = rand.Next(0, 101);
            this.TankMobility = rand.Next(0, 101);
        }

        public string TankName { get; set; }
        public int TankAmo { get; set; }
        public int TankArmor { get; set; }
        public int TankMobility { get; set; }

        public void Show() 
        {
            Console.Write("Tank: {0} (Armor: {1}%, Amo: {2}%, Mobility: {3}%)", this.TankName, this.TankArmor, this.TankAmo, this.TankMobility);
        }

        public string TankToString()
        {
            return String.Format("Tank: {0} (Armor: {1}%, Amo: {2}%, Mobility: {3}%)", this.TankName, this.TankArmor, this.TankAmo, this.TankMobility);
        }


        public static TMyTank operator *(TMyTank a, TMyTank b)
        {
            if (((a.TankAmo > b.TankAmo) && (a.TankArmor > b.TankArmor)) ||
                ((a.TankAmo > b.TankAmo) && (a.TankMobility > b.TankMobility))||
                ((a.TankMobility > b.TankMobility) && (a.TankArmor > b.TankArmor)))
            {
                return a;
            }
            else
                return b;
        }
    }
}
