using System;
using System.Collections.Generic;

namespace TemplatePrograming.Lab2.ClassLibrary
{
    public class SparseVector : IVector
    {
        private readonly IDictionary<int, double> _values = new Dictionary<int, double>();

        public int Dimension { get; private set; }

        public SparseVector(int dimension)
        {
            Dimension = dimension;
        }

        public double GetValue(int index)
        {
            if (index < 0 || index > Dimension - 1)
                throw new ArgumentOutOfRangeException("index");
            if (!_values.ContainsKey(index))
                return 0.0;
            return _values[index];
        }

        public void SetValue(int index, double value)
        {
            if (index < 0 || index > Dimension - 1)
                throw new ArgumentOutOfRangeException("index");
            if (!_values.ContainsKey(index) && value != 0.0)
                _values.Add(index, value);
            else if (value == 0.0)
                _values.Remove(index);
            else
                _values[index] = value;
        }
    }
}