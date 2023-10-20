// class Solution {
// public:
//     bool isPalindrome(string s) {
//         int start = 0 ;
//         int end = s.size() - 1;
        
//         while(start <= end){
            
//             while(start < end && !isalnum(s[start])){
//                 start++;
//             }
            
//             while(start < end && !isalnum(s[end])){
//                 end--;
//             }
            
//             if(start < end && tolower(s[start]) != tolower(s[end]))
//             return false;
            
//             start++;
//             end--;
//         }
//         return true;
        
//        //  int start=0;
//        // int end=s.size()-1;
//        // while(start<=end){
//        //     if(!isalnum(s[start])){start++; continue;}
//        //     if(!isalnum(s[end])){end--;continue;}
//        //     if(tolower(s[start])!=tolower(s[end]))return false;
//        //     else{
//        //         start++;
//        //         end--;
//        //     }
//        // }
//        // return true;
//     }
// };

class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for(auto i : s) {
            if (isalpha(i) || isdigit(i)) {
                i = tolower(i);
                t += i;
            }
        }
        string p = t;
        reverse(t.begin(), t.end());
        if (t == p) {
            return true;
        }
        return false;
    }
};