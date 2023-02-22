// class Solution {
// public:
//     int shipWithinDays(vector<int>& weights, int days) {
// //         int sum = 0;
// //         int max = INT_MIN;
// //         for(int i =  0 ; i<weights.size(); i++){
// //             if(weights[i] > max) max = weights[i];
// //             sum+=weights[i];
            
// //         }
// //         int low = max;// max element in the arr = 10
// //         int high = sum; // sum of the array = 
//         int low = *max_element(weights.begin(), weights.end());
//         int high = accumulate(weights.begin(), weights.end(), 0);
//         int ans;
//         while(low <= high){
//             int mid = (low+high)/2;
            
//             if(fnc(mid , weights, days)){
//                 ans = mid;
//                 high = mid-1;
//             }
//             else{
//                 low = mid+1;
//             }
//         }
//         return ans;
        
//     }
    
//     bool fnc(int mid , vector<int>& weights , int days){
//         int sum = 0;
//         int d = 1;
//         for(int i =  0 ; i<weights.size(); i++){
//             if(sum + weights[i] <= mid) sum  += weights[i];
//             else{
//                 sum = weights[i]; // reset
//                 d++; // increase no of ways
//             }
//         }
//         if(days <= d) return true;
//         return false;
        
        
    
// }
// };



class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int cur = 0, need = 1;
            for (int w : weights) {
                if (cur + w > mid) {
                    cur = 0;
                    need++;
                }
                cur += w;
            }
            if (need <= days) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};