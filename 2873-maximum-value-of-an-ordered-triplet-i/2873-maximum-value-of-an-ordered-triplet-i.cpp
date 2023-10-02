class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n= nums.size();
        long ans = 0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1; j<n ; j++){
                for(int k = j+1 ; k<n ; k++){
                   long val = (long)(nums[i]-nums[j]) * (long) nums[k];
                    
                    // if(ans < 0)
                    //     return 0;
                    if(val > ans)
                        ans = val;
                }
            }
        }
            
        return ans;
    }
};