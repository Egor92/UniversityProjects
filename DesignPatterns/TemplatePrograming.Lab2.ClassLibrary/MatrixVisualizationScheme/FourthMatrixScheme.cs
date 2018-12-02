using System.Windows.Media;

namespace TemplatePrograming.Lab2.ClassLibrary
{
    public class FourthMatrixScheme : IMatrixVisualizationScheme
    {
        public double ItemSize
        {
            get { return 35; }
        }

        public Brush MatrixBorderBrush
        {
            get { return Brushes.Black; }
        }

        public Brush MatrixBackground
        {
            get { return null; }
        }

        public Brush ItemBorderBrush
        {
            get { return Brushes.Black; }
        }

        public Brush ValueItemBackground
        {
            get { return null; }
        }

        public Brush EmptyItemBackground
        {
            get { return null; }
        }

        public bool IsShadowVisible
        {
            get { return true; }
        }
    }
}
