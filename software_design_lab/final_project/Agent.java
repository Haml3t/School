/**
 *
 * @author Nooreddin Naghibolhosseini
 * @since JDK 1.8
 */

//package finalproject;

public abstract class Agent
{
    public int x;
    public int y;
    private double energy;
    private int age;
    private Environment env;

    private MoveState moveState;

    public Agent(int x, int y, Environment env, MoveState moveState) {
	this.x = x;
	this.y = y;
	this.moveState = moveState;
	this.energy = 6;
	this.age = 0;
	this.env = env;
    }

    public int getX() {
	return x;
    }

    public int getY() {
	return y;
    }

    public double getEnergy() {
	return energy;
    }

    public int getAge() {
	return age;
    }

    public void setX(int x) {
	this.x = x;
    }

    public void setY(int y) {
	this.y = y;
    }

    public void setEnergy( double energy) {
	this.energy = energy;
    }

    public void setAge( int age) {
	this.age = age;
    }

    public MoveState getMoveState()
    {
	return moveState;
    }

    public abstract String getName();

    // public abstract boolean isMale();

    // public abstract void attack(Agent target);

    // public abstract void eat(Agent target);


    public boolean isMovable() {
	return moveState instanceof CarnivoreMove || moveState instanceof HerbivoreMove;
    }

    public Movable moveInstance() {
	return (Movable) moveState;
    }

    public Immovable immmoveInstance() {
	return (Immovable) moveState;
    }

    public void die() {
	Agent[][] world = env.getData();
	world[this.getX()][this.getY()] = null;
    }
}
