namespace ControlWorks.Variant1.ClassLibrary
{
    public class EulerRange : Range
    {
        public EulerRange(int count) 
            : base(count)
        {
        }

        public override int GetFirst()
        {
            return 1;
        }

        public override int GetSecond()
        {
            return 1;
        }

        public override int GetNext(int current, int last)
        {
            return current + last + 1;
        }
    }
}