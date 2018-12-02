package pacmangame;

import java.awt.*;
import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.Timer;
import java.util.TimerTask;
import javax.swing.JPanel;

/* Класс, представляющий игровой мир */
public class PlayingWorld extends JPanel 
{
    //Поля игрового мира
    public Field[][] Fields;
 
    //Список PacMan'ов
    public ArrayList PacMansList;
    
    //Список Фантомов
    public ArrayList PhantomsList;
    
    //Размеры игрового мира
    public static final int WORLD_WIDTH = 19 + 2;
    public static final int WORLD_HEIGHT = 25 + 2;

    //Размеры панели
    public static final int PANEL_WIDTH = Field.FIELD_WIDTH * WORLD_WIDTH + 6;
    public static final int PANEL_HEIGHT = Field.FIELD_WIDTH * WORLD_HEIGHT + 27;
    
    //Скорость игры
    public static final int GAME_FREQUENCY = 6;
    
    //Радиус взаимодействия персонажей
    public static final int INTERACTION_RADIUS = 2;
    
    public PlayingWorld()
    {
        this.setPreferredSize(new Dimension(PlayingWorld.PANEL_WIDTH, PlayingWorld.PANEL_HEIGHT));
        this.Fields = new Field[WORLD_WIDTH][WORLD_HEIGHT];
        this.setBackground(Color.black);
        this.PacMansList = new ArrayList();
        this.PhantomsList = new ArrayList();
    }
    
    public void AddPacMan(PacMan pacman)
    {
        pacman.World = this;
        this.PacMansList.add(pacman);
    }
    
    public void AddPhantom(Phantom phantom)
    {
        phantom.World = this;
        this.PhantomsList.add(phantom);
    }
    
    public void SetControlling(PacMan pacman)
    {
         this.addKeyListener(new KeyPressingListener(pacman));
    }

    public void RunGame()
    {
        Timer timer = new Timer();
        TimerTask task = new NextStepTask();
        timer.schedule(task, 0, PlayingWorld.GAME_FREQUENCY);
    }
    
    private class NextStepTask extends TimerTask 
    {
        @Override
        public void run() 
        {
            if (!IsGameOver())
            {
                //Определение нового местоположения персонажа
                for (Object pacman: PacMansList)
                {
                    ((PacMan) pacman).GoToNextStep();
                }

                //Определение нового местоположения персонажа
                for (Object phantom: PhantomsList)
                {
                    ((Phantom) phantom).GoToNextStep();
                    ToKillPacMansByPhantom((Phantom) phantom);
                }

                repaint();
            }
        }
    }
    
    @Override
    public void paintComponent(Graphics g)
    {
        super.paintComponent(g);
        
        //Отрисовать мир
        PaintTheWorld((Graphics2D) g);
            
        for (Object pacman: this.PacMansList)
        {
            ((PacMan) pacman).Paint((Graphics2D) g);
        }

        for (Object phantom: this.PhantomsList)
        {
            ((Phantom) phantom).Paint((Graphics2D) g);
        }
    }
    
    public void BuildTheWorld(String FileName)
    {
        //Создать мир
        BuildBorderOfTheWorld();
        this.BuildTheWorldFromFile(FileName);
        //Отрисовать мир
        this.repaint();
    }

    private void BuildBorderOfTheWorld()
    {
        for (int I=0; I<PlayingWorld.WORLD_WIDTH; I++)
        {
            if (I == 0 || I == PlayingWorld.WORLD_WIDTH - 1)
            {
                for (int J=0; J<PlayingWorld.WORLD_HEIGHT; J++)
                {
                    this.Fields[I][J] = new Field(true, false);
                }
            }
            else
            {
                this.Fields[I][0] = new Field(true, false);
                this.Fields[I][PlayingWorld.WORLD_HEIGHT - 1] = new Field(true, false);
            }
        }
    }
    
    private void BuildTheDefaultWorld()
    {
        for (int I=1; I<PlayingWorld.WORLD_WIDTH - 1; I++)
        {
            for (int J=1; J<PlayingWorld.WORLD_HEIGHT - 1; J++)
            {
                this.Fields[I][J] = new Field(false, true);
            }
        }
    }

    private void BuildTheWorldFromFile(String FileName)
    {
        try
        {
            FileInputStream inFile = new FileInputStream(".//maps//" + FileName + ".txt");
            byte[] str = new byte[inFile.available()];
            inFile.read(str);
            String[] WorldStructure = new String(str).split("\r\n");
            for (int I=0; I<(PlayingWorld.WORLD_WIDTH - 2); I++)
            {
                for (int J=0; J<(PlayingWorld.WORLD_HEIGHT - 2); J++)
                {
                    String _S = WorldStructure[J];
                    char _C = _S.charAt(I);
                    this.Fields[I+1][J+1] = new Field(_C);
                }
            }
            this.Fields[PacMan.DEFAULT_PACMAN_LOCATION.x][PacMan.DEFAULT_PACMAN_LOCATION.y] = new Field(false, false);
            this.Fields[Phantom.DEFAULT_PHANTOM_LOCATION.x][Phantom.DEFAULT_PHANTOM_LOCATION.y] = new Field(false, false);
        }
        catch (Exception ex) { }
    }

    private void PaintTheWorld(Graphics2D g)
    {
        for (int I=0; I<PlayingWorld.WORLD_WIDTH; I++)
        {
            for (int J=0; J<PlayingWorld.WORLD_HEIGHT; J++)
            {
                this.Fields[I][J].Paint(I, J, g);
            }
        }
    }
    
    public boolean ThereIsPacManOnThisLocation(Point Location)
    {
        for (Object pacman: this.PacMansList)
        {
            if (((PacMan) pacman).IsAlive)
            {
                if (((PacMan) pacman).Location.equals(Location))
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    private boolean IsGameOver()
    {
        if (this.AllPacmansAreDead() || this.AllCornsWereEaten())
        {
            return true;
        }
        return false;
    }

    private boolean AllPacmansAreDead()
    {
        for (Object pacman: this.PacMansList)
        {
            if (((PacMan) pacman).IsAlive)
            {
                return false;
            }
        }
        return true;
    }
    
    private boolean AllCornsWereEaten()
    {
        for (int I=1; I<(PlayingWorld.WORLD_WIDTH - 1); I++)
        {
            for (int J=1; J<(PlayingWorld.WORLD_HEIGHT - 1); J++)
            {
                if (this.Fields[I][J].HasCorn())
                {
                    return false;
                }
            }
        }
        return true;
    }
    
    private void ToKillPacMansByPhantom(Phantom phantom)
    {
        Point PhantomLocation = phantom.Location;
        for (Object pacman: this.PacMansList)
        {
            Point PacManLocation = ((PacMan) pacman).Location;
            double Epsilon = PhantomLocation.distanceSq(PacManLocation);
            if (Epsilon < INTERACTION_RADIUS)
            {
                ((PacMan) pacman).ToKill();
            }
        }
    }
}
