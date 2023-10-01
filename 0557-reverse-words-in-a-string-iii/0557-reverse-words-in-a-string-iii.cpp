class Solution {
public:
    string reverseWords(string s) {
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


          int i = 0;
        for(int j=0;j<s.length();j++)
        {
            if(s[j]==' ')
            {
                reverse(s.begin()+i,s.begin()+j);
                i=j+1;
            }
        }
        reverse(s.begin()+i,s.end());
        return s;
    }
};