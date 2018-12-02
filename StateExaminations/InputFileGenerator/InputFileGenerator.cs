using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

public enum NumbersType
{
	Integer, Double, String
}

public static class InputFileGenerator
{
	public static void GenerateFile(string inputFileName, int numbersCount, int maxValue, NumbersType numbersType)
	{
		using (StreamWriter writer = new StreamWriter(inputFileName))
		{
			Random random = new Random(DateTime.Now.Millisecond);
			for (int i = 0; i < numbersCount; i++)
			{
				switch (numbersType)
				{
					case NumbersType.Integer:
						writer.Write(random.Next(maxValue));
						if (i < numbersCount - 1)
							writer.Write(' ');
						break;
					case NumbersType.Double:
						writer.Write(random.NextDouble() * maxValue);
						if (i < numbersCount - 1)
							writer.Write(' ');
						break;
					case NumbersType.String:
						bool isSpace = (random.Next(maxValue) == 0);
						if (isSpace)
							writer.Write(' ');
						else
						{
							int letter = random.Next(65, 80);
							writer.Write(Char.ConvertFromUtf32(letter));
						}
						break;
					default:
						throw new NotImplementedException();
				}
			}
		}
	}
}
