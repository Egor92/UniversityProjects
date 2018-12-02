using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace year2012var6
{
	class Program
	{
		private const string InputFile1 = @"in1.txt";

		private const string InputFile2 = @"in2.txt";

		private const string OutputFile = @"res.txt";

		static void Main(string[] args)
		{
			InputFileGenerator.GenerateFile(InputFile1, 1000, 1000, NumbersType.Integer);
			InputFileGenerator.GenerateFile(InputFile2, 555, 1000, NumbersType.Integer);

			StreamReader reader = new StreamReader(InputFile1);
			List<int> numbers1 = reader.ReadLine().Split(' ').Select(x => int.Parse(x)).ToList();
			reader = new StreamReader(InputFile2);
			List<int> numbers2 = reader.ReadLine().Split(' ').Select(x => int.Parse(x)).ToList();
			reader.Dispose();

			List<int> result = new List<int>();
			result.AddRange(numbers1);
			result.AddRange(numbers2);
			result = result.OrderBy(x => x).ToList();

			using (StreamWriter writer = new StreamWriter(OutputFile))
			{
				for (int i = 0; i < result.Count; i++)
					writer.WriteLine(result[i]);
			}
		}
	}
}
