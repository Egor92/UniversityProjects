using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ThePenaltyMethod.Functions.ObjectiveFunctions
{
	/// <summary> Целевая функция, заданная выражением "4x^2 + 3y^2" </summary>
	public class Function_2 : ObjectiveFunction
	{
		public Function_2()
		{
			this.Name = "Функция №1\n-1/(x*x+y*y)";
		}

		public override double Value(System.Windows.Point p)
		{
			return -1/(p.X*p.X + p.Y*p.Y);
		}

		public override double Derivative_dX(System.Windows.Point p)
		{
			return 0.0;
		}

		public override double Derivative_dY(System.Windows.Point p)
		{
			return 0.0;
		}
	}
}
