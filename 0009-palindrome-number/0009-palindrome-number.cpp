// class Solution {
// public:
//     bool isPalindrome(int x) {
//         long int rev = 0 ;
//         int temp = x;
//         if(x<0)
// 	     return false;

//     while(x){
//     rev = rev * 10 + x % 10;//remainder 121%10 = 1
//     x /= 10;
// 	}
//         // rev = 0*10+1 = 1
// //         x = 121/10= 12
// //         rev = 1*10 +12%10 = 10+2 = 12
       
//         // x = 12/10 = 1
// //         rev = 12*10+ 1%10 = 121
        
// return (temp == res);
//         // if(temp == rev)
//             // return true;
//     }
// };

// Convert the number to a string, revert it and compare.

class Solution {
public:
    bool isPalindrome(int x) {
        string rev = to_string(x);
        reverse(rev.begin(), rev.end());
        return to_string(x) == rev;
    }
};



// Convert the number to a string, then use two pointers at beginning and end to check if it's a palindrome.

// class Solution {
// public:
//     bool isPalindrome(int x) {
//         string s = to_string(x);
//         int i = 0, j = s.size()-1;
//         while (i <= j) if (s[i++] != s[j--]) return false;
//         return true;
//     }
// };