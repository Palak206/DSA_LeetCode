class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        int m=t.size();
      map<char,char>mp;
      map<char,char>mp1;
      for(int i=0;i<m;i++){
        if(mp.find(s[i])==mp.end() and mp1.find(t[i])==mp1.end()){
          mp[s[i]]=t[i];
          mp1[t[i]]=s[i];
        }
        else if(mp[s[i]]!=t[i]){
          return false;
        }
      }
      return true;
        
//         if(s.length() != t.length()) return false;

//         // create 2 unordered maps to hold the mapping of each char in s and t
//         unordered_map<char, char> m1, m2;
//         int len = s.length();
        
//         for(int i=0; i<len; i++){
// // if a mapping already exists, and the mapped char isn't equal to the existing char
//             // reuturn false
//             if((m1[s[i]] && m1[s[i]]!=t[i]) || (m2[t[i]] && m2[t[i]]!=s[i])) 
//                 return false;
            
//             // else add a mapping for the current char in both strings
//             m1[s[i]] = t[i];   // e: a , g: d
//             m2[t[i]] = s[i];    // a:e ,d:g
            
//         }
//         return true;
    }
};