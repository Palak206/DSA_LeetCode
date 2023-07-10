// t.c = o(mlogm) s.c = o(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0; i<n; i++){
            nums1[m+i] = nums2[i];
        }
        // nums1[3+0] = nums2[0]
        // nums1[3] = [1 , 2 , 3 , 2]
        // nums1[3+1] = [1, 2,3 ,2 , 5]
         // nums1[3+2] = [1, 2,3 ,2 , 5 , 6]
        // sort = [1 , 2 ,2 ,3 ,5 ,6]

        
        sort(nums1.begin(), nums1.end());
    }
};

// using 2 pointers
// t.c = o(m+n) s.c = o(1)
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int i = m-1;
//         int j = n-1;
//         int k = m+n-1;
//         while(i>=0 && j>=0){
//             if(nums1[i] > nums2[j]){
//                 nums1[k] = nums1[i];
//                 i--; k--;
//             }
//             else{
//                 nums1[k] = nums2[j];
//                 j--; k--;
//             }
//         }
//         while(j>=0){
//             nums1[k] = nums2[j];
//             j--; k--;
//         }
//     }
// };