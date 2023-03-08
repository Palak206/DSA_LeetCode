// class Solution {
// public:
//     int minEatingSpeed(vector<int>& piles, int h) {
//         int low = 1;
//         int high = *max_element(piles.begin() , piles.end());
        
//         int ans = 0;
//         while(low <= high){
//             int mid = low+high/2;
//             int time = timefnc(mid ,piles);
//             if(time<=h){
//                 ans = mid;
//                 high = mid-1;
//             }
//             else
//                 low = mid+1;
            
//         }
//         return ans;
//     }
    
//     int timefnc(int mid , vector<int>&piles){
//         int sum = 0;
//         for(int i = 0 ; i<piles.size() ; i++){
// //             for n = 4  , k = 1+(ceil(6/4)+1)+(ceil(7/4)+1)+(ceil(11/4)+1)
//                sum += (piles[i]/mid)+((piles[i]%mid) != 0);
//                    //if remainder is not 0 so we add +1
//         }
//         return sum;
//     }
// };


class Solution {
public:
    long long getHoursToEatAll(vector<int>&piles, int bananasPerHour)
    {
        long long totalHours = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            int hoursToEatPile = ceil(piles[i] / (double)bananasPerHour);
            totalHours += hoursToEatPile;
        }
        return totalHours;
    }
    int minEatingSpeed(vector<int>& piles, int targetHours)
    {
        int low = 1, high = *(max_element(piles.begin(), piles.end()));
        int ans = -1;
        //================================================================
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            long long hoursToEatAll = getHoursToEatAll(piles, mid);
            
            if (hoursToEatAll <= targetHours)
            {
                ans = mid; //record the answer (this is the best we could record till curr step)
                high = mid - 1;
            }
            else low = mid + 1;
        }
        //=================================================================
        return ans;
    }
};