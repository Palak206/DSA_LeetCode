class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        //count the frrquency of the number
        for(auto x: nums){
            m[x]++;
        }

        for(auto x: m){
            if(x.second == 1){
                return x.first;
            }
        }
        
        return -1;
    }
};