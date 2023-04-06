// class Solution {
// public:
//     uint32_t reverseBits(uint32_t n) {
//         uint32_t ans = 0;
//         int d = 0;
//         while(n>0){
//             ans += (n%2) << (31-d);
//             n >>= 1;
//             d++;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    bool findKthbitset(int k , uint32_t n){
        if(((1 << (k-1) & n) != 0)) return true;
        return false;
    }
           
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int i = 1 ; i<=32 ; i++){
            if(findKthbitset(i , n)){ //check current set is 1 or not
                //set a bit
                ans = 1 << (32-i) | ans;
            }
        }
        return ans;
    }
};