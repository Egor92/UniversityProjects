using System;

namespace ControlWorks.Variant1.ClassLibrary
{
    public abstract class Range : IRange
    {
        public int Count { get; private set; }

        protected Range(int count)
        {
            Count = count;
        }

        public abstract int GetFirst();

        public abstract int GetSecond();

        public abstract int GetNext(int current, int last);

        public void Iterate(Action<int> action)
        {
            if (Count < 1)
                return;
            var first = GetFirst();
            action(first);
            if (Count == 1)
                return;
            var second = GetSecond();
            action(second);
            int current = second;
            int last = first;
            for (int i = 2; i < Count; i++)
            {
                var next = GetNext(current, last);
                last = current;
                current = next;
                action(current);
            }
        }
    }
}
