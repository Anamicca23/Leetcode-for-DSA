struct Robot {
    int position;
    int health;
    char direction;
    int originalIndex;
    
    Robot(int position, int health, char direction, int originalIndex)
        : position(position), health(health), direction(direction), originalIndex(originalIndex) {}
};

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<Robot> robots;
        for (int i = 0; i < n; i++) {
            robots.emplace_back(positions[i], healths[i], directions[i], i);
        }
        
        sort(robots.begin(), robots.end(), [](const Robot& a, const Robot& b) {
            return a.position < b.position;
        });
        
        stack<Robot> st;
        vector<Robot> survivors;
        
        for (Robot& robot : robots) {
            if (robot.direction == 'R') {
                st.push(robot);
            } else {
                while (!st.empty() && st.top().health < robot.health) {
                    Robot rightRobot = st.top();
                    st.pop();
                    robot.health -= 1;
                }
                if (!st.empty() && st.top().health == robot.health) {
                    st.pop(); 
                } else if (!st.empty()) {
                    st.top().health -= 1; 
                } else {
                    survivors.push_back(robot);
                }
            }
        }
        
        while (!st.empty()) {
            survivors.push_back(st.top());
            st.pop();
        }
        
        vector<int> result(n, -1);
        for (Robot& robot : survivors) {
            result[robot.originalIndex] = robot.health;
        }
        result.erase(remove(result.begin(), result.end(), -1), result.end());
        
        return result;
    }
};