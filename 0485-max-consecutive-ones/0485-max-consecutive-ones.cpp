class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0;
        int maxi = 0;
        int res;
        
        for(int i=0; i<n ; i++){
            if(nums[i] == 1)
                count1++;
            else{
                int temp = count1;
                maxi = max(maxi , count1 );
                count1 = 0;
            }
        }
        return res = max(maxi,count1);
    }
};