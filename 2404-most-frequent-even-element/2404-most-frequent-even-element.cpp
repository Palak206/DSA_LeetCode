class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        int cnt = 0 , maxi = 0, res;
        
        for(int i=0; i<n ; i++){
            if(nums[i]%2 != 0)
                cnt++;
            else {
                //we store the freq of even numbers
                mp[nums[i]]++;
            }
                
        }
        if(cnt == n){  // test case 3
            return -1;
        }
        
        // 0->1 2->2 , 4->2
        
        for(auto it:mp){
            if(it.second > maxi){
                res = it.first; // r=0 (2>1) r=2 (2 !> 2) so res = 2
                maxi = it.second; // m=1 m=2
            }
        }
        return res;
    }
};


