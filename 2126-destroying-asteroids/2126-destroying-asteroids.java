class Solution {
    public boolean asteroidsDestroyed(int mass, int[] asteroids) {
        Arrays.sort(asteroids);
        long curMass=mass;
        for(int val:asteroids){
            if(val>curMass)return false;
            curMass+=val;
        }
        return true;
    }
}