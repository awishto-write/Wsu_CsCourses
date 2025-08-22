public class Player { 
    private int current_score;
    private int numPoints_basicHits;
    private int numPoints_shrinkHits;
    private int numPoints_bounceHits;
    private int numPoints_splitHits;
 
     // Constructor
    public Player() {   // Setting the components to default values
        current_score = 0;
        numPoints_basicHits = 0;
        numPoints_shrinkHits = 0;
        numPoints_bounceHits = 0;
        numPoints_splitHits = 0;
    }
    
           // Getters   ~ Getting the current score and hits for each ball type and total hits 

    public int getCurrentScore() {
        return current_score;
    }

    public int getTotalHits() {  // Sum of the hits of each type of balls
        return numPoints_basicHits + numPoints_shrinkHits + numPoints_bounceHits + numPoints_splitHits;
    }

    public int getNumPointsBasicHits() {
        return numPoints_basicHits;
    }

    public int getNumPointsShrinkHits() {
        return numPoints_shrinkHits;
    }

    public int getNumPointsBounceHits() {
        return numPoints_bounceHits;
    }

    public int getNumPointsSplitHits() {
        return numPoints_splitHits;
    }

             // Record all the hit values for each type of balls
    public void recordHitValue(String ballType, int score) {
        current_score += score;
        switch (ballType) {
            case "basic":
                numPoints_basicHits++;
                break;
            case "shrink":
                numPoints_shrinkHits++;
                break;
            case "bounce":
                numPoints_bounceHits++;
                break;
            case "split":
                numPoints_splitHits++;
                break;
            default:
                System.out.println("Undefined ball type");
        }
    }
 
}
 