using System;
using ControlWorks.Variant1.ClassLibrary;

namespace ControlWorks.Variant1.Client
{
    class Program
    {
        static void Main(string[] args)
        {
            Taks1();
            Task2();
            Task3();

            Console.Read();
        }

        private static void Taks1()
        {
            Console.WriteLine("Taks1:");
            IRange fibonacci = new FibonacciRange(10);
            Console.Write("Fibonacci:");
            fibonacci.Iterate(x => Console.Write("  {0}", x));
            Console.WriteLine();

            IRange euler = new EulerRange(10);
            Console.Write("Euler:");
            euler.Iterate(x => Console.Write("  {0}", x));
            Console.WriteLine();
        }

        private static void Task2()
        {
            Console.WriteLine("Taks2:");
            IRange fibonacci = new FibonacciRange(10);
            IRange negativeFibonacciRange = new NegativeRange(fibonacci);
            Console.Write("Negative Fibonacci:");
            negativeFibonacciRange.Iterate(x => Console.Write("  {0}", x));
            Console.WriteLine();
            IRange euler = new EulerRange(10);
            IRange negativeEulerRange = new NegativeRange(euler);
            Console.Write("Negative Euler:");
            negativeEulerRange.Iterate(x => Console.Write("  {0}", x));
            Console.WriteLine();
        }

        private static void Task3()
        {
            Console.WriteLine("Taks3:");
            IRange fibonacci = new FibonacciRange(10);
            IRange euler = new EulerRange(10);
            IRange rangeSumma = new RangeSumma(10, fibonacci, euler);
            Console.Write("Fibonacci + Euler:");
            rangeSumma.Iterate(x => Console.Write("  {0}", x));
            Console.WriteLine();
            IRange rangeDifference = new RangeDifference(10, fibonacci, euler);
            Console.Write("Fibonacci - Euler:");
            rangeDifference.Iterate(x => Console.Write("  {0}", x));
            Console.WriteLine();
        }
    }
}
