class Solution {
public:
    int addDigits(int num) {

    int ans = 0;
    if (num <= 9)
        return num;
    while (num != 0)
    {
        ans = ans + num % 10;
        num = num / 10;
        if (ans > 9 && num == 0)
        {
            num = ans;
            ans = 0;
        }
    }
    return ans;

    }
};



//10 1
// 11 2
// 12 3
// 13 4
// 14 5
// 15 6
// 16 7
// 17 8
// 18 9
// --------
// 19 1
// 20 2
// 21 3
// 22 4
// 23 5
// 24 6
// 25 7
// 26 8
// 27 9
// that is the digit num starts from 0 and ends at 9
// Thus the ans is the remainder of the division of the number with 9
// Unless remainder is 0 then the ans is 9


// class Solution {
// public:
//     int addDigits(int num) {
//         if(num == 0) return 0;
//         return num%9 == 0 ?9 : num%9;
//     }
// };