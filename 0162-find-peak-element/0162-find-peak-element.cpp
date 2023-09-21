class Solution {
public:
//     int findPeakElement(vector<int>& nums) {
//         int n = nums.size();
//         for(int i=0; i<n-1; i++){
//             if(nums[i]>nums[i+1])return i;
//         }
//         return nums.size()-1;
//         // return 0;
//     }
// };

// . One Liner :
// Time Complexity : O(n)
// Space Complexity : O(1)

int findPeakElement(vector<int>& nums) {
        return max_element(nums.begin(), nums.end())-nums.begin();
    }
};

// 2. Binary Search :
// Time Complexity : O(logn)
// Space Complexity : O(1)

// int findPeakElement(vector<int>& nums) {
//         int low=0, high=nums.size()-1, mid;
//         while(low<high){
//             mid=(low+high)/2;
//             if(nums[mid]>nums[mid+1])
//                 high=mid;
//             else low=mid+1;
//         }
//         return low;
//     }
// };