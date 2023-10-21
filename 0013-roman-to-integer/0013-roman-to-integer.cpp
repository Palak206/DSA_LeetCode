// //values are in non  increasing order
// //CCLXXXIII = 100 100 50 10 10 10 1 1 1 = 283
// //CDXCVII = 100 500( 100<500) = 500-100 = 400 (10<100) 90 5 1 1 = 497
// class Solution {
// public:
//     int romanToInt(string s) {
//         // unordered_map<char>[('I' , 1) , ('V' , 5) , ('X' , 10) ,('L' , 50),
//                            //('C' , 100) , ('D' , 500) , ('M', 1000)];
//         int count=0;
//         int prev = 0;
        
//         for(int i=0 ; i<s.length() ; i++){
//             if(s[i] == 'I')
//                 count += 1;
            
//             else if(s[i] == 'V')
//                  count += 5;
             
//             else if(s[i] == 'X')
//                  count += 10;
             
//             else if(s[i] == 'L')
//                  count += 50;
             
//             else if(s[i] == 'C')
//                  count += 100;
            
//             else if(s[i] == 'D')
//                  count += 500;
            
//             else if(s[i] == 'M')
//                 count += 1000;
            
            
//         }
//         return count;
//     }
// };

class Solution {
public:
int romanToInt(string s) {
    unordered_map<char,int> mp{
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000},
    };
    int ans =0;
    for(int i=0;i<s.size();i++){
        if(mp[s[i]]<mp[s[i+1]])
            ans-=mp[s[i]];
        else
            ans+=mp[s[i]];
    }
    return ans;
    
  }
};