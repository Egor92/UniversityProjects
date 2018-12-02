package pacmangame;


import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

/* Обработчик события нажатия кнопки */
public class KeyPressingListener extends KeyAdapter
{
    //Пак-Мэн, находящийся под управлением данного игрока
    private PacMan PacMan;
    
    public KeyPressingListener(PacMan pacman) 
    {
        super();
        this.PacMan = pacman;
    }

    @Override
    public void keyPressed(KeyEvent e) 
    {
        switch (e.getKeyCode())
        {
            case KeyEvent.VK_LEFT:
                this.PacMan.WantedDirection = Direction.Left;
                break;
            case KeyEvent.VK_UP:
                this.PacMan.WantedDirection = Direction.Up;
                break;
            case KeyEvent.VK_RIGHT:
                this.PacMan.WantedDirection = Direction.Right;
                break;
            case KeyEvent.VK_DOWN:
                this.PacMan.WantedDirection = Direction.Down;
                break;
        }
    }
    
}
