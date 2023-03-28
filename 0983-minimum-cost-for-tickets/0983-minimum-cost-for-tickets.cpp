// class Solution {
// public:
//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         int n = day.size();
//         vector<int>dp(n);
//         dp[0] = min({cost[1], cost[7] , cost[30]});
        
//         for(int i = 0 ; i<n ; i++){
//             int last7 = i ,last30 = i;
//             // last7 = going to the last day before 7 days
//             // last30 = going to the last day before 30 days that is ultimately 0
//             while(last7>=0 && days[last7]+7 > days[i]) last7--;
//             while(last30>=0 && days[last30]+7 > days[i]) last30--;
            
            
//             dp[i] = cost[0] + dp[i-1];  //1 day ticket
            
//             if(last7 != -1)
            
//         }
         
//     }
// };

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(366, INT_MAX);
        dp[0] = 0;
        int j = 0;
        for (int i = 1; i <= 365; i++) {
            if (j < n && i == days[j]) {
                dp[i] = min(dp[i], dp[i-1] + costs[0]);
                if (i >= 7) 
                    dp[i] = min(dp[i], dp[i-7] + costs[1]);
                else 
                    dp[i] = min(dp[i], costs[1]);
                if (i >= 30) 
                    dp[i] = min(dp[i], dp[i-30] + costs[2]);
                else 
                    dp[i] = min(dp[i], costs[2]);
                j++;
            } 
            else {
                dp[i] = dp[i-1];
            }
        }
        return dp[365];
    }
};