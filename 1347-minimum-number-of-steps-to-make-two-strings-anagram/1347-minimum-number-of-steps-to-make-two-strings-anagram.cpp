class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        vector<int>mp1(26,0);
        vector<int>mp2(26,0);
        
        //count the freq of each character
        for(char ch : s){
            mp1[ch-'a']++;
        }
        
        for(char ch : t){
            mp2[ch-'a']++;
        }
        
        int ans =0;
        
        for(int i=0; i<26; i++){
            if(mp1[i] > mp2[i]){
                ans += abs(mp1[i]-mp2[i]);
            }
        }
        return ans;
    }
};