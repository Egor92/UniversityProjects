using System;
using EkoPort.Wpf.Mvvm;

namespace EkoPort.Wpf
{
    public class DataBase
    {
        public DataItemCollection<Contaminant> Contaminants { get; private set; }
        public DataItemCollection<TransshippingArea> TransshippingAreas { get; private set; }
        public DataItemCollection<ControlStation> ControlStations { get; private set; }
        public DataItemCollection<Port> Ports { get; private set; }
        public DataItemCollection<EnvironmentalEquipment> EnvironmentalEquipments { get; private set; }

        public bool HasChanges { get; set; }

        public DataBase()
        {
            Contaminants = new DataItemCollection<Contaminant>();
            TransshippingAreas = new DataItemCollection<TransshippingArea>();
            ControlStations = new DataItemCollection<ControlStation>();
            Ports = new DataItemCollection<Port>();
            EnvironmentalEquipments = new DataItemCollection<EnvironmentalEquipment>();

            TransshippingAreas.AddRelation(new ResetingRelation(Contaminants, x => ((Contaminant)x).TransshippingAreaId, x => ((Contaminant)x).TransshippingAreaId = 0));

            Contaminants.DataChanged += OnDataBaseChanged;
            TransshippingAreas.DataChanged += OnDataBaseChanged;
            ControlStations.DataChanged += OnDataBaseChanged;
            Ports.DataChanged += OnDataBaseChanged;
            EnvironmentalEquipments.DataChanged += OnDataBaseChanged;
        }

        private void OnDataBaseChanged(object sender, EventArgs e)
        {
            HasChanges = true;
        }

        public void Clear()
        {
            Contaminants.Clear();
            TransshippingAreas.Clear();
            ControlStations.Clear();
            Ports.Clear();
            EnvironmentalEquipments.Clear();
        }

        public void Merge(DataBase other)
        {
            foreach (var item in other.Contaminants)
                Contaminants.Add(item);
            foreach (var item in other.TransshippingAreas)
                TransshippingAreas.Add(item);
            foreach (var item in other.ControlStations)
                ControlStations.Add(item);
            foreach (var item in other.Ports)
                Ports.Add(item);
            foreach (var item in other.EnvironmentalEquipments)
                EnvironmentalEquipments.Add(item);
        }
    }
}
