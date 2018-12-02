using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;

namespace year2012var1
{
	class Program
	{
		static void Main(string[] args)
		{
			InputFileGenerator.GenerateFile("in.txt", 555, 1000, NumbersType.Integer);

			List<int> numbers;
			using (var reader = new StreamReader("in.txt"))
				numbers = reader.ReadLine().Split(' ').Where(x => x != string.Empty).Select(int.Parse).OrderBy(x => x).Distinct().ToList();

			foreach (int number in numbers)
				Console.WriteLine(number);

			Console.ReadKey();
		}
	}
}
