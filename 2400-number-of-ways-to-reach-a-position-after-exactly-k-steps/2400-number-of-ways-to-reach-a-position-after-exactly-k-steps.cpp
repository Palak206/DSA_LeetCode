//if start-end is odd so k should be odd then only we can find solution is not no solution
//recursion tree we hve to option either we can go left(-1) nd right(+1) s= 1 e = 2 k=3 
//                            1   
//             l          /       \ r+1 
//                     0            2      1step
//                 /     \        /     \
//            -1          1      1       3     2step 
//        /    \       /    \   /  \    /   \
//     -2      0      0     2  0    2  2    4   3step
//    f       f      f      t  f     t t    f
// f for those not able to reach end point
// t for those who reach the end point
// ans = 3
//T.C = EXPO 0(2^K) S.C = O(K)
//TIME LIMIT EXCEED
// class Solution {
// public:
//     int mod = 1e9+7;
//     int solve(int startPos , int endPos , int k){
//         if(k == 0){
//             //and we reach the end point curr == end return 1 otherwise return 0
//             return startPos == endPos;
            
//         }
//         return (solve(startPos+1 , endPos, k-1)%mod 
//                 + solve(startPos-1 , endPos, k-1)%mod) % mod;
//     }
//     int numberOfWays(int startPos, int endPos, int k) {
//         int diff = endPos - startPos;
//         if(diff % 2 != k%2) return 0;
        
//         return solve(startPos , endPos ,k)%mod;
//     }
// };

//OPTIMIZED
//2 things are changing strtpos and k so make 2d dp
// startpos last -1000 ho skta h and high can be 1000 + 1000 = 2000
class Solution {
public:
    int mod = 1e9+7;
    int dp[1001][5000];
    
    int solve(int startPos , int endPos , int k){
        if(k == 0){
            //and we reach the end point curr == end return 1 otherwise return 0
            return startPos == endPos;
            
        }
        
        if(dp[k][startPos+1000]!=-1)
            return dp[k][startPos+1000];
        
        
        return dp[k][startPos+1000] = (solve(startPos+1 , endPos, k-1)%mod 
                + solve(startPos-1 , endPos, k-1)%mod) % mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp , -1 , sizeof(dp));
        //if start > end then we have to swap
        if(startPos > endPos){
            int t = endPos ;
            endPos = startPos;
            startPos = t;
        }
        
        int diff = endPos - startPos;
        if(diff % 2 != k%2) return 0;
        
        return solve(startPos , endPos ,k)%mod;
    }
};
