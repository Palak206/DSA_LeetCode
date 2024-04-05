// a + 32 = A
// A - 32 = a

class Solution {
public:
    string makeGood(string s) {
        int n = s.length();
        string res = "";
        
        for(int i=0; i<n; i++){
            if(res.size() > 0 && (res.back() + 32 == s[i] || res.back() - 32 == s[i])){
                //both re capital-small || smll-capital
                res.pop_back();
            }
            else{
                res.push_back(s[i]);
            }
        }
        return res;
    }
};