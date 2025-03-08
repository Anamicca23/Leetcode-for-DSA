class Solution {
public:
    int minimumRecolors(string blocks, int k) {
    int back = 0, front = 0, count_w = 0, ans = INT_MAX;
    while(front < blocks.size()){
        if(blocks[front] == 'W'){ count_w++; }
        if(front - back + 1 == k){
            ans = min(ans, count_w);
            if(blocks[back] == 'W') count_w--;
            back++;
        }
        front++;
    }
    return ans;
}
};