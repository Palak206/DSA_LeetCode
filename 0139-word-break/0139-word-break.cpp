class Solution {
public:
    unordered_set<string> st;
    //memo
    int t[301];
    bool solve(int idx , string s){
        if(idx == s.length())
            return true;
        
        if(st.find(s) != st.end())
            return true;
        
        if(t[idx] != -1)
            return t[idx];
        
        for(int i=1 ; i<=s.length() ; i++){
            //to check all length 1 2 3 and break it
            
            string temp = s.substr(idx , i);
            
            if(st.find(temp) != st.end() && solve(idx+i, s)){
                // 0+4 = Leet 
                return t[idx] = true;
            }
        }
            return t[idx] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
       int n = s.length();
        memset(t, -1 , sizeof(t));
        //store all the string of worddict in set
       for(string &word: wordDict){
           st.insert(word);//no need to check again and again using loop
       }
        
        return solve(0 , s);
    
    }
};