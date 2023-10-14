//greedy [1 2 3 2] 
// time  [1 2 3 2]
// paid time 1 h to sbse mhnge bala free me krega that is 3 remove it 
// then take  = 1+2 = 3 remove 2

// cost [3 1 1 1 1 1 1 1]
//time  [7 1 1 1 1 1 1 1]
//using greedy so for pid we take that cost that is cheap so take 1 and time 1
//then remove 3 7
// using this 1+1+1+1 = 4ns

//non greedy
//suppose we take cost 3 for pid panter and he took 7 days t complete
// so free painter complete 7 days in free and all the 1's remove
//ans is 3 
//here greedy is fail

// walls = 8 - 1 - 1
// total walls-(paid)-occupied time(free painter)

//solve(idx , remain)
//if remain <=0 return 0
// if idx >=n return infinite

//if not then  2 option pint or not paint
//if paint = cost[idx]+ solve(idx+1 , rem-1-time[idx])
//if not =  solve(idx+1 , rem)
// return min(paint , no_paint)
// class Solution {
// public:
//     int n;
//     int solve(int idx ,int remain , vector<int>& cost, vector<int>& time ){
//         if(remain <= 0)
//             return 0;
        
//         if(remain >= n){
//             return 1e9;//invalid case out of the bound
//         }
        
//         int paint = cost[idx] + solve(idx+1 , remain - 1 - time[idx], cost , time);
//         int no_paint = solve(idx+1 , remain , cost , time);
        
//         return min(paint ,no_paint);
//     }
    
//     int paintWalls(vector<int>& cost, vector<int>& time) {
//          n = cost.size();//remaining balls 4
        
//         return solve(0, n , cost , time);
//     }
// };

//memo
class Solution {
public:
    
    int dp[501][501];
    int solve(int idx ,int remain , vector<int>& cost, vector<int>& time ){
        if(remain <= 0)
            return 0;
        
        if(idx >= cost.size()){
            return 1e9;//invalid case out of the bound
        }
        
        if(dp[idx][remain] != -1){
            return dp[idx][remain];
        }
        
        int paint = cost[idx] + solve(idx+1 , remain - 1 - time[idx], cost , time);
        int no_paint = solve(idx+1 , remain , cost , time);
        
        return  dp[idx][remain]  = min(paint ,no_paint);
    }
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();//remaining balls 4
        memset(dp , -1, sizeof(dp));
        
        return solve(0, n , cost , time);
    }
};