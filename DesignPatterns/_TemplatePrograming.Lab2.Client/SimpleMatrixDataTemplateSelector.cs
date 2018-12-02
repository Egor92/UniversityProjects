using System.Windows;
using System.Windows.Controls;
using System.Windows.Markup;

namespace TemplatePrograming.Lab2.Client
{
    public class SimpleMatrixDataTemplateSelector : DataTemplateSelector
    {
        private const string BorderedItemTemplateString =
            @"<DataTemplate xmlns='http://schemas.microsoft.com/winfx/2006/xaml/presentation' xmlns:x='http://schemas.microsoft.com/winfx/2006/xaml'>
                <Border Margin='4' BorderThickness='4' Background='{Binding ValueItemBackground, Mode=OneWay}' BorderBrush='{Binding ItemBorderBrush, Mode=OneWay}' Height='{Binding ItemSize, Mode=OneWay}' Width='{Binding ItemSize, Mode=OneWay}'>
                    <Border.Style>
                        <Style TargetType='{x:Type Border}'>
                            <Style.Resources>
                                <DropShadowEffect x:Key='DropShadowEffect' />
                            </Style.Resources>
                            <Style.Triggers>
                                <DataTrigger Binding='{Binding Path=IsShadowVisible}' Value='True'>
                                    <Setter Property='Effect' Value='{StaticResource DropShadowEffect}' />
                                </DataTrigger>	
                            </Style.Triggers>
                        </Style>
                    </Border.Style>
                    <TextBlock HorizontalAlignment='Center' VerticalAlignment='Center' Text='{Binding Value, Mode=OneWay, StringFormat=\{0:n1\}}' />
                </Border>
            </DataTemplate>";

        private DataTemplate _borderedItemTemplate;
        protected DataTemplate BorderedItemTemplate
        {
            get { return _borderedItemTemplate ?? (_borderedItemTemplate = ParseItemTemplate(BorderedItemTemplateString)); }
        }

        public override DataTemplate SelectTemplate(object item, DependencyObject container)
        {
            return BorderedItemTemplate;
        }

        protected static DataTemplate ParseItemTemplate(string dataTemplateString)
        {
            return XamlReader.Parse(dataTemplateString) as DataTemplate;
        }
    }
}
