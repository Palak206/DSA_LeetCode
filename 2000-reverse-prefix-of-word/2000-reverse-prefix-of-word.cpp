class Solution {
public:
    string reversePrefix(string word, char ch) {
        int chIdx = word.find(ch);
        reverse(word.begin(),word.begin() + chIdx + 1);
        
        return word;
    }
};