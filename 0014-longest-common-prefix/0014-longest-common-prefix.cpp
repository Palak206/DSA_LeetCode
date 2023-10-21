class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //we sort the word by alphabetical order of a b c 
        // flight, flow, flower 
        //check the first char of the word[0] str[0] = last cword of char str[n-]
        int n = strs.size();
        sort(strs.begin() , strs.end());
        
        string start = strs[0];
        string end = strs[n-1];
        string ans = "";
        
        for(int i=0 ; i<start.size(); i++){
            if(start[i] == end[i])
                ans += start[i];
            else
                break;
        }
        return ans;
    }
};

// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         string prefix = "";
//         prefix = strs[0];
        
//         for(int i=1; i<strs.size(); i++){
//             if(prefix.size()){
//                 for(int j=0; j<prefix.size(); j++){
//                     if(prefix[j] != strs[i][j]){
//                         prefix = prefix.substr(0, j);
//                         break;
//                     }
//                 }
//             }
//             else return "";
//         }
//         return prefix;
//     }
// };