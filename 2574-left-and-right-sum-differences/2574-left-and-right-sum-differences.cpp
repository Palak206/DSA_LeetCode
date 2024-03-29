class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n,0),right(n,0);
        left[0] = 0;
        right[n-1] = 0;
        
        for(int i=1;i<n;i++){
            left[i] = left[i-1]+nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            right[i] = right[i+1] + nums[i+1];
        }
        for(int i=0;i<nums.size();i++){
            nums[i] = abs(left[i]-right[i]);
        }
        return nums;
    }
};