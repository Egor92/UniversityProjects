package pacmangame;

import java.awt.Graphics2D;
import java.awt.Point;
import java.util.Random;

/* Класс Фантома */
public class Phantom extends Character
{
    //Начальное положение Фантома в игре
    public static final Point DEFAULT_PHANTOM_LOCATION = new Point(10 * Field.FIELD_WIDTH, 10 * Field.FIELD_WIDTH);
    
    //Генератор псевдослучайного направления движения фантома
    private static Random RND = new Random();
    
    //Вероятность поворота Фантома налево
    private static int CHANCE_TO_GO_LEFT = 25;
    
    //Вероятность поворота Фантома направо при условии, что он не повернул налево
    private static int CHANCE_TO_GO_RIGHT = 33;
    
    public Phantom()
    {
        super();
        this.ID = 0;
        this.SetCurrentDirection(Direction.None);
        this.Location = new Point(DEFAULT_PHANTOM_LOCATION);
        this.Color = Color.white;
    }
    
    @Override
    public void Paint(Graphics2D g)
    {
        g.setColor(this.Color);
        g.fillOval(this.Location.x, this.Location.y, Field.FIELD_WIDTH, Field.FIELD_WIDTH);
    }

    @Override
    protected int GetStepFrequency() 
    {
        return 3;
    }

    @Override
    public void UpdateDirection() 
    {
        Direction DirectionToNearestPacMan = GetDirectionToNearestPacMan();
        if (DirectionToNearestPacMan != null)
        {
            this.SetCurrentDirection(DirectionToNearestPacMan);
        }
        else
        {
            if (this.IsInTheField())
            {
                if (this.GetCurrentDirection() == Direction.None)
                {
                    this.SetCurrentDirection(this.GenerateDirection());
                    if (this.IsTheWallOnThisDirection(this.GetCurrentDirection()))
                    {
                        Direction _direction;
                        while (this.IsTheWallOnThisDirection(_direction = this.GenerateDirection()));
                        this.SetCurrentDirection(_direction);
                    }
                }
                    
                //Хотим ли повернуть налево?
                if (!this.IsTheWallOnThisDirection(Direction.GetLeft(this.GetCurrentDirection()))
                        && this.WantToRotate(CHANCE_TO_GO_LEFT))
                {
                    this.SetCurrentDirection(Direction.GetLeft(this.GetCurrentDirection()));
                }
                //Хотим ли повернуть направо?
                else if (!this.IsTheWallOnThisDirection(Direction.GetRight(this.GetCurrentDirection()))
                        && WantToRotate(CHANCE_TO_GO_RIGHT))
                {
                    this.SetCurrentDirection(Direction.GetRight(this.GetCurrentDirection()));
                }
                else
                {
                    //Если тупик
                    if (this.IsTheWallOnThisDirection(Direction.GetLeft(this.GetCurrentDirection()))
                        && this.IsTheWallOnThisDirection(Direction.GetRight(this.GetCurrentDirection()))
                        && this.IsTheWallOnThisDirection(this.GetCurrentDirection())
                        && !this.IsTheWallOnThisDirection(Direction.GetBackSide(this.GetCurrentDirection())))
                    {
                        this.SetCurrentDirection(Direction.GetBackSide(this.GetCurrentDirection()));
                    }
                    //Если впереди стена, но не тупик
                    else if (this.IsTheWallOnThisDirection(this.GetCurrentDirection()))
                    {
                        Direction _direction;
                        while (this.IsTheWallOnThisDirection(_direction = this.GenerateDirection()));
                        this.SetCurrentDirection(_direction);
                    }
                }
            }
        }
    }

    private Direction GetDirectionToNearestPacMan()
    {
        //Расстояния до ближайших пакменов слева, сверху, справа, снизу соответственно
        int Distances[] = new int[4];
        for (int I=0; I<4; I++)
        {
            Distances[I] = Integer.MAX_VALUE;
        }
        
        //Смотрим пакменов слева
        for (int I = this.Location.x; I>0; I--)
        {
            Point WatchingLocation = new Point(I, this.Location.y);
            if (Field.CanLookToThisField(this.World, WatchingLocation))
            {
                if (this.World.ThereIsPacManOnThisLocation(WatchingLocation))
                {
                    Distances[0] = this.Location.x - I;
                    break;
                }
            }
            else break;
        }
        //Смотрим пакменов сверху
        for (int I = this.Location.y; I>0; I--)
        {
            Point WatchingLocation = new Point(this.Location.x, I);
            if (Field.CanLookToThisField(this.World, WatchingLocation))
            {
                if (this.World.ThereIsPacManOnThisLocation(WatchingLocation))
                {
                    Distances[1] = this.Location.y - I;
                    break;
                }
            }
            else break;
        }
        //Смотрим пакменов справа
        for (int I = this.Location.x; I<(PlayingWorld.WORLD_WIDTH * Field.FIELD_WIDTH); I++)
        {
            Point WatchingLocation = new Point(I, this.Location.y);
            if (Field.CanLookToThisField(this.World, WatchingLocation))
            {
                if (this.World.ThereIsPacManOnThisLocation(WatchingLocation))
                {
                    Distances[2] = I - this.Location.x;
                    break;
                }
            }
            else break;
        }
        //Смотрим пакменов снизу
        for (int I = this.Location.y; I<(PlayingWorld.WORLD_HEIGHT * Field.FIELD_WIDTH); I++)
        {
            Point WatchingLocation = new Point(this.Location.x, I);
            if (Field.CanLookToThisField(this.World, WatchingLocation))
            {
                if (this.World.ThereIsPacManOnThisLocation(WatchingLocation))
                {
                    Distances[3] = I - this.Location.y;
                    break;
                }
            }
            else break;
        }
        
        int MinDistance = Distances[0];
        for (int I=1; I<4; I++)
        {
            if (MinDistance > Distances[I] && Distances[I] != Integer.MAX_VALUE)
            {
                MinDistance = Distances[I];
            }
        }
        
        if (MinDistance != Integer.MAX_VALUE)
        {
            if (MinDistance == Distances[0])
            {
                return Direction.Left;
            }
            else if (MinDistance == Distances[1])
            {
                return Direction.Up;
            }
            else if (MinDistance == Distances[2])
            {
                return Direction.Right;
            }
            else if (MinDistance == Distances[3])
            {
                return Direction.Down;
            }
        }
        return null;
    }
    
    private Direction GenerateDirection()
    {
        Direction Result = Direction.GetBackSide(this.GetCurrentDirection());
        while (Result == Direction.GetBackSide(this.GetCurrentDirection()))
        {
            int A = this.RND.nextInt(4);
            switch (A)
            {
                case 0:
                    Result = Direction.Left;
                    break;
                case 1:
                    Result = Direction.Up;
                    break;
                case 2:
                    Result = Direction.Right;
                     break;
               case 3:
                    Result = Direction.Down;
                     break;
               default:
                    Result = Direction.None;
                    break;
            }
        }
        return Result;
    }
    
    private boolean WantToRotate(int Chance)
    {
        int A = this.RND.nextInt(100);
        if (A < Chance)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
