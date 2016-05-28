/**
 * Created by nooreddin on 3/29/16.
 */

//package finalproject;

public interface Movable extends MoveState
{
    void move();
    void try_move(int x, int y);
    boolean attack(Agent foe);
    void reproduce(Agent mate);
    void eat(Agent prey);
    boolean isMale();
}
