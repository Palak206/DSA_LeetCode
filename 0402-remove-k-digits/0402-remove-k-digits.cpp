//incresing order 1 2 3...
//4>3 not inc then pop(4) 
// monotonic stack
//while nums already  in sorted order
//nums = [1,2,3,6,8]  k = 3 so in that cse we'll not get the chance to delete k
//k > 0 st.top() will delete [8,6 3] ns = 1d2
//T.C = O(2*N) every elemete comes only 2 times
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        if(n == k)
            return "0";
        
        string res = ""; // it will act s a stack
        
        for(int i=0; i<n; i++){
            
            while(res.length() > 0 && res.back() > num[i] && k > 0){
                //res.bck = stack.top()  4>3
                res.pop_back(); //st.pop)()
                k--;
            }
            
            //remove 0 second input
            if(res.length() > 0 || num[i] != '0'){
                res.push_back(num[i]);
            }
            
        }
        
        //nums = [1,2,3,6,8]  k = 3 non decreasing
        while(res.length() > 0 && k>0){
            res.pop_back();
            k--;
        }
        if(res == ""){
            return "0";
        }
        
        return res;
        
    }
};