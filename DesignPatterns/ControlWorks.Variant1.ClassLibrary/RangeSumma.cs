using System;
using System.Collections.Generic;
using System.Linq;

namespace ControlWorks.Variant1.ClassLibrary
{
    public class RangeSumma : IRange
    {
        private readonly IRange[] _ranges;
        public int Count { get; private set; }

        public RangeSumma(int count, params IRange[] ranges)
        {
            _ranges = ranges;
            Count = count;
        }

        public int GetFirst()
        {
            return _ranges.Sum(x => x.GetFirst());
        }

        public int GetSecond()
        {
            return _ranges.Sum(x => x.GetSecond());
        }

        public int GetNext(int current, int last)
        {
            return current + last;
        }

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
            int[] current = _ranges.Select(x => x.GetSecond()).ToArray();
            int[] last = _ranges.Select(x => x.GetFirst()).ToArray();
            int[] next = new int[_ranges.Count()];
            for (int i = 2; i < Count; i++)
            {
                for (int j = 0; j < _ranges.Length; j++)
                {
                    var range = _ranges.ElementAt(j);
                    next[j] = range.GetNext(current[j], last[j]);
                    last[j] = current[j];
                    current[j] = next[j];
                }

                var sum = current.Sum();
                action(sum);
            }
        }
    }
}