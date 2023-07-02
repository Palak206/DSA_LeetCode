// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         vector<int> cnt(nums.size(),0);
//         int ind =  0;
		
// 		// store the cnt of each value in the cnt vector
//         for(int i = 0; i<nums.size(); i++)
//         {
//             cnt[nums[i]]++;
//         }
        
//         for(int i = 0; i<cnt.size(); i++)
//         {
// 			// if cnt[i] > 1
// 			// this means that element occur more than once in nums
// 			// we have to return i
//             if(cnt[i] > 1)
//             {
//                 ind  = i;
//                 break;
//             }
//         }
        
//         return ind;
//     }

// };


class Solution {
    public:
    int findDuplicate(vector<int>& nums){
        int low = 0,high = nums.size() - 1, cnt;
        while(low <= high){
            int mid = low + (high - low)/2;
            cnt = 0;
            for(int num:nums){
                if(num <= mid){
                    cnt++;
                }
            }
            if(cnt <= mid){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
    return low; 
    }
   
};