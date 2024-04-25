// class Solution {
// public:
//     int longestIdealString(string s, int k){
//         int n = s.length();
        
//         vector<int>t(n,1);
        
//         int res = 1;
//         for(int i=0; i<n; i++){
//             for(int j=i-1; j>=0; j--){
//                 if(abs(s[i] - s[j]) <= k){
//                     t[i] = max(t[i], t[j]+1);
//                 }
//             }
//             res = max(res,t[i]);
//         }
//         return res;
//     }
// };

class Solution {
public:
    int longestIdealString(string s, int k){
        int n = s.length();
        
        vector<int>t(26,0);
        
        int res = 0;
        
        for(int i=0; i<n; i++){
            int curr = s[i]-'a';
            int left = max(0,curr-k);
            int right = min(25,curr+k);
            
            int longest = 0;
            for(int j=left; j<= right; j++){
                longest = max(longest,t[j]);
            }
            t[curr] = max(t[curr], longest+1);
            res = max(res,t[curr]);
        }
        return res;
    }
};