//  a
//    ab
   // aba = ab|a
    //           ac
    //           aca = ac|a
    //                     ab
    //                     aba = ab|a = ab already occured dlt it
//   a|ab|     ac|       a = 4



class Solution {
public:
    int partitionString(string s) {
        unordered_set<char>st;
        int count = 1; //count of no of sub-str so far at every partition ,one substring would increase
        for(int i = 0 ; i<s.size() ; i++){
            if(st.find(s[i]) != st.end()){ 
                // means "aba" a is repeating at first and at last
                count++;
                // reset the set ab| a whwnever partion came
                st.clear();
                
            }
            st.insert(s[i]);
        }
        return count;
        
    }
};