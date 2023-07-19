// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         int sum = accumulate(nums.begin(), nums.end(), 0); 
        
//         if (sum%2 != 0) return false; 
//         bitset<20001> bits(1); 
        
//         for (auto &num : nums) 
//             bits |= bits << num; 
        
//         return bits[sum/2]; 
//     }
    
// };
   

class Solution {
   public:
    bool solve(int index , vector<int>& nums ,int target){
        //base case
        if(index >= nums.size())
            return 0;
        if(target < 0)
            return 0;
        if(target == 0)
            return 1;
        //include case
        //we can do include using sum also sum = 0 sum += nums[i]
        // 0+1 = 1
        //1+5 = 6//incl
        //6+11 = 17>11 excl index++
        // 6+5 = 11 = 11 incl
        
        bool incl = solve(index+1 ,nums , target - nums[index]);//11-1= 10
        bool excl = solve(index+1 , nums , target -0);//11-0
        
        return incl || excl;
    }
    
     bool solveMem(int index , vector<int>& nums ,int target, vector<vector<int>>&dp){
        //base case
        if(index >= nums.size())
            return 0;
        if(target < 0)
            return 0;
        if(target == 0)
            return 1;
        //include case
         //bcoz 2 thins ar changing index and target so it's a 2d array
         if(dp[index][target] != -1)
             return dp[index][target];
         
        
        bool incl = solveMem(index+1 ,nums , target - nums[index],dp);//11-1= 10
        bool excl = solveMem(index+1 , nums , target -0, dp);//11-0
        
        return dp[index][target] = incl or excl;;
    }
    
    bool canPartition(vector<int>& nums){
        int n= nums.size();
        int sum =0;
        
        for(int i=0 ; i<n ; i++){
            sum += nums[i];
        }
        
        if(sum%2 != 0) return false;
        
        int target = sum/2; //11
        
        for(int i=0 ;i<n ; i++){
            
        }
        
        // return solve(0 , nums , target);
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return solveMem(0, nums , target , dp);
    }
};
