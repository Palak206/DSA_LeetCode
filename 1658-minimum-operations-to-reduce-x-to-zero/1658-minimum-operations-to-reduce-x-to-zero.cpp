// // TLE
// //T.C : O(2^n) -  We take and skip each ith and jth index
// //S.C : O(1) excluding Stack space
// class Solution {
//     int minCount;
// public:
    
//     void solve(vector<int>& nums, int x , int count , int i , int j){
       
//         // int leftmost = 0;
//         // int rightmost = n-1;
        
//         if(x == 0){
//             minCount = min(minCount , count);
//             return ;

//         }
//         else if (x<0 || i>j || count >= minCount){
//             return ;
//         }
        
//         else{
//             solve(nums , x-nums[i] ,count+1, i+1 , j );
//             solve(nums , x-nums[j] ,count+1, i , j-1 );
//         }
//     }
//     int minOperations(vector<int>& nums, int x) {
//         int n = nums.size();
//          minCount = INT_MAX;
        
//         solve(nums , x, 0 , 0, n-1);
        
//         if(minCount == INT_MAX)
//             return -1;
        
        
//         return minCount;
//     }
// };


//left  sum-x right
// sum - x is the longest subarray 

class Solution{
    public:
         int minOperations(vector<int>& nums, int x){
             int n = nums.size();
             
             unordered_map<int , int>mp;
             int sum = 0;
             
             mp[0] = -1;
             
             for(int i=0 ; i<n ; i++){
                 sum += nums[i]; //1
                 
                 mp[sum] = i; // index no 0 pr storing in map
             }
             
             if(sum < x)
                 return -1;
             
             int remainSum = sum - x; // 11-5 = 6
             int longestSubArray = INT_MIN;
             
             sum = 0;
             for(int i=0 ; i<n ; i++){
                 sum += nums[i];
                 
                 int findSum = sum - remainSum; //
                 
                 if(mp.find(findSum) != mp.end()){
                     
                     int idx = mp[findSum];
                     
                     longestSubArray = max(longestSubArray , i-idx);
                 }
             }
             return longestSubArray == INT_MIN ? -1 : (n - longestSubArray);
         }
       
};


