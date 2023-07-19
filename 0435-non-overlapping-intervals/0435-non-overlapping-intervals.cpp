// class Solution {
// public:
//     int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//         int n = intervals.size();
//         int count = 0;
        
//         for(int i=0 ; i<n ; i++){
//             for(int j= 0; j<intervals[i].size() ; j++){
//                 if(intervals[i][j] == intervals[i++][j++])
//                     count++;
//                 else
//                     i++;
//                     j++;
//             }
//         }
//         return count;
        
//     }  
// };

// we sort according to starting point 
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);

        int prev = 0;
        int count = 0;

        for(int i = 1; i < n; i++){
            if(intervals[prev][1]>intervals[i][0])
                count++;
            else{
                prev=i;
            }

        }
        return count;
    }
};