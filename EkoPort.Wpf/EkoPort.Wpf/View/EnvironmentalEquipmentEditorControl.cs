using System.Windows;

namespace EkoPort.Wpf
{
    public class EnvironmentalEquipmentEditorControl : DataItemEditorControl
    {
        static EnvironmentalEquipmentEditorControl()
        {
            DefaultStyleKeyProperty.OverrideMetadata(typeof (EnvironmentalEquipmentEditorControl), 
                new FrameworkPropertyMetadata(typeof (EnvironmentalEquipmentEditorControl)));
        }
    }
}
