/**
 * The main running module of the project.
 * This is a singleton class.
 *
 * @author Nooreddin Naghibolhosseini
 * @since JDK 1.8
 */
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
		    earth[i][j] = new Plant(i, j);
		}
		else if( Math.random() < 0.10 )
		{
		    earth[i][j] = new Herbivore(i, j);
		}
		else if( Math.random() < 0.05 )
		{
		    earth[i][j] = new Carnivore(i, j);
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
		    if (earth[i][j] != null &&
			    earth[i][j].getMoveState() instanceof Movable) {
			((Movable) earth[i][j].getMoveState()).move();
		    }
		}
	    }

	    printEarth();
	    System.out.println();

	    try {
		Thread.sleep(5);
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
}
