/**
 *
 * @author Nooreddin Naghibolhosseini
 * @since JDK 1.8
 */
public abstract class Agent
{
    private int x;
    private int y;

    private MoveState moveState;

    public Agent(int x, int y, MoveState moveState)
    {
	this.x = x;
	this.y = y;
	this.moveState = moveState;
    }


    int randomWithRange(int min, int max)
    {
	int range = (max - min) + 1;
	return (int)(Math.random() * range) + min;
    }

    public int getX() {
	return x;
    }

    public int getY() {
	return y;
    }

    public MoveState getMoveState()
    {
	return moveState;
    }
}
