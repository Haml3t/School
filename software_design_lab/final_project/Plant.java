/**
 * Created by nooreddin on 4/5/16.
 */


public class Plant extends Agent {

    private String name = "PLANT";

    public String getName() {
	return name;
    }

    public Plant(int x, int y, Environment env) {
	super(x, y, env, new PlantImmove(env, x, y));
    }

}
