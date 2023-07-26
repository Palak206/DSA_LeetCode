//last element ko ciel me convert ni krna hai 
// 1/2 =ceil(0.5) = 1 , 3/2 = ceil(1.5) = 2  6/2 = 3

class Solution {
public:
    double solve(vector<int>& dist,int mid_speed){
        double time = 0.0;
        int n = dist.size();
        
        for(int i=0 ; i<n-1; i++){
            double t = (double)dist[i]/(double)mid_speed; //hour 1/1
            
            time += ceil(t);//1.5->2
            
        }
        //last integer not written in ceil
        time += (double)dist[n-1]/(double)mid_speed;
        return time;
        
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1;
        int r = 1e7;
        
        int res = -1;
        while(l<=r){
            
            int mid_speed = l+(r-l)/2;
            
            if(solve(dist, mid_speed) <= hour){ // res = mis_speed r = mid-1
                res = mid_speed;
                r = mid_speed-1; //possibility of min answer
            }
            else{
                l = mid_speed+1; //hour <=
            }
        }
        // if(l > 1e7) return -1;
        //n*(logk)
        return res;
    }
};