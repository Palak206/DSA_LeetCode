// class Solution {
// public:
//     int findMaxK(vector<int>& nums) {        
//         int maxi = -1;
//         for(int i=0; i<nums.size(); i++){
//             for(int j=i+1; j<nums.size(); j++){
//                 if(nums[i] == (-nums[j])){
//                     maxi = max(maxi , abs(nums[i]));
//                 }
//             }
//         }
//         return maxi;
//     }
// };

// class Solution {
// public:
//     int findMaxK(vector<int>& nums) {        
//         sort(nums.begin(), nums.end());
        
//         int i = 0;
//         int j =nums.size()-1;
        
//         while(i<j){
//             if((-nums[i]) == nums[j]){
//                 return abs(nums[j]);
//             }
            
//             else if((-nums[i]) > nums[j]){
//                 i++;
//             }
//             else{
//                 j--;
//             }
//         }
//         return -1;
//     }
// };

// T.C = O(N)

class Solution {
public:
    int findMaxK(vector<int>& nums) {        
        unordered_set<int>st;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < 0)
                st.insert(nums[i]);
        }
        
        int res = -1;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > res && st.contains(-nums[i])){
                res = nums[i];
            }
        }
        return res;
    }
};