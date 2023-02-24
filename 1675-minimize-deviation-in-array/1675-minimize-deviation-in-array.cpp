// class Solution {
// public:
//     int minimumDeviation(vector<int>& nums) {
//         sort(nums.begin() , nums.end());
//         int ans;
//         int n = nums.size();
//         int max = nums[n-1] ;
//         int min = nums[0];
        
       
        
//         if(max % 2 == 0)
//             max = max/2;
//         if(min % 2 != 0)
//             min = min*2;
//         // }
        
        
//         ans = max - min;
//         return ans;
        
        
//     }
// };

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        
        int n = nums.size();
        int maxe = INT_MIN ;
        int mine = INT_MAX ;
        
        priority_queue<int> pq;
        for(int i = 0 ;i<n ; i++){
            if(nums[i] %2 != 0){
                nums[i] = nums[i]*2;
            }
            maxe = max(maxe,nums[i]);
            mine = min(mine,nums[i]);
            
            pq.push(nums[i]);
        
        }
        int ans = maxe - mine;
        
        while(pq.top() % 2 == 0){
            int top = pq.top(); pq.pop();
            ans = min(ans , top-mine);
            top /= 2;
            mine = min(mine , top);
            pq.push(top);
        }
        ans = min(ans, pq.top() - mine);
        return ans;
 }
};
