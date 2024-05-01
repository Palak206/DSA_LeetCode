class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        for(int i=0; i<k; i++){
            sum += nums[i];
        }
        double ans = sum;
        for(int j = k; j<nums.size(); j++){
            sum += nums[j];
            
            sum -= nums[j-k];
            
            ans = max(ans,sum);
        }
        return ans/k;
    }
};