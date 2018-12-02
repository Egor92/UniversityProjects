using System;

namespace TemplatePrograming.Lab5.Client
{
    internal static class RandomHelper
    {
        private readonly static Random Random = new Random(DateTime.Now.Millisecond);

        internal static int GetInteger(int min, int max)
        {
            return Random.Next(min, max + 1);
        }

        internal static double GetDouble(double min, double max)
        {
            return min + (max - min) * Random.NextDouble();
        }
    }
}