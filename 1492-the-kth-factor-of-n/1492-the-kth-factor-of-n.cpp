// class Solution {
// public:
//     int kthFactor(int n, int k) {
//         vector<int>ans;
//        for(int i=1; i<=n; i++){
//            if(n%i==0){
//               ans.push_back(i);
//             }
//            // sort(ans.begin()) , ans.end());
//         }
//           if(k<=ans.size()){
//             return ans[k-1];
//            }
//      return -1;
     
//     }
// };

class Solution {
public:
int kthFactor(int n, int k) {
        vector<int>ans;
        for(int i=1;i<=n;i++){
            if(n%i==0){
               ans.push_back(i);
               // if(n/i!=i){
               //  ans.push_back(n/i);
               
            }
        }
        sort(ans.begin(),ans.end());
        if(ans.size()<k){
            return -1;
        }
    return ans[k-1];
    }
};