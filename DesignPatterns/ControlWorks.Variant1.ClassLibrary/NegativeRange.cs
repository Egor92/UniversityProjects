using System;

namespace ControlWorks.Variant1.ClassLibrary
{
    public class NegativeRange : IRange
    {
        private readonly IRange _sourceRange;

        public NegativeRange(IRange sourceRange)
        {
            _sourceRange = sourceRange;
        }

        public int GetFirst()
        {
            return -_sourceRange.GetFirst();
        }

        public int GetSecond()
        {
            return -_sourceRange.GetSecond();
        }

        public int GetNext(int current, int last)
        {
            return -_sourceRange.GetNext(-current, -last);
        }

        public void Iterate(Action<int> action)
        {
            _sourceRange.Iterate(x => action(-x));
        }
    }
}