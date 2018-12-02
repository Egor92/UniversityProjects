using System.Windows.Media;

namespace TemplatePrograming.Lab2.ClassLibrary
{
    public class FirstMatrixScheme : IMatrixVisualizationScheme
    {
        public double ItemSize
        {
            get { return 40; }
        }

        public Brush MatrixBorderBrush
        {
            get { return Brushes.BlueViolet; }
        }

        public Brush MatrixBackground
        {
            get { return Brushes.Yellow; }
        }

        public Brush ItemBorderBrush
        {
            get { return Brushes.Red; }
        }

        public Brush ValueItemBackground
        {
            get { return Brushes.Orange; }
        }

        public Brush EmptyItemBackground
        {
            get { return Brushes.Red; }
        }

        public bool IsShadowVisible
        {
            get { return false; }
        }
    }
}
