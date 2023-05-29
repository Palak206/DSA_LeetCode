class Solution {
public:
    unordered_set<string> st;
    vector<int> dp;
    int func(string s, int id){
        if(id >= s.size()) return 0;
        
        if(dp[id] != -1)
            return dp[id];
        
        int res = INT_MAX;
        for(int i=1 ; id + i <= s.size(); i++){
            string t = s.substr(id,i);
            if(st.find(t) != st.end()){
                res = min(res,func(s , id+i));
            }
        }
        res = min(res,1+func(s,id+1));
        return dp[id] = res;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        int n= s.size();
        dp.resize(n+1,-1);
        
        for(auto d:dictionary) st.insert(d);
        return func(s,0);
    
    }
};