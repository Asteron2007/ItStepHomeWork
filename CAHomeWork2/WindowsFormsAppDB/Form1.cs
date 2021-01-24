using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.Configuration;

namespace WindowsFormsAppDB
{
    public partial class Form1 : Form
    {
        SqlConnection connect = null;
        SqlDataAdapter adapter = null;
        DataTable table = new DataTable();
        DataSet dbCashe = null;
        SqlCommandBuilder command = null;
        string selectSQL = "SELECT * FROM Authors";

        public Form1()
        {
            InitializeComponent();
            adapter = new SqlDataAdapter(selectSQL, connect);
            dbCashe = new DataSet();
            adapter.Fill(dbCashe);


            DataTable table = new DataTable();
            table.Columns.Add("ID");
            table.Columns.Add("FirstName");
            table.Columns.Add("LastName");

            DataRow row = table.NewRow();
            row[0] = 1;
            row[1] = "Maxim";
            row[2] = "Ivanov";
            table.Rows.Add(row);

        }

        private void button1_Click(object sender, EventArgs e)
        {
            SqlCommand command = new SqlCommand();
            command.CommandText = "SELECT * FROM Authors";
            command.Connection = connect;
            connect.Open();
            


            table = new DataTable();
            SqlDataReader reader = command.ExecuteReader();

            do
            {
                bool lineCount = true;

                while (reader.Read())
                {
                    if (lineCount)
                    {
                        for (int i = 0; i < reader.FieldCount; i++)
                        {
                            table.Columns.Add(reader.GetName(i));
                        }
                        lineCount = false;
                    }
                    DataRow row = table.NewRow();
                    for (int i = 0; i < reader.FieldCount; i++)
                    {
                        row[i] = reader[i];
                    }
                    table.Rows.Add(row);
                }
                dataGridView1.DataSource = table;

            } while (true);// rea
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //SqlConnection connection = new SqlConnection()
            connect = new SqlConnection();

            //connect.ConnectionString = ConfigurationManager
            connect.Open();
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            
        }

        private void button3_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            dbCashe = new DataSet();
            selectSQL = "SELECT * FROM AUTHORS";
            adapter = new SqlDataAdapter(selectSQL, connect);
            command = new SqlCommandBuilder(adapter);
            SqlCommand commandUpdate = new SqlCommand("Update Books SET price = @price WHERE id = ");
            commandUpdate.Parameters.Add(new SqlParameter("@price", SqlDbType.Int));
            commandUpdate.Parameters["@price"].SourceVersion = DataRowVersion.Current;
            commandUpdate.Parameters["@price"].SourceColumn = "Price";

            commandUpdate.Parameters.Add(new SqlParameter("@ID", SqlDbType.Int));
            commandUpdate.Parameters["@ID"].SourceVersion = DataRowVersion.Original;
            commandUpdate.Parameters["@ID"].SourceColumn = "id";


            //SqlCommand commandUpdateProc = new SqlCommand("UpdateBooks", );
            //commandUpdateProc.CommandType = CommandType.StoredProcedure;
          //  SqlParameterCollection param = coom;

            adapter.UpdateCommand = commandUpdate;

            adapter.Update(dbCashe, "table");
            adapter.Fill(dbCashe, "mytable");
            adapter.Fill(dbCashe);//, "mytable");
            //dataGridView1.DataSource = dbCashe.Tables[0];
            dataGridView1.DataSource = dbCashe.Tables["mytable"];

        }
    }
}
        


