class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int rows = matrix.size(), cols = matrix[0].size(),
            left = 0, right = cols - 1;
			
        while (left < rows && right > -1) {
            int cur = matrix[left][right];
            if (cur == target) 
                return true;
            if (target > cur) 
                left++;
            else 
                right--;
        }
        
        return false;
     
    }
};