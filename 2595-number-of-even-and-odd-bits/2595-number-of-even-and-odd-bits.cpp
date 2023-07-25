// class Solution {
// public:
//     string DecToBin(int num){
//         string str;
//         while(num){
//             if(num & 1) str += '1';
//             else str +='0';
//             num >>= 1;
//         }
//         return str;
//     }
    
//     vector<int> evenOddBit(int n) {
    
//         string s = DecToBin(n);
//         int odd = 0;
//         int even = 0;
//         for(int i =0 ; i<s.size() ; i++){
//             if(i%2 != 0 && s[i] == '1') odd++;
//             if(i%2 == 0 && s[i] == '1') even++;
//         }
//         return {even , odd};
//     }
// };

class Solution {
public:
    vector<int> evenOddBit(int n){
        int i=0;
        int e=0, od = 0;
        
        while(n){
            if(n%2){
                if(i%2) od++;
                else
                    e++;
            }
            n = n/2;
            i++;
        }
        vector<int>ans;
        
        ans.push_back(e);
        ans.push_back(od);
        
        return ans;
    }
};