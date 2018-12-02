namespace ControlWorks.Variant1.ClassLibrary
{
    public class RangeDifference : RangeSumma
    {
        public RangeDifference(int count, IRange firstRange, IRange secondRange)
            : base(count, firstRange, new NegativeRange(secondRange))
        {
        }
    }
}
