import java.awt.Color;
import java.awt.Font;
import java.util.ArrayList;

public class BallGame { 

    public static void main(String[] args) {
  
    	// number of bouncing balls
    	int numBalls = Integer.parseInt(args[0]);
    	//ball types
    	String ballTypes[] = new String[numBalls];
    	//sizes of balls
    	double ballSizes[] = new double[numBalls];
    	
    	//retrieve ball types
    	int index =1;
    	for (int i=0; i<numBalls; i++) {
    		ballTypes[i] = args[index];
            ballSizes[i] = Double.parseDouble(args[index + 1]);
    		index = index+2;
    	}
    	//retrieve ball sizes
    	index = 2;
    	for (int i=0; i<numBalls; i++) {
    		ballSizes[i] = Double.parseDouble(args[index]);
    		index = index+2;
    	}
     
    	//TO DO: create a Player object and initialize the player game stats.  
        Player player = new Player(); // Just added
         // Create an ArrayList to store the balls
        ArrayList<BasicBall> balls = new ArrayList<>(numBalls);
        
        int activeBalls = 0; // Just added
        StdDraw.enableDoubleBuffering();
        StdDraw.setCanvasSize(800, 800);
        // set boundary to box with coordinates between -1 and +1
        StdDraw.setXscale(-1.0, +1.0);
        StdDraw.setYscale(-1.0, +1.0);

        // Create ball instances based on types and sizes
        for (int i = 0; i < numBalls; i++) {
            switch (ballTypes[i]) {
                case "basic":
                    balls.add(new BasicBall(ballSizes[i], Color.RED, ballTypes[i]));
                    break;
                case "bounce":
                    balls.add(new BounceBall(ballSizes[i], Color.BLUE, ballTypes[i], 3));
                    break;
                case "shrink":
                    balls.add(new ShrinkBall(ballSizes[i], Color.GREEN, ballTypes[i]));
                    break;
                case "split":
                    balls.add(new SplitBall(ballSizes[i], Color.YELLOW, ballTypes[i]));
                    break;
                default:
                    throw new IllegalArgumentException("Unknown ball type: " + ballTypes[i]);
            }
        }

        // The loop for the game
       // int activeBalls = numBalls; 
        activeBalls = balls.size();
        StdDraw.enableDoubleBuffering();

        while (activeBalls > 0) {
            // Move and draw each ball
            for (BasicBall ball : balls) {
                ball.move();
               // ball.draw();
            }

            if (StdDraw.isMousePressed()) {  // Check if a ball has been hit
                double x = StdDraw.mouseX();
                double y = StdDraw.mouseY();
                int temp = balls.size();

                for (int i = 0; i < temp; i++) {
                    BasicBall ball = balls.get(i);
                    if (ball.isHit(x, y, player)) {
                        ball.reset();
    
                        if (ball.getType().equals("split")) {  // Add 2 new SplitBall instances to handle the split ball
                            balls.add(new SplitBall(ball.getRadius(), ball.getColor(), ball.getType()));
                            balls.add(new SplitBall(ball.getRadius(), ball.getColor(), ball.getType()));
                            activeBalls += 2;
                        }
                    }

                }

            }

            // Count active balls and check for game termination
            activeBalls = 0;
            StdDraw.clear(StdDraw.GRAY); // Added
            StdDraw.setPenColor(StdDraw.BLACK); // Added
            for (BasicBall ball : balls) {
                if (!ball.isOut()) {
                    ball.draw();
                    activeBalls++;
                }
            }

            // Clear the canvas and set up text display
            StdDraw.setPenColor(StdDraw.BLACK); // Added
            Font font = new Font("Arial", Font.BOLD, 20);
            StdDraw.setFont(font);

            // Display game status during gameplay
            StdDraw.text(-0.5, 0.75, "Number of balls in game: " + activeBalls);
            StdDraw.text(-0.5, 0.70, "Number of hits: " + player.getTotalHits());
            StdDraw.text(-0.5, 0.65, "Total Score: " + player.getCurrentScore());

            // Refresh the display and pause
            StdDraw.show();
            StdDraw.pause(20);
        }

        // Display final player statistics after the game is over
       // StdDraw.clear();
        StdDraw.setPenColor(StdDraw.BLUE);
        Font gameOverFont = new Font("Arial", Font.BOLD, 60);
        Font other = new Font("Arial", Font.BOLD, 20);
        StdDraw.setFont(gameOverFont);
        StdDraw.text(0, 0, "GAME OVER");
        StdDraw.setFont(other);
        StdDraw.setPenColor(Color.BLUE);


    
        Font statsFont = new Font("Arial", Font.BOLD, 20);
        StdDraw.setFont(statsFont);
        StdDraw.setPenColor(Color.BLACK);
        StdDraw.text(0, -0.12, "Number of balls in game: " + activeBalls);
      //  StdDraw.text(0, -0.20, "Score: " + player.getCurrentScore());
        StdDraw.text(0, -0.19, "Basic Hits: " + player.getNumPointsBasicHits());
        StdDraw.text(0, -0.26, "Bounce Hits: " + player.getNumPointsBounceHits());
        StdDraw.text(0, -0.33, "Shrink Hits: " + player.getNumPointsShrinkHits());
        StdDraw.text(0, -0.40, "Split Hits: " + player.getNumPointsSplitHits());

        // Show the final display
        StdDraw.show();

   }

}