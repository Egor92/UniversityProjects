namespace ControlWorks.Variant1.ClassLibrary
{
    public interface IRange : InternalIterator
    {
        int GetFirst();
        int GetSecond();
        int GetNext(int current, int last);
    }
}
