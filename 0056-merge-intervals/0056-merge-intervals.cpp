class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() ,intervals.end());// according to the start no.
        
        vector<vector<int>> ans;
        for(int i=0 ; i<intervals.size() ; i++){
            if(ans.empty()){
                ans.push_back(intervals[i]);
            }
            else{
                vector<int> &v = ans.back();//previous element
                
                int y = v[1];// end time of previous intervals (ending value)
                // compare end time 'y' with current intervals'i'
                
                // [1 , 3] [2 ,6] =2 is less than 3
                // max(3,6) = 6 [1,6]
                // overlapping
                if(intervals[i][0] <= y){
                    v[1] =  max(y , intervals[i][1]);
                }
                
                // not overlapping
                else{
                    ans.push_back(intervals[i]);
                }
            }
        }
        return ans;
    }
};