// class Solution {
// public:
//     string reverseWords(string s) {
//         string result;
        
//         int i = 0;
//         int n = s.length();
        
//         while(i<n){
//             while(i<n && s[i] == ' ')//non space first space
//                 i++;
            
//             if(i >= n) break;
//             int j =i+1;
//             while(j<n && s[j] != ' ') // is looking for space
//                 j++;
            
//             string sub = s.substr(i , j-i);
//             if(result.length() == 0)
//                 result = sub;
//             else
//                 result = sub +" "+result;
//             i = j+1;
//         }
        
//         return result;
//     }
// };

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        
        string result;
        int n = s.length();
        int i = 0;
        
        int l = 0 , r = 0; //revrse the words
        
        while(i<n){
            while(i<n && s[i] != ' '){
                s[r] = s[i];
                i++;
                r++;
            }
            
            //space come
            if(l<r){
                reverse(s.begin()+l , s.begin()+r);
                
                s[r] = ' '; //only 1 spce assign
                r++;
                
                l = r; //second word
            }
            i++;
        }
        s = s.substr(0,r-1);
        return s;
        
    }
};