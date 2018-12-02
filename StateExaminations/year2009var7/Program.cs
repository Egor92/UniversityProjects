using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace year2009var7
{
	class Program
	{
		static void Main(string[] args)
		{
			string str1 = Console.ReadLine();
			string str2 = Console.ReadLine();
			List<char> chars = new List<char>();
			chars.AddRange(str1.ToCharArray());
			chars.AddRange(str2.ToCharArray());
			Console.WriteLine(chars.Distinct().OrderBy(x => x).ToArray());
			Console.ReadLine();
		}
	}
}
