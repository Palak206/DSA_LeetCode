//  divisior will go from 1 to max element(9)
// To calculate the result, we will iterate over the given array using a loop. Within this loop, we will divide each element in the array by the current divisor, d, and sum up the obtained ceiling values.
// Inside the outer loop, If result <= threshold: We will return d as our answer.
// Finally, if we are outside the nested loops, we will return -1.
// O(N2)
// class Solution{
//     public:
//     int smallestDivisor(vector<int>& nums, int threshold){
//          int n = nums.size(); //size of array.
//          //Find the maximum element:
//          int maxi = *max_element(arr.begin(), arr.end());
     
//          //Find the smallest divisor:
//          for (int d = 1; d <= maxi; d++) {
//              //Find the summation result:
//              int sum = 0;
//              for (int i = 0; i < n; i++) {
//                  sum += ceil((double)(arr[i]) / (double)(d));
//              }
//              if (sum <= limit)
//                  return d;
//          }
//          return -1;
//      }
// };

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
        int end = INT_MAX; //*max_elemnt(nums.begin() , nums.end())
        
        int ans = 0;
        
        if(n > threshold) return -1;
        while(start <= end){
            int mid = start+(end-start)/2;
            
            if(helper(nums , threshold , mid)){ //true but we don't know which smallest 
                //val we get ans = mid
                end = mid-1;
                
            }
            else{
                start = mid+1;
                
            }
        }
        return start;
    }
};
