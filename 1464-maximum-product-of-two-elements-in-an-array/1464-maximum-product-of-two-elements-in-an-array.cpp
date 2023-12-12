// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
        
//         int n = nums.size();
//         int res = INT_MIN;
        
//         for(int i=0; i<n; i++){
//             for(int j=i+1 ; j<n; j++){
//                 res = max(res,(nums[i]-1)*(nums[j]-1));
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        int res = INT_MIN;
        sort(nums.begin() , nums.end());
        
        //so now we just have to find 2 largest number
        int x = nums[n-1];
        int y = nums[n-2];
        
        res = (x-1)*(y-1);
            
        
        return res;
    }
};