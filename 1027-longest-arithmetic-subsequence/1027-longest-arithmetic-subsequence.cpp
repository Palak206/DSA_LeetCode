// 1 4 | 5 6 7 10 8
// 4 5 6 7 8
// so brute force approach is we can fix 1st ,2nd element
// 1 4 7 10 increase the lenght by 1 
// t.c = o(n3)

// optimal
// 1 4 = diff = 3 4 -> 3 : 2(lenght) 
// 6 5 diff = 1 6:1(diff):3(length increase by 1)

// we update dp[i][diff] based on whether we have seen a previous arithmetic subsequence ending at index j with a common difference of diff.
// If dp[j].count(diff) returns true, it means we have encountered an arithmetic subsequence ending at index j with the common difference diff. In this case, we update dp[i][diff] to be dp[j][diff] + 1, which extends the subsequence and increments its length by 1.
// If dp[j].count(diff) returns false, it means we haven't seen an arithmetic subsequence ending at index j with the common difference diff. In this case, we initialize dp[i][diff] to 2 because we have found a new arithmetic subsequence of length 2 (nums[j], nums[i]).
// After updating dp[i][diff], we check if the current length dp[i][diff] is greater than the current longest arithmetic subsequence length longest. If so, we update longest to the new maximum length.
// Once we finish iterating through all pairs of indices, we have computed the lengths of all possible arithmetic subsequences ending at each index. The maximum length among these subsequences is stored in longest, so we return it as the result.
// dp[i][diff] = dp[j].count(diff) ? dp[j][diff] + 1 : 2;



class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

            if(n <= 2)
             return n;
             
         unordered_map<int,int> dp[n+1];

         for(int i=1;i<n;i++){//1st element
             for(int j=0;j<i;j++){//2nd element

                 int diff = nums[i]-nums[j];
                 int cnt = 1;

                 if(dp[j].count(diff))
                  cnt = dp[j][diff];

                  dp[i][diff] = 1 + cnt;  
                  ans = max(ans,dp[i][diff]);
             }
         }

        return ans;
    }
};