class PlantImmove implements Immovable {

    Environment env;
    int x, y;
    Agent[][] earth;

    public PlantImmove(Environment env, int x, int y) {
	this.env = env;
	this.x = x;
	this.y = y;
	mofk().setEnergy(0);
    }


    public void act() {
	earth = this.env.getData();
	if (mofk().getEnergy() > 5) {
	    reproduce();
	}
	this.gain_energy();
    }
    public void reproduce() {
	if (mofk().getAge() > 4) {
	    int[] childSpace = env.freeSpace(x, y);
	    if (childSpace != null) {
		earth[childSpace[0]][childSpace[1]] = new Plant(childSpace[0], childSpace[1], env);
		mofk().setEnergy(mofk().getEnergy()-4);
	    }
	}
    }
    public void gain_energy() {
	mofk().setEnergy(mofk().getEnergy() + 1);
    }

    public Agent mofk() {
	return (Plant) earth[x][y];
    }
}
