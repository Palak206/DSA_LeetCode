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