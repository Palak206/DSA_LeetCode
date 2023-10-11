//TLE
// class Solution {
// public:
//     int minOperations(vector<int>& nums) {
        
//         int n = nums.size();
//         int res = INT_MAX;
        
        
//         //min ele wessume nums[i]
//         //max = min+n-1
//         for(int i=0; i<n ; i++){
//             int mini = nums[i];
//             int maxi = mini + n - 1;
            
//             //and check every element duplicate or not nd stored in set
//             //for tracking duplicate ele
            
//             int opr = 0;
//             unordered_set<int> st;
            
//             //iterate over all the ele
//             //and check which element out of range [min , max]
            
//             for(int j=0 ; j<n ; j++){
//                 if(nums[j] >= mini && nums[j] <= maxi && st.find(nums[j]) == st.end()){
//                     st.insert(nums[j]);
//                     continue;
//                 }
//                 //if duplicate hua
//                 else{
//                     opr++;
//                 }
//             }
//             res = min(res ,opr);
//         }
//         return res;
        
//     }
// };


// we have a range [ L , R]
// if we sort our array thenwe don't need to iterate whole array for checking inrange ele
// for left side we already know
// [2 6 7 8 11 12] range[7, 10]
// we just have to find the next greter element index of max use upperbound direct
//for right side 
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        //in that case we remove the duplicate element
        // [ 1 2 3 3] = convert [1 2 3]
        // within_range = j-i = 3-0
        //outofrange = n-within = 4-3=1
        //sort kr dega set
        set<int> st(begin(nums), end(nums));
        
        vector<int> temp(begin(st), end(st));
        int res = INT_MAX;
        
        for(int i=0; i<temp.size() ; i++){
            int L = temp[i];
            int R = L + n - 1;
            
            //r-l = n-1
            //right most range ka greater index
            //upper bound give only pointer we have to find index
            // int j= upper_bound(temp.begin() , temp.end() ,R) - temp.begin() ;
            int j = upper_bound(begin(temp), end(temp), R) - begin(temp);
            
            
            int within_range = j - i;
            int out_range = n - within_range;
            
            res = min(res , out_range);
        }
        return res;
    }
};