using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Drawing.Drawing2D;

namespace LabWindowsFormsApp
{
   
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Click(object sender, EventArgs e)
        {
            DialogResult result = MessageBox.Show("Click", "Dialog", MessageBoxButtons.YesNoCancel);
            if (DialogResult.Yes == result)
            {
                MessageBox.Show("Yes pressed");
            }

        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            this.Text = $"Coordinates x = {e.X.ToString()}, y = {e.Y.ToString()}";
        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFiledlg = new OpenFileDialog();
            openFiledlg.Filter = "text files (*.txt)|*.txt|Bakup files (*.bak)|*.bak||";
            //openFiledlg.Filter += "Back files (*.bak)|*.bak||";
            if (openFiledlg.ShowDialog() == DialogResult.OK)
            {
                using (StreamReader reader = File.OpenText(openFiledlg.FileName))
                {
                    textBox2.Text = reader.ReadToEnd();
                }
            };
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;

            Pen pen = new Pen(Brushes.Red, 5);
            pen.DashStyle = System.Drawing.Drawing2D.DashStyle.Dash;

            g.DrawEllipse(pen, 50, 50, 100, 250);
            Rectangle rect = new Rectangle(100, 100, 150, 250);
            //SolidBrush sbrush = new SolidBrush(Color.Blue);
            LinearGradientBrush lgbrush = new LinearGradientBrush(
                rect,
                Color.FromArgb(255, 255, 0, 0),
                Color.FromArgb(255, 0, 0, 255),
                90,
                true
                );
            HatchBrush hbbrush = new HatchBrush(HatchStyle.Cross, Color.Green, Color.Blue);
            TextureBrush textureBrush = new TextureBrush(new Bitmap("C:\\Users\\Book\\Desktop\\html\\lesson06\\images\\ir_image.gif"));



           // g.FillRectangle(sbrush, rect);
            //g.FillRectangle(lgbrush, rect);
            //g.FillRectangle(hbbrush, rect);

            g.FillRectangle(textureBrush, rect);

            Font f1 = new Font("Courier",24);
            g.DrawString("Привет", f1, Brushes.Red, 300, 200);




            Image im = new Bitmap("C:\\Users\\Book\\Desktop\\html\\lesson06\\images\\ir_image.gif");
            g.DrawImage(im, 100, 200);//,400,60);


            //g.Dispose();
        }
    }

    class DllInpoertExample
    {
        [System.Runtime.InteropServices.DllImport("gdi32.dll")]
        public static extern int GetPolyFillMode();
    }

}
