using System.Windows;

namespace TemplatePrograming.Lab2.Client
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App
    {
        protected override void OnStartup(StartupEventArgs e)
        {
            var mainWindow = new MainWindow
            {
                DataContext = new MainWindowViewModel()
            };
            mainWindow.Show();
        }
    }
}
