//  a->1 b->2
class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        map< char , int> mp;
        int val = 1;
        int n1 = chars.size();
        for(char c = 'a' ; c<= 'z'; c++){
            mp[c] = val++;
        }
        
        for(int i=0 ; i<n1 ; i++){
            mp[chars[i]] = vals[i];// mp[char[0]] = -1000
        }
        int ans = 0, curr_sum = 0 , n2 = s.size();
        for(int i=0 ; i<n2 ;i++){
            curr_sum += mp[s[i]];
            if(curr_sum < 0) curr_sum = 0;
            
            ans = max(ans,curr_sum);
        }
        return ans;
    }
};