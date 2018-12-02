using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace year2012var3
{
	class Program
	{
		static void Main(string[] args)
		{
			InputFileGenerator.GenerateFile(@"in.txt", 100, 1000, NumbersType.Double);

			List<double> points;
			using (StreamReader reader = new StreamReader(@"in.txt"))
				points = reader.ReadLine().Split(' ').Select(x => double.Parse(x)).OrderBy(x => x).ToList();

			double minDistance = double.MaxValue;
			for (int i = 1; i < points.Count; i++)
			{
				double distance = points[i] - points[i - 1];
				if (distance < minDistance)
					minDistance = distance;
			}
			Console.WriteLine(minDistance);
			Console.ReadKey();
		}
	}
}
