using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.ComponentModel;

namespace ThePenaltyMethod.Functions
{
	/// <summary> Абстрактный класс для представления функции </summary>
	public abstract class Function : INotifyPropertyChanged
	{
		/// <summary> Имя функции </summary>
		public string Name { get; set; }

		/// <summary> Вычисляет значение функции в точке </summary>
		public abstract double Value(Point p);

		/// <summary> Вычисляет значение производной по переменной "X" функции в точке </summary>
		public abstract double Derivative_dX(Point p);

		/// <summary> Вычисляет значение производной по переменной "Y" функции в точке </summary>
		public abstract double Derivative_dY(Point p);

		public event PropertyChangedEventHandler PropertyChanged;

		protected void NotifyPropertyChanged(string propertyName)
		{
			if (this.PropertyChanged != null)
				this.PropertyChanged(null, new PropertyChangedEventArgs(propertyName));
		}
	}
}
