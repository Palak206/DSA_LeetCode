// time limit exceed
// class Solution {
// public:
//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         int n = days.size();
//         vector<int>dp(n);
//         dp[0] = min({costs[1], costs[7] , costs[30]});
        
//         for(int i = 1 ; i<n ; i++){
//             int last7 = i ,last30 = i;
//             // last7 = going to the last day before 7 days
//             // last30 = going to the last day before 30 days that is ultimately 0
//             while(last7>=0 && days[last7]+7 > days[i]) last7--;
//             while(last30>=0 && days[last30]+30 > days[i]) last30--;
            
            
//             dp[i] = costs[0] + dp[i-1];  //1 day ticket
            
//             if(last7 != -1) dp[i] = min(dp[i] , costs[1] + dp[last7]); // - 7 days pass
//             else dp[i] = min(dp[i] , costs[1]);

//             if(last30 != -1) dp[i] = min(dp[i] , costs[2] + dp[last30]); // - 30 days pass
//             else dp[i] = min(dp[i] , costs[2]);
            
//         }
//         return dp[n-1] ;
//     }
// };
// TIME C = O(N) N IS THE NO OF TRAVEL DAYS
// S.C = O(30+7) = O(1)
class Solution {
public:
       int mincostTickets(vector<int>& days, vector<int>& costs, int cost = 0) {
       queue<pair<int, int>> last7, last30;
       for (auto d : days) {
         while (!last7.empty() && last7.front().first + 7 <= d) last7.pop();
//            keep n removing from queue untill we get last required day
         while (!last30.empty() && last30.front().first + 30 <= d) last30.pop();
           
         last7.push({ d, cost + costs[1] });
         last30.push({ d, cost + costs[2] });
           
         cost = min({ cost + costs[0], last7.front().second, last30.front().second });
                        // 1 DAY PASS       2nd DAY PASS           3rd DAY PASS
       }
       return cost;

    }
};

// class Solution {
// public:
//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         int n = days.size();
//         vector<int> dp(366, INT_MAX);
//         dp[0] = 0;
//         int j = 0;
//         for (int i = 1; i <= 365; i++) {
//             if (j < n && i == days[j]) {
//                 dp[i] = min(dp[i], dp[i-1] + costs[0]);
//                 if (i >= 7) 
//                     dp[i] = min(dp[i], dp[i-7] + costs[1]);
//                 else 
//                     dp[i] = min(dp[i], costs[1]);
//                 if (i >= 30) 
//                     dp[i] = min(dp[i], dp[i-30] + costs[2]);
//                 else 
//                     dp[i] = min(dp[i], costs[2]);
//                 j++;
//             } 
//             else {
//                 dp[i] = dp[i-1];
//             }
//         }
//         return dp[365];
//     }
// };