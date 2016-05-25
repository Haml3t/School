
/**
 *
 * @author Nooreddin Naghibolhosseini
 * @since JDK 1.8
 */
public class Herbivore extends Agent
{

    private String name = "HERBIVORE";

    public String getName() {
        return name;
    }
    public Herbivore(int x, int y)
    {
        super(x, y, new Movable() {
            public void move(){

            }
        });
    }
}
