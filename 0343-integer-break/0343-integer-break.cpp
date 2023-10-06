//  n =        5    *     *
      // (1,4) (2,3) (3,2) (4,1) 
         // |
 // (1,3) (2,2) (3,1)

// i*(n-i) or i*solve(n-i)
//ans = i * max(n-i , solve(n-i))
             
//T.C= o(n * n^n-1)

// class Solution {
// public:
//     int solve(int n){
//         if(n == 1)
//             return 1; // we can't break it further
        
//         int res = INT_MIN;
        
//         for(int i=1 ; i<=n-1 ; i++){
//            int prod = i * max(n-i , solve(n-i));
//            res = max(res , prod);
//         }
//         return res;
//     }
    
//     int integerBreak(int n) {
//         return solve(n);
//     }
// };

//memo
class Solution {
public:
    int t[59];
    int solve(int n){
        if(n == 1)
            return 1; // we can't break it further
        
        if(t[n] != -1)
            return t[n]; // alredy solved tree diagram stored 3 already(1,2)
        int res = INT_MIN;
        
        for(int i=1 ; i<n ; i++){
           int prod = i * max(n-i , solve(n-i));
           res = max(res , prod);
        }
        return t[n] = res;
    }
    
    int integerBreak(int n) {
        memset(t, -1,sizeof(t));
        return solve(n);
    }
};