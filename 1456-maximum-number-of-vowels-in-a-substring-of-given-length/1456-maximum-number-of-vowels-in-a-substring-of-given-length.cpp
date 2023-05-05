
class Solution {
public:
    int isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            return 1;
        return 0;
    }

    int maxVowels(string s, int k) {
        int maxi = 0, cur_vow=0;
        for(int i=0;i<s.size();i++){
            cur_vow += isVowel(s[i]); //adding new element in our subarray
            //for k=3 first it goes 0 to 2
            //then after completing one substring we delte the 0th element a
            // then it goes from 1(4-3) to 3(bci)
            if(i>=k)
                cur_vow -= isVowel(s[i-k]);// delete the(i-k)th element in subarray
            maxi = max(maxi, cur_vow);
        }
        return maxi;    
    }
};