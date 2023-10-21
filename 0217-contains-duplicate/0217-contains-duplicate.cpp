// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         int n = nums.size();
        
//         for(int i=0 ; i<n; i++){
//             for(int j=i+1 ; j<n ;j++){
//               if(nums[i] == nums[j])
//                   return true;
//             }
//         }
//         return false;
//     }
// };

// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
        
//         for(int i =0;i<nums.size()-1;i++){
//             if(nums[i] == nums[i+1]) return true;
//         }
//         return false;
//     }
// };

// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         return nums.size() > set<int>(nums.begin(),nums.end()).size();
//     }
// };

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        
        for(auto i : nums)
            mp[i]++;
        
        for(auto i:mp){
            if(i.second > 1)
                return true;
        }
        return false;
    }
};