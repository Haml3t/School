/**
 *
 * @author Nooreddin Naghibolhosseini
 * @since JDK 1.8
 */


public class Herbivore extends LocomotiveAgent {

     public Herbivore(int x, int y, Environment env) {
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

		    // simple move costs 1 energy
		    // setEnergy(getEnergy() - 1);
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
			 else if (target instanceof Carnivore) {
			      // TODO run away
			 }
		    }
		    else { // its a plant
			 eat(target);
		    }
	       }
	  }
     }

     public void eat(Agent target) {
	 int xNew = target.getX();
	 int yNew = target.getY();
	 target.die();
	 setEnergy(getEnergy()+6); // yum

	 env.getData()[getX()][getY()] = null;
	 env.getData()[xNew][yNew] = this;

	 setX(xNew);		    // move into its space
	 setY(yNew);
     }
}
