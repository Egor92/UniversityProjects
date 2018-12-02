using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace year2011var1
{
	class Program
	{
		static void Main(string[] args)
		{
			int inputedNumber = int.Parse(Console.ReadLine());

			if (inputedNumber % 2 != 0)
			{
				Console.WriteLine("Inputed number {0} isn't even!", inputedNumber);
				Console.ReadLine();
				return;
			}

			List<int> simpleNumbers = GetSimpleNumbersFor(inputedNumber);

			using (StreamWriter writer = new StreamWriter(@"out.txt"))
			{
				for (int i = 0; i < simpleNumbers.Count; i++ )
					for (int j = i; j < simpleNumbers.Count; j++)
						if (simpleNumbers[i] + simpleNumbers[j] == inputedNumber)
							writer.WriteLine("{0}+{1}={2}", simpleNumbers[i], simpleNumbers[j], inputedNumber);
			}
		}

		static List<int> GetSimpleNumbersFor(int hiNumber)
		{
			List<int> result = new List<int>();
			for (int number = 3; number < hiNumber; number += 2)
			{
				if (result.All(simpleNumber => number % simpleNumber != 0))
					result.Add(number);
			}
			return result;
		}
	}
}
