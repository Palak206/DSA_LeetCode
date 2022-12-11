class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        sort(nums.begin() , nums.end());
        
        map<int , int> mp;
        for(i = 0 ; i<n ; i++){
            int x = sqrt(nums[i]);
            if(x*x == nums[i] && mp.find(x) != mp.end()){
                mp[nums[i]] = mp[x]+1;
            }
            else{
                mp[nums[i]] = 1;
            }
        }
        int ans = -1;
        for(auto x:mp){
            ans = max(ans , x.second);
        }
        if(ans == 1){
            return -1;
        }
        return ans;
    }
};