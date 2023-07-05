// (head-tail) for deleted element
// T.C = O(N^2) & S.C = O(1)
// class Solution {
// public:
//     int longestSubarray(vector<int>& nums) {
//         int i =0, j=0, res=0, count=0;
        
//         for(i =0; i<nums.size() ; i++){
//             if(nums[i] == 0)
//                 count++;
            
//             while(count > 1){// that means we got 0 element
//                 if(nums[j] == 0) count--;//valid case delete element
//                 j++;
                
//             }
//             res = max(res,i-j);
//         }
//         return res;
//     }
// };

// T.C = O(N)
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int i = 0, cnt = 0,prev = -1;
        while(i < n){
            if(nums[i] == 0){
                ans = max(ans, cnt);
                cnt = i - prev - 1;
                prev = i;
            }
            else cnt++;
            i++;
        }
        ans = max(ans, cnt);
        return cnt == n? ans-1 : ans; 
    }
};