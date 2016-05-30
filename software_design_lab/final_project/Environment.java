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
		    earth[i][j].setEnergy(0);
		}
		else if( Math.random() < 0.15 )
		{
		    earth[i][j] = new Herbivore(i, j, this);
		    earth[i][j].setEnergy(6);
		}
		else if( Math.random() < 0.05 )
		{
		    earth[i][j] = new Carnivore(i, j, this);
		    earth[i][j].setEnergy(6);
		}
	    }
	}
	printEarth();
	System.out.println();

	try {
	    Thread.sleep(100);
	} catch (InterruptedException e) {
	    e.printStackTrace();
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
			if (earth[i][j] instanceof LocomotiveAgent) {
			     ((LocomotiveAgent) earth[i][j]).move();
			}
			else if (earth[i][j] instanceof NonLocomotiveAgent) {
			    ((NonLocomotiveAgent) earth[i][j]).act();
			}
		    }
		}
	    }

	    printEarth();
	    System.out.println();

	    try {
		Thread.sleep(1000);
		System.out.print("\033[H\033[2J");
		System.out.flush();
	    } catch (InterruptedException e) {
		e.printStackTrace();
	    }
	}
    }

    private void printEarth() {
	int carnCount = 0;
	int herbCount = 0;
	int plantCount = 0;
	for (int i = 0; i < 30; i++) {
	    for (int j = 0; j < 30; j++) {
		if(earth[i][j] instanceof Carnivore) {
		    System.out.print(CARNIVORE);
		    ++carnCount;
		}
		else if(earth[i][j] instanceof Herbivore) {
		    System.out.print(HERBIVORE);
		    ++herbCount;
		}
		else if(earth[i][j] instanceof Plant) {
		    System.out.print(PLANT);
		    ++plantCount;
		}
		else
		    System.out.print(' ');

		System.out.print(' ');
	    }
	    System.out.println();
	}
	System.out.println("Carnivores: " + carnCount + " Herbivores: " + herbCount + " Plants: " + plantCount);
    }

    public Agent[][] getData() {
	return earth;
    }

    public int[] freeSpace(int x, int y) { // returns a free space adjacent to the agent

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
	    spaces.add(new int[]{ x-1, y-1});
	}

	if (isEmpty(x, y-1)) {
	    spaces.add(new int[]{ x, y-1});
	}

	if (isEmpty(x+1, y-1)) {
	    spaces.add(new int[]{ x+1, y-1});
	}
	if (spaces.size() > 0) {
	    int choice = randomWithRange(0,spaces.size() - 1 );
	    return spaces.get(choice);
	}

	return null;
    }

    public boolean isEmpty(int x, int y) {
	 return (x >= 0 && y >= 0 && x < 30 && y < 30 && earth[x][y] == null);
    }

    public static int randomWithRange(int min, int max) {
	int range = (max - min) + 1;
	return (int)(Math.random() * range) + min;
    }

}
