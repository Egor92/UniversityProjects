using System.Windows;

namespace EkoPort.Wpf
{
    public class ContaminantEditorControl : DataItemEditorControl
    {
        static ContaminantEditorControl()
        {
            DefaultStyleKeyProperty.OverrideMetadata(typeof (ContaminantEditorControl), 
                new FrameworkPropertyMetadata(typeof (ContaminantEditorControl)));
        }
    }
}
