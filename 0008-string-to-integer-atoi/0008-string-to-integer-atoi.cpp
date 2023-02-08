// #include <cstdlib>
// class Solution {
// public:
//     int myAtoi(string str) {
//         int result=0;  
//         //Stores and returns the integer converted value for str
//        int i=0;    
//         //just a current character pointer for string
//         int sign = 1;  
//         //multiplied at the end to result to determine if the string is +ve or -ve
//     if(str[i]=='-') //Check the sign of string (+ or -)
//     {
//         sign = -1;
//         i++;
//     }
//     //Now traverse the entire string and convert it into integer
//     while(str[i])
//     {
//         //If any character is not an integer then just return -1
//         if(!(str[i]-'0'>=0 && str[i]-'0'<=9))
//             return -1;
//         //else just keep updating the result
//         result = result*10 + str[i]-'0';
//         i++;
//     }
//     return result*sign;
//     }
// };



#include <cstdlib>
class Solution {
public:
    int myAtoi(string str) {
        int sign = 1, base = 0, i = 0;
        while (str[i] == ' ') i++;
        if (str[i] == '-' || str[i] == '+') sign = 1 - 2 * (str[i++] == '-');
        while (str[i] >= '0' && str[i] <= '9'){
            if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)){
                if (sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            base = 10 * base + (str[i++] - '0');
        }
        return base * sign;
    }
};