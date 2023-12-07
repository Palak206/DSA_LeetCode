//if last digit is odd so whole no is odd return as it is
class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        
        for(int i=n-1; i>=0; i--){
            if((num[i] - '0') % 2 != 0){
                //if last no odd
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};