// space = (n-1)*2 + 1
// n= 1 possibilities = 1
// n= 2 space=3 1 k liye pos = 1 sum of 3 = 3+2+1= 6(n(n+1)/2) 6*1 = 6 ans
//  n= 3 space = 5 pos of 2 = 6 sum of 5 = 15 ans= 15*6 = 90
class Solution {
public:
    int M = 1e9+7;
    
    int countOrders(int n) {
        
        if(n == 1)
            return 1;
        
        long long res = 1;
        
        for(int i=2 ; i<=n ; i++){
           int spaces = (i-1)*2 + 1; // s=3
            
           int curr_pos = spaces*(spaces+1)/2; //sum of digits 6
            
           res *= curr_pos;
           
           res %= M;
            
            
        }
        return res;
    }
};