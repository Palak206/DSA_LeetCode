class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
//         int diff;
//         int min_diff = 0;
        
//         if(n == 1 )
//             return 0;
        
//         for(int i=0 ; i<=n-k ; i++){
//             int min_val = 0;
//             int max_val = 0;
            
//             for(int j= i ; j<i+k ; j++){
//                 min_val = min(min_val , nums[j]);
//                 max_val = max(max_val , nums[j]);
//             }
//                 diff = max_val - min_val;;
//                 min_diff = min(min_diff, diff);
            
//         }
//         return min_diff;
        
        
        
        sort(nums.begin(),nums.end());
        if(n == 1)
            return 0;
        int ans=INT_MAX;
        int diff;
        
        for(int i=0; i<=n-k; i++)
        {
            diff = nums[i+k-1]-nums[i];
            ans=min(ans , diff);
        }
        return ans;
    }
};