class CarnivoreMove implements Movable {

    Environment env;
    int x, y;
    boolean amIMale;
    Agent[][] earth;

    public CarnivoreMove(Environment env, int x, int y)  {
	this.env = env;
	this.x = x;
	this.y = y;
	amIMale = Environment.randomWithRange(0,1) == 0 ? false : true;
	mofk().setEnergy(6);
    }


    public void move() {
	earth = this.env.getData();
	if (mofk().getEnergy() < 1) {	// if it runs out of energy
	    mofk().die();		// brutal
	}
	else {
	    int move_value = Environment.randomWithRange(1,9); // otherwise pick a cell to move to

	    switch (move_value) {
	    case 1: try_move(x-1, y+1);
	    case 2: try_move(x, y+1);
	    case 3: try_move(x+1, y+1);
	    case 4: try_move(x-1, y);
	    case 5: break;
	    case 6: try_move(x+1, y);
	    case 7: try_move(x-1, y-1);
	    case 8: try_move(x, y-1);
	    case 9: try_move(x+1, y-1);
	    }
	}
    }
    public void try_move(int xNew, int yNew) {
	if(env.moveAgent(x, y, xNew, yNew)) {
	    x = xNew;
	    y = yNew;
	    mofk().setEnergy(mofk().getEnergy() + 1);
	    // Agent's x, y are set in moveAgent
	}
	mofk().setAge(mofk().getAge() + 1);
    }
    public boolean attack(Agent foe) {
	if (mofk().getEnergy() > 5) {
	    if (mofk().getEnergy() > foe.getEnergy()) { // if the Agent has more energy than the foe then it wins
		foe.die();
		mofk().setEnergy(mofk().getEnergy()-3); // fighting is exhausting
		return true;
	    }
	    else {		// ties go to the defender
		mofk().die();
		foe.setEnergy(foe.getEnergy()-2);   // defending is easier
		return false;			    // maybe needs to break instead? if the Agent gets deleted it can't return to try_move can it?
	    }
	}
	return false;
    }

    public void reproduce(Agent mate) {
	if (mofk().getAge() > 3 && mate.getAge() > 3 && mofk().getEnergy() > 6 && mate.getEnergy() > 6) {
	    mofk().setEnergy(mofk().getEnergy() - 4); // reproducing is exhausting
	    mate.setEnergy(mate.getEnergy() - 4);

	    int[] childSpace = env.freeSpace(x, y);
	    if (childSpace != null) { // makes sure a valid space for the child is found
		// spawns a new Carnivore at that space
		earth[childSpace[0]][childSpace[1]] = new Carnivore(childSpace[0], childSpace[1], env);
	    }

	}
    }

    public void eat(Agent prey) {
	prey.die();
	mofk().setEnergy(mofk().getEnergy()+6); // yum
    }


    public boolean isMale() {
	return amIMale;
    }

    public Agent mofk() {
	return (Carnivore) earth[x][y];
    }
}
