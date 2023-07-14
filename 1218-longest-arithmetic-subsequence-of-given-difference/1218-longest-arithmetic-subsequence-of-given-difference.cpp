class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        
        unordered_map<int,int> dp;
        int ans = 0;
        
        for(int i=0; i<n ; i++){
            int temp = arr[i] - difference;// 5-(-2)   = 7
            //if 7 is present in backward so add the ans of 7 in 1+ans
            
            int tempAns = 0;
            
            if(dp.count(temp))
                tempAns = dp[temp]; // for ex ans of 7 is 1
            
            //current answer update
            dp[arr[i]] = 1+tempAns;
            
            //ans update
            ans = max(ans,dp[arr[i]]);
        }
        return ans;
    }
};