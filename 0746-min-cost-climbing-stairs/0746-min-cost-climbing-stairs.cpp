// time limit exceed
// class Solution {
// public:
//     int minCost(vector<int>& cost , int n){
//         if(n <= 1) return 0;// cost = [10] = 0 direct 2 step 
//         if(n == 2)
//             return min(cost[0] , cost[1]);
//         return min(minCost(cost , n-1) + cost[n-1] , //1 jump
//                   minCost(cost , n-2) + cost[n-2]); // 2 jump
//     }
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n= cost.size();
//         return minCost(cost ,n);
        
//     }
// };

// using dp bcoz this ia  repeating 
//                  5
//       n-1     /    \n-2
//              4      3
//            /  \    /  \
//           3    2   2   1 //repeating
//         /  \
//        2    1

vector<int>dp(1001 , -1);
class Solution {
public:
    int minCost(vector<int>& cost , int n){
        if(dp[n] != -1)
            return dp[n];
        if(n <= 1) return dp[n] = 0;// cost = [10] = 0 direct 2 step 
        if(n == 2)
            return dp[n] =  min(cost[0] , cost[1]);
        return dp[n] =  min(minCost(cost , n-1) + cost[n-1] , //1 jump
                  minCost(cost , n-2) + cost[n-2]); // 2 jump
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        fill(dp.begin() , dp.end() , -1);
        return minCost(cost ,n);
        
    }
};