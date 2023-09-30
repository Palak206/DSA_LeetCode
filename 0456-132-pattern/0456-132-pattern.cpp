// tle
// class Solution {
// public:
//     bool find132pattern(vector<int>& nums) {
//        int n = nums.size();
        
//         for(int i=0; i<n-2 ; i++){
//             for(int j=i+1; j<n-1 ; j++){
//                 for(int k=j+1; k<n ; k++){
//                     if(nums[i] < nums[k] && nums[k] < nums[j] && nums[i] < nums[j])
//                         return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

// as we have seen in the que nums[i] < nums[k] && nums[i] <nums[j]
// so nums_i is a minimum element we store this is in variable
//tle
// class Solution{
//     public:
//         bool find132pattern(vector<int>& nums){
//             int n = nums.size();
            
//             int num_i = nums[0];
            
//             for(int j=1; j<n ; j++){
//                 num_i = min(num_i , nums[j]);
//                 for(int k = j+1; k<n ; k++){
//                     if(num_i < nums[k] && nums[k] < nums[j])
//                         return true;
//                 }
//             }
//             return false;
//         }
// };

 
// nums[i]  nums[j]   nums[k]

// nums[i]     nums[k]     nums[j]
//          just smaller    largest
//we traverse from n-1 
//store in decreasing order in stack (monotonic stack inc/dec)
class Solution{
    public:
        bool find132pattern(vector<int>& nums){
            int n = nums.size();
            
            int num3 = INT_MIN; //MAX ELE
            
            stack<int> st;
            for(int i=n-1; i>=0 ; i--){
                if(nums[i] < num3){
                    return true;
                }
                
                while(!st.empty() && st.top() < nums[i]){
                    num3 = st.top();
                    st.pop();
                }
                //push the largest element
                st.push(nums[i]);
            }
            return false;
            
        }
};