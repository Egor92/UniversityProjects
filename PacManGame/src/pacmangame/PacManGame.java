package pacmangame;

import java.awt.Color;
import javax.swing.JFrame;
import javax.swing.RepaintManager;
import javax.swing.SwingUtilities;

public class PacManGame 
{
    //Форма с игрой
    private static JFrame GamesFrame;
    private static PlayingWorld World;
    
    public static void main(String[] args) 
    {
        SwingUtilities.invokeLater(new Runnable() 
        {

            @Override
            public void run() {
                CreateGamesFrame();

                CreatePacMan();

                for (int I=0; I<10; I++)
                {
                    CreatePhantom();
                }
                
                World.RunGame();
            }
        });
    }
    
    private static void CreateGamesFrame()
    {
        World = new PlayingWorld();
        GamesFrame = new GameFrame(World);
        GamesFrame.show();
        World.setFocusable(true);
        World.BuildTheWorld("MapEditor");
        RepaintManager.currentManager(World).setDoubleBufferingEnabled(true);
    }
    
    private static void CreatePacMan()
    {
        PacMan _pacman = new PacMan(1, Color.yellow);
        World.AddPacMan(_pacman);
        World.SetControlling(_pacman);
        World.AddPacMan(new PacMan(2, Color.red));
    }

    private static void CreatePhantom()
    {
        Phantom _phantom = new Phantom();
        World.AddPhantom(_phantom);
    }
}
