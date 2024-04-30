// class Solution {
// public:
//     int maxOperations(vector<int>& nums, int k) {
//         int n = nums.size();
//         int count = 0;
        
//         for(int i=0; i<n; i++){
            
//             if(nums[i] == -1)
//                 continue;
            
//             for(int j=i+1; j<n; j++){
//                 if(nums[j] == -1)
//                   continue;
//                 if(nums[i] + nums[j] == k){
//                     count++;
//                     nums[i] = -1;
//                     nums[j] = -1;
//                     break;
//                 }
//             }
//         }
//         return count;
//     }
// };


class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        int i=0, j=n-1;
        
        int count = 0;
        
        while(i<j){
            if(nums[i]+nums[j] == k){
                count++;
                i++;
                j--;
            }
            
            else if(nums[i]+nums[j] > k){
                j--;
            }
            else{
                i++;
            }
        }
        
        return count;
    }
};