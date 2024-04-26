// leftSide = flowers[i-1] == 0 || i == 0(starting ind)
// rightSide = flowers[i+1] == 0 || i == size-1(last ind)

// class Solution {
// public:
//     bool canPlaceFlowers(vector<int>& flowerbed, int n) {
//         if (n == 0) {
//             return true;
//         }
//         for (int i = 0; i < flowerbed.size(); i++) {
//             if (flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == flowerbed.size()-1 || flowerbed[i+1] == 0)) {
//                 flowerbed[i] = 1;
//                 n--;
//                 if (n == 0) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int l = flowerbed.size();
        
        if (n == 0) {
            return true;
        }
        for (int i = 0; i < l; i++) {
            if(flowerbed[i] == 0){
                bool left_side = (i == 0) || (flowerbed[i-1] == 0);
                
                bool right_side = (i == l-1) || (flowerbed[i+1] == 0);
                
                //i can plant only if leftside and right side empty = 0
                if(left_side && right_side){
                    flowerbed[i] = 1; //insert 1
                    n--;
                    
                    if(n == 0){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};