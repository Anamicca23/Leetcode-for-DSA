class Solution {
public:
    int dfs(int boxes, vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes , 
    unordered_set<int>&visited, unordered_set<int>&foundboxes){
        if(visited.count(boxes))return 0; // if box is visited we can't collect any condies.
        if(status[boxes]==0){foundboxes.insert(boxes); return 0;} // if box is closed just add it in foundboxes and we can't get any candies form closed ones .
        
        visited.insert(boxes);
        int collectedcandies = candies[boxes];

        for(int &insideboxes: containedBoxes[boxes]){
            collectedcandies += dfs(insideboxes, status, candies, keys, containedBoxes, visited, foundboxes); // collect all candies which is on opened boxes.
        }
        for(int &keyfoundbox: keys[boxes]){
            status[keyfoundbox]=1;  // mark status opened whose key has been founded.
            if(foundboxes.count(keyfoundbox)){ //if that closed box if in foundedbox then only add candies . 
              collectedcandies += dfs(keyfoundbox, status, candies, keys, containedBoxes, visited, foundboxes);
            }
        }
        return collectedcandies;
    }
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int collectedcandies = 0;
        unordered_set<int> visited;
        unordered_set<int> foundboxes;
        for(int &box: initialBoxes){
            collectedcandies += dfs(box, status, candies, keys, containedBoxes, visited, foundboxes);
        }
        return collectedcandies;
    }
};