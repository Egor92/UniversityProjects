using System.Windows;

namespace TemplatePrograming.Lab2.Client
{
    public class SparseMatrixDataTemplateSelector : SimpleMatrixDataTemplateSelector
    {
        private const string EmptyItemTemplateString =
            @"<DataTemplate xmlns='http://schemas.microsoft.com/winfx/2006/xaml/presentation'>
                <Border Margin='4' BorderThickness='4' Background='{Binding EmptyItemBackground, Mode=OneWay}' BorderBrush='{Binding ItemBorderBrush, Mode=OneWay}' Height='{Binding ItemSize, Mode=OneWay}' Width='{Binding ItemSize, Mode=OneWay}' />
            </DataTemplate>";

        private DataTemplate _emptyTemplate;
        protected DataTemplate EmptyTemplate
        {
            get { return _emptyTemplate ?? (_emptyTemplate = ParseItemTemplate(EmptyItemTemplateString)); }
        }

        public override DataTemplate SelectTemplate(object item, DependencyObject container)
        {
            var valueItemViewModel = item as ValueItemViewModel;
            if (valueItemViewModel == null || valueItemViewModel.Value == 0.0)
                return EmptyTemplate;
            return BorderedItemTemplate;
        }
    }
}
