using System;
using System.Collections.Generic;
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

namespace WpfAppCrossesZeros
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        Boolean IsCross;

        int GamesCount = 0;
        int CrossWin = 0;
        int ZeroWin = 0;

        const int FieldSize = 3;

        // Попробуйте реализовать игру крестики и нолики 3х3 на WPF.
        // Если получится против компьютера — будет очень круто,
        // но будет достаточно для двух человек.
        // Тогда, приложение это просто поле для интерактивного взаимодействия игроков.


        public MainWindow()
        {
            InitializeComponent();
            RestartGame();
        }

        private void RestartGame()
        {
            IsCross = true;
            GamesCount++;

            CheckGameIsOver();

            btn0_0.Content = "";
            btn0_1.Content = "";
            btn0_2.Content = "";
            btn1_0.Content = "";
            btn1_1.Content = "";
            btn1_2.Content = "";
            btn2_0.Content = "";
            btn2_1.Content = "";
            btn2_2.Content = "";
        }

        private enum TWinMode { wmZero, wmCross, wmNome };

        private void RefreshForm()
        {
            if (IsCross)
            {
                lblPlayer.Content = "Cross player";
                lblCrossWin.Content = "Cross win: " + CrossWin.ToString();
            }
            else
            {
                lblPlayer.Content = "Zero player";
                lblZeroWin.Content = "Zero win: " + ZeroWin.ToString();
            }
        }
        private TWinMode CheckGameIsOver()
        {
            int CrossCounter = 0;
            int ZeroCounter = 0;

            object wantedNode = null;

            // check vinner horisontal
            for (int i = 0; i < FieldSize; i++)
            {
                CrossCounter = 0;
                ZeroCounter = 0;
                for (int j = 0; j < FieldSize; j++)
                {
                    wantedNode = FormGrid.FindName("btn" + i.ToString() + "_" + j.ToString());
                    if (wantedNode is Button)
                    {
                        Button wantedButton = wantedNode as Button;
                        if (wantedButton.Content == "X")
                            CrossCounter++;
                        else if (wantedButton.Content == "0")
                            ZeroCounter++;
                    }

                    if (CrossCounter == FieldSize)
                        return TWinMode.wmCross;
                    if (ZeroCounter == FieldSize)
                        return TWinMode.wmZero;
                }
                CrossCounter = 0;
                ZeroCounter = 0;
            }

            // check vinner vertical
            for (int i = 0; i < FieldSize; i++)
            {
                CrossCounter = 0;
                ZeroCounter = 0;
                for (int j = 0; j < FieldSize; j++)
                {
                    wantedNode = FormGrid.FindName("btn" + j.ToString() + "_" + i.ToString());
                    if (wantedNode is Button)
                    {
                        Button wantedButton = wantedNode as Button;
                        if (wantedButton.Content == "X")
                            CrossCounter++;
                        else if (wantedButton.Content == "0")
                            ZeroCounter++;
                    }

                    if (CrossCounter == FieldSize)
                        return TWinMode.wmCross;
                    if (ZeroCounter == FieldSize)
                        return TWinMode.wmZero;
                }
                CrossCounter = 0;
                ZeroCounter = 0;
            }

            // check vinner diagonal
            // main diagonal
            for (int i = 0; i < FieldSize; i++)
            {
                wantedNode = FormGrid.FindName("btn" + i.ToString() + "_" + i.ToString());
                if (wantedNode is Button)
                {
                    Button wantedButton = wantedNode as Button;
                    if (wantedButton.Content == "X")
                        CrossCounter++;
                    else if (wantedButton.Content == "0")
                        ZeroCounter++;
                }
            }
            if (CrossCounter == FieldSize)
                return TWinMode.wmCross;
            if (ZeroCounter == FieldSize)
                return TWinMode.wmZero;
            CrossCounter = 0;
            ZeroCounter = 0;
            //second diagonal
            for (int i = 0; i < FieldSize; i++)
            {
                wantedNode = FormGrid.FindName("btn" + (FieldSize-1- i).ToString() + "_" + i.ToString());
                if (wantedNode is Button)
                {
                    Button wantedButton = wantedNode as Button;
                    if (wantedButton.Content == "X")
                        CrossCounter++;
                    else if (wantedButton.Content == "0")
                        ZeroCounter++;
                }


            }
            if (CrossCounter == FieldSize)
                return TWinMode.wmCross;
            if (ZeroCounter == FieldSize)
                return TWinMode.wmZero;
            //CrossCounter = 0;
            //ZeroCounter = 0;


            return TWinMode.wmNome;
        }

        private void ButtonClick(object sender)
        {

            if (((Button)sender).Content == "")
            {
                if (IsCross)
                {
                    ((Button)sender).Content = "X";
                    lblPlayer.Content = "Zero player";
                }
                else
                {
                    ((Button)sender).Content = "0";                    
                    lblPlayer.Content = "Cross player";
                }

                IsCross = !IsCross;

                TWinMode Winner = CheckGameIsOver();


                switch (Winner)
                {
                    case TWinMode.wmZero:
                        MessageBox.Show("Zero", "Winer");
                        ZeroWin++;
                        Button_Click(this, new RoutedEventArgs());
                        RefreshForm();
                        break;
                    case TWinMode.wmCross:
                        MessageBox.Show("Cross", "Winer");
                        CrossWin++;
                        Button_Click(this, new RoutedEventArgs());
                        RefreshForm();
                        break;
                    default:
                        RefreshForm();
                        break;
                }
                
            }
        }

        private void btn0_0_Click(object sender, RoutedEventArgs e)
        {
            ButtonClick(sender);
        }

        private void btn0_1_Click(object sender, RoutedEventArgs e)
        {
            ButtonClick(sender);
        }

        private void btn0_2_Click(object sender, RoutedEventArgs e)
        {
            ButtonClick(sender);
        }

        private void btn1_0_Click(object sender, RoutedEventArgs e)
        {
            ButtonClick(sender);
        }

        private void btn1_1_Click(object sender, RoutedEventArgs e)
        {
            ButtonClick(sender);
        }

        private void btn1_2_Click(object sender, RoutedEventArgs e)
        {
            ButtonClick(sender);
        }

        private void btn2_0_Click(object sender, RoutedEventArgs e)
        {
            ButtonClick(sender);
        }

        private void btn2_1_Click(object sender, RoutedEventArgs e)
        {
            ButtonClick(sender);
        }

        private void btn2_2_Click(object sender, RoutedEventArgs e)
        {
            ButtonClick(sender);
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            if (MessageBox.Show("Begin new game?","Warning", MessageBoxButton.YesNoCancel) == MessageBoxResult.Yes)
                RestartGame();
        }
    }
}
