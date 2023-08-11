// class Solution {
// public:
//     int subarrayGCD(vector<int>& nums, int k) {
        
//     }
// };

class Solution {
public:
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a%b);
    }
    int subarrayGCD(vector<int>& nums, int k) {
         int n = nums.size();
        // int x = 1; 
         int res = 0;
        
        for(int i = 0 ; i<n ; i++){
             int temp = nums[i];
            for(int j = i ; j<n ; j++){
                // if(temp == -1) temp = nums[j];
                // else
                if(nums[j]%k!=0) break;
                temp = gcd(temp , nums[j]);
                if(temp == k)
                    res++;
                
            }
        }
        return res;
        
    }
    
};