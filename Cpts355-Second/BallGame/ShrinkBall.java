import java.awt.Color;

public class ShrinkBall extends BasicBall {
	private double originalSize; // Store the original size
 
	public ShrinkBall(double r, Color c, String type) {
		super(r, c, type);
		originalSize = r; // Store the original size
	}

	// Interact with the player and shrink the ball
	@Override
    public boolean isHit(double x, double y, Player player) {
        if ((Math.abs(rx - x) <= radius) && (Math.abs(ry - y) <= radius)) {
            numberHits++;
            player.recordHitValue(type, getScore());
            // Shrink the ball
            radius *= 0.66;
            if (radius <= originalSize * 0.25) {
                reset();
            }
            return true;
        }
        return false;
    }

    // GetScore to return shrink ball hit score
    @Override
    public int getScore() {
        return 20; // Shrink ball hit score
    }

    // Reset to reset ball's size and position
    @Override
    public int reset() {
        super.reset();
        radius = originalSize;
		return 1;
    }

}
 