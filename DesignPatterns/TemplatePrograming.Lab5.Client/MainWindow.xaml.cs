using System.Windows;
using TemplatePrograming.Lab2.ClassLibrary;
using TemplatePrograming.Lab5.ClassLibrary;
using CommandManager = TemplatePrograming.Lab5.ClassLibrary.CommandManager;

namespace TemplatePrograming.Lab5.Client
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private IMatrixDrawer _matrixDrawer;
        private IMatrix _matrix;

        public MainWindow()
        {
            InitializeComponent();
        }

        private void MainWindow_OnLoaded(object sender, RoutedEventArgs e)
        {
            _matrixDrawer = new CanvasMatrixDrawer(MatrixCanvas, new FirstMatrixScheme());
            var matrixRef = new Ref<IMatrix>(() => _matrix, x => _matrix = x);
            new InitializeAppCommand(matrixRef).Execute();
            DisplayMatrixes();
        }

        private void ChangeButton_OnClick(object sender, RoutedEventArgs e)
        {
            var matrixRef = new Ref<IMatrix>(() => _matrix, x => _matrix = x);
            new ChangeRandomMatrixValueCommand(matrixRef).Execute();
            DisplayMatrixes();
            UndoButton.IsEnabled = CommandManager.CanUndo;
        }

        private void UndoButton_OnClick(object sender, RoutedEventArgs e)
        {
            if (!CommandManager.CanUndo)
                return;
            CommandManager.Undo();
            DisplayMatrixes();
            UndoButton.IsEnabled = CommandManager.CanUndo;
        }

        private void DisplayMatrixes()
        {
            if (_matrixDrawer != null)
                _matrix.Draw(_matrixDrawer);
        }
    }
}
