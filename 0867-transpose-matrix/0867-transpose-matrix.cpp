// class Solution {
// public:
//     vector<vector<int>> transpose(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();
        
//         vector<vector<int>> res(m ,vector<int>(n));
        
//         for(int i=0 ; i<n ; i++){
//             for(int j=0 ; j<m; j++){
//                  res[i][j] = matrix[j][i];
//             }
//         }
//         return res;

//     }          
// };

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> result(col, vector<int>(row, 0));
        
        for (int i = 0; i < col; ++i) {
            for (int j = 0; j < row; ++j) {
                result[i][j] = matrix[j][i];
            }
        }
        
        return result;
    }
};