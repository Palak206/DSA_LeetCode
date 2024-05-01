// class Solution {
// public:
//     string reversePrefix(string word, char ch) {
//         int chIdx = word.find(ch);
//         reverse(word.begin(),word.begin() + chIdx + 1);
        
//         return word;
//     }
// };

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int chIdx = word.find(ch);
        
        if(chIdx == -1)
            return word;// if ch not find in the string
        
        int n = word.length();
        string res;
        
        for(int i=0; i<n; i++){
            if(i <= chIdx){
                res += word[chIdx-i]; //reverse
            }
            else{
                res += word[i]; //last words
            }
        }
        return res;
    
    }
};