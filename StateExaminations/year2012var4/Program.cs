using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace year2012var5
{
	class Program
	{
		static void Main(string[] args)
		{
			InputFileGenerator.GenerateFile(@"in.txt", 1000, 10, NumbersType.String);

			List<string> words = new List<string>();

			using (StreamReader reader = new StreamReader(@"in.txt"))
				words = reader.ReadLine().Split(' ').Where(x => !string.IsNullOrWhiteSpace(x)).ToList();

			Console.WriteLine("Input string width");
			int stringWidth = int.Parse(Console.ReadLine());
			int currentStringWidth = 0;

			for (int i = 0; i < words.Count; i++)
			{
				if (currentStringWidth + words[i].Length > stringWidth)
				{
					Console.WriteLine();
					currentStringWidth = 0;
				}
				Console.Write("{0} ", words[i]);
				currentStringWidth += words[i].Length;
			}

			Console.ReadKey();
		}
	}
}
