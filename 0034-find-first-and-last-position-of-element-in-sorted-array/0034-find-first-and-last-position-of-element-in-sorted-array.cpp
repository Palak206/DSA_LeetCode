class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                ans.push_back(i);
                break;
            }
        }
        for(int j=n-1;j>=0;j--){
            if(nums[j]==target){
                ans.push_back(j);
                break;
            }
        }
        if(ans.size()==0){
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};
        
