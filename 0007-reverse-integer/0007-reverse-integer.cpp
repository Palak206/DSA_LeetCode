class Solution {
public:
    int reverse(int x) {
        int rem;
        int res= 0;//long

         while(x !=0){
             if(res>INT_MAX/10||res<INT_MIN/10){
            return 0;
             }
         
           
           rem = x%10;
            res = res*10+rem;
            x /= 10;
         
         }
        
        return res;
    }
};