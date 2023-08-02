class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        //1st we find freq of each number
        // if num[i] is appear only once then we check the adjacent num (x+1,x-1)
        //present or not in the array
        //if it;s present so that num is lonely num we simply store in our ans
        
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i=0 ; i<n; i++){
            mp[nums[i]]++;
        }
        vector<int>ans;
        for(auto x:mp){
            if(x.second == 1){
                if((mp.find(x.first-1) == mp.end()) && (mp.find(x.first+1) == mp.end())){
                    ans.push_back(x.first);
                }
            }
        }
        return ans;
        
    }
};