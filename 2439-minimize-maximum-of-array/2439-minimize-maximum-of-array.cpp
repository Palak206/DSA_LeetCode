// class Solution {
// public:
//     int minimizeArrayValue(vector<int>& nums) {
//         long long answer = 0, sum = 0;
        
//         // Iterate over nums, update prefix sum and answer.
//         for (int i = 0; i < nums.size(); ++i) {
//             sum += nums[i];
//             answer = max(answer, (sum + i) / (i + 1));
//         }
        
//         return answer;
//     }
// };


class Solution{
    public:
    bool isValid(vector<int>& nums, int mid_max, int n ){
        vector<long long>arr(begin(nums) , end(nums));
        
        for(int i=0 ; i<n-1 ; i++){
            if(arr[i] > mid_max)
                return false;
            
            long long buffer = mid_max - arr[i];
            
            arr[i+1] = arr[i+1] - buffer;
        }
        return arr[n-1] <= mid_max;
    }
    
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        int maxL = 0;
        int maxR = *max_element(nums.begin(), nums.end()); // Initial max value
        
        int res =0;
        
        while (maxL <= maxR) {
            int mid_max = maxL+(maxR-maxL)/2;
            
            if(isValid(nums,mid_max,n)){
                res = mid_max;
                maxR = mid_max-1; //left
            }
            else{
                maxL = mid_max+1; //right
            }
        }
        
        return res;
    }
};