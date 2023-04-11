// // T.C = O(N) & S.C = O(N)

// class Solution {
// public:
//     string removeStars(string s) {
//         stack<char>st;
//         for(int i =  0; i<s.length() ; i++){
//             if(s[i] == '*'){
//                 st.pop();
//             }
//             else{
//                 st.push(s[i]);
//             }
//         }
// // we Store all the elements of stack in a variable.
// // and we have performed this operation in stack therfore the obtained string will be in reverse order.
// // at the end we Reverse the string and return it as answer
//         string ans = "";
//         while(!st.empty()){
//             ans += st.top();
//             st.pop();
            
//         }
//         reverse(ans.begin() , ans.end());
//         return ans;
//     }
// };


// TWO POINTER T.C = O(N) S.C = O(1)
class Solution {
public:
    string removeStars(string s) {
        int i=0,j=0;
        for(i=0;i<s.size();i++){
            if(s[i]=='*'){
                j--;
            }else{
                s[j++] = s[i];
            }
        }
        return s.substr(0,j);
    }
};