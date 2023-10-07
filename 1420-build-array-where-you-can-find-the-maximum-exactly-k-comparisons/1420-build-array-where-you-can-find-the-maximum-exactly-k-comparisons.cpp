// //length fixed h k = 2 longest increasing susequence x  , x , y , z, h ..
// // search_cost should ebe equal to k that is the ques
// // array is no given we have to make it
// //we have option there from 1 to n we can put 1 , 2 , 3 = m for loop

// // tree diagram      index(m=3) searchcost = 0, maxvl = -1
// //              1       2         3
// //       1>-1 so max_val = 1 , search_cost = 1
// // options 1,   (1,2,3)
// //       (1, 1) max_val = 1 s_c = 1 =k 1 answe
// //searchcost = k

//T.C = O(N^M)
// class Solution {
// public:
//     int N , M , K;
//     int MOD = 1e9+7;
    
//     int solve(int idx, int search_cost , int max_val){
//         if(idx == N){
//             if(search_cost == K){
//                 return 1;  //search_cost = search_cost+1 0+1=1
//             }
//             //if not 
//             return 0;
//         }
        
//         int res = 0;
        
//         for(int i=1 ; i<=M ; i++){
//             if(max_val < i){
//                 res = (res + solve(idx+1, search_cost+1, i)) % MOD ;//update mxval = i
//                 //3D dp use bcoz 3 things are changing
//             }
//             else{
//                 res =  (res + solve(idx+1, search_cost , max_val)) % MOD;
//             }
//         }
//         return res%MOD;
//     }
//     int numOfArrays(int n, int m, int k) {
//         N = n;
//         M = m;
//         K = k;
        
//         return solve(0,0,0);
//     }
// };


//length fixed h k = 2 longest increasing susequence x  , x , y , z, h ..
// search_cost should ebe equal to k that is the ques
// array is no given we have to make it
//we have option there from 1 to n we can put 1 , 2 , 3 = m for loop

// tree diagram      index(m=3) searchcost = 0, maxvl = -1
//              1       2         3
//       1>-1 so max_val = 1 , search_cost = 1
// options 1,   (1,2,3)
//       (1, 1) max_val = 1 s_c = 1 =k 1 answe
//searchcost = k

class Solution {
public:
    int N , M , K;
    int MOD = 1e9+7;
    int dp[51][51][101];
    
    int solve(int idx, int search_cost , int max_val){
        if(idx == N){
            if(search_cost == K){
                return 1;  //search_cost = search_cost+1 0+1=1
            }
            //if not 
            return 0;
        }
        
        if(dp[idx][search_cost][max_val] != -1)
            return dp[idx][search_cost][max_val];
        
        int res = 0;
        
        for(int i=1 ; i<=M ; i++){
            if(max_val < i){
                res = (res + solve(idx+1, search_cost+1, i)) % MOD ;//update mxval = i
                //3D dp use bcoz 3 things are changing
            }
            else{
                res =  (res + solve(idx+1, search_cost , max_val)) % MOD;
            }
        }
        return dp[idx][search_cost][max_val] =  res%MOD;
    }
    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;
        
        memset(dp , -1 , sizeof(dp));
        
        return solve(0,0,0);
    }
};