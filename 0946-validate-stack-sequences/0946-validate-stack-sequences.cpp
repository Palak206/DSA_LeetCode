// T.C , S.C = O(N)

// class Solution {
// public:
//     bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
//         stack<int>st;
//         int  j=0;
//         for(int x: pushed){
//             st.push(x);
//             while (st.size() && st.top() == popped[j]) {
//                 st.pop();
//                 j++;
//             }
//         }
//         return st.size() == 0;
        
//     }
// };

// OPTIMAL T.C = O(N) S.C = O(1)
class Solution{
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped){
        int i = 0 , j=0;
        for (int x : pushed) {
            pushed[i++] = x;
            while (i > 0 && pushed[i - 1] == popped[j])
                --i, ++j;
        }
        return i == 0;
        
    }

};