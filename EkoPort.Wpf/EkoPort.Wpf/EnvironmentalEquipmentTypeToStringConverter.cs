using System;
using System.ComponentModel;
using System.Globalization;
using System.Reflection;
using System.Windows.Data;
using System.Windows.Markup;

namespace EkoPort.Wpf
{
    public class EnvironmentalEquipmentTypeToStringConverter : MarkupExtension, IValueConverter
    {
        private static readonly EnvironmentalEquipmentTypeToStringConverter Instance = new EnvironmentalEquipmentTypeToStringConverter();

        public override object ProvideValue(IServiceProvider serviceProvider)
        {
            return Instance;
        }

        private static string GetEnumDescription(Enum enumObj)
        {
            FieldInfo fieldInfo = enumObj.GetType().GetField(enumObj.ToString());

            object[] attribArray = fieldInfo.GetCustomAttributes(false);

            if (attribArray.Length == 0)
            {
                return enumObj.ToString();
            }
            var descriptionAttribute = attribArray[0] as DescriptionAttribute;
            return descriptionAttribute.Description;
        }

        object IValueConverter.Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            Enum myEnum = (Enum)value;
            string description = GetEnumDescription(myEnum);
            return description;
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    }
}
