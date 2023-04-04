//  a
//    ab
   // aba = ab|a
    //           ac
    //           aca = ac|a
    //                     ab
    //                     aba = ab|a = ab already occured dlt it
//   a|ab|     ac|       a = 4


// T.C = O(N) , S.C = O(26) = 26 char 
// class Solution {
// public:
//     int partitionString(string s) {
//         unordered_set<char>st;
//         int count = 1; //count of no of sub-str so far at every partition ,one substring would increase
// //         if we use partion in place of we start from and in answer we write it partion+1 
// //         if there are n partion so n+1 substring are there 
//         for(int i = 0 ; i<s.size() ; i++){
//             if(st.find(s[i]) != st.end()){ 
//                 // means "aba" a is repeating at first and at last
//                 count++;
//                 // reset the set ab| a whenever partion came
//                 st.clear();
                
//             }
//             st.insert(s[i]); // upcoming char would for sure go in
//         }
//         return count;
        
//     }
// };


// Bit -> t.c = o(n) s.c = o(1)
class Solution{
    public:
          int partitionString(string s){
              int i = 0, ans = 1, flag = 0;
              while(i < s.size()){
                  int val = s[i] - 'a';
                  if(flag & (1<<val)){
                      flag = 0;
                      ans++;
                  }
                  flag = flag | (1<<val); //-> set the bit of that character
                  i++;
              }
              return ans;
          }
    
};