class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 == str2 + str1){
            return str1.substr(0, gcd(str1.length(), str2.length()));
        }
        return "";
    }
};

// str1 = "ABCABC", str2 = "ABC"
// str1+str2 = ABCABCABC
// str2+str1 = ABCABCABC
// so (str1+str2 = str2+str1) now we calculate the gcd of both string size
// if (str1+str2 != str2+str1) then 0
// if(str1+str2 = str2+str1) then gcd(size(str1), sizee(str2))
// gcd(6,3) = 3
// factors 6 = 3*2
// factor 3 = 3*1
// gcd =  3