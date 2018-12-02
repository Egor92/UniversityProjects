using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Data;
using System.Windows.Media;
using System.Globalization;
using System.Windows;

namespace ThePenaltyMethod.Converters
{
	[ValueConversion(typeof(bool), typeof(bool))]
	public class BooleanNegationToVisibilityConverter : IValueConverter
	{
		public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if ((bool)value == true)
				return Visibility.Collapsed;
			else
				return Visibility.Visible;
		}

		public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
		{
			if ((Visibility)value == Visibility.Visible)
				return false;
			else
				return true;
		}
	}
}
