// class Solution {
// public:
//     int maxValue(vector<vector<int>>& piles,int index, int k,vector<vector<int>> &dp){
//         if(index == piles.size() || k == 0){
//             return 0;
//         }
//         if(dp[index][k] != -1){
//             return dp[index][k];
//         }
//         int ans = INT_MIN;
//         int notTaken = maxValue(piles,index+1,k,dp);
        
//         for(int i = 0 ; i<piles[index].size() ; i++){
//             int taken =0;
//             if(k-i >= 0){
//                 taken = piles[index][i]+maxValue(piles,index+1,k-i-1,dp);
//             }
//             ans = max(ans,taken);
//         }
//          int res = max(notTaken,ans);
//          return dp[index][k] = res;
//     }
//     int maxValueOfCoins(vector<vector<int>>& piles, int k) {
//         int n = piles.size();
// //         first we find prefix sum of each piles
//          // [1,100,3] = [1 , 1+100 , 1+100+3] = [1,101,104
//         for(int i = 0 ; i<n ; i++){
//             for(int j = 1 ; j<piles[i].size(); i++){
//                 piles[i][j] += piles[i][j-1];
//             }
//         }
//         vector<vector<int>> dp(n , vector<int>(k+1 , -1));
        
//         return maxValue(piles , 0 , k , dp);
//     }
// };
// T.C = O(M*K) = M Is the sum of no.of coins in each piles
// S.C = O(N*K) = N =  size of piles
class Solution{
    public:
       int maxValue(int i, int k,vector<vector<int>>& piles, vector<vector<int>>&dp){
           if(dp[i][k] > 0) return dp[i][k];
           if(i==piles.size() || k==0) return 0;
           int res = maxValue(i+1 , k,piles,dp) ,curr = 0; 
           //take no coin from ith pile
           for(int j = 0 ; j<piles[i].size() && j<k ; j++){
               curr += piles[i][j];
               res = max(res , maxValue(i+1, k-j-1, piles, dp)+curr);
           }
           dp[i][k] = res ;
           return res;
           
       }
        int maxValueOfCoins(vector<vector<int>>& piles, int k){
            int n= piles.size();
            vector<vector<int>>dp(n+1 ,vector<int>(k+1 ,0));
            return maxValue(0,k,piles,dp);
        }
    
};