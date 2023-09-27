// decode the string find the length of the string
// then run a loop in reverse n-1 to 0
// k = k%size ;
///if(k==0 && char(i)) then return the last char
// if it is char if(char{i}) then size-1
//if digit size = size/digit
// char to int ch-'0' = '9' - '0' = 9
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        int n = s.length();
        
        long long size = 0;
        
        for(char &ch : s){
            if(isdigit(ch)){ //number
                size = size*(ch - '0');// 2*(2-0) = 4*2 = 8 2nd ex
            }
            else{
                size += 1; //if char
            }
        }
        
        for(int i=n-1 ; i>=0 ; i--){
            k = k%size;
            
            if(k == 0  && isalpha(s[i])){
                return string(1,s[i]); //last char of string return it
            }
            
            if(isalpha(s[i]))
                size -= 1;
            else
                //if digit
                size = size/(s[i] - '0'); // size/digit 8/2 = 4 4/2 = 2 ha  
        }
        return "";
    }
};