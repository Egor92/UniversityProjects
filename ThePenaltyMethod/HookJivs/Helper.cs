using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;

namespace HookJivs
{
	public static class Helper
	{
		public static Point Mult(this Point p, double d)
		{
			return new Point(p.X * d, p.Y * d);
		}

		public static Point Add(this Point p, Point q)
		{
			return new Point(p.X * q.X, p.Y * q.Y);
		}
	}
}
