//i -------->  1
//i+1 --------> 1 br 1 likha h upar so 11
//i+2 ---------> 2 bar 1 likha h upar so 21
//i+3 ---------> 1 bar 2 likha h upar + 1 bar 1likha h = 12+11 = 1211


class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        
        string say = countAndSay(n-1);
        
        //processing
        string res = "";
        for(int i=0 ; i<say.length() ; i++){
            char ch = say[i];
            
            //n= 1 k count 1 already 
            int count = 1;
            while(i < say.length()-1 && say[i] == say[i+1]){ // 222 count = 3
                count++;
                i++;  
            }
            res += to_string(count)+string(1 , ch);
        }
        return res;
    }
};