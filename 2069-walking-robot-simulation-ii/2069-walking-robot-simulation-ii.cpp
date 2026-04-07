#pragma GCC optimize("Ofast,unroll-loops,inline")
#include <string>
#include <vector>

static const int speedup = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Robot {
    int w, h, p, curr;
    bool moved;
    const std::string dirs[4] = {"East", "North", "West", "South"};

public:
    Robot(int width, int height) : w(width), h(height), curr(0), moved(false) {
        p = (w + h - 2) << 1;
    }

    inline void step(int num) {
        moved = true;
        curr = (curr + num) % p;
    }

    inline std::vector<int> getPos() {
        if (curr < w)
            return {curr, 0};
        if (curr < w + h - 1)
            return {w - 1, curr - w + 1};
        if (curr < (w << 1) + h - 2)
            return {(w << 1) + h - 3 - curr, h - 1};
        return {0, p - curr};
    }

    inline std::string getDir() {
        if (!moved)
            return dirs[0];
        if (curr == 0)
            return dirs[3];
        if (curr < w)
            return dirs[0];
        if (curr < w + h - 1)
            return dirs[1];
        if (curr < (w << 1) + h - 2)
            return dirs[2];
        return dirs[3];
    }
};