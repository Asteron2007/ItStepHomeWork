using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSHomeWork5
{
    class Program
    {
        static void Main(string[] args)
        {
            TMyTank[] TanksT34 = { null, null, null, null, null };
            for (int i = 0; i < 5; i++)
            {
                TanksT34[i] = new TMyTank("T34 N" + i);
                //TanksT34[i].Show();
                //Console.WriteLine();
            }

            TMyTank[] TanksPantera = { null, null, null, null, null };
            for (int i = 0; i < 5; i++)
            {
                TanksPantera[i] = new TMyTank("Pantera N" + i);
                //TanksPantera[i].Show();
                //Console.WriteLine();
            }


            // Fight
            Console.WriteLine("Battle of Tanks:\n");

            for (int i = 0; i < 5; i++)
            {
                try
                {
                    TanksPantera[i].Show();
                    Console.Write(" VS ");
                    TanksT34[i].Show();
                    Console.Write(" WIN ");
                    (TanksT34[i] * TanksPantera[i]).Show();
                    Console.WriteLine();
                }
                catch (Exception)
                {
                    Console.WriteLine("One of Tanks not initialized!");
                }
            }


            Console.ReadLine();
        }
    }
}
