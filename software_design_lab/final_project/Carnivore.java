/**
 *
 * @author Nooreddin Naghibolhosseini
 * @since JDK 1.8
 */


public class Carnivore extends Agent {

    private String name = "CARNIVORE";

    public String getName() {
	return name;
    }

    public Carnivore(int x, int y, Environment env) {
	super(x, y, env, new CarnivoreMove(env, x, y));
    }

}
