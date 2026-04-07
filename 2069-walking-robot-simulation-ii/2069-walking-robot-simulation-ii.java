class Robot {

    int direction;
    String[] directionName;
    int width, height;
    int[] position;
    int[][] stepMovement;
    int num;

    public Robot(int width, int height) {
        this.width = width;
        this.height = height;
        this.position = new int[2];
        this.position[0] = 0;
        this.position[1] = 0;
        this.direction = 0;
        this.directionName = new String[]{"East", "North", "West", "South"};
        this.stepMovement = new int[][]{{1,0},  {0,1}, {-1, 0}, {0, -1}};
        this.num = 0;

    }
    
    private void lazyStep(int num){
        num = num%(2*(this.width + this.height) - 4);
        if(num == 0){
            num = 2*(this.width + this.height) - 4;
        }
        while(num > 0){
            switch(direction){
                case 0:
                    if(this.position[0] + num > this.width - 1){
                        num = num - (this.width - this.position[0] - 1);
                        this.direction = (this.direction + 1)%4;
                        this.position[0] = this.width-1;
                    }
                    else{
                        this.position[0] = this.position[0] + num;
                        num = 0;
                    }
                    break;
                case 2:
                    if(this.position[0] - num < 0){
                        num = num - (this.position[0]);
                        this.direction = (this.direction + 1)%4;
                        this.position[0] = 0;
                    }
                    else{
                        this.position[0] = this.position[0] - num;
                        num = 0;
                    }
                    break;
                case 1:
                    if(this.position[1] + num > this.height - 1){
                        num = num - (this.height - this.position[1] - 1);
                        this.direction = (this.direction + 1)%4;
                        this.position[1] = this.height - 1;
                    }
                    else{
                        this.position[1] = this.position[1] + num;
                        num = 0;
                    }
                    break;
                case 3:
                    if(this.position[1] - num < 0){
                        num = num - (this.position[1]);
                        this.direction = (this.direction + 1)%4;
                        this.position[1] = 0;
                    }
                    else{
                        this.position[1] = this.position[1] - num;
                        num = 0;
                    }
                    break;
            }
        }
        this.num = 0;
    }
    public void step(int num) {
        this.num += num;
    }
    
    public int[] getPos() {
        if(this.num > 0)
            this.lazyStep(this.num);
        return this.position;
    }
    
    public String getDir() {
        if(this.num > 0)
            this.lazyStep(this.num);
        return this.directionName[this.direction];
    }
}

/**
 * Your Robot object will be instantiated and called as such:
 * Robot obj = new Robot(width, height);
 * obj.step(num);
 * int[] param_2 = obj.getPos();
 * String param_3 = obj.getDir();
 */