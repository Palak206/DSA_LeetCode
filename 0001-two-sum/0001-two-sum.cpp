class Solution {
public:
    // Time Complexity : O(N^2)
// Space Complexity :- O(1)
//     vector<int> twoSum(vector<int>& nums, int target) {
//        for(int i=0;i<nums.size();i++)
//      {
//          int curr= nums[i];
//          for(int j=i+1;j<nums.size();j++)
//          {
//              if(nums[i] + nums[j] == target)
//              {
//                  return {i, j};
//              }
//          }
//      }
//   
    // return {-1,-1};
    // Time Complexity : O(N)
    // Space Complexity :- O(N)
 
   vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, int> mp;
       
        for(int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            if(mp.find(diff) == mp.end())
                mp[nums[i]] = i;
            else
                return {mp[diff], i};
        }
 
        return {-1, -1};
    
    }
};