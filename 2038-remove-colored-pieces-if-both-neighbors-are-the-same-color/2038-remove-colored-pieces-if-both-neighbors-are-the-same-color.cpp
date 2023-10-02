class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.length();
        int aliceCnt = 0 , bobCnt = 0;
        
        for(int i=0 ; i<n; i++){
            if(colors[i] == 'A' && colors[i+1] == 'A' && colors[i+2] == 'A'){
                aliceCnt++;
            }
            if(colors[i] == 'B' && colors[i+1] == 'B' && colors[i+2] == 'B'){
                bobCnt++;
            }
        }
        return aliceCnt > bobCnt;
        
    }
};