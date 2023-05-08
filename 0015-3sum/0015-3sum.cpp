//TIME LIMIT EXCEED
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         //we have to sort the array first bcoz set store element in sorted order
//         sort(nums.begin(), nums.end());
//         int n= nums.size();
//         set<vector<int>> s;
//         vector<vector<int>>res;
//         for(int i= 0; i<n ; i++){
//             for(int j= i+1; j<n ; j++){
//                 for(int k = j+1 ; k<n ; k++){
//                     vector<int> t;
//                     if(nums[i] + nums[j] + nums[k] == 0){
//                         t.push_back(nums[i]);
//                         t.push_back(nums[j]);
//                         t.push_back(nums[k]);
//                         s.insert(t);
//                     }
//                 }
//             }
//         }
//         for(auto x : s)
//             res.push_back(x);
//         return res;
        
        
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         set<vector<int>> set;
//         vector<vector<int>> output;
//         for(int i=0; i<n-2; i++){
//             for(int j=i+1; j<n-1; j++){
//                 for(int k=j+1; k<n; k++){
//                     if((nums[i] + nums[j] + nums[k] == 0) && i != j && j != k && k != i){
//                         set.insert({nums[i], nums[j], nums[k]});
//                     }
//                 }
//             }
//         }
//         for(auto it : set){
//             output.push_back(it);
//         }
//         return output;
//     }
// };

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> set;
        vector<vector<int>> output;
        for(int i=0; i<n-2; i++){
            int low = i+1, high = n-1;
            while(low < high){
                if(nums[i] + nums[low] + nums[high] < 0){
                    low++;
                }
                else if(nums[i] + nums[low] + nums[high] > 0){
                    high--;
                }
                else{
                    set.insert({nums[i], nums[low], nums[high]});
                    low++;
                    high--;
                }
            }
        }
        for(auto it : set){
            output.push_back(it);
        }
        return output;
    }
};
