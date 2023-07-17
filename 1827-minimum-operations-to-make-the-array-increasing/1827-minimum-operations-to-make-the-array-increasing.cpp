class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        if(n == 1)
            return 0;
                
        for(int i=1; i<n ; i++){
            // count = nums[i-1] - nums[i] + 1;
            // 1 5 2 4 1
            // 1 5 6 4 1 (2<5) 5-2+1 = 4+2 = 6
            // 1 5 6 7 1 (4<6) 6-4+1 = 3+4 = 7
            // 1 5 6 7 8 (1<7) 7-1+1 = 7+1 = 8
            if(nums[i] <= nums[i-1]){ // 2 < 5
                int change = nums[i-1] - nums[i] + 1;// 5-2+1 = 4 
                count += change; //0+3
                nums[i] += change; // 4+2=6 
            }
            
            
        }
        return count;
    }
};