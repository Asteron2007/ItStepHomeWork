using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WpfApp2
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        bool FloatNow = false;
        public MainWindow()
        {
            InitializeComponent();
        }

        private bool LastSymIsDigit(String str)
        {
            if (str.Length > 0)
            {
                Char ch = str[str.Length - 1];
                if (((ch >= '0') && (ch <= '9')) || (ch == '.'))
                    return true;
            }
            return false;
        }

        private bool LastSymIsThisChar(Char Sym, String str)
        {
            if (str.Length > 0)
            {
                Char ch = str[str.Length - 1];
                if (ch == Sym)
                    return true;
            }
            return false;
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            if (((Button)sender).Content.ToString() == "CE")
            {
                FormulaTextBox.Text = "";
                ResultTextBox.Text = "0";
                return;
            }
            // замена минусов в начале строки
            // замена минуса *-!!
            // удаление предыдущего (последнего) символа
            // 


            
            Char ch = ' ';
            if (((Button)sender).Content.ToString().Length > 0)
                ch = ((Button)sender).Content.ToString()[0];

            if (ch == 'C')
            {
                FormulaTextBox.Text = "";
                ResultTextBox.Text = "0";
                
                return;
            }

            if (ch == '<')
            {
                if (FormulaTextBox.Text != "")
                {
                    FormulaTextBox.Text = FormulaTextBox.Text.Substring(0, FormulaTextBox.Text.Length - 1);
                }
                return;
            }

            if ((ch >= '0') && (ch <= '9'))
            {
                FormulaTextBox.Text += ((Button)sender).Content;
                return;
            }

            switch (ch)
            {
                case '+':
                    if (LastSymIsDigit(FormulaTextBox.Text))
                        FormulaTextBox.Text += ((Button)sender).Content;
                    else
                       if (FormulaTextBox.Text != "")
                    {
                        do
                        {
                            FormulaTextBox.Text = FormulaTextBox.Text.Substring(0, FormulaTextBox.Text.Length - 1);
                        } while (!LastSymIsDigit(FormulaTextBox.Text));

                        FormulaTextBox.Text += ((Button)sender).Content.ToString();
                    }
                    FloatNow = false;
                    break;
                case '-':
                    if (FormulaTextBox.Text != "")
                        if (FormulaTextBox.Text[FormulaTextBox.Text.Length - 1] == '-')
                            return;
                    FormulaTextBox.Text += ((Button)sender).Content;
                    FloatNow = false;
                    break;
                case '/':
                    if (LastSymIsDigit(FormulaTextBox.Text))
                        FormulaTextBox.Text += ((Button)sender).Content;
                    else
                        if (FormulaTextBox.Text != "")
                    {
                        do
                        {
                            FormulaTextBox.Text = FormulaTextBox.Text.Substring(0, FormulaTextBox.Text.Length - 1);
                        } while (!LastSymIsDigit(FormulaTextBox.Text));

                        FormulaTextBox.Text += ((Button)sender).Content.ToString();
                    }
                    FloatNow = false;
                    break;
                case '*':
                    if (LastSymIsDigit(FormulaTextBox.Text))
                        FormulaTextBox.Text += ((Button)sender).Content;
                    else
                       if (FormulaTextBox.Text != "")
                    {
                        do
                        {
                            FormulaTextBox.Text = FormulaTextBox.Text.Substring(0, FormulaTextBox.Text.Length - 1);
                        } while (!LastSymIsDigit(FormulaTextBox.Text));

                        FormulaTextBox.Text += ((Button)sender).Content.ToString();
                    }
                    FloatNow = false;
                    break;
                case '.':
                    if ((LastSymIsThisChar('.', FormulaTextBox.Text)) || (FloatNow))
                        return;
                    if (LastSymIsDigit(FormulaTextBox.Text))
                        FormulaTextBox.Text += ((Button)sender).Content;
                    else
                        FormulaTextBox.Text += "0" + ((Button)sender).Content;
                    FloatNow = true;
                    break;
                default:
                    break;
            }
        

            if (((Button)sender).Content.ToString() == "=")
            {               
                ResultTextBox.Text = new DataTable().Compute(FormulaTextBox.Text, null).ToString();
                FormulaTextBox.Text = "";
                return;
            }
        }
    }
}
