using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace year2012var2
{
	class Program
	{
		private const string InputFile1 = @"in1.txt";

		private const string InputFile2 = @"in2.txt";

		static void Main(string[] args)
		{
			InputFileGenerator.GenerateFile(InputFile1, 2, 2, NumbersType.Integer);
			InputFileGenerator.GenerateFile(InputFile2, 2, 2, NumbersType.Integer);

			StreamReader reader = new StreamReader(InputFile1);
			List<int> numbers1 = reader.ReadLine().Split(' ').Select(x => int.Parse(x)).OrderBy(x => x).Distinct().ToList();
			reader = new StreamReader(InputFile2);
			List<int> numbers2 = reader.ReadLine().Split(' ').Select(x => int.Parse(x)).OrderBy(x => x).Distinct().ToList();
			reader.Dispose();

			List<int> difference = new List<int>();
			difference.AddRange(numbers1.Except(numbers2));
			difference.AddRange(numbers2.Except(numbers1));

			Console.WriteLine(!difference.Any());

			Console.ReadKey();
		}
	}
}
