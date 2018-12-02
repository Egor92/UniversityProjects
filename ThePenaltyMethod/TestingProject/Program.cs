using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TestingProject
{
	class Program
	{
		static void Main(string[] args)
		{
			double Sigma = 0.001;
			double Gamma_0 = 25;


			double e = 0.001;
			double[] x = new double[2];
			double[] x_last = new double[2];
			double _G;

			//y_k = y(x_k, N);

			int k = 0;

			for (; true ; k++)
			{
				x_last[0] = x[0] = 3.2;
				x_last[1] = x[1] = 2.8;

				double Gamma_k = Gamma_0 * k;
				while(true)
				{

					double _anti_dS_dx0 = -dS_dx0(x, Gamma_k);
					double _anti_dS_dx1 = -dS_dx1(x, Gamma_k);

					double t = Get_t(x, _anti_dS_dx0, _anti_dS_dx1, Gamma_k);

					x[0] += t * _anti_dS_dx0;
					x[1] += t * _anti_dS_dx1;

					double difference = Math.Abs( S(x, Gamma_k) - S(x_last, Gamma_k) );

					double _H = H(x);


					double grad_length = _anti_dS_dx0 * _anti_dS_dx0 + _anti_dS_dx1 * _anti_dS_dx1;

					if (difference < e) break;

					x_last[0] = x[0];
					x_last[1] = x[1];
				}

				_G = G(x);
				if (_G < Sigma) break;
			}

			Console.WriteLine("Minimum is in point x1 = {0}, x2 = {1}, iterations k = {2}", x[0], x[1], k+1);
			Console.WriteLine("\n");
	

			Console.ReadKey();
	   }

	

		private static double S(double[] x, double Gamma_k)
		{
			double Result = y(x) + Gamma_k * H(x);
			return Result;
		}

		private static double dS_dx0(double[] x, double Gamma_k)
		{
			double Result = dy_dx0(x) + Gamma_k * dH_dx0(x);
			return Result;
		}

		private static double dS_dx1(double[] x, double Gamma_k)
		{
			double Result = dy_dx1(x) + Gamma_k * dH_dx1(x);
			return Result;
		}





		private static double g(double[] x)
		{
			double Result = -x[0] - x[1] + 5;
			return Result;
		}

		private static double dg_dx0(double[] x)
		{
			double Result = -1.0;
			return Result;
		}

		private static double dg_dx1(double[] x)
		{
			double Result = -1.0;
			return Result;
		}



		private static double j(double[] x)
		{
			double Result = x[0] - 4*x[1];
			return Result;
		}

		private static double dj_dx0(double[] x)
		{
			double Result = 1.0;
			return Result;
		}

		private static double dj_dx1(double[] x)
		{
			double Result = -4.0;
			return Result;
		}




		private static double h(double[] x)
		{
			double Result = x[0];
			return Result;
		}

		private static double dh_dx0(double[] x)
		{
			double Result = 1.0;
			return Result;
		}

		private static double dh_dx1(double[] x)
		{
			double Result = 0.0;
			return Result;
		}





		private static double H(double[] x)
		{
			double p = 2.0;
			double Result = 0.0;
			double _g = g(x);
			double _h = h(x);
			double _j = j(x);
			Result += Math.Pow(Math.Max(_g, 0), p);
			//Result += Math.Pow(Math.Max(_j, 0), p);
			//Result += Math.Pow(Math.Abs(_h), p);
			return Result;
		}

		private static double dH_dx0(double[] x)
		{
			double Result = 0.0;
			if (g(x) > 0.0)
				Result += 2 * g(x) * dg_dx0(x);
			/*if (j(x) > 0.0)
				Result += 2 * j(x) * dj_dx0(x);*/
			/*if (h(x) < 0.0)
				Result += dh_dx0(x);
			else if (h(x) > 0.0)
				Result += -dh_dx0(x);*/
			return Result;
		}

		private static double dH_dx1(double[] x)
		{
			double Result = 0.0;
			if (g(x) > 0.0)
				Result += 2 * g(x) * dg_dx1(x);
			/*if (j(x) > 0.0)
				Result += 2 * j(x) * dj_dx1(x);*/
			/*if (h(x) < 0.0)
				Result += dh_dx1(x);
			else if (h(x) > 0.0)
				Result += -dh_dx1(x);*/
			return Result;
		}





		private static double G(double[] x)
		{
			double _g = g(x);
			double _h = h(x);
			double _j = j(x);
			//double Result = Math.Max(Math.Max(_g, Math.Abs(_h)), 0);
			double Result = Math.Max(_g, 0);
			//double Result = Math.Max(Math.Abs(_h), 0);
			//double Result = Math.Max(Math.Max(_g, _j), 0);
			return Result;
			//return 0;
		}





		private static double y(double[] x)
		{
			return (4*x[0]*x[0] + 3*x[1]*x[1] - 2*x[0]*x[1]);
		}

		private static double dy_dx0(double[] x)
		{
			double Result = (8 * x[0] - 2 * x[1]);
			return Result;
		}

		private static double dy_dx1(double[] x)
		{
			double Result = (6 * x[1] - 2 * x[0]);
			return Result;
		}



		private static bool checkSecondCriteria(double[] x, double d0, double d1, double Gamma_k, double t)
		{
			const double MU = 0.1;
			double fiVal_0 = S(x, Gamma_k);
			double[] u = new double[2] { x[0] + t * d0, x[1] + t * d1 };
			double fiVal_1 = S(u, Gamma_k);
			return (DoubleEquals(fiVal_0, fiVal_1)) ||
				fiVal_1 <= fiVal_0 + t * MU * (dS_dx0(x, Gamma_k) * d0 + dS_dx1(x, Gamma_k) * d1);
		}

		public static bool DoubleEquals(double d1, double d2)
		{
			return Math.Abs(d1 - d2) < 1E-5;
		}

		public static double Get_t(double[] x, double d0, double d1, double Gamma_k)
		{
			const double NU = 0.5;
			double Result = 1.0;

			while (!checkSecondCriteria(x, d0, d1, Gamma_k, Result))
				Result *= NU;

			return Result;
		}


	}
}
