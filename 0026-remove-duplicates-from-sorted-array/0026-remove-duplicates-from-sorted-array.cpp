class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int n = nums.size();
         int ind=0;
   if(n == 0)  
       return 0;
    for(int i=0; i<n;i++){
        if(nums[ind]!=nums[i]){
            nums[++ind]=nums[i];
        }
    }
    return ind+1;

    }
};