using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Spline_Interpolation
{
	class Polynom
	{
		public double A { get; set; }
		public double B { get; set; }
		public double C { get; set; }
		public double D { get; set; }
		public double Xi { get; set; }
		public double LeftLimit { get; set; }
		public double RightLimit { get; set; }
		public string Interval 
		{
			get 
			{
				return string.Format("({0};{1})", this.LeftLimit.ToString("F2"), this.RightLimit.ToString("F2"));
			}
		}

		public double S_2(double X)
		{ 
			return C + D*(X-Xi);
		}

		public Polynom() { }

		public double S(double X)
		{
			return A + B * (X - Xi) + C * (X - Xi) * (X - Xi) / 2
							+ D * (X - Xi) * (X - Xi) * (X - Xi) / 6;
		}
	}
}
