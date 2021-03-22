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
    public partial class Form3 : Form
    {
        int LButtonCounter = 0;
        int RButtonCounter = 0;
        public Form3()
        {
            InitializeComponent();

//Задание 1: 
//Написать приложение, в котором ведётся подсчёт количества «кликов» левой, правой и средней кнопки мыши.Обновляемую статистику необходимо выводить в заголовок окна.

//Задание 2
//Создайте Windows-приложение «Часы». Программа должна показывать актуальное время.Кратность изменения значения времени – 1 секунда.

        }

        private void Form3_Load(object sender, EventArgs e)
        {

        }

        private void Form3_MouseClick(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                LButtonCounter++;
            }
            else if (e.Button == MouseButtons.Right)
            {
                RButtonCounter++;
            }
            this.Text = DateTime.Now.ToLongTimeString() + " Mouse click: LeftButton = " + LButtonCounter.ToString() + ", RightButton = " + RButtonCounter.ToString();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            this.Text = DateTime.Now.ToLongTimeString() + " Mouse click: LeftButton = " + LButtonCounter.ToString() + ", RightButton = " + RButtonCounter.ToString();
        }

    }
}

