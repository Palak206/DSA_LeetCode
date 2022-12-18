// BRUTE-FORCE T.C = O(N^2) S.C = O(1)
// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& T) {
//         vector<int> ans(size(T));
//         for(int i = 0; i < size(T); i++) 
//             for(int j = i+1; j < size(T) && !ans[i]; j++) 
//                 // loop till next warmer day isnt found
//                 if(T[j] > T[i]) 
//                     ans[i] = j - i;
//         return ans;
//     }
// };




// USING STACK 
// Time Complexity: O(N) Since we move from right to left, and the inner while loop stack only visit each temperature of the temperatures vector only once in all the iterations, so it's O(N) time complexity 
// Space Complexity: O(N) (stack)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> ans;
        int n = temperatures.size();
        
        for(int i = n-1 ; i>=0 ; i--){
            if(s.empty()){
                s.push(i);//index
                ans.push_back(0);
            }
            else{
                while(!s.empty() && temperatures[s.top()] <= temperatures[i]){
                    s.pop();
                }
                if(s.empty()){
                    s.push(i);//index
                   ans.push_back(0);
                }
                else{
                    ans.push_back(s.top()-i);
                    s.push(i);
                }
            }
        }
//         we have taken it in reverse order bcox stack
        reverse(ans.begin() , ans.end());
        return ans;
    }
};



// Optimized Approach
// T.C = O(N)
// S.C = O(1)

// class Solution{
//     public:
//         vector<int> dailyTemperatures(vector<int>& temperatures) {
//             int n = temperatures.size();
//             vector<int> ans(n , 0);
//             int warmer = INT_MIN;
            
//             for(int i = n-1 ; i>=0 ; i--){
//                 if(temperatures[i] >= warmer){
//                     warmer = temperatures[i];
//                 }
//                 else{
//                     int it = i+1;
//                     while(temperatures[it] <= temperatures[i]){
//                         it = it+ans[it];
//                     }
//                     ans[i] = it - i;
//                 }
//             }
            
//             return ans;
//         }
// };