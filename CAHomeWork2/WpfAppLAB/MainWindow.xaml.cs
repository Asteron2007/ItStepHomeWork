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

namespace WpfAppLAB
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            Grid grid = new Grid();
            this.Content = grid;
            Button btn = new Button();
            btn.Width = 400;
            btn.Height = 150;
            btn.Content = "Hello";
            btn.Click += Button_Click;
            grid.Children.Add(btn);

        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show( ((Button)sender).Content.ToString() );
        }

        private void Ellipse_MouseEnter(object sender, MouseEventArgs e)
        {
           // ((Ellipse)sender).
        }
    }
}
