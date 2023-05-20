class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxsum= nums[0];
        int currentsum=0;
        
        for( int i=0 ; i<n ; i++)
        {
              currentsum = currentsum+nums[i];
              if(currentsum >= maxsum)
               {
                  maxsum = currentsum;
               }
              if(currentsum < 0)
              {
                  currentsum=0;
              }
        }
        return maxsum;
    }
};