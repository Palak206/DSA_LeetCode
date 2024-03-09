// class Solution {
// public:
//     int getCommon(vector<int>& nums1, vector<int>& nums2) {
//         // vector<int>ans;
//         int n = nums1.size();
//         int m = nums2.size();
        
// //         for(int i=0; i<n; i++){
// //             for(int j = 0; j<m; j++){
// //                 if(nums1[i] == nums2[j]){
// //                     ans.push_back(nums1[i]);
// //                 }
// //             }
// //         }
        
// //         return ans[0];
//         int i = 0;
//         int j = 0;
//         while(i < n && j < m){
//             if(nums1[i] < nums2[j]){
//                 i++;
//             }
//             else if(nums1[i] > nums2[j]){
//                 j++;
//             }
//             else{
//                 return nums1[i];
//             }
//         }
//         return - 1;
//     }
// };

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2){
        unordered_set<int>s1(nums1.begin(), nums1.end());
        
        for(int x : nums2){
            if(s1.contains(x)){
                return x;
            }
        }
        return - 1;
    }
};