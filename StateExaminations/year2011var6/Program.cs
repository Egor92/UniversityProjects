using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace year2011var6
{
	class Program
	{
		private const string InputFile = @"in.txt";

		private const string OutputFile = @"out.txt";

		static void Main(string[] args)
		{
			List<string> lines = new List<string>();

			using (StreamReader reader = new StreamReader(InputFile))
			{
				while (!reader.EndOfStream)
					lines.Add(reader.ReadLine());
			}

			using (StreamWriter writer = new StreamWriter(OutputFile))
				for (int i = lines.Count - 1; i >= 0; i--)
					writer.WriteLine(lines[i]);
		}
	}
}
