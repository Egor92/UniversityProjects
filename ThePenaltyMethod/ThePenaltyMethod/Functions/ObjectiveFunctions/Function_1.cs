using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ThePenaltyMethod.Functions.ObjectiveFunctions
{
	/// <summary> Целевая функция, заданная выражением "4x^2 + 3y^2" </summary>
	public class Function_1 : ObjectiveFunction
	{
		public Function_1()
		{
			this.Name = "Функция №1\n4x^2 + 3y^2";
		}

		public override double Value(System.Windows.Point p)
		{
			return 4 * p.X * p.X + 3 * p.Y * p.Y;
		}

		public override double Derivative_dX(System.Windows.Point p)
		{
			return 8 * p.X - 2 * p.Y;
		}

		public override double Derivative_dY(System.Windows.Point p)
		{
			return 6 * p.Y - 2 * p.X;
		}
	}
}
