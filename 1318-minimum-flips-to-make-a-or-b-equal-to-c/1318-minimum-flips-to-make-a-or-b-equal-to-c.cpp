class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        
        while(a>0 || b>0 || c>0){
            int bitA = a & 1; //simply go to the last bits
            int bitB = b & 1;
            int bitC = c & 1;
            
            if(bitC == 0){
                flips += (bitA + bitB);
            }
            else{
                if(bitA == 0 && bitB == 0){
                    flips += 1;
                }
            }
            // right shift operation(divide) to move on to next last bit 
            
            a >>= 1;
            b >>= 1;
            c >>= 1;
            
        }
        return flips;
    }
};