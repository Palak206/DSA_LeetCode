// T.C AND S.C = O(N+M)
// # means backspace it will remove the last character character thst come before #
// for ex S= ab#c after backspacing it 'll S = ac'
// class Solution {
// public:
//     bool backspaceCompare(string s, string t) {
//         stack<int> st,sts;
//         for(int i=0;i<s.length();i++){
//             if(!st.empty() && s[i]=='#'){
//                 st.pop();   
//             }
//             else if(s[i]!='#') st.push(s[i]);
//         }
        
        
//         for(int i=0;i<t.length();i++){
//             if(!sts.empty() && t[i]=='#' ){
//                 sts.pop();
//             }
//             else if(t[i]!='#') sts.push(t[i]);
//         }
        
//         if(sts==st) return true;
//         return false;
    
//     }
// };


// TWO POINTER
class Solution{
    public:
        bool backspaceCompare(string s, string t) {
            int j=0 , k = 0;
            // for 1st string
            for(int i = 0 ; i<s.size() ; i++){
                if(s[i] == '#'){
                    j--;
                    j=max(0,j); // j will never be -ve
                }
                else{
                    s[j] = s[i];
                    j++;
                }
            }
             // for 2nd string
            for(int i = 0 ; i<t.size() ; i++){
                if(t[i] == '#'){
                    k--;
                    k=max(0,k); // k will never be -ve
                }
                else{
                    t[k] = t[i];
                    k++;
                }
            }
            
//             compare the both string
        if(j!=k) return false;
        else
        {
            for(int i=0;i<k;i++)
            {
                if(s[i]!=t[i]) return false;
            }
            return true;
        } 
  }
};

