// (head-tail) for deleted element
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i =0, j=0, res=0, count=0;
        
        for(i =0; i<nums.size() ; i++){
            if(nums[i] == 0)
                count++;
            
            while(count > 1){// that means we got 0 element
                if(nums[j] == 0) count--;//valid case
                j++;
                
            }
            res = max(res,i-j);
        }
        return res;
    }
};