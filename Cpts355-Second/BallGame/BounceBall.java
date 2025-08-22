import java.awt.Color;

public class BounceBall extends BasicBall {
    private int bounceCount = 0;
 
    public BounceBall(double r, Color c, String type, int bounce) {
        super(r, c, type);
        bounceCount = bounce;
    }

    // Override isHit to interact with the player
    @Override
    public boolean isHit(double x, double y, Player player) {
        if ((Math.abs(rx - x) <= radius) && (Math.abs(ry - y) <= radius)) {
            numberHits++;
            player.recordHitValue(type,getScore());
            return true;
        }
        return false;
    }

    // Modify move method to handle bouncing and check if it should exit
    @Override
    public void move() {
        rx += vx;
        ry += vy;

        // Check for bounces
        if (Math.abs(rx) > 1.0 || Math.abs(ry) > 1.0) {
            if(bounceCount >= 3){  // 3 being the max number of bounces
                isOut = true;
            }

            // Other Cases where the ball can bounce
            else if (bounceCount < 3){

                if((rx < -1.0) && (ry > 0)){ // To the left up
                    vx = Math.abs(vx);
                    vy = StdRandom.uniform(0, 0.01);
                    rx = rx + vx;
                    ry = ry + vy;
                    bounceCount++;
                }
                else if((rx < -1.0) && (ry < 0)){   // To the left down
                    vx = Math.abs(vx);
                    vy = StdRandom.uniform(-0.01, 0);
                    rx = rx + vx;
                    ry = ry + vy;
                    bounceCount++;
                }
                else if((rx > 1.0) && (ry > 0)){ // To the right up
                    vx = -vx;
                    vy = StdRandom.uniform(0, 0.01);
                    rx = rx + vx;
                    ry = ry + vy;
                    bounceCount++;
                }
                else if((rx > 1.0) && (ry < 0)){ // To the right down
                    vx = -vx;
                    vy = StdRandom.uniform(-0.01, 0);
                    rx = rx + vx;
                    ry = ry + vy;
                    bounceCount++;
                }

                else if((rx > 0) && (ry > 1.0)){ // To up right
                    vx = StdRandom.uniform(0, 0.01);
                    vy = -vy;
                    rx = rx + vx;
                    ry = ry + vy;
                    bounceCount++;
                }
                else if((rx < 0) && (ry > 1.0)){ // To up left
                    vx = StdRandom.uniform(-0.01, 0);
                    vy = -vy;
                    rx = rx + vx;
                    ry = ry + vy;
                    bounceCount++;
                }
                else if((rx > 0) && (ry < -1.0)){   // To down right
                    vx = StdRandom.uniform(0, 0.01);
                    vy = Math.abs(vy);
                    rx = rx + vx;
                    ry = ry + vy;
                    bounceCount++;
                }
                else if((rx < 0) && (ry < -1.0)){  // To down left
                    vx = StdRandom.uniform(-0.01, 0);
                    vy = Math.abs(vy);
                    rx = rx + vx;
                    ry = ry + vy;
                    bounceCount++;
                }
               
            }
        }
    }

    // Override getScore to return bounce ball hit score
    @Override
    public int getScore() {
        return 15; // Bounce ball hit score
    }
   
    
}
 