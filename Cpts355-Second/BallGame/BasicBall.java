import java.awt.Color;

public class BasicBall { 
    protected double rx, ry;         // position
    protected double vx, vy;         // velocity
    protected double radius;   // radius
    protected final Color color;     // color
    public boolean isOut; 
    protected int numberHits; // Number of hits
    protected String type; // Type  of balls

    // constructor
    public BasicBall(double r, Color c, String ballType) {
        rx = 0.0;
        ry = 0.0;
        vx = StdRandom.uniform(-0.01, 0.01);
        vy = StdRandom.uniform(-0.01, 0.01);
        radius = r;
        color = c;
        isOut = false;
        type = ballType;
        numberHits = 0;
    }
   
   
    // move the ball one step
    public void move() {
        rx = rx + vx;
        ry = ry + vy;
        if ((Math.abs(rx) > 1.0) || (Math.abs(ry) > 1.0)) 
        	isOut = true;
    }

    // draw the ball
    public void draw() { 
    	if ((Math.abs(rx) <= 1.0) && (Math.abs(ry) <= 1.0)) {
    		StdDraw.setPenColor(color);
    		StdDraw.filledCircle(rx, ry, radius);
    	} else
    		isOut = true;
    	
    }

    public int reset() {
        rx = 0.0;
        ry = 0.0; 
        vx = StdRandom.uniform(-0.01, 0.01);
        vy = StdRandom.uniform(-0.01, 0.01);
        return 1;
    }

    public boolean isHit(double x, double y, Player player) {
    	if ((Math.abs(rx-x)<=radius) && (Math.abs(ry-y)<=radius)) {
            numberHits++;
            player.recordHitValue(type, getScore());
            return true;
        }
		return false;
    }

             // Getters
    public int getScore() {
    	return 25;
    }
    
    public double getRadius() {
    	return radius;
    }

    public Color getColor() {
        return color;
    }

    public String getType() {
        return type;
    }

    public int getHits() {
        return numberHits;
    }

    public boolean isOut() {
        return isOut;
    }

}