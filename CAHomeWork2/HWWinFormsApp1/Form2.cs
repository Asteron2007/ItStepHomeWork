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

namespace HWWinFormsApp1
{
    public partial class Form2 : Form
    {
        /*
        Задание 3: 
        Программа запрашивает у пользователя путь к файлу с символами Unicode.
        После чего программа копирует содержимое файла в новый файл, преобразовывая исходное содержимое в формат ANSI. 
        Задание 4: 
        Посчитать количество названий фруктов в файле. Названия фруктов и путь к файлу пользователь вводит с клавиатуры. 
        Названия фруктов и содержимое файла в формате Unicode.
         */

        public Form2()
        {
            InitializeComponent();
            openFileDialog1.Filter = "Text files(*.txt)|*.txt|All files(*.*)|*.*";

            dataGridView1.ColumnCount = 2;
            dataGridView1.ColumnHeadersVisible = true;

            // Set the column header style.
            DataGridViewCellStyle columnHeaderStyle = new DataGridViewCellStyle();

            columnHeaderStyle.BackColor = Color.Beige;
            columnHeaderStyle.Font = new Font("Verdana", 10, FontStyle.Bold);
            dataGridView1.ColumnHeadersDefaultCellStyle = columnHeaderStyle;

            // Set the column header names.
            dataGridView1.Columns[0].Name = "Fruit";
            dataGridView1.Columns[1].Name = "Count";




        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            openFileDialog1.FileName = textBox1.Text;
            if (openFileDialog1.ShowDialog() == DialogResult.Cancel)
                return;

            textBox1.Text = openFileDialog1.FileName;
            textBox3.Text = Path.GetDirectoryName(openFileDialog1.FileName) + @"\" + Path.GetFileNameWithoutExtension(openFileDialog1.FileName) + "-new"
                + Path.GetExtension(openFileDialog1.FileName);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            using (StreamReader file = new StreamReader(textBox1.Text, Encoding.Unicode))
            {
                using (StreamWriter outputFile = new StreamWriter(textBox3.Text, false, Encoding.GetEncoding(1251)))
                {
                    while (!file.EndOfStream)
                    {
                        string s = file.ReadLine();
                        outputFile.WriteLine(s);


                    }
                    MessageBox.Show("Convert complete");
                }
            }
           
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            button3.Enabled = (textBox1.Text != "");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            openFileDialog1.FileName = textBox1.Text;
            if (openFileDialog1.ShowDialog() == DialogResult.Cancel)
                return;

            textBox2.Text = openFileDialog1.FileName;
        }

        private int SubStrCount(String str, string substr)
        {
            if (str.IndexOf(substr) > -1)
                return 1 + SubStrCount(str.Remove(0, str.IndexOf(substr) + substr.Length), substr);
            else return 0;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            for (int i = 1; i < dataGridView1.Rows.Count; i++)
            {
                dataGridView1.Rows[i - 1].Cells[1].Value = "0";
            }
                       
            using (StreamReader file = new StreamReader(textBox2.Text, Encoding.Unicode))
            {
                int count = 0;
                while (!file.EndOfStream)
                {
                    string s = file.ReadLine().ToUpper();
                    for (int i = 1; i < dataGridView1.Rows.Count; i++)
                    {
                        try
                        {
                            count = Int32.Parse(dataGridView1.Rows[i - 1].Cells[1].Value.ToString());
                        }
                        catch (FormatException)
                        {
                            MessageBox.Show($"Unable to parse '{dataGridView1.Rows[i - 1].Cells[1].Value.ToString()}'");
                        }




                        //string[] row1 = new string[] { dataGridView1.Rows[i - 1].Cells[0].Value.ToString().ToUpper(), 



                        dataGridView1.Rows[i - 1].Cells[1].Value = (count + SubStrCount(s, dataGridView1.Rows[i - 1].Cells[0].Value.ToString().ToUpper())).ToString();

                    
                        //dataGridView1.Rows.Add(row1);                    
                    }
                }
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            
            for (int i = 1; i < dataGridView1.Rows.Count; i++)
            {
                if ((textBox4.Text.ToUpper() == dataGridView1.Rows[i-1].Cells[0].Value.ToString().ToUpper()) || (textBox4.Text == ""))
                    return;
            }

            string[] row1 = new string[] { textBox4.Text, "0" };


            dataGridView1.Rows.Add(row1);

            button5.Enabled = (textBox2.Text != "") && (dataGridView1.Rows.Count > 0);


        }

      
        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            button5.Enabled = (textBox2.Text != "") && (dataGridView1.Rows.Count > 0);
        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {
            button4.Enabled = (textBox4.Text != "");
        }

        private void dataGridView1_SelectionChanged(object sender, EventArgs e)
        {
            try
            {
                if (dataGridView1.CurrentRow.Cells[0] != null)
                    textBox4.Text = dataGridView1.CurrentRow.Cells[0].Value.ToString();
            }
            catch (Exception)
            {

                //throw;
            }
            

        }
    }
}
