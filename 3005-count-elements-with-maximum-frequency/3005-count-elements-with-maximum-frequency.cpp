class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>mp;
        
        for(auto x: nums){
            mp[x]++;
        }
        
        int total = 0;
        int max_freq = INT_MIN;
        for(auto m : mp){
            if(m.second > max_freq)
                max_freq = m.second;
        }
        
        for(auto m : mp){
            if(m.second  == max_freq)
                total += m.second;
        }
        return total;
    }
};