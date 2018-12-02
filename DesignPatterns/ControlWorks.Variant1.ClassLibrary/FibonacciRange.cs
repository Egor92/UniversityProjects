namespace ControlWorks.Variant1.ClassLibrary
{
    public class FibonacciRange : Range
    {
        public FibonacciRange(int count)
            : base(count)
        {
        }

        public override int GetFirst()
        {
            return 0;
        }

        public override int GetSecond()
        {
            return 1;
        }

        public override int GetNext(int current, int last)
        {
            return current + last;
        }
    }
}