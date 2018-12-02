using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using ThePenaltyMethod.Functions;

namespace ThePenaltyMethod
{
	public class PenaltyMethod
	{
		private GeneralFunction GeneralFunction;

		public PenaltyMethod(GeneralFunction generalFunction)
		{
			this.GeneralFunction = generalFunction;
		}

		/// <summary> Выполнить поиск </summary>
		public Tuple<List<Point>, int> Perform(Point startPoint, double Sigma_Discrepancy, double Sigma_HookJeevs, double h0, double Gamma_0)
		{
			List<Point> AlgorithmSteps = new List<Point>();
			List<Point> Point_list = new List<Point>();
			Point z;

			int k = 1;
			int i = 0;
			double h = h0;

			for (; true; k++)
			{
				h = h0;
				i = 0;

				double Gamma_k = Math.Pow(Gamma_0, k);
				AlgorithmSteps.Clear();
				Point_list.Clear();
				Point_list.Add(z = startPoint);

				while (true)
				{
					Point_list.Add(GetConfiguration(z, h, Gamma_k));

					if (this.GeneralFunction.Value(Point_list[i + 1], Gamma_k) < this.GeneralFunction.Value(Point_list[i], Gamma_k))
					{
						i++;
						z = new Point()
						{
							X = Point_list[i].X + 2 * (Point_list[i].X - Point_list[i - 1].X),
							Y = Point_list[i].Y + 2 * (Point_list[i].Y - Point_list[i - 1].Y)
						};
					}
					else if (h < Sigma_HookJeevs)
						break;
					else
					{
						if (i == 0)
							h /= 2;

						Point lastPoint = Point_list[i];
						AlgorithmSteps.AddRange(Point_list.Take(i));
						Point_list.Clear();
						Point_list.Add(lastPoint);
						i = 0;
						z = lastPoint;
					}
				}


				AlgorithmSteps.Add(Point_list.Last());


				if (this.Discrepancy(Point_list[i]) < Sigma_Discrepancy) break;
			}

			return new Tuple<List<Point>, int> (AlgorithmSteps, k);
		}

		/// <summary> Возвращает конфигурацию </summary>
		private Point GetConfiguration(Point z, double h, double Gamma_k)
		{
			Point Result = z;

			Point a = new Point(Result.X + h, Result.Y);
			Point b = new Point(Result.X - h, Result.Y);
			if (this.GeneralFunction.Value(a, Gamma_k) < this.GeneralFunction.Value(Result, Gamma_k))
				Result = a;
			else if (this.GeneralFunction.Value(b, Gamma_k) < this.GeneralFunction.Value(Result, Gamma_k))
				Result = b;

			Point c = new Point(Result.X, Result.Y + h);
			Point d = new Point(Result.X, Result.Y - h);
			if (this.GeneralFunction.Value(c, Gamma_k) < this.GeneralFunction.Value(Result, Gamma_k))
				Result = c;
			else if (this.GeneralFunction.Value(d, Gamma_k) < this.GeneralFunction.Value(Result, Gamma_k))
				Result = d;

			return Result;
		}

		/// <summary> Невязка </summary>
		private double Discrepancy(Point p)
		{
			double Result = 0.0;
			foreach (ConditionFunction cond in this.GeneralFunction.GetConditionFunction())
				Result = Math.Max(Result, cond.Value(p));
			return Result;
		}
	
	}
}
