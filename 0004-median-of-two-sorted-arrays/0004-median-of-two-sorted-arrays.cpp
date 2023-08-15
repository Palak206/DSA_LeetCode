class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>n3;
        
        for(int i=0 ; i<nums1.size() ; i++){
            n3.push_back(nums1[i]);
            
        }
        for(int j=0 ; j<nums2.size() ; j++){
            n3.push_back(nums2[j]);
        }
        int n = n3.size();
        sort(n3.begin() , n3.end());
        
        if(n%2 != 0)
            return n3[n/2];
        
        return (n3[(n-1)/2] + n3[n/2])/2.0;
    }
};