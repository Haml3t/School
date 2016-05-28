/**
 * The main running module of the project.
 * This is a singleton class.
 *
 * @author Nooreddin Naghibolhosseini
 * @since JDK 1.8
 */

//package finalproject;

import java.util.ArrayList;

public class Environment
{
    private static final char CARNIVORE = 'C';
    private static final char HERBIVORE = '@';
    private static final char PLANT = '*';

    private Agent[][] earth;
    private static Environment instance;

    private Environment()
    {
	earth = new Agent[30][30];
	initEarth();
    }

    private void initEarth() {
	for (int i = 0; i < 30; i++) {
	    for (int j = 0; j < 30; j++) {
		if( Math.random() < 0.20 ) {
		    earth[i][j] = new Plant(i, j, this);
		}
		else if( Math.random() < 0.10 )
		{
		    earth[i][j] = new Herbivore(i, j, this);
		}
		else if( Math.random() < 0.05 )
		{
		    earth[i][j] = new Carnivore(i, j, this);
		}
	    }
	}
    }

    public static Environment getInstance()
    {
	if( instance == null )
	    instance = new Environment();

	return instance;
    }

    public void startEarth(int numItr)
    {
	for (int itr = 0; itr < numItr; itr++) {
	    for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
		    if (earth[i][j] != null) {
			if (earth[i][j].getMoveState() instanceof Movable) {
			    ((Movable) earth[i][j].getMoveState()).move();
			}
			else if (earth[i][j].getMoveState() instanceof Immovable) {
			    ((Immovable) earth[i][j].getMoveState()).act();
			}
		    }
		}
	    }

	    printEarth();
	    System.out.println();

	    try {
		Thread.sleep(100);
		System.out.print("\033[H\033[2J");
		System.out.flush();
	    } catch (InterruptedException e) {
		e.printStackTrace();
	    }
	}
    }

    private void printEarth() {
	for (int i = 0; i < 30; i++) {
	    for (int j = 0; j < 30; j++) {
		if(earth[i][j] instanceof Carnivore)
		    System.out.print(CARNIVORE);
		else if(earth[i][j] instanceof Herbivore)
		    System.out.print(HERBIVORE);
		else if(earth[i][j] instanceof Plant)
		    System.out.print(PLANT);
		else
		    System.out.print(' ');

		System.out.print(' ');
	    }
	    System.out.println();
	}
    }

    public Agent[][] getData() {
	return earth;
    }


    public int[] freeSpace(int x, int y) { // returns a free cell adjacent to the input cell as an array of ints representing the ordered pair

	ArrayList<int[]> spaces = new ArrayList<>();

	if (isEmpty(x-1, y+1)) {
	    spaces.add(new int[]{ x-1, y+1 });
	}

	if (isEmpty(x, y+1)) {
	    spaces.add(new int[]{ x, y+1});
	}

	if (isEmpty(x+1, y+1)) {
	    spaces.add(new int[]{ x+1, y+1});
	}

	if (isEmpty(x-1, y)) {
	    spaces.add(new int[]{ x-1, y});
	}

	if (isEmpty(x+1, y)) {
	    spaces.add(new int[]{ x+1, y});
	}

	if (isEmpty(x-1, y-1)) {
	    spaces.add(new int[]{ x-1, y-11});
	}

	if (isEmpty(x, y-1)) {
	    spaces.add(new int[]{ x, y-1});
	}

	if (isEmpty(x+1, y-1)) {
	    spaces.add(new int[]{ x+1, y-1});
	}
	if (spaces.size() > 0) {
	    int choice = randomWithRange(0,spaces.size());
	    return spaces.get(choice);
	}

	return null;
    }

    public boolean isEmpty(int x, int y) {
	if (x > 0 && y > 0 && earth[x][y] == null) {
	    return true;
	}
	else
	    return false;
    }

    // returns true if move succeeded
    public boolean moveAgent(int xOld, int yOld, int xNew, int yNew) {
	Agent agent = earth[xOld][yOld];
	Movable agentMove = agent.moveInstance();

	if (xNew >= 0 && xNew < 30 && yNew >= 0 && yNew < 30) { // valid coordinate?
	    Agent target = earth[xNew][yNew];

	    if (target == null) { // nothing in the target space, just go there
		earth[xNew][yNew] = agent;
		earth[xOld][yOld] = null;
		agent.setX(xNew);
		agent.setY(yNew);
		return true;
	    }
	    else {

		if(!target.isMovable()) { // target is plant
		    if(agent instanceof Carnivore) {
			return false; // carns dont eat plants
		    }
		    else if (agent instanceof Herbivore) {
			agentMove.eat(target);
			return true;
		    }
		}

		else { // target is an animal
		    if (target.getName() == agent.getName()) { // same species
			// if same sex, do attack
			if(((Movable)target.getMoveState()).isMale() == agentMove.isMale()) {
			    return agentMove.attack(target);
			}
			else {
			    agentMove.reproduce(target);
			    return false; // reproduction is not moving
			}
		    }
		    else { // different species of animal
			if(agent instanceof Carnivore) {
			    agentMove.eat(target);
			    return true;
			}
			else if (agent instanceof Herbivore) {
			    ; // run away
			    return false; // for now chill
			}
		    }
		}
	    }
	}

	return false;
    }

    public static int randomWithRange(int min, int max) {
	int range = (max - min) + 1;
	return (int)(Math.random() * range) + min;
    }

}
