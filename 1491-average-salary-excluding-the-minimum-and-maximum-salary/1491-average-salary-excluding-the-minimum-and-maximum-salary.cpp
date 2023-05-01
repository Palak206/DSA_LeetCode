// class Solution {
// public:
//     double average(vector<int>& salary) {
//         int n= salary.size();
//         sort(salary.begin(),salary.end());
//         double ans=0;
        
//         for(int i=1;i<n-1;i++){
//             ans += salary[i];
//         }
//         ans =  ans / (n-2);
//         return ans;
    
//     }
// };
class Solution{
    public:
    double average(vector<int>& salary) {
        double ans = 0;
        int n= salary.size();
        int mn = INT_MAX;
        int mx = INT_MIN;
        
        for(int i= 0 ; i<n ; i++){
            mx = max(mx , salary[i]);
            mn = min(mn , salary[i]);
            ans += salary[i];
        }
        
         ans = ans-mx-mn;
         ans = ans/(n-2);
         return ans;

}
};