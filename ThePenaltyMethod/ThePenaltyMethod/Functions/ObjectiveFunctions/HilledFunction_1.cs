using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ThePenaltyMethod.Functions.ObjectiveFunctions
{
	/// <summary> Целевая функция, заданная выражением "Sin(x) * Cosh(y)^2 - |Sin(xy)|" </summary>
	public class HilledFunction_1 : ObjectiveFunction
	{
		public HilledFunction_1()
		{
			this.Name = "Овражная функция №1\nSin(x) * Cosh(y)^2 - |Sin(xy)|";
		}

		public override double Value(System.Windows.Point p)
		{
			return Math.Sin(p.X) * Math.Pow(Math.Cosh(p.Y), 2.0) - Math.Abs(Math.Sin(p.X * p.Y));
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
