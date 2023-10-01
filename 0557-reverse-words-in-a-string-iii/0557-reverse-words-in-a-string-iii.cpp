// class Solution {
// public:
//     string reverseWords(string s) {
//         int i = 0 , j=0;
//         int n = s.size();
        
//         while(i<n){
//             while(j<n && s[i] != ' ')
//                 j++; //j will stop at "s" bcoz after it space is there
//             reverse(s.begin()+i, s.end()+j);// that give "s'tel"
//                 i = j+1;
//                 j = i;
//         }
//                 return s;
//     }
// };


//           int i = 0;
//         for(int j=0;j<s.length();j++)
//         {
//             if(s[j]==' ')
//             {
//                 reverse(s.begin()+i,s.begin()+j);
//                 i=j+1;
//             }
//         }
//         reverse(s.begin()+i,s.end());
//         return s;
//     }
// };

class Solution {
public:
    string reverseWords(string s){
        int n = s.length();
        
        int start = 0;
        int end = 0;
        
        for(int i=0 ;i<=n ; i++){
            //space or end of the word then reverse the word
            if(s[i] == ' ' || i == n){
                end = i-1;
                //reverse word
                while(start < end){
                    swap(s[start] ,  s[end]);
                    start++;
                    end--;
                    // take
                    // i   j
                    // e   t
                    // e k a t
                }
                start = i+1;//for next word
            }
        }
        return s;
    }
};