// we hve to find longest palindrome subsequenece for "mbadm" LCS = 'mam' and remaining are 'bd' so we 2 character(bd) to make our string palindrome
// so in this que we firsr find LCS then remaining character we add it

class Solution {
public:

    int LCS(string& a, string& b){

        int n1 = a.length();
        int n2 = b.length();

        vector<vector<int>> dp(n1+1, vector<int> (n2+1, 0));

        vector<int> currRow(n2+1, 0);
        vector<int> nextRow(n2+1, 0);

        for(int i = n1-1; i>=0; i--){
            for(int j = n2-1; j>=0; j--){
                int ans = 0;

                if(a[i] == b[j])
                    ans = 1 + nextRow[j+1];

                else
                {
                    ans = max(nextRow[j], currRow[j+1]);
                }

                currRow[j] = ans;
            }

            nextRow = currRow;
        }
        
        return nextRow[0];
    }

    int longestPalindromeSubseq(string s) {

        string revS = s;
        reverse(revS.begin(), revS.end());

        return LCS(s, revS);
    }
    int minInsertions(string s) {
        return s.length() - longestPalindromeSubseq(s);
    }
};

// class Solution {
// public:
//     int longestPalindromeSubseq(string& s) {
//         int n = s.size();
//         vector<int> dp(n), dpPrev(n);

//         for (int start = n - 1; start >= 0; --start) {
//             dp[start] = 1;
//             for (int end = start + 1; end < n; ++end) {
//                 if (s[start] == s[end]) {
//                     dp[end] = dpPrev[end - 1] + 2;
//                 } else {
//                     dp[end] = max(dpPrev[end], dp[end - 1]);
//                 }
//             }
//             dpPrev = dp;
//         }

//         return dp[n - 1];
//     }

//     int minInsertions(string s) {
//         return s.length() - longestPalindromeSubseq(s);
//     }
// };