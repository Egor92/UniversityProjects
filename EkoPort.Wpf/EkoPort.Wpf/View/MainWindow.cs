using System.Windows;

namespace EkoPort.Wpf
{
    public class MainWindow : Window
    {
        public MainWindow()
        {
            WindowStartupLocation = WindowStartupLocation.CenterScreen;
        }

        static MainWindow()
        {
            DefaultStyleKeyProperty.OverrideMetadata(typeof (MainWindow),
                new FrameworkPropertyMetadata(typeof (MainWindow)));
        }
    }
}
