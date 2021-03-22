using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.Common;
using System.Configuration;

namespace ADOWinFormsApp
{
    public partial class Form1 : Form
    {
        DbConnection connect = null;
        DbProviderFactory factory = null;
        string provider = "";

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            DataTable providersTable = DbProviderFactories.GetFactoryClasses();
            comboBox1.Items.Clear();
            foreach (DataRow row in providersTable.Rows)
            {
                comboBox1.Items.Add(row["InvariantName"]);
            } 
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            factory = DbProviderFactories.GetFactory(comboBox1.SelectedIndex.ToString());
            connect = factory.CreateConnection();

        }
    }
}
