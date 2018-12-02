using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;

namespace HookJivs
{
	class Program
	{
		static void Main(string[] args)
		{
			List<Point> AlgorithmSteps = new List<Point>();
			List<Point> Point_list = new List<Point>();
			Point z = new Point();

			double Sigma = 0.0001;
			double Sigma_HJ = 0.0001;
			double h0 = 1.5;

			double Gamma_0 = 25;
			int k = 1;
			int i = 0;

			double _H;
			double _G;
			double _S;

			double h;

			for (; true; k++)
			{
				h = h0;
				i = 0;
				int i_fix = 0;
				double Gamma_k = Gamma_0 * k;
				AlgorithmSteps.Clear();
				Point_list.Clear();
				Point_list.Add(z = new Point(10, 40));

				while (true)
				{
					_H = H(Point_list.Last());
					_S = S(Point_list.Last(), Gamma_k);

					Point_list.Add(GetConfiguration(z, h, Gamma_k));

					_H = H(Point_list.Last());
					_S = S(Point_list.Last(), Gamma_k);

					if (S(Point_list[i + 1], Gamma_k) < S(Point_list[i], Gamma_k))
					{
						i++;
						z = new Point()
						{
							X = Point_list[i].X + 2 * (Point_list[i].X - Point_list[i - 1].X),
							Y = Point_list[i].Y + 2 * (Point_list[i].Y - Point_list[i - 1].Y)
						};
					}
					else if (h < Sigma_HJ)
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



				_G = G(Point_list[i]);
				if (_G < Sigma) break;
			}


			Console.WriteLine("Minimum is in point x1 = {0}, x2 = {1}, iterations k = {2}", Point_list[i].X, Point_list[i].Y, k);
			//Console.WriteLine("Minimum is in point x1 = {0}, x2 = {1}, iterations k = {2}", y.X, y.Y, k);
			Console.WriteLine("\n");

			for (int I = 0; I < AlgorithmSteps.Count; I++)
			{
				Console.WriteLine("I={0}, X={1}, Y={2}", I, AlgorithmSteps[I].X, AlgorithmSteps[I].Y);
			}


			Console.ReadKey();
		}



		private static Point GetConfiguration(Point z, double h, double Gamma_k)
		{
			Point Result = z;

			Point a = new Point(Result.X + h, Result.Y);
			Point b = new Point(Result.X - h, Result.Y);
			if (S(a, Gamma_k) < S(Result, Gamma_k))
				Result = a;
			else if (S(b, Gamma_k) < S(Result, Gamma_k))
				Result = b;

			Point c = new Point(Result.X, Result.Y + h);
			Point d = new Point(Result.X, Result.Y - h);
			if (S(c, Gamma_k) < S(Result, Gamma_k))
				Result = c;
			else if (S(d, Gamma_k) < S(Result, Gamma_k))
				Result = d;

			return Result;
		}



		private static double S(Point p, double Gamma_k)
		{
			double Result = y(p) + Gamma_k * H(p);
			return Result;
		}

		private static double dS_dx0(Point p, double Gamma_k)
		{
			double Result = dy_dx0(p) + Gamma_k * dH_dx0(p);
			return Result;
		}

		private static double dS_dx1(Point p, double Gamma_k)
		{
			double Result = dy_dx1(p) + Gamma_k * dH_dx1(p);
			return Result;
		}





		private static double g(Point p)
		{
			double Result = -p.X - p.Y + 5;
			return Result;
		}

		private static double dg_dx0(Point p)
		{
			double Result = -1.0;
			return Result;
		}

		private static double dg_dx1(Point p)
		{
			double Result = -1.0;
			return Result;
		}



		private static double j(Point p)
		{
			double Result = 4 * p.X - p.Y;
			return Result;
		}

		private static double dj_dx0(Point p)
		{
			double Result = 4.0;
			return Result;
		}

		private static double dj_dx1(Point p)
		{
			double Result = -1.0;
			return Result;
		}






		private static double H(Point p)
		{
			double r = 2.0;
			double Result = 0.0;
			double _g = g(p);
			double _j = j(p);
			Result += Math.Pow(Math.Max(_g, 0), r);
			Result += Math.Pow(Math.Max(_j, 0), r);
			//Result += Math.Pow(Math.Abs(_h), p);
			return Result;
		}

		private static double dH_dx0(Point p)
		{
			double Result = 0.0;
			if (g(p) > 0.0)
				Result += 2 * g(p) * dg_dx0(p);
			if (j(p) > 0.0)
				Result += 2 * j(p) * dj_dx0(p);
			/*if (h(x) < 0.0)
				Result += dh_dx0(x);
			else if (h(x) > 0.0)
				Result += -dh_dx0(x);*/
			return Result;
		}

		private static double dH_dx1(Point p)
		{
			double Result = 0.0;
			if (g(p) > 0.0)
				Result += 2 * g(p) * dg_dx1(p);
			if (j(p) > 0.0)
				Result += 2 * j(p) * dj_dx1(p);
			/*if (h(x) < 0.0)
				Result += dh_dx1(x);
			else if (h(x) > 0.0)
				Result += -dh_dx1(x);*/
			return Result;
		}





		private static double G(Point p)
		{
			double Result = 0.0;
			double _g = g(p);
			double _j = j(p);
			//double Result = Math.Max(Math.Max(_g, Math.Abs(_h)), 0);
			Result = Math.Max(_g, Result);
			//double Result = Math.Max(Math.Abs(_h), 0);
			Result = Math.Max(_j, Result);
			return Result;
			//return 0;
		}





		private static double y(Point p)
		{
			return (4 * p.X * p.X + 3 * p.Y * p.Y/* - 2 * p.X * p.Y*/);
		}

		private static double dy_dx0(Point p)
		{
			double Result = (8 * p.X - 2 * p.Y);
			return Result;
		}

		private static double dy_dx1(Point p)
		{
			double Result = (6 * p.Y - 2 * p.X);
			return Result;
		}




	}
}
