using System;
using System.Collections;

namespace EkoPort.Wpf.Mvvm
{
    public abstract class Relation
    {
        private readonly Func<DataItem, int> _getRelatedId;

        internal IList Collection { get; private set; }

        protected Relation(IList collection, Func<DataItem, int> getRelatedId)
        {
            Collection = collection;
            _getRelatedId = getRelatedId;
        }

        internal int GetRelatedId(DataItem dataItem)
        {
            return _getRelatedId(dataItem);
        }

        public abstract void Action(DataItem dataItem);
    }

    public class DeletingRelation : Relation
    {
        public DeletingRelation(IList collection, Func<DataItem, int> getRelatedId) 
            : base(collection, getRelatedId)
        {
        }

        public override void Action(DataItem dataItem)
        {
            Collection.Remove(dataItem);
        }
    }

    public class ResetingRelation : Relation
    {
        private readonly Action<DataItem> _resetRelatedId;

        public ResetingRelation(IList collection, Func<DataItem, int> getRelatedId, Action<DataItem> resetRelatedId) 
            : base(collection, getRelatedId)
        {
            _resetRelatedId = resetRelatedId;
        }

        public override void Action(DataItem dataItem)
        {
            _resetRelatedId(dataItem);
        }
    }
}
