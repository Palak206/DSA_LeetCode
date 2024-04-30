// class Solution {
// public:
//     int maxOperations(vector<int>& nums, int k) {
//         int n = nums.size();
//         int count = 0;
        
//         for(int i=0; i<n; i++){
            
//             if(nums[i] == -1)
//                 continue;
            
//             for(int j=i+1; j<n; j++){
//                 if(nums[j] == -1)
//                   continue;
//                 if(nums[i] + nums[j] == k){
//                     count++;
//                     nums[i] = -1;
//                     nums[j] = -1;
//                     break;
//                 }
//             }
//         }
//         return count;
//     }
// };


// class Solution {
// public:
//     int maxOperations(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end());
        
//         int n = nums.size();
//         int i=0, j=n-1;
        
//         int count = 0;
        
//         while(i<j){
//             if(nums[i]+nums[j] == k){
//                 count++;
//                 i++;
//                 j--;
//             }
            
//             else if(nums[i]+nums[j] > k){
//                 j--;
//             }
//             else{
//                 i++;
//             }
//         }
        
//         return count;
//     }
// };


// For every element check if (K - nums[i]) is present in the map. If it is there then we got a pair ,and we decrease the frequency of (K - nums[i]) by 1 since we used one occurence of this element.
// If we did not find (K - nums[i]) with frequency greater than zero, then we put our current element in the hashmap too.

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int count = 0;
        
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            int diff = k-nums[i];
            
            if(mp[diff] > 0){
                count++;
                mp[diff]--;
            }
            else{
                mp[nums[i]]++;
            }
        }
        
        return count;
    }
};
