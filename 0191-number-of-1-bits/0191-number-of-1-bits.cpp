class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        
        while(n != 0){
            count += (n%2);
            n >>= 1;  //n = n/2
//             n = 11 first change bit num to integer
//             n = 11/2 rem = 1
        }
        
        return count;
    }
};