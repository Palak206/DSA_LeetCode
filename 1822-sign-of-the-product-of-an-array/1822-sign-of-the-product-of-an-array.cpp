class Solution {
public:
    
    int arraySign(vector<int>& nums) {
        int ans = 1;
        for(auto i : nums){
            if(i==0) 
                return 0;
            else if(i>0) 
                ans *=1;
            else 
                ans *= -1;
        }
        return ans;
    }
};