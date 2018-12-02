namespace TemplatePrograming.Lab5.ClassLibrary
{
    public abstract class Command : ICommand
    {
        protected Command()
        {
            CommandManager.Register(this);
        }

        public abstract void Execute();
    }
}
