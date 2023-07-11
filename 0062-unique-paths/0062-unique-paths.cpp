class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int>(n , 1));
        // we can take ant value initially but we take 1 directly
        //bcoz we have add 1 in all the boxes so initially i 'll make all box 1's
        
        for(int i=1 ; i<m  ; i++){
            for(int j=1 ; j<n ; j++){
                dp[i][j] = dp[i][j-1]+dp[i-1][j];
                //(1 , 4) = dp[1][3]+dp[0][4] = 4+1 = 5
            }
        }
        return dp[m-1][n-1];//last element
    }
};