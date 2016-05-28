/**
 *
 * @author Nooreddin Naghibolhosseini
 * @since JDK 1.8
 */

//package finalproject;

public class Herbivore extends Agent
{

    private String name = "HERBIVORE";

    public String getName() {
	return name;
    }


    public Herbivore(int x, int y, Environment env) {
	super(x, y, env, new HerbivoreMove(env, x, y));

    }
}
