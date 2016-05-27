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
	super(x, y, new Movable() {
		public void move() {
		    int move_value = randomWithRange(1,9);
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
		public void try_move(int x, int y) {
		    if (x >= 0 && x <= 30 && y >= 0 && y <= 30)
			if (earth[x][y] == null) {
			    earth[x][y] = this;
			    earth[this.getX()][this.getY()] = null;
			    this.x = x;
			    this.y = y;
			}
		}
	    });
    }
}
