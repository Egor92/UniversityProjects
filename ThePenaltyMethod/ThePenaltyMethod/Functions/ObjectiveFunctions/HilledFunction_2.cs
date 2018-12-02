using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ThePenaltyMethod.Functions.ObjectiveFunctions
{
	/// <summary> Целевая функция, заданная выражением "Sin(2x-1) - 3*Cos(xy-1)" </summary>
	public class HilledFunction_2 : ObjectiveFunction
	{
		public HilledFunction_2()
		{
			this.Name = "Овражная функция №2\nSin(2x-1) - 3*Cos(xy-1)";
		}

		public override double Value(System.Windows.Point p)
		{
			return Math.Sin(2*p.X-1)  - 3*(Math.Cos(p.X * p.Y-1));
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
