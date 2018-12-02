using System.Windows;

namespace EkoPort.Wpf
{
    public class TransshippingAreaEditorControl : DataItemEditorControl
    {
        static TransshippingAreaEditorControl()
        {
            DefaultStyleKeyProperty.OverrideMetadata(typeof (TransshippingAreaEditorControl), 
                new FrameworkPropertyMetadata(typeof (TransshippingAreaEditorControl)));
        }
    }
}
