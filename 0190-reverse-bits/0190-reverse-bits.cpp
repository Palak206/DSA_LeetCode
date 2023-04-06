class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int d = 0;
        while(n>0){
            ans += (n%2) << (31-d);
            n >>= 1;
            d++;
        }
        return ans;
    }
};