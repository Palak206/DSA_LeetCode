class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        long long int pre[n] , suff[n];
        pre[0] = nums[0];
        //prefix sum;
        
        for(int i=1 ; i<n; i++){
            pre[i] = pre[i-1]+nums[i];
        }
        
        //sufix sum
        suff[n-1] = nums[n-1];
        for(int i=n-2; i>=0 ; i--){
            suff[i] = suff[i+1]+nums[i];
        }
        
        vector<int>ans;
        for(int i=0 ; i<n ; i++){
            if(i-k<0 || i+k>=n){
                ans.push_back(-1);
                //kth left element & right element not there so ans = -1
            }
            
            //index 4
            else{
                long long int sum = (long long int)((suff[i-k]-suff[i])+
                                                    (pre[i+k] - pre[i])+nums[i]);
                sum = sum/(2*k+1);
                ans.push_back(sum);
            }
        }
        return ans;
    }
};