using System;
using System.Windows;
using TemplatePrograming.Lab2.ClassLibrary;

namespace TemplatePrograming.Lab2.Client
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private IMatrixDrawer _simpleMatrixDrawer;
        private IMatrixDrawer _sparseMatrixDrawer;
        private IMatrix _simpleMatrix;
        private IMatrix _sparseMatrix;

        private IMatrixVisualizationScheme SelecedVisualizationScheme
        {
            get
            {
                if (FirstSchemeRadioButton.IsChecked.HasValue && FirstSchemeRadioButton.IsChecked.Value)
                    return new FirstMatrixScheme();
                if (SecondSchemeRadioButton.IsChecked.HasValue && SecondSchemeRadioButton.IsChecked.Value)
                    return new SecondMatrixScheme();
                if (ThirdSchemeRadioButton.IsChecked.HasValue && ThirdSchemeRadioButton.IsChecked.Value)
                    return new ThirdMatrixScheme();
                if (FourthSchemeRadioButton.IsChecked.HasValue && FourthSchemeRadioButton.IsChecked.Value)
                    return new FourthMatrixScheme();
                return null;
            }
        }

        public MainWindow()
        {
            InitializeComponent();
        }

        private void MainWindow_OnLoaded(object sender, RoutedEventArgs e)
        {
            _simpleMatrixDrawer = new CanvasMatrixDrawer(SimpleMatrixCanvas, SelecedVisualizationScheme);
            _sparseMatrixDrawer = new CanvasMatrixDrawer(SparseMatrixCanvas, SelecedVisualizationScheme);
        }

        private void GenerateMatrixButton_OnClick(object sender, RoutedEventArgs e)
        {
            var random = new Random(DateTime.Now.Millisecond);
            var rowCount = random.Next(3, 7);
            var columnCount = random.Next(3, 7);
            _simpleMatrix = new Matrix(rowCount, columnCount);
            _sparseMatrix = new SparseMatrix(rowCount, columnCount);
            for (int i = 0; i < rowCount; i++)
            {
                for (int j = 0; j < columnCount; j++)
                {
                    double value = random.NextDouble() > 0.5
                        ? 10 * random.NextDouble()
                        : 0.0;
                    _simpleMatrix.SetValue(i, j, value);
                    _sparseMatrix.SetValue(i, j, value);
                }
            }
            DisplayMatrixes();
        }

        private void SchemeChanged(object sender, RoutedEventArgs e)
        {
            DisplayMatrixes();
        }

        private void DisplayMatrixes()
        {
            if (SelecedVisualizationScheme == null)
                return;
            if (_simpleMatrixDrawer != null)
                _simpleMatrix.Draw(_simpleMatrixDrawer);
            if (_sparseMatrixDrawer != null)
                _sparseMatrix.Draw(_sparseMatrixDrawer);
        }
    }
}
