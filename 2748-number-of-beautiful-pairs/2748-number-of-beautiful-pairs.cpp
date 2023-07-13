// class Solution {
// public:
//     int gcd(int n1 , int n2){
//         while (n2 != 0) {
//             int res = n2;
//             n2 = n1 % n2;
//             n1 = res;
//         }
//         return n1;
//     }
    
//     int countBeautifulPairs(vector<int>& nums) {
//         int n = nums.size() , ans = 0;
        
//         for(int i=0 ; i<n ; i++){
//             for(int j = i+1 ; j<n ; j++){
//                 string s1 = to_string(nums[i]);
//                 string s2 = to_string(nums[j]);
                
//                 int n1 = s1[0] - '0'; 
//                 int n2 = s2.back() - '0';
                
//                 if (gcd(n1,n2) == 1)
//                     ans++;
//             }
//         }
//         return ans;
//     }
// };


class Solution{
    public:
         int countBeautifulPairs(vector<int>& nums){
             int n = nums.size() , ans = 0;
             
             for(int i=0 ; i<n ; i++){
                 int n1 = nums[i] , n2;
                 while(n1>0){
                     n2 = n1%10;
                     n1/=10;
                 }
                 
                 for(int j=i+1; j<n ; j++){
                     if(__gcd(n2, nums[j]%10) == 1)
                         ans++;
                 }
             }
             return ans;
         }
    
};