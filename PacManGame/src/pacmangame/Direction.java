package pacmangame;

/* Перечисление возможных направлений движения персонажа */
public enum Direction 
{
    None, Left, Up, Right, Down;
    
    public static Direction GetLeft(Direction direction)
    {
        switch (direction)
        {
            case Left:
                return Down;
            case Up:
                return Left;
            case Right:
                return Up;
            case Down:
                return Right;
            default:
                return None;
        }
    }

    public static Direction GetRight(Direction direction)
    {
        switch (direction)
        {
            case Left:
                return Up;
            case Up:
                return Right;
            case Right:
                return Down;
            case Down:
                return Left;
            default:
                return None;
        }
    }

    public static Direction GetBackSide(Direction direction)
    {
        switch (direction)
        {
            case Left:
                return Right;
            case Up:
                return Down;
            case Right:
                return Left;
            case Down:
                return Up;
            default:
                return None;
        }
    }
}
