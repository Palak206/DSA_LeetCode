// 0 1 1 0 0 1  prev = 3
// 0 0 0 0 0 0  curr = 0   prev = 3
// 0 1 0 1 0 0  prev = 2   curr = 2 3*2 = 6
// 0 0 1 0 0 0  curr = 1   prev = 1
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        
        int prevDeviceCnt = 0;
        int res = 0;
        
        for(int i=0; i<n ; i++){
            int currDeviceCnt = 0;
            for(char &ch :bank[i]){
                if(ch == '1'){
                    currDeviceCnt++;
                }
            }
            
            res += (currDeviceCnt * prevDeviceCnt);
            
            if(currDeviceCnt != 0){
                prevDeviceCnt = currDeviceCnt;
            }
        }
        return res;
    }
};