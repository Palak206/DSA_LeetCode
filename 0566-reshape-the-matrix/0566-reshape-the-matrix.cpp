class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> ans(r , vector<int>(c,0));
        int row=0, col=0;
        
        if(m*n != r*c) 
            return mat; //for 2nd test case 
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                ans[row][col] = mat[i][j];
                col++;
                
                if(col == c){
                    row++; //then moce to 2nd row
                    col=0; //row 1 col = 0
                }
                    
            }
        }
        return ans;
    }
};