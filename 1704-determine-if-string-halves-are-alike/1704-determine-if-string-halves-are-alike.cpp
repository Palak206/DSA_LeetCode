class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    bool halvesAreAlike(string s) {
        int first_half = 0 , sec_half = 0;
        int half_len = s.size()/2;
        
        for(int i=0 ; i<half_len ; i++){
            if(isVowel(s[i]))
                first_half++;
            if(isVowel(s[i+half_len]))
                sec_half++;
        }
        if(first_half == sec_half)
            return true;
        return false;
    }
};