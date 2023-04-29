class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans(n);
        
        for(int i=0;i<n;i++){
            ans[(i+k)%n]=nums[i]; // ans[3%7] = ans[3] = n[0]
        }
        nums=ans;
        
        
    }
};