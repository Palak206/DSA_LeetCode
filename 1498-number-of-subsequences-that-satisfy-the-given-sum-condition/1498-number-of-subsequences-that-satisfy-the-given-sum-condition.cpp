class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int res = 0, mod = 1e9+7, lt = 0, rt = nums.size() - 1;
        vector<int> pre = {1};
        for (auto i = 1; i <= nums.size(); ++i)
            pre.push_back((pre.back() << 1) % mod);   
                
        sort(begin(nums), end(nums));
        
        while (lt <= rt) {
            if (nums[lt] + nums[rt] > target) {
                rt--;
            } else {
                res = (res + pre[rt - lt++]) % mod;
            }
        }

        return res;
    }
};