// class Solution {
// public:
//     int longestPalindromeSubseq(string s) {
//         reverse(s.begin() , s.end());
//         stack<int>st;
//         int j = 0;
//         for(int i=0 ; i<s.size(); i++){
//             st.push(s[i]);
//         }
//             while(!st.empty()){
//             if(st.top() == s[j]){
//                 st.push(s[j]);
//                 j++;
                
//             }
//             else{
//                 st.top();
//                 st.pop();
                
//             }
            
        
//     }
        
//         return st.size();
//     }
// };


class Solution {
public:

    int solveSpaceOP(string& a, string& b){

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

        // int n = s.length();

        // for(int i=n-1; i>=0; i--){
        //     revS += s[i];
        // }

        reverse(revS.begin(), revS.end());

        return solveSpaceOP(s, revS);
    }
};


