// in the 1st iteration we on all the bulb
// in the 2nd iteration we on multiple of 2  bulb
// in the 3rd iteration we on multiple of 3  bulb
// we only take those bulb , those factos no. is odd; T.C = O(N*F) Factor

//  those no(1to n) are perfect square (4,9,16) so these have odd no of factors
// / factors of 1 = 1 total no.of fact = 1
// factors of 4 = 1,2,4 total no.of fact = 3
// factors of 9 = 1,3,9 total no.of fact = 3
//  so these are the bulb that ' ll be ON'

//  so conslusion is we first take all the perfect no b/w (1 to n) 
// the count it and return it
// so perfectSquare(10) = 3.16 math.floor(3.16) = 3

// class Solution {
// public:
//     int bulbSwitch(int n) {
//         int count = 0;
//         int i = 1;//multiple of ith
        
//         while((i*i)<=n){ // 0 to n
//             i++;
//             count++;
//         }
            
//         return count;
            
        
//     }
// };

// T.C = O(sqrtN)
class Solution {
public:
    int bulbSwitch(int n) {
        double sq =sqrt(n); // 10 = 3.16 
        double ans = abs(sq); // (3.16) = 3
        
        return (int)ans;
        
    }
    
};