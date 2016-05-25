
/**
 *
 * @author Nooreddin Naghibolhosseini
 * @since JDK 1.8
 */

public class Carnivore extends Agent
{

    private String name = "CARNIVORE";

    public String getName() {
        return name;
    }

    public Carnivore(int x, int y) {
        super(x, y, new Movable(){
            public void move(){

            }
        });
    }
}
