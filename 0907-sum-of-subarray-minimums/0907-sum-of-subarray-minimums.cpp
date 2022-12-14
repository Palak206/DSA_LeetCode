// Approach 1 : Brute Force Approach Time complexity is O(N* N *N) and space complexity O(1).
// class Solution {
// public:
//     #define mod 1000000007;
//     int sumSubarrayMins(vector<int>& arr) {
//         int sum=0;
//         for(int i=0;i<arr.size();i++){
//             for(int j=i;j<arr.size();j++){
//                 int mini=INT_MAX;
//                 for(int k=i;k<=j;k++){
                    
//                     mini=min(mini,arr[k]);
//                 }
//                 sum=(sum+mini)%mod;
//             }
//         }
//         return sum;
//     }
// };



// class Solution {
// public:
//     // #define mod 1000000007;
//     int mod = 1e9 + 7;
//     int sumSubarrayMins(vector<int>& arr) {
//         int sum=0;
        
//         for(int i=0;i<arr.size();i++){
            
//             int mini=arr[i];
//             for(int j=i;j<arr.size();j++){
                
// //                 if(arr[j] < min_element){

// //                     min_element = arr[j];
// //                 } ans += min_element;

//                 mini=min(mini,arr[j]);
//                sum=(sum+mini)%mod;
//             }
//         }
//         return sum;
//     }
// };

// class Solution{
//     public:
//     int sumSubarrayMins(vector<int>& arr){
//         int n = arr.size();
//         stack<int> s1 , s2;
//         vector<int> next_smaller(n), pre_smaller(n);
//             for(int i = 0 ; i<n ; i++){
//                next_smaller[i] = n-i-1;
//                pre_smaller[i] = i;
//             }
        
//             for(int i = 0 ; i<n ; i++){
//                while (!s1.empty() && arr[s1.top()] > arr[i]){
//                    next_smaller[s1.top()] = i- s1.top()-1;
//                    s1.pop();
//                }
//               s1.push(i);      
//            }
        
// //         RIGHT
//             for(int i = n-1 ; i>=0 ; i--){
//                 while (!s2.empty() && arr[s2.top()] >= arr[i]){
//                    pre_smaller[s2.top()] =  s2.top()-i-1;
//                    s2.pop();
//                 }
//             s2.push(i);           
//             }
//         int ans = 0;
//         int mod = 1e9+7;
//         for(int i = 0 ; i<n ; i++){
//             ans += (arr[i] * (pre_smaller[i]+1) * (next_smaller[i]+1));
//             ans %= mod;
//         }
//         return ans;
    
// }
    
// };


// Optimal Solution
class Solution{
   public:
    int sumSubarrayMins(vector<int> &arr){
    long n = arr.size();
    vector<int>left(n), right(n);
    stack<pair<int,int>>s1,s2;
    for (int i = 0; i < n; i++){
        int count = 1;
        while(!s1.empty() && s1.top().first > arr[i]){
            count += s1.top().second;
            s1.pop();
        }
        s1.push({arr[i], count});
        left[i] = count;
    }
    for (int i = n-1; i >= 0; i--){
        int count = 1;
        while(!s2.empty() && s2.top().first >= arr[i]){
            count += s2.top().second;
            s2.pop();
        }
        s2.push({arr[i], count});
        right[i] = count;
    }

    long res = 0, mod = 1e9 + 7;
    for (int i = 0; i < n; i++)
        res = (res + (long)arr[i]*left[i]*right[i])%mod;

    return res;
}
};
               