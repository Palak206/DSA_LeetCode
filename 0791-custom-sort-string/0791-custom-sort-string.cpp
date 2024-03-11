class Solution {
public:
    //just sort the string s according to string order
    
    string customSortString(string order, string s) {
        unordered_map<char,int>mp;
        string res = "";
        for(char x : s){
            mp[x]++;
        }
        
        for(char x : order){
            while(mp[x]-- > 0){
                res.push_back(x);
            }
        }
        
        //if string s charcter not present in order extra char
        for(char ch : s){
            if(mp[ch] > 0)
                res.push_back(ch);
        }
        return res;
    }
};

// class Solution {
// public:
    
//     string customSortString(string order, string s) {
        
//         sort(s.begin(), s.end(), [order](char c1, char c2){
//             return order.find(c1) < order.find(c2);
//         });
//         return s;
//     }
// };

