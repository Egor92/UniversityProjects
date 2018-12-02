package pacmangame;

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.Point;

/* Класс Pac-Man */
public class PacMan extends Character
{
    //Начальное положение Pac-Man'а в игре
    public static final Point DEFAULT_PACMAN_LOCATION = new Point(10 * Field.FIELD_WIDTH, 20 * Field.FIELD_WIDTH);
    
    //Желаемое направление движения
    public Direction WantedDirection = Direction.None;
    
    //Жив ли Pacman
    public boolean IsAlive = true;
    
    //Набранное оличество очков
    public int Points = 0;
    
    public PacMan() 
    {
        super();
        this.ID = 1;
        this.SetCurrentDirection(Direction.None);
        this.Location = new Point(DEFAULT_PACMAN_LOCATION);
        this.Color = Color.yellow;
    }
    
    public PacMan(int ID, Color PacManColor) 
    {
        super();
        this.ID = ID;
        this.SetCurrentDirection(Direction.None);
        this.Location = new Point(DEFAULT_PACMAN_LOCATION);
        this.Color = PacManColor;
    }
    
    @Override
    public void Paint(Graphics2D g)
    {
        if (this.IsAlive)
        {
            g.setColor(this.Color);
            g.fillOval(this.Location.x, this.Location.y, Field.FIELD_WIDTH, Field.FIELD_WIDTH);
        }
    }

    @Override
    protected int GetStepFrequency() 
    {
        return 2;
    }
 
    @Override
    public void GoToNextStep()
    {
        if (this.IsAlive)
        {
            super.GoToNextStep();
        }
    }

    @Override
    public void UpdateDirection() {
        if (this.IsInTheField())
        {
            //Направление движения можно менять только дойдя следующего до поля...
            Point _fieldIndexes = Field.GetFieldsIndexesOfCharacterLocation(this);
            Field _field = this.World.Fields[_fieldIndexes.x][_fieldIndexes.y];
            if (_field.HasCorn())
            {
                _field.EatTheCorn();
                this.Points++;
            }
            
            if (this.WantedDirection == this.GetCurrentDirection() && this.IsTheWallOnThisDirection(this.GetCurrentDirection()))
            {
                this.SetCurrentDirection(Direction.None);
            }
            else if (!this.IsTheWallOnThisDirection(this.WantedDirection))
            {
                this.SetCurrentDirection(this.WantedDirection);
            }
            else if (this.IsTheWallOnThisDirection(this.GetCurrentDirection()))
            {
                this.SetCurrentDirection(Direction.None);
            }
        }
        else
        {
            //...направление движения на противоположное можно менять в любое время
            if (this.GetCurrentDirection() == Direction.Left && this.WantedDirection == Direction.Right)
            {
                this.SetCurrentDirection(Direction.Right);
            }
            else if (this.GetCurrentDirection() == Direction.Up && this.WantedDirection == Direction.Down)
            {
                this.SetCurrentDirection(Direction.Down);
            }
            else if (this.GetCurrentDirection() == Direction.Right && this.WantedDirection == Direction.Left)
            {
                this.SetCurrentDirection(Direction.Left);
            }
            else if (this.GetCurrentDirection() == Direction.Down && this.WantedDirection == Direction.Up)
            {
                this.SetCurrentDirection(Direction.Up);
            }
        }
    }
    
    public void ToKill()
    {
        this.IsAlive = false;
    }
    
}
