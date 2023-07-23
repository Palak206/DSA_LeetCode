// Binary search 1 to n
class Solution {
public:
    bool helper(vector<int>& nums, int threshold , int mid){
        int cnt = 0;
        for(int i=0 ; i<nums.size() ; i++) {
            cnt += (nums[i]+mid-1)/mid;
            if(cnt > threshold) 
                return false;
        }
        return true;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int start = 1;
        int end = INT_MAX;
        
        int ans = 0;
        
        while(start <= end){
            int mid = start+(end-start)/2;
            
            if(helper(nums , threshold , mid)){ //true but we don't know which smallest 
                //val we get
                end = mid-1;
                
            }
            else{
                start = mid+1;
                
            }
        }
        return start;
    }
};