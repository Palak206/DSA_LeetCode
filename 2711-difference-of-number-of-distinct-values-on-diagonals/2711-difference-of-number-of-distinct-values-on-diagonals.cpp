class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size();
        int n= grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                int x = i + 1, y = j + 1;
                set<int>st1;
                //consider {i, j} as top-left cell 
                while(x < m && y < n) //keep going bottom right
                {
                    st1.insert(grid[x][y]);
                    x++;
                    y++;
                }
                //consider {i, j} as bottom right cell 
                x = i - 1; y = j - 1;
                set<int>st2;
                while(x >= 0 && y >= 0) //keep going top left
                {
                    st2.insert(grid[x][y]);
                    x--;
                    y--;
                }
                int topLeft = st1.size(), bottomRight = st2.size();
                ans[i][j] = abs(topLeft - bottomRight);
                
            }
        }
        return ans;
          
    }
};