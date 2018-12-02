package pacmangame;

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.Point;
import java.awt.geom.Point2D;

/* Абстрактный класс, представляющий движующиеся объекты (персонажи) */
public abstract class Character 
{
    //Уникальный номер персонажа
    public int ID;
    
    //Направление движения персонажа
    private Direction CurrentDirection;
    
    //Координаты персонажа
    public Point Location;
    
    //Цвет персонажа
    protected Color Color;
    
    //Цвет персонажа
    private int StepCounter = 0;
    
    //Игровой мир
    protected PlayingWorld World;
    
    protected Character() { }
    
    public abstract void Paint(Graphics2D g);
    
    public void SetCurrentDirection(Direction direction)
    {
        if (this.CurrentDirection != direction)
        {
            this.CurrentDirection = direction;
        }
    }
    
    public Direction GetCurrentDirection()
    {
        return this.CurrentDirection;
    }
    
    public boolean IsInTheField()
    {
        if (this.Location.x % Field.FIELD_WIDTH == 0 && this.Location.y % Field.FIELD_WIDTH == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    protected abstract int GetStepFrequency();
    
    protected abstract void UpdateDirection();
    
    private void UpdateLocation()
    {
        if (this.CurrentDirection == Direction.Left)
        {
            this.Location.x -= 1;
        }
        else if (this.CurrentDirection == Direction.Up)
        {
            this.Location.y -= 1;
        }
        else if (this.CurrentDirection == Direction.Right)
        {
            this.Location.x += 1;
        }
        else if (this.CurrentDirection == Direction.Down)
        {
            this.Location.y += 1;
        }
    }
    
    public void GoToNextStep()
    {
        this.StepCounter++;
        if (this.StepCounter % this.GetStepFrequency() == 0)
        {
            this.UpdateDirection();
            this.UpdateLocation();
        }
    }

    protected boolean IsTheWallOnThisDirection(Direction direction)
    {
        if (this.IsInTheField())
        {
            Point _fieldIndexes = Field.GetFieldsIndexesOfCharacterLocation(this);
            if (direction == Direction.Left)
            {
                if (this.World.Fields[_fieldIndexes.x - 1][_fieldIndexes.y].IsWall())
                {
                    return true;
                }
            }
            else if (direction == Direction.Up)
            {
                if (this.World.Fields[_fieldIndexes.x][_fieldIndexes.y - 1].IsWall())
                {
                    return true;
                }
            }
            else if (direction == Direction.Right)
            {
                if (this.World.Fields[_fieldIndexes.x + 1][_fieldIndexes.y].IsWall())
                {
                    return true;
                }
            }
            else if (direction == Direction.Down)
            {
                if (this.World.Fields[_fieldIndexes.x][_fieldIndexes.y + 1].IsWall())
                {
                    return true;
                }
            }
        }
        return false;
    }
}
