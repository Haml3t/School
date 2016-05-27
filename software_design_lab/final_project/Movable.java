/**
 * Created by nooreddin on 3/29/16.
 */
public interface Movable extends MoveState
{
    void move();
    void try_move(int x, int y);
}
