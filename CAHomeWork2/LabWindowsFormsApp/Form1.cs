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
    }
}
