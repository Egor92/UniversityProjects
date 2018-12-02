using System.Windows.Controls;
using TemplatePrograming.Lab1.ClassLibrary;

namespace TemplatePrograming.Lab2.Client
{
    public class SimpleMatrixControlViewModel : MatrixControlViewModel
    {
        public override DataTemplateSelector ItemTemplateSelector
        {
            get { return new SimpleMatrixDataTemplateSelector(); }
        }

        public SimpleMatrixControlViewModel(Matrix matrix, IMatrixVisualizationScheme scheme) 
            : base(matrix, scheme)
        {
        }
    }
}
