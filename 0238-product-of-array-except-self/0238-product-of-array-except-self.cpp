// t.c & s.c = o(n)

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//        vector<int> left(n,1), right(n,1) , ans(n);
//         int i , j;
        
//         for( i=1; i<n; i++) {
//              left[i] = nums[i-1] * left[i-1];
//         }
        
//         for(j=n-2; j>=0; j--) {
//             right[j] = nums[j+1]*right[j+1];
//         }
//         for (i = 0; i < n; i++){
//            ans[i] = left[i] * right[i];
//         }
//         return ans;
 
//     }
// };

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int n = nums.size();
        vector<int> output;
        if(n<1)
            return output;
        
        int product = 1;
        for(int i = 0 ; i<n ; i++){
            product *= nums[i];
            output.push_back(product);
            
        }
        
//         Traverse from right and update output array
        product = 1;
        for(int i =n-1 ; i>0 ; --i){
            output[i] = output[i-1]*product;
            product *= nums[i];
        }
        output[0] = product;
        return output;
   }
};
