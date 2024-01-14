class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>m1(26,0);
        vector<int>m2(26,0);
        
        for(char ch : word1){
            m1[ch-'a']++;
        }
        
        for(char ch : word2){
            m2[ch-'a']++;
        }
        
        for(int i=0; i<26; i++){
            if((m1[i] == 0 && m2[i] != 0) || (m1[i] != 0 && m2[i] == 0))
               return false;
        }
        //sort both string
        sort(m1.begin(), m1.end());
        sort(m2.begin(), m2.end());
               
        for(int i=0; i<26; i++){
            if(m1[i] != m2[i])
                return false;
        }
    
        return true;
    }
};