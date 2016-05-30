import java.lang.reflect.*;

public abstract class NonLocomotiveAgent extends Agent {

     public NonLocomotiveAgent(int x, int y, Environment env) {
	  super(x, y, env);
     }

     public void asexualReproduce() {
	  if (getAge() > 4) {
	       int[] childSpace = env.freeSpace(x, y);
	       if (childSpace != null) {

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
		    int minEnergyLoss = 5;
		    int maxEnergyLoss = 8;
		    setEnergy(getEnergy()-(int)(Math.random()*(maxEnergyLoss-minEnergyLoss+1)+minEnergyLoss));
	       }
	  }
     }

     public void act() {
	 setAge(getAge() + 1);
	  if (getEnergy() > 6) {
	       asexualReproduce();
	  }
	  gain_energy();
     }

    public void gain_energy() {
	int minEnergyGain = 0;
	int maxEnergyGain = 2;
	setEnergy(getEnergy()+(int)(Math.random()*(maxEnergyGain-minEnergyGain+1)+minEnergyGain));
    }

}
