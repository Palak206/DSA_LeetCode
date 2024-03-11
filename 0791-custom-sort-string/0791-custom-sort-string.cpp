// class Solution {
// public:
//     //just sort the string s according to string order
//     static string str;
//     static bool comp(char c1, char c2){
//         return (str.find(c1) < str.find(c2));
//     }
    
//     string customSortString(string order, string s) {
//         str = order;
//         sort(s.begin(), s.end(), comp);
//         return s;
//     }
// };

class Solution {
public:
    
    string customSortString(string order, string s) {
        
        sort(s.begin(), s.end(), [order](char c1, char c2){
            return order.find(c1) < order.find(c2);
        });
        return s;
    }
};

