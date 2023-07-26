// 0->01
// 1->10
// 0 n=1
// 0 1 n= 2 k=1 return 0
// 0 1 1 0 n = 3 , k = 1
//k 1 2 3 4 return 1(k=1,n=3)
// k =4-> 0 1 1 0 | 1 0 0 1 (8/2 = 4 mid)
//     k = 3(n-1)   compliment of(0 1  1 0) 0 ka 1 1 ka 0 (k-mid)
// if k <= mid solve(N-1 ,K)
// if k >= mid solve(N-1 ,K-mid)

class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1 && k == 1)
             return 0;
        int length = pow(2 , n-1);//2^n-1
        int mid = length/2;
        
        if(k <= mid)
           return kthGrammar(n-1 , k);
        else
           return !kthGrammar(n-1 , k-mid);
          
          
    }
};