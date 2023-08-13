// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int n = obstacleGrid.size();
//         int m = obstacleGrid[0].size();
        
//         if(obstacleGrid[0][0] || obstacleGrid[n-1][m-1])
//             return 0;
        
//         vector<vector<int>> dp(n , vector<int>(m , 0));
//         dp[0][0]=1;
        
//         for(int i=1;i<n;i++){
//             if(obstacleGrid[i][0])
//                 dp[i][0]=0;
//             else 
                // dp[i][0]=dp[i-1][0];
//         }
//         for(int i=1;i<m;i++){
//             if(obstacleGrid[0][i])
//                 dp[0][i]=0;
//             else 
                // dp[0][i]=dp[0][i-1];
//         }
        
//         for(int i=1 ; i<n  ; i++){
//             for(int j=1 ; j<m ; j++){
//                 if(!obstacleGrid[i][j]) 
//                     dp[i][j] = dp[i][j-1]+dp[i-1][j];
//                 //(1 , 4) = dp[1][3]+dp[0][4] = 4+1 = 5
//             }
//         }
//         return dp[n-1][m-1];//last element
//     }
// };

// if it's visited temp = grid[i][j]
//                grid[i][j] = -1;
// then we return grid[i][j] = temp00
//t.c = o(m*n)
class Solution {
public:
    int m, n;
    int dp[101][101];
    
    //i , j will never go <0 bcoz we only down and right
    int solve(vector<vector<int>>& obstacleGrid , int i , int j){
        //out of bound  obstacle
        if(i<0 || i>=m || j<0 || j>=n || obstacleGrid[i][j] == 1){
            return 0;
        }
        
        //if we already find the answer of the sell means we visit it already
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(i == m-1 && j == n-1)
            return 1; //if we reach at the end grid[m-1][n-1] we complete the path
        
        int right = solve(obstacleGrid , i , j+1);
        int down = solve(obstacleGrid ,i+1 , j);
        
        return dp[i][j] =  right+down;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
         m = obstacleGrid.size();
         n = obstacleGrid[0].size();
        
        memset(dp , -1, sizeof(dp));
        return solve(obstacleGrid, 0 ,0);
    }
};