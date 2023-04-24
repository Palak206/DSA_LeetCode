// All even number of letters -> can form a palindrome
// All odd number of letters -> can also form a palindrome (but remove 1 letter to make them even)
// 1 middle letter in the palindrom string is optional and they don't need a pair, so if odd number of letters exist -> add 1.


class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>ans;
        for(int i=0;i<s.length();i++){
            ans[s[i]]++;
        }
        int count=0;
        for(auto i:ans){
            if(i.second%2!=0){
                count++;
            }
        }
        if(count>1){
            return s.length()-count+1;//8-2+1
        }
        return s.length();
        }
};
