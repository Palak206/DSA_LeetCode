class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        stack<int>s;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                s.push(nums[i]);
            }
        }
        vector<int>num;
        int count=0;
        while(!s.empty()){
            count++;
            num.push_back(s.top());
            s.pop();
        }
        reverse(num.begin(),num.end());
        nums=num;
        return count;
        
    }
};
// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
        
//         int n=nums.size();
//         stack<int> s;
//         for(int i=0;i<n;i++)
//         {
//             if(nums[i]!=val)
//                 s.push(nums[i]);
//         }
//         nums.clear();
//          while(!s.empty())
//          {
//              nums.push_back(s.top());
//              s.pop();
//          }
//         return nums.size();
//     }
// };