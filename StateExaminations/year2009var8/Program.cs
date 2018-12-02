using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace year2009var8
{
	class Program
	{
		static void Main(string[] args)
		{
			for (int i = 100; i < 999; i++)
			{
				if (i.ToString().ToCharArray().Distinct().Count() == 3)
					Console.WriteLine(i);
			}
			Console.ReadKey();
		}
	}
}
