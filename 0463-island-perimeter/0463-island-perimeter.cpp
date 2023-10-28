// if there is 1 box ans = 4
//if 2 box up down 4-2+4=6
//if 3 1 up 1 down 1 left 4+4+4-4 = 8

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int ans = 0;
        
        for(int i=0 ; i<n ; i++){
            for(int j=0; j<m ; j++){
                //if there is one island
                if(grid[i][j] == 1){
                    ans += 4;
                    
                    //nums[i-1][j] above component
                    //nums[i][j-1] left comp
                    if(i>0 && grid[i-1][j] == 1) //above island
                        ans -= 2;
                    if(j>0 && grid[i][j-1] == 1) //left island
                        ans -= 2;
                        
                }
            }
        }
        return ans;
    }
};