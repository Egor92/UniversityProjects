using System;

namespace ControlWorks.Variant1.ClassLibrary
{
    public interface InternalIterator
    {
        void Iterate(Action<int> action);
    }
}