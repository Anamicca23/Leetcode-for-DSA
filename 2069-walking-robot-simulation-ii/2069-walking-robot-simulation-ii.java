class Robot {
    Map<Integer, Pair<int[], String>> map;
    int currPos;
    int perimeter;
    boolean moved;
    
    public Robot(int width, int height) {
        map = new HashMap<>();
        currPos = 0;
        perimeter = 0;
        moved = false;
        
        map.put(0, new Pair(new int[]{0, 0}, "South"));
        
        for(int e = 1; e < width; ++e)
            map.put(++perimeter, new Pair(new int[]{e, 0}, "East"));
        
        for(int n = 1; n < height; ++n)
            map.put(++perimeter, new Pair(new int[]{width - 1, n}, "North"));
        
        for(int w = width - 2; w >= 0; --w)
            map.put(++perimeter, new Pair(new int[]{w, height - 1}, "West"));
        
        for(int s = height - 2; s >= 0; --s)
            map.put(++perimeter, new Pair(new int[]{0, s}, "South"));
        
    }
    
    public void move(int num) {
        moved = true;
        currPos = (currPos + num) % perimeter;
    }
    
    public int[] getPos() {
        return map.get(currPos).getKey();
    }
    
    public String getDir() {
        return moved ? map.get(currPos).getValue() : "East";
    }
}