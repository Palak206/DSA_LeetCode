// class Solution {
// public:
//     int subarrayLCM(vector<int>& nums, int k) {
//         unsigned int n = nums.size();
//         // int x = 1; 
//         unsigned int res = 0;
        
//         for(int i = 0 ; i<n ; i++){
//             unsigned int temp = nums[i];
//             for(int j = i ; j<n ; j++){
//                 temp = lcm(temp , nums[j]);
//             if(temp == k)
//                 res++;
//             }
//         }
//         return res;
        
//     }
// };

class Solution {
public:
    int lcm(int a, int b){
        int g = gcd(a,b);
        return a*b/g;
    }
    int subarrayLCM(vector<int>& nums, int k) {
         int n = nums.size();
        // int x = 1; 
         int res = 0;
        
        for(int i = 0 ; i<n ; i++){
             int temp = -1;
            for(int j = i ; j<n ; j++){
                if(temp == -1) temp = nums[j];
                else
                   temp = lcm(temp , nums[j]);
                if(temp == k)
                    res++;
                if(temp > k)
                    break;
            
            }
        }
        return res;
        
    }
    
};