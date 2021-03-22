using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HWWinFormsApp1
{
    public partial class Form4 : Form
    {
        int MBoxCount = 0;
        int SymCount = 0;
        
        public Form4()
        {
            InitializeComponent();
            textBox1.Text = "Резюме ТСН" +
                "\r\n" +
                "Родился " +
                "\r\n" +
                "Учился " +
                "\r\n" +
                "Высшее образование " +
                "\r\n" +
                "Служба в армии" +
                "\r\n" +
                "семейное положение" +
                "\r\n" +
                "Первое место работы" +
                "\r\n" +
                "Второе место работы" +
                "\r\n" +
                "Третье место работы" +
                "\r\n" +
                "Хобби";
        }

//1. Вывести на экран свое(краткое!!!) резюме с помощью последовательности MessageBox’ов(числом не менее трех). 
//Причем на заголовке последнего должно отобразиться среднее число символов на странице(общее количество символов в резюме / количество MessageBox’ов).

//2. Написать функцию, которая «угадывает» задуманное пользователем число от 1 до 2000. Для запроса к пользователю использовать MessageBox.
//После того, как число отгадано, необходимо вывести количество запросов, потребовавшихся для этого, и предоставить пользователю возможность сыграть еще раз, не выходя из программы (MessageBox’ы оформляются кнопками и значками соответственно ситуации).


        private void Form4_Load(object sender, EventArgs e)
        {

        }

        private void Form4_Shown(object sender, EventArgs e)
        {
            String Mes = "";
            for (int i = 1; i < textBox1.Lines.Length+1; i++)
            {
                Mes += textBox1.Lines[i-1];

                if (i % 3 == 0)
                {
                    MessageBox.Show(Mes, "Резюме");
                    MBoxCount++;
                    SymCount += Mes.Length;
                    Mes = "";
                }

            }
            if (Mes.Length>0)
            {
                MessageBox.Show(Mes, "Резюме");
                MBoxCount++;
                SymCount += Mes.Length;
                Mes = "";
            }

            Mes = "Mesage box count: " + MBoxCount.ToString() + "\n SymbolCount: " + SymCount.ToString();
            MessageBox.Show(Mes, "Резюме");







        }
    }
}
