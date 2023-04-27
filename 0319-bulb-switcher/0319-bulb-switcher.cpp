// in the 1st iteration we on all the bulb
// in the 2nd iteration we on multiple of 2  bulb
// in the 3rd iteration we on multiple of 3  bulb


class Solution {
public:
    int bulbSwitch(int n) {
        int count = 0;
        int i = 1;//multiple of ith
        
        while((i*i)<=n){
            i++;
            count++;
        }
            
        return count;
            
        
    }
};