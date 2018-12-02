using System.Windows;
using System.Windows.Controls;
using TemplatePrograming.Lab2.ClassLibrary;

namespace TemplatePrograming.Lab4.Client
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow
    {
        private int _depth = 1;
        private int _maxGroupWidth = 1;
        private int _maxSize = 1;
        private IMatrixDrawer _matrixDrawer;

        private IMatrixDrawer MatrixDrawer
        {
            get { return _matrixDrawer ?? (_matrixDrawer = new BrightCanvasMatrixDrawer(MatrixCanvas)); }
        }

        private bool IsAvailable
        {
            get { return _depth > 0 && _maxGroupWidth > 0 && _maxSize > 0; }
        }

        public MainWindow()
        {
            InitializeComponent();
        }

        private void DepthSlider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            var slider = (Slider)sender;
            int newValue = (int)e.NewValue;
            slider.Value = newValue;
            if (_depth == newValue)
                return;
            _depth = newValue;
            DiplayMatrix();
        }

        private void MaxGroupWidthSlider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            var slider = (Slider)sender;
            int newValue = (int)e.NewValue;
            slider.Value = newValue;
            if (_maxGroupWidth == newValue)
                return;
            _maxGroupWidth = newValue;
            DiplayMatrix();
        }

        private void MaxSizeSlider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            var slider = (Slider)sender;
            int newValue = (int)e.NewValue;
            slider.Value = newValue;
            if (_maxSize == newValue)
                return;
            _maxSize = newValue;
            DiplayMatrix();
        }

        private void DiplayMatrix()
        {
            if (!IsAvailable && IsLoaded)
                return;
            var matrix = MatrixFactory.GetMatrix(_depth, _maxGroupWidth, _maxSize);
            matrix.Draw(MatrixDrawer);
        }
    }
}
