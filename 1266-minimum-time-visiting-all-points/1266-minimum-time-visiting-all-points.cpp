class Solution {
public:
    int to_time(vector<int>&from , vector<int>&to){
        int x1 = abs(from[0] - to[0]);
        int y1 = abs(from[1] - to[1]);
        
        return max(x1 , y1);
    }
    
    
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        //just like dis b/w 2points
        int total_time = 0;
        
        for(int i=1; i<points.size(); i++){
            total_time += to_time(points[i-1],points[i]);
        }
        return  total_time;
    }
};