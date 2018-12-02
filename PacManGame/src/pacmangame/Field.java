package pacmangame;

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.Point;

/* Класс, представляющий одну клетку на игровом пространстве */
public class Field 
{
    private boolean isWall;
    private boolean hasCorn;
    
    //Ширина клетки (должна быть кратна возвращаемому значению методы GetStep() каждого персонажа)
    public final static int FIELD_WIDTH = 18;
    
    //Радиус зерна
    private final static int CORN_RADIUS = 1;
    
    //Стена
    private final static char IS_WALL = '0';
    //Стена
    private final static char HAS_CORN = '*';
    //Стена
    private final static char IS_EMPTY = ' ';
    
    public Field()
    {
        this.isWall = false;
        this.hasCorn = true;
    }
    
    public Field(boolean IsWall, boolean HasCorn)
    {
        this.isWall = IsWall;
        this.hasCorn = HasCorn;
    }
    
    public Field(char Type)
    {
        if (Type == Field.IS_WALL)
        {
            this.isWall = true;
            this.hasCorn = false;
        }
        else if (Type == Field.HAS_CORN)
        {
            this.isWall = false;
            this.hasCorn = true;
        } 
        else if (Type == Field.IS_EMPTY)
        {
            this.isWall = false;
            this.hasCorn = false;
        }
    }
    
    public boolean IsWall()
    {
        return this.isWall;
    }

    public boolean HasCorn()
    {
        //В стене не может быть зёрен
        if (this.isWall) return false;
        //Если это не стена:
        return this.hasCorn;
    }
    
    public void EatTheCorn()
    {
        this.hasCorn = false;
    }
    
    public void Paint(int X, int Y, Graphics2D graphics)
    {
        if (this.IsWall())
        {
            graphics.setColor(Color.blue);
            graphics.fillRect(X * Field.FIELD_WIDTH,
                              Y * Field.FIELD_WIDTH,
                              Field.FIELD_WIDTH,
                              Field.FIELD_WIDTH);
        }
        else if (this.HasCorn())
        {
            graphics.setColor(Color.orange);
            graphics.fillOval(X * Field.FIELD_WIDTH + Field.FIELD_WIDTH / 2 - Field.CORN_RADIUS,
                              Y * Field.FIELD_WIDTH + Field.FIELD_WIDTH / 2 - Field.CORN_RADIUS,
                              2 * Field.CORN_RADIUS,
                              2 * Field.CORN_RADIUS);
        }
    }
    
    public static Point GetFieldsIndexesOfCharacterLocation(Character character)
    {
        int X = character.Location.x / Field.FIELD_WIDTH;
        int Y = character.Location.y / Field.FIELD_WIDTH;
        return new Point(X, Y);
    }
    
    public static boolean IsCorrectLocationForField(Point Location)
    {
        return ((Location.x % FIELD_WIDTH == 0) || ((Location.y % FIELD_WIDTH == 0)));
    }
    
    public static boolean CanLookToThisField(PlayingWorld World, Point Location)
    {
        if (IsCorrectLocationForField(Location))
        {
            int X = Location.x / Field.FIELD_WIDTH;
            int Y = Location.y / Field.FIELD_WIDTH;
            if (!World.Fields[X][Y].IsWall())
            {
                return true;
            }
        }
        return false;
    }

}
