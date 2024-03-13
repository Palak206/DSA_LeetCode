// class Solution {
// public:
//     int pivotInteger(int n) {
//         int sum = 0;
        
//         for(int i = 1 ; i<=n ; i++){
//             sum += i; // Initialize the sum of elements from 1 to x
//             int temp = 0; // Initialize the sum of elements from x to n
//             for(int j = i ; j<=n ; j++){
//                 temp += j;
//             }
//             if(temp == sum)
//                return i;
            
//         }
//         return -1;
//     }
// };



class Solution {
public:
    int pivotInteger(int n) {
        int sum = n*(n+1)/2;
        
        double a = sqrt(sum);
        
        if(a - ceil(a) == 0)
            return int(a);
        
        return -1;
    }
};

         

        