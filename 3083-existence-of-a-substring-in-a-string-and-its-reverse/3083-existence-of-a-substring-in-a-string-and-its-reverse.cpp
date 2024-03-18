//O(N^2)
// class Solution {
// public:
//     bool isSubstringPresent(string s) {
//         int n = s.length();
        
//         for(int i=0; i<n-1; i++){
//             string sub = s.substr(i,2);
//             string rev = string(sub.rbegin(), sub.rend());
//             if(s.find(rev) != string::npos)
//                 return true;
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool isSubstringPresent(string s) {
        unordered_set<string> t;
        int n = s.length();
        
        for(int i =0; i < n-1; i++)
        {
            t.insert(s.substr(i,2));
        }
        
        reverse(s.begin(), s.end());
        for(int i =0; i < n-1; i++)
        {
            string x = s.substr(i,2);
            if(t.find(x) != t.end())
                return true;
        }
        return false;
    }
};