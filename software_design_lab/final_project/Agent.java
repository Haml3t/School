/**
 *
 * @author Nooreddin Naghibolhosseini
 * @since JDK 1.8
 */

//package finalproject;

public abstract class Agent {
     public int x;
     public int y;
     private double energy;
     private int age;
     protected Environment env;

     public Agent(int x, int y, Environment env) {
	  this.x = x;
	  this.y = y;
	  this.age = 0;
	  this.env = env;
     }

     ///// accessors

     public int getX() {
	  return x;
     }
     public int getY() {
	  return y;
     }
     public void setX(int x) {
	  this.x = x;
     }
     public void setY(int y) {
	  this.y = y;
     }
     public double getEnergy() {
	  return energy;
     }
     public void setEnergy( double energy) {
	  this.energy = energy;
     }
     public int getAge() {
	  return age;
     }
     public void setAge( int age) {
	  this.age = age;
     }

     public void die() {
	  Agent[][] world = env.getData();
	  world[getX()][getY()] = null;
	  System.err.println(getClass().toString() + " dying");
     }

}
