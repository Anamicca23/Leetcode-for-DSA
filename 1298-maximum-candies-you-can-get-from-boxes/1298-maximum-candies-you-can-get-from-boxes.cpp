class Solution {
public:
    int dfs(int boxes, vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, 
    unordered_set<int>&visited,unordered_set<int>&foundboxes){
        if(visited.count(boxes))return 0;
        if(status[boxes]==0){foundboxes.insert(boxes);return 0;}
        visited.insert(boxes);
        int collectedcandies = candies[boxes];

        for(int &insidebox:containedBoxes[boxes]){
            collectedcandies += dfs(insidebox,status, candies, keys,containedBoxes, visited, foundboxes);
        }
        for(int &keyboxes: keys[boxes]){
            status[keyboxes]=1;
            if(foundboxes.count(keyboxes)){
                collectedcandies += dfs(keyboxes, status, candies, keys, containedBoxes, visited, foundboxes);
            }
        }
        return collectedcandies;
    }
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int collectedcandies =0;
        unordered_set<int>visited;
        unordered_set<int>foundboxes;
        for(int &box: initialBoxes){
            collectedcandies += dfs(box, status, candies,keys, containedBoxes,visited, foundboxes);
        }
        return collectedcandies;
    }
};