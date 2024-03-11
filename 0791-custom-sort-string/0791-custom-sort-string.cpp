// class Solution {
// public:
//     //just sort the string s according to string order
//     //count the freq of s char
//     // then 
//     string customSortString(string order, string s) {
//         //we can use int count[26] = {0} bcoz in que lower char used only
//         // so in that ay space will be constant
//         //mp[ch-'a']
//         unordered_map<char,int>mp;
//         string res = "";
//         for(char x : s){
//             mp[x]++;
//         }
//         //for each character of order, append to result the same frequency it appears in s.
//         for(char x : order){
//             while(mp[x]-- > 0){
//                 res.push_back(x);
//             }
//         }
        
//         //if string s charcter not present in order extra char
//         for(char ch : s){
//             if(mp[ch] > 0)
//                 res.push_back(ch);
//         }
//         return res;
//     }
// };

// class Solution {
// public:
    
//     string customSortString(string order, string s) {
        
//         sort(s.begin(), s.end(), [order](char c1, char c2){
//             return order.find(c1) < order.find(c2);
//         });
//         return s;
//     }
// };


class Solution {
public:
    //sort the string s according to index of order string
    //         0 1 2
    // order = c b a
    
    //     2 1 0 infinite
    // s = a b c d
    // after sort = c b a d
    string customSortString(string order, string s) {
        vector<int> index(26, -1);
        
        for(int i=0; i<order.length(); i++){
            char ch = order[i];
            index[ch-'a'] = i;
        }
        auto comp = [&index](char& ch1, char& ch2){
            if(index[ch1-'a'] < index[ch2-'a']){
                return true;
            }
            return false;
        };
        
        sort(s.begin(), s.end(), comp);
        return s;;
           
    }
};



