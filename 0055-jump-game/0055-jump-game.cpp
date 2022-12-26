// from n-1 to 0 index
// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
        
//         int n = nums.size();
//         int index = n-1;
        
//         for(int i = n-1 ; i>=0 ; i--){
//             if(nums[i] + i >= index){
//                 index = i;
//             }
//         }
        

//         if(index == 0)  return true;
//         return false;
//     }
// };


// from o to n
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size(), ind=0;
        for(int i=0;i<n;i++){
            if(ind<i)return 0;
            ind=max(ind,i+nums[i]);
        }
        return 1;
    }
};