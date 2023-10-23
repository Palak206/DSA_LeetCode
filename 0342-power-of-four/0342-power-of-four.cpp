//T.C = O(LOG4N) we have to check again n again 4 times
//  class Solution {
// public:
//     bool isPowerOfFour(int n) {
//         if (n <= 0) {
//             return false;
//         }
//         //16%4 4%4 then n= 1
//         while (n % 4 == 0) {
//             n /= 4;
//         }
//         //jese h n== 1 rh jaye that means it's a poer of 4
//         if(n==1)
//           return true;
//         return false
//     }
// };

//4^x == n take log both side
//log(4^x) = logn
// xlog4 = logn
//x = logn/log4
//if x is == n then true for ex
 // n== 16 x = log16/log4 = 2
//4^2 = 16 = n true
//t.c = o(logn)+log(x)
// class Solution {
// public:
//     bool isPowerOfFour(int n) {
//         if (n <= 0) {
//             return false;
//         }
//         if(n == 1) return true;
        
//         int x = log(n)/log(4);
//         //4^2 = 16 = n
//         if(pow(4,x) == n)
//             return true;
//         return false;
        
//     }
// };

//if n is a pow of 4 so it must be pow of 2(2^2)^x n&(n-1)
//16-1=15 4-1 = 3 64-1 = 63 all divisible by 3
//(n-1)%3
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) {
            return false;
        }
        
        if((n&(n-1)) == 0 && (n-1)%3 == 0)
            return true;
        return false;
        
    }
};