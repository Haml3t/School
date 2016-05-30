/**
 *
 * @author Nooreddin Naghibolhosseini
 * @since JDK 1.8
 */


public class Carnivore extends LocomotiveAgent {

     public Carnivore(int x, int y, Environment env) {
	  super(x, y, env);
     }

     public void tryMove(int xNew, int yNew) {
	  Agent[][] earth = env.getData();

	  boolean success = false;

	  if (xNew >= 0 && xNew < 30 && yNew >= 0 && yNew < 30) { // valid coordinate?
	       Agent target = earth[xNew][yNew];

	       if (target == null) { // nothing in the target space, just go there
		    earth[xNew][yNew] = this;
		    earth[x][y] = null;
		    setX(xNew);
		    setY(yNew);

	       }

	       else { // something in the way
		    if(target instanceof LocomotiveAgent) { // if target is not an immovableagent

			 LocomotiveAgent locoTarget = (LocomotiveAgent) target;

			 if (target.getClass() == getClass()) { // same species
			      // if same sex, do attack
			      if(isMale() == locoTarget.isMale()) {
				   attack(locoTarget);
			      }

			      else {
				   sexualReproduce(locoTarget);
			      }

			 }
			 else if (target instanceof Herbivore) {
			      eat(locoTarget);
			 }
		    }
	       }
	  }
     }

     public void eat(Agent target) {
	 int xNew = target.getX();
	 int yNew = target.getY();
	 target.die();
	 int minEnergyGain = 5;
	 int maxEnergyGain = 7;
	 setEnergy(getEnergy()+(int)(Math.random()*(maxEnergyGain-minEnergyGain+1)+minEnergyGain)); // yum

	 env.getData()[getX()][getY()] = null;
	 env.getData()[xNew][yNew] = this;

	 setX(xNew);		    // move into its space
	 setY(yNew);
     }
}
