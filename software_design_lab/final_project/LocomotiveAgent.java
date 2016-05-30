import java.lang.reflect.*;

public abstract class LocomotiveAgent extends Agent {

    private boolean is_male;

    public LocomotiveAgent(int x, int y, Environment env) {
	super(x, y, env);
	is_male = Environment.randomWithRange(0,1) == 0 ? false : true;
    }

    public void sexualReproduce(LocomotiveAgent mate) {
	if(mate.getClass() != this.getClass()) return;

	if (getAge() > 3 && mate.getAge() > 3 && getEnergy() > 6 && mate.getEnergy() > 6) {
	    int minEnergyLoss = 3;
	    int maxEnergyLoss = 5;
	    setEnergy(getEnergy()-(int)(Math.random()*(maxEnergyLoss-minEnergyLoss+1)+minEnergyLoss)); // reproducing is exhausting
	    mate.setEnergy(getEnergy()-(int)(Math.random()*(maxEnergyLoss-minEnergyLoss+1)+minEnergyLoss));

	    int[] childSpace = env.freeSpace(x, y);

	    if (childSpace != null) { // makes sure a valid space for the child is found
		// spawns a new Agenr at that space

		System.err.println(childSpace[0] + " " + childSpace[1]);

		Constructor constructor = this.getClass().getConstructors()[0]; // pretty sure we'll have a constructor
		try {
		    env.getData()[childSpace[0]][childSpace[1]] =
			(Agent) constructor.newInstance(childSpace[0], childSpace[1], env);
		} catch (InstantiationException e) {
		    System.err.print(e);
		} catch (IllegalAccessException e) {
		    System.err.print(e);
		} catch (InvocationTargetException e) {
		    System.err.print(e);
		}
	    }
	}
    }

    public void move() {
	Agent[][] earth = env.getData();
	setAge(getAge() + 1);
	int minEnergyLoss = 0;
	int maxEnergyLoss = 2;
	setEnergy(getEnergy()-(int)(Math.random()*(maxEnergyLoss-minEnergyLoss+1)+minEnergyLoss));

	if (getEnergy() < 1) {	// if it runs out of energy
	    die();		// brutal
	}
	else {
	    int move_value = Environment.randomWithRange(1,9); // otherwise pick a cell to move to

	    boolean success = false;
	    switch (move_value) {
	    case 1: tryMove(x-1, y+1); break;
	    case 2: tryMove(x  , y+1); break;
	    case 3: tryMove(x+1, y+1); break;
	    case 4: tryMove(x-1, y);   break;
	    case 5:                    break;
	    case 6: tryMove(x+1, y);   break;
	    case 7: tryMove(x-1, y-1); break;
	    case 8: tryMove(x  , y-1); break;
	    case 9: tryMove(x+1, y-1); break;
	    }
	}
    }

    public abstract void tryMove(int xNew, int yNew);

    public void attack(LocomotiveAgent target) {
	if (getEnergy() > 5) {
	    if (getEnergy() > target.getEnergy()) { // if we have more energy than the foe then we win
		int xNew = target.getX();
		int yNew = target.getY();

		target.die();
		setEnergy(getEnergy()-3); // fighting is exhausting

		// move to where target was
		env.getData()[getX()][getY()] = null;
		env.getData()[xNew][yNew] = this;
		setX(xNew);
		setY(yNew);

	    }
	    else {		// ties go to the defender
		target.setEnergy(target.getEnergy()-2);   // defending is easier
		die();
	    }
	}
    }

    public abstract void eat(Agent target);

    public boolean isMale() {
	return is_male;
    }
}
