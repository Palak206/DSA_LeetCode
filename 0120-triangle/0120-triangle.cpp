class Solution {
public:
    //bottom up to top
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int>dp(n,0);
        
        for(int i=0 ;i<n; i++){
            dp[i] = triangle[n-1][i];//0 , 1 , 2 ,3
        }
        
        for(int i=n-2; i>=0 ; i--){ // 0,1,2 bottom up to top
            for(int j=0; j<triangle[i].size(); j++){
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j]; //1<4 so 1+6=7
            }
        }
        return dp[0];
    }
};