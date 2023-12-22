//first we count the 1's in the string
//then iterate from 0 to n-1
//if s[i] == 1 then dec the 1's
//if s[i] == 0 then zeroOnes++
//res = max(res , zero+ones);

class Solution {
public:
    int maxScore(string s) {
        int n= s.length();
        
        int ones = count(s.begin() , s.end() , '1');
        int zeros = 0;
        int res = INT_MIN;
        
        for(int i=0 ; i<n-1 ; i++){
            if(s[i] == '0'){
                zeros++;
            }
            else{
                ones--;
            }
            res = max(res , zeros+ones);
        }
        return res;
    }
};