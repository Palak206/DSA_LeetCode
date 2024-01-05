// Using recursion time limit exceed
// t.c = o(2^n)
// class Solution {
// public:
//     //if i >= n ho gaya out of bound return 0
//     int solve(int i , int prev ,vector<int>& nums){
//         int n = nums.size();
//         if(i >= n){
//             return 0;
//         }
        
        
//         //take ith element n[p]<n[i] for strictly increasing
//         int take = 0;
//         if(prev == -1 || nums[prev] < nums[i]){
//             //prev = curr[i]
//             take = 1+solve(i+1,i,nums);
//         }
//         //skip the ith elemet
//         int skip = solve(i+1, prev , nums);
        
//         return max(take , skip);
//     }
    
//     int lengthOfLIS(vector<int>& nums) {
//         int n= nums.size();
//         return solve(0,-1 , nums);
//     }
// };

//memo index and prev is changing dp[n+1][n+1] = n*n
//t.c = o(n*n)
class Solution{
public:
    int dp[2501][2501];
    
    int solve(int i , int prev ,vector<int>& nums){
        //if i >= n ho gaya out of bound return 0
        int n = nums.size();
        if(i >= n){
            return 0;
        }
        
        if(prev != -1 && dp[i][prev] != -1){
            return dp[i][prev];
        }
        
        //take ith element n[p]<n[i] for strictly increasing
        int take = 0;
        if(prev == -1 || nums[prev] < nums[i]){
            //prev = curr[i]
            take = 1+solve(i+1,i,nums);
        }
        //skip the ith elemet
        int skip = solve(i+1, prev , nums);
        
        if( prev != -1)
            dp[i][prev] = max(take , skip);
        
        return max(take , skip);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        
        memset(dp,-1,sizeof(dp));
        return solve(0,-1 , nums);
    }
};