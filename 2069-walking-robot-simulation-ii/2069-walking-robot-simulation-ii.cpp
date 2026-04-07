class Robot {
private:
    int w, h, perimeter;
    int x = 0, y = 0, dir = 0;
    static constexpr int dirs[5] = {0, 1, 0, -1, 0};
    static constexpr const char* dirsText[4] = {"East", "North", "West", "South"};
public:
    Robot(int width, int height) : w(width), h(height), perimeter(2 * (w + h - 2)) {}
    void step(int num) {
        num %= perimeter;
        while (num) {
            int move = 0;
            if (dir == 0) move = w - 1 - x;
            else if (dir == 1) move = h - 1 - y;
            else if (dir == 2) move = x;
            else move = y;
            if (num <= move) {
                x += dirs[dir + 1] * num;
                y += dirs[dir] * num;
                num = 0;
            } 
            else {
                x += dirs[dir + 1] * move;
                y += dirs[dir] * move;
                num -= move;
                dir = (dir + 1) % 4;
            }
        }
        if (x == 0 && y == 0 && num == 0 && dir == 0) dir = 3;
    }
    vector<int> getPos() const {
        return {x, y};
    }
    string getDir() const {
        return dirsText[dir];
    }
};