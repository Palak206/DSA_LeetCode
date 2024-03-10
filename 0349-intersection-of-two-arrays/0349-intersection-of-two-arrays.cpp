// class Solution {
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         sort(nums1.begin(), nums1.end());
//         sort(nums2.begin(), nums2.end());
        
//         set<int>s;
//         int i=0 , j= 0;
//         int n = nums1.size();
//         int m = nums2.size();
        
//         while(i < n && j < m){
//             if(nums1[i] < nums2[j]){
//                 i++;
//             }
//             else if(nums1[i] > nums2[j]){
//                 j++;
//             }
//             else{
//                 s.insert(nums1[i]);
//                 i++;
//                 j++;
//             }
//         }
//         vector<int>ans;
//         for(auto x : s)
//             ans.push_back(x);
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1(nums1.begin(), nums1.end());
        set<int>s2(nums2.begin(), nums2.end());
        
        vector<int>ans;
        
        for(auto x : s1){
            if(s2.find(x) != s2.end())
                ans.push_back(x);
        }
        
        return ans;
    }
};