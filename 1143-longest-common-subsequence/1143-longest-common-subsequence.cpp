// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         // vector<int> ans;
//         int count = 0;
//         for(int i = 0 ; i<text1.size() ;i++){
//             for(int j = 0 ; j<text2.size() ;j++){
//                 if(text1[i] == text2[j]){
//                     // ans.push_back(text1[j]);
//                     count++;
//                 }
//                 // else{
//                 //     return 0;
//                 // }
//             }
//         }
//         return count;
        
//     }
// };


class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) 
    {
        int n = s1.length();
        int m = s2.length();
        vector<int> curr(m+1,0), prev(m+1,0);

        // no need to write base case as we already declare our dp as 0

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    curr[j] = 1 + prev[j-1];
                }
                else
                {
                    curr[j] = max(curr[j-1],prev[j]);
                }
            }
            prev = curr;
        }

        return curr[m];
    }
};