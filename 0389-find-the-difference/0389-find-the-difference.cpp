// failed
// class Solution {
// public:
//     char findTheDifference(string s, string t) {
//        int n = s.length() ;
//         int m = t.length();
//         char ans;
//         int i , j;
//         for( i=0 ; i<n; i++){
//             for( j=0; j<m ; j++){
//                 if(s[i] == t[j]){
//                     i++;
//                     j++;
//                 }
//                 // if(m > n){
//                 //     ans = t[m - 1];
//                 // }
//             }
            
//         }
//         return t[m-1];
//     }
// };

class Solution{
    public:
         char findTheDifference(string s, string t){
             int n = s.length();
             sort(s.begin(), s.end());
             sort(t.begin(), t.end());
             
             for(int i=0; i<n; i++){
                 if(s[i]!=t[i]) 
                     return t[i];
             } 
             return t[n];
         }
       
};
        