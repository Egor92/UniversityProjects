using System.Windows.Controls;
using TemplatePrograming.Lab1.ClassLibrary;

namespace TemplatePrograming.Lab2.Client
{
    public class SparseMatrixControlViewModel : MatrixControlViewModel
    {
        public override DataTemplateSelector ItemTemplateSelector
        {
            get { return new SparseMatrixDataTemplateSelector(); }
        }

        public SparseMatrixControlViewModel(SparseMatrix matrix, IMatrixVisualizationScheme scheme)
            : base(matrix, scheme)
        {
        }
    }
}
