class Solution {
public:
     int LargestRectangleArea(vector<int> heights) {
        int ret = 0;
        vector<int> increasing_height;
        int i = 0, n = heights.size();
        int top_height, width;
        while(i < n){
            if(increasing_height.empty() || heights[increasing_height.back()] < heights[i]){
                increasing_height.push_back(i);
                i++;
            }else{
                top_height = heights[increasing_height.back()];
                increasing_height.pop_back();
                width = increasing_height.empty()? i : i - increasing_height.back() - 1;
                ret = max(ret, top_height * width);
            }   
        }
        while(!increasing_height.empty()){
            top_height = heights[increasing_height.back()];
            increasing_height.pop_back();
            width = increasing_height.empty()? n : n - increasing_height.back() - 1;
            ret = max(ret, top_height * width);
        }
        return ret;
    }
    void Out(vector<int>& array){
        for(int i : array){
            cout << i << " ";
        }
        cout << endl;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int columns = rows? matrix[0].size() : 0;
        vector<int> heights(columns);
        int maximal_area = 0;
        for(int row = 0; row < rows; row++){
            for(int column = 0; column < columns; column++){
                if(matrix[row][column] == '1') heights[column]++;
                else heights[column] = 0;
            }
            maximal_area = max(LargestRectangleArea(heights), maximal_area); 
        }
        return maximal_area;
    }
};