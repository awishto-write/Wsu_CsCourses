import java.awt.Color;
import java.util.ArrayList;

public class SplitBall extends BasicBall {

    public SplitBall(double r, Color c, String type) {
        super(r, c, type);
    }

    // Interact with the player and handle splitting
    @Override
    public boolean isHit(double x, double y, Player player) {
        if ((Math.abs(rx - x) <= radius) && (Math.abs(ry - y) <= radius)) {
            numberHits++;
            player.recordHitValue(type, getScore());
            return true;
        }
        return false;
    }

    @Override
    public int getScore() {
        return 10; // Split ball hit score
    }

    // Splitting the ball into two new SplitBall instances
    public void split(ArrayList<BasicBall> balls) {
        balls.add(new SplitBall(radius, color, type));
        balls.add(new SplitBall(radius, color, type));
    }
}
