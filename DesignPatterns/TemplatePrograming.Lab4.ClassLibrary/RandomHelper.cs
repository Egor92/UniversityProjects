using System;
using System.Windows.Media;

namespace TemplatePrograming.Lab4.Client
{
    public static class RandomHelper
    {
        private static Random _random;

        private static Random Random
        {
            get { return _random ?? (_random = new Random(DateTime.Now.Millisecond)); }
        }

        public static bool GetBool()
        {
            return Random.NextDouble() > 0.5;
        }

        public static int GetInt(int min, int max)
        {
            return Random.Next(min, max + 1);
        }

        public static double GetDouble(double min, double max)
        {
            return min + (max - min)*Random.NextDouble();
        }

        public static byte GetByte()
        {
            return (byte)Random.Next(0, 256);
        }

        public static SolidColorBrush GetSolidColorBrush()
        {
            var r = GetByte();
            var g = GetByte();
            var b = GetByte();
            var color = Color.FromRgb(r, g, b);
            return new SolidColorBrush(color);
        }
    }
}
