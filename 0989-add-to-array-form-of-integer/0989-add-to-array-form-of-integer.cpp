// `num` = [2,1,5], `k` = 806
// At index 2 num = [2, 1, 811] 
// So, `k` = 81 and `num` = [2, 1, 1]

// At index 1 num = [2, 82, 1]
// So, `k` = 8 and `num` = [2, 2, 1]

// At index 0 num = [10, 2, 1]
// So, `k` = 1 and `num` = [0, 2, 1]

// Now `k` > 0
// So, we add at the beginning of num
// `num` = [1, 0, 2, 1]

// num = [1,2,0,0] k = 34
// at index 3 num = [1,2,0,34] num+k
// so k = 34/10= 3 and num = [ 1, 2 , 0 ,4] rem = 34/10

// at index 2 num = [1,2,0+3, 4] 
// so k = 3/10 = 0
// rem = 3 num = [1,2,3,4] and num = 0



class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        for(int i=num.size()-1;i>=0;i--){
            num[i] += k;
            k = num[i]/10;
            num[i] %= 10;
        }
        while(k > 0){
            num.insert(num.begin(), k%10);
            k /= 10;
        }
        return num;
    }
};