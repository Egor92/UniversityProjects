using System;
using System.Windows;
using TemplatePrograming.Lab2.ClassLibrary;
using TemplatePrograming.Lab3.ClassLibrary;

namespace TemplatePrograming.Lab3.Client
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private readonly Random _random = new Random(DateTime.Now.Millisecond);
        private CanvasMatrixDrawer _simpleMatrixDrawer;
        private CanvasMatrixDrawer _sparseMatrixDrawer;
        private IMatrix _simpleMatrix;
        private IMatrix _sparseMatrix;
        private int _matrixSize;

        private bool CanDecorate
        {
            get { return _matrixSize > 0; }
        }

        private IMatrixVisualizationScheme SelectedVisualizationScheme
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
            _simpleMatrixDrawer = new CanvasMatrixDrawer(SimpleMatrixCanvas, SelectedVisualizationScheme);
            _sparseMatrixDrawer = new CanvasMatrixDrawer(SparseMatrixCanvas, SelectedVisualizationScheme);
        }

        private void GenerateMatrixButton_OnClick(object sender, RoutedEventArgs e)
        {
            _matrixSize = _random.Next(3, 7);
            _simpleMatrix = new Matrix(_matrixSize, _matrixSize);
            _sparseMatrix = new SparseMatrix(_matrixSize, _matrixSize);
            for (int i = 0; i < _matrixSize; i++)
            {
                for (int j = 0; j < _matrixSize; j++)
                {
                    double value = _random.NextDouble() > 0.5
                        ? 10 * _random.NextDouble()
                        : 0.0;
                    _simpleMatrix.SetValue(i, j, value);
                    _sparseMatrix.SetValue(i, j, value);
                }
            }
            DisplayMatrixes();
        }

        private void SchemeChanged(object sender, RoutedEventArgs e)
        {
            if (SelectedVisualizationScheme == null)
                return;
            if (_simpleMatrixDrawer != null)
                _simpleMatrixDrawer.Scheme = SelectedVisualizationScheme;
            if (_sparseMatrixDrawer != null)
                _sparseMatrixDrawer.Scheme = SelectedVisualizationScheme;
            DisplayMatrixes();
        }

        private void DisplayMatrixes()
        {
            if (_simpleMatrixDrawer != null)
                _simpleMatrix.Draw(_simpleMatrixDrawer);
            if (_sparseMatrixDrawer != null)
                _sparseMatrix.Draw(_sparseMatrixDrawer);
        }

        private void RenumberRowsButton_OnClick(object sender, RoutedEventArgs e)
        {
            if (!CanDecorate)
                return;
            var i = _random.Next(_matrixSize);
            var j = i;
            while (j == i)
                j = _random.Next(_matrixSize);
            _simpleMatrix = new RowSwapDecorator(_simpleMatrix, i, j);
            _sparseMatrix = new RowSwapDecorator(_sparseMatrix, i, j);
            StatusTextBlock.Text = string.Format("Стоки {0} и {1} поменялись местами", i, j);
            DisplayMatrixes();
        }

        private void RenumberColumns_OnClick(object sender, RoutedEventArgs e)
        {
            if (!CanDecorate)
                return;
            var i = _random.Next(_matrixSize);
            var j = i;
            while (j == i)
                j = _random.Next(_matrixSize);
            _simpleMatrix = new ColumnSwapDecorator(_simpleMatrix, i, j);
            _sparseMatrix = new ColumnSwapDecorator(_sparseMatrix, i, j);
            StatusTextBlock.Text = string.Format("Столбцы {0} и {1} поменялись местами", i, j);
            DisplayMatrixes();
        }

        private void TransposeButton_OnClick(object sender, RoutedEventArgs e)
        {
            if (!CanDecorate)
                return;
            _simpleMatrix = new TranspositionDecorator(_simpleMatrix);
            _sparseMatrix = new TranspositionDecorator(_sparseMatrix);
            StatusTextBlock.Text = string.Format("Транспонирование произведено");
            DisplayMatrixes();
        }

        private void UndoButton_OnClick(object sender, RoutedEventArgs e)
        {
            if (!CanDecorate)
                return;
            var simpleMatrixDecorator = _simpleMatrix as MatrixDecorator;
            if (simpleMatrixDecorator != null)
                _simpleMatrix = simpleMatrixDecorator.SourceMatrix;
            var sparseMatrixDecorator = _sparseMatrix as MatrixDecorator;
            if (sparseMatrixDecorator != null)
                _sparseMatrix = sparseMatrixDecorator.SourceMatrix;
            StatusTextBlock.Text = string.Format("Отмена произведена");
            DisplayMatrixes();
        }

        private void RestoreButton_OnClick(object sender, RoutedEventArgs e)
        {
            if (!CanDecorate)
                return;
            var simpleMatrixDecorator = _simpleMatrix as MatrixDecorator;
            if (simpleMatrixDecorator != null)
                _simpleMatrix = simpleMatrixDecorator.GetOriginalMatrix();
            var sparseMatrixDecorator = _sparseMatrix as MatrixDecorator;
            if (sparseMatrixDecorator != null)
                _sparseMatrix = sparseMatrixDecorator.GetOriginalMatrix();
            StatusTextBlock.Text = string.Format("Матрицы восстановлены");
            DisplayMatrixes();
        }
    }
}
