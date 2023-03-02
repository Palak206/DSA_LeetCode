class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 1;
        string ans;
        ans.push_back(chars[0]);
        
        for(int i = 1 ; i<chars.size() ; i++){
            if(chars[i] == chars[i-1])
                count++;
            else{
                if(count > 1)
                    ans = ans + to_string(count);
                
                count = 1;
                ans.push_back(chars[i]);
            }
        }
        if(count > 1) // for last value of chars in this ex at last c  = previous character so count++ count = 3 so we push it here
           ans = ans + to_string(count);
        
        for(int i = 0 ;i<ans.size() ; i++)
            chars[i] = ans[i];
        
        return ans.size();
        
    }
};


// class Solution {
// public:
//     int compress(vector<char>& chars) {
//         int count = 0;
//         string ans;
//         // ans.push_back(chars[0]);
        
//         for(int i = 0 ; i<chars.size() ; i++){
//             if(chars[i] == chars[i+1])
//                 count++;
//             else{
//                 if(count > 1)
//                     ans = ans + to_string(count);
                
//                 count == 1;
//                  ans.push_back(chars[i]);
//             }
//         }
//         if(count > 1) // for last value of chars in this ex at last c  = previous character so count++ count = 3 so we push it here
//            ans = ans + to_string(count);
        
//         for(int i = 0 ;i<chars.size() ; i++)
//             chars[i] = ans[i];
        
//         return ans.size();
        
//     }
// };