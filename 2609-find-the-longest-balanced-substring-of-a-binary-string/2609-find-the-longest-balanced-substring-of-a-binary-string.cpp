// class Solution {
// public:
//     int findTheLongestBalancedSubstring(string s) {
//         int maxi = 0;
//         // sort(s.begin , s.end());
//         int count1=0,count2=0;
        
//         for(int i =0 ; i<s.size() ; i++){
//             if(s[i] == '0')
//                 count1++;
//             if(s[i] == '1')
//                 count2++;
//             if(s[i] == '1' && s[i+1] == '0'){
//                     count1 = 0;
//                     count2=0;
//                 }
            
            
            
//         }
//         int len = 2 * min(count1, count2);
//             maxi = max(maxi, len);
//         return maxi;
//     }
// };

class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int ans = 0;
        int count1 = 0;
        int count2=0;
        for(int i=0;i<s.length();i++){
            
            
            if(s[i]=='0') count1++;
            if(s[i]=='1'){ count2++;}
            
            if(count2>=count1){
                ans = max(ans,count1*2);
            }
            if(count1>=count2){
                ans = max(ans,count2*2);
            }
            
            if(s[i]=='1' && s[i+1]=='0') {
                             count1=0;
                             count2=0;
                         }
            
        }
        
        return ans;
    }
};