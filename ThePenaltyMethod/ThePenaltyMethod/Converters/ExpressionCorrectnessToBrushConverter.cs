using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Data;
using System.Windows.Media;
using System.Globalization;

namespace ThePenaltyMethod.Converters
{
	[ValueConversion(typeof(bool), typeof(SolidColorBrush))]
	public class ExpressionCorrectnessToBrushConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if (((bool)value) == true)
				return Brushes.Transparent;
			else
				//return Brushes.Red;
				return Brushes.Transparent;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			return null;
		}
	}
}
