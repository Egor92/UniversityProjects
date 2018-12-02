package pacmangame;

import java.awt.Dimension;
import javax.swing.JFrame;

/* Фрэйм с игрой */
public class GameFrame extends JFrame
{
    public GameFrame(PlayingWorld World)
    {
        super("Pac-Man Game");
        this.setLocationByPlatform(true);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setPreferredSize(new Dimension(PlayingWorld.PANEL_WIDTH, PlayingWorld.PANEL_HEIGHT));
        this.add(World);
        this.pack();
        this.setVisible(true);
        this.setResizable(false);
    }
}
