typedef tuple<int, int, int, int> tup4;

class Solution {
    const int L = 0, R = 1;
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int size = positions.size();
        vector<tup4> robots;
        robots.reserve(size);
        for (int i = 0; i < size; i++)
            robots.push_back({i, positions[i], healths[i], directions[i] == 'R'});
        sort(robots.begin(), robots.end(), [](tup4 &robot1, tup4& robot2) {
            return get<1>(robot1) < get<1>(robot2);
        });
        int l = 0, r = 0;
        for (int r = 0; r < size; r++) {
            auto &[idx, pos, hp, dir] = robots[r];
            if (dir == R) {
                robots[l++] = robots[r];
                continue;
            }
            while (l && get<3>(robots[l - 1]) == R && hp) {
                // dir0: R dir: L
                auto &[idx0, pos0, hp0, dir0] = robots[l - 1];
                if (hp0 > hp) {
                    hp = 0;
                    if (--hp0 == 0)
                        --l;
                } else if (hp0 < hp) {
                    --hp;
                    --l;
                } else {
                    hp = 0;
                    --l;
                }
            }
            if (hp) {
                robots[l++] = robots[r];
            }
        }
        robots.resize(l);
        sort(robots.begin(), robots.end(), [](tup4 &robot1, tup4& robot2) {
            return get<0>(robot1) < get<0>(robot2);
        });
        vector<int> res;
        res.reserve(robots.size());
        for (const auto &[idx, pos, hp, dir]: robots) {
            res.push_back(hp);
        }
        return res;
    }
};