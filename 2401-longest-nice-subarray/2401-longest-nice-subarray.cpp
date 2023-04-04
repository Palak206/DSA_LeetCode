class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int used = 0;
        int j = 0;
        int res = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            while ((used & nums[i]) != 0){ // 1 && 3 != 0 sp there is a problem
                //keep remving no. from back sight
                //unless problem is solved
                // bcoz we need ALL PAIR SHOULD BE 0
                used ^= nums[j++]; // we remove 1 in bitset using xor 1 ^1 =0
            }
            //if & will be 0 then just add in subarray
            used |= nums[i]; //setting bits inside num with our current element
            // for max length = (i-j+1) = (3-1+1), ans = 3
            // nums[i=3]= 48 , nums[j=1] = 3
            res = max(res, i - j + 1);
        }
        return res;
        
    }
};