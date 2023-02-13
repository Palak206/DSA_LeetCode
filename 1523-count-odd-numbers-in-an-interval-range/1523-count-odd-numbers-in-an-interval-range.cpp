// class Solution {
// public:
//     int countOdds(int low, int high) {
//         int count = 0;
//         int i ;
//         for(i = low ; i<=high ; i++){
//             if(i%2 != 0)
//                 count++;
//         }
//         return count;
        
//     }
// };




// Total odd number between 1 and low - 1 islow/2.
// Total odd number between 1 and high is (high + 1 ) / 2.
// For getting answer we will do
// Total odd number between 1 and high - Total odd number between 1 and low - 1
// Complexity
// Time complexity:O(1)
// Space complexity:O(1)

class Solution {
public:
    int countOdds(int l, int h) {
        return ((h + 1) / 2) - (l / 2);
    }
};