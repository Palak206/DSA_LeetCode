class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n  = nums.size();
        unordered_map<int,int>mp;
        int count = 0;
        
        int i = 0;
        int j = 0;
        int res = 0;
        
        while(j<n){
            mp[nums[j]]++;
            
            while(i<j && mp[nums[j]] > k){
                mp[nums[i]]--; // freq of 1 = 3 <k then freq--
                i++;
            }
            res = max(res, j-i+1);
            j++;
        }
        return res;
    }
};