using System.Collections.Generic;

namespace TemplatePrograming.Lab5.ClassLibrary
{
    public class CommandManager
    {
        private static CommandManager _instance;
        private readonly IList<ICommand> _commands = new List<ICommand>();

        private static CommandManager Instance
        {
            get { return _instance ?? (_instance = new CommandManager()); }
        }

        public static bool CanUndo
        {
            get { return Instance._commands.Count > 1; }
        }

        internal static void Register(ICommand command)
        {
            Instance._commands.Add(command);
        }

        public static void Undo()
        {
            if (!CanUndo)
                return;
            Instance._commands.RemoveAt(Instance._commands.Count - 1);
            foreach (var command in Instance._commands)
                command.Execute();
        }
    }
}
