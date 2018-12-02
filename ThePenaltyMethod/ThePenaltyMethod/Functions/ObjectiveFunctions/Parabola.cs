using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ThePenaltyMethod.Functions.ObjectiveFunctions
{
	/// <summary> Целевая функция, заданная выражением "x^2 + y^2" </summary>
	public class Parabola : ObjectiveFunction
	{
		public Parabola()
		{
			this.Name = "Квадратичная парабола\nx^2 + y^2";
		}

		public override double Value(System.Windows.Point p)
		{
			return Math.Pow(p.X, 2) + Math.Pow(p.Y, 2);
		}

		public override double Derivative_dX(System.Windows.Point p)
		{
			return 2 * p.X;
		}

		public override double Derivative_dY(System.Windows.Point p)
		{
			return 2 * p.Y;
		}
	}
}
