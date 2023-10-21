//we need to declare boxes in decreasing order those has more no. of unitperbox tht come 1st
//2nd ex [5,10] [3,9] [4,7] [2,5] we use heap 
//trucksize = 10
// 5 box that contains 10 units = 5*10 = 50 ans trcuksize-5= 10-5=5
// 3 box that contains 9 units = 3*9 = 27 ans trcuksize-5= 5-3=2
// wee have 4 box but only need 2 bo so 2*7 = 14
// ans = 50+27+14 = 91

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<pair<int,int>>pq;
        
        int count = 0;
        
        //why dont we use pq defalut way of sort by 1st parameter
        //pq already sorted number in that order we store them in 
        //reverse [numberOfUnitsPerBoxi , numberOfBoxes] = [10,5]
        
        for(vector<int>x: boxTypes){
            pq.push({x[1] , x[0]});//[10,5]
        }
            int units = 0;
            
            while(!pq.empty() && count < truckSize){
                //0+5=5<10
                if(count + pq.top().second < truckSize){
                    //increase count by no of boxes
                    count += pq.top().second;// 0+5= 5 , 5+3=8 , 8+2=10
                    units += pq.top().second * pq.top().first;//0+5*10= 50
                    
                    pq.pop();
                }
                
                //if we have to only 2 boxes bu there are 4
                else{
                    int quantity = truckSize - count ;//10-8=2
                    count += quantity;//8+2 = 10
                    units += quantity * pq.top().first;
                    
                    pq.pop();
                }
            }
        
        return units;
    }
};