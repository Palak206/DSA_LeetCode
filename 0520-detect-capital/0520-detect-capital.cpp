class Solution {
public:
    bool detectCapitalUse(string word) {
//         step 1 find the no. of captital leters using count
        int count=0; 
        for(int i=0;i<word.length();i++){
            if(isupper(word[i])){   // if word is captical count incremented
                count++;
            }
        }
        //if total caipital letter(count) == size of word and count = 0 then true
        if(count==word.length() || count==0) 
            return true;
        
        //if count is 1 and and its first index is capital others are small then true
        if(count==1 && isupper(word[0])) 
            return true;
        else 
            return false;

    }
};