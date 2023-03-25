// class Solution {
// public:
//     int getSum(int a, int b) {
//         return a+b;
//     }
// };

// without +, - oerator
// using bit manipulation
class Solution {
public:
    int getSum(int a, int b) {
        unsigned int buff;
        do {
            buff = a & b; // 1 & 2(10) = 0
            a ^= b;  // 1^2 = 11  = 3
            b = buff << 1; // b = 0 << 1 = 0*(2^1) = 0
        } while(buff);  // so buff is 0 ans is 3
        return a;
    }
};

// using logarithmic
// class Solution{
//     public:
//           int getSum(int a, int b){
//               return log2(std::pow(2, a) * std::pow(2, b));
//           }
    
// };

// log2(2^a * 2^b) = log2(2^a)+log2(2^b) = log2(2^1) + log2(2^2) = 1(log2(2))+ 2(log2(2)) = 1+2 = 3