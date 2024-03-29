// class Solution {
// public:
//     bool search(vector<int>& nums, int target) {
//         for(int i=0 ; i<nums.size() ; i++){
//             if(target == nums[i])
//                 return true;
//         }
//         return false;
//     }
// };


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // sort(nums.begin() , nums.end());
        
        int l = 0 , r = nums.size()-1;
        
        while(l <= r){
            int mid = l + (r - l)/2;
            
            if(nums[mid] == target)
                return true;
            
            // with duplicates we can have this contdition, just update left & right
            if((nums[l] == nums[mid]) && (nums[r] == nums[mid]))
            {
                l++;
                r--;
            }
            
            // first half
			// first half is in order
            else if(nums[l] <= nums[mid])
            {
				// target is in first  half
                if((nums[l] <= target) && (nums[mid] > target))
                    r = mid - 1;
                else
                    l = mid + 1;
            }
			// second half
			// second half is order
			// target is in second half
            else
            {
                if((nums[mid] < target) && (nums[r]>= target))
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            
        }
        return false;
    }
};