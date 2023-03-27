class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> prefSum(n+1, 0);
        for(int i=0;i<n;i++){
             prefSum[i+1] = prefSum[i] + nums[i];
        }
        nums.insert(nums.begin(), 0);
        n++;
        vector<long long> ans;
        for(auto q : queries){
        long long lidx = lower_bound(nums.begin(), nums.end(), q) - nums.begin() - 1;
            long long uidx = upper_bound(nums.begin(), nums.end(), q) - nums.begin();
            long long val = q*lidx - (prefSum[lidx] - prefSum[0]);
            if(uidx!=n){
                val += (prefSum[n-1] - prefSum[uidx-1]) - q*(n-uidx);
            }
        ans.push_back(val);
        }
        return ans;
    }
};