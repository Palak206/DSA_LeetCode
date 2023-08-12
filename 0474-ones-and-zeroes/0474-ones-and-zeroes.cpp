class Solution {
public:
    int solve(vector<string>& strs, int m, int n , int idx ,vector<pair<int,int>>& count
             ,vector<vector<vector<int>>>&dp){
        if(m<0 || n<0)
            return INT_MIN;
        
        if(idx == strs.size() ||(m==0 && n==0))
            return 0;
        
        if(dp[idx][m][n] != -1)
            return dp[idx][m][n];
        
        //if we take ones zeros so m,n will get reduced
        // for taken we add +1 so taking one subset
        int taken = 1+solve(strs,m-count[idx].first, n-count[idx].second,idx+1,count,dp);
        int notTaken = solve(strs,m,n,idx+1,count,dp);
        
        return dp[idx][m][n] = max(taken,notTaken);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        //create count vec to store zeros and ones
        vector<pair<int,int>> count;
        
        for(int i=0 ; i<strs.size() ; i++){
            int zero = 0;
            int one = 0;
            
            for(int j=0 ; j<strs[i].size() ; j++){
                if(strs[i][j] == '0')
                    zero++;
                else
                    one++;
            }
            count.push_back({zero,one});
        }
        
        //cout'0 = count[idx].first ,cout'1 = count[idx].second
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m+1,
                                                      vector<int>(n+1 , -1)));
        return solve(strs,m,n,0,count,dp);
    }
};