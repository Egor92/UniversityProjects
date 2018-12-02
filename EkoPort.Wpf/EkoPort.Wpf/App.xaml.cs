using System;
using System.IO;
using System.Windows;

namespace EkoPort.Wpf
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application
    {
        private const string TimeFormat = @"yyyy-MM-dd hh-mm-ss";

        protected override void OnStartup(StartupEventArgs e)
        {
            AppDomain.CurrentDomain.UnhandledException += CurrentDomain_UnhandledException;

            var mainWindow = new MainWindow();
            var mainWindowViewModel = new MainWindowViewModel();
            mainWindow.DataContext = mainWindowViewModel;
            mainWindow.Show();
        }

        private void CurrentDomain_UnhandledException(object sender, UnhandledExceptionEventArgs e)
        {
            var stackTrace = Environment.StackTrace;
            var timeString = DateTime.Now.ToString(TimeFormat);
            string path = string.Format(@"{0}\error ({1}).txt", Directory.GetCurrentDirectory(), timeString);
            File.WriteAllText(path, stackTrace);
            string message = string.Format(@"Произошла необработанная ошибка. Приложение будет закрыто. Файл с логами находится по пути: ""{0}""", path);
            MessageBox.Show(message, "Ошибка", MessageBoxButton.OK, MessageBoxImage.Error);

            Shutdown();
        }
    }
}
