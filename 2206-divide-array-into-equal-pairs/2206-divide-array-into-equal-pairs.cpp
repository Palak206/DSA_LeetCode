class Solution {
public:
    bool divideArray(vector<int>& nums) {
        //count the frequency of element
        unordered_map<int , int>mp;
        for(int i = 0 ; i<nums.size() ; i++){
            mp[nums[i]]++;
        }
        // freq(3) = 2
        // freq(2) = 4 so both are even number so they make a pair
                    //   mp.second()
       // ex-2 freq(1) = 1
        // freq(2) = 1
        // freq(3) = 1
        // freq(4) = 1
        // so all frequencies are odd so they don't make a pair
        for(auto it:mp)
        {
            if(it.second%2!=0)return false;
        }
        return true;
    }
};