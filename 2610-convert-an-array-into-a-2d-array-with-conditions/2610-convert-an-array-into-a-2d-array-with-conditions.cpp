class Solution {
public:
    //find the freq of each element and pus it into the row
    //if the number is repeating so push it into other row
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int,int>mp;
        
        vector<vector<int>> res;
        
        for(int i=0 ; i<n ; i++){
            int freq = mp[nums[i]];
            
            if(freq == res.size()){
                //add one more row
                res.push_back({});
            }
            //and push the integer into the row
            res[freq].push_back(nums[i]);
            
            //increase the freq
            mp[nums[i]]++;
        }
        return res;
    }
};