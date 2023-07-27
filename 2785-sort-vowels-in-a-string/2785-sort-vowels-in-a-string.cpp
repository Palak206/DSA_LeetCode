// 1st i push allthe vowels in a vector
// then i sort it according to ascii val
class Solution {
public:
    bool isVowel(char ch){
        // ch = tolower(ch);
        return (ch =='a' || ch =='e' || ch == 'i' || ch =='o' || ch =='u'
        || ch =='A' || ch =='E' || ch == 'I' || ch =='O' || ch =='U') ;
        
    }
    string sortVowels(string s) {
        vector<char>st;
        for(int i=0 ;i<s.size() ; i++){
            if(isVowel(s[i])){
                st.push_back(s[i]);
            }
        }
        sort(st.begin() , st.end());
        
        int j =0;
        for(int i=0 ; i<s.length() ; i++){
            if(isVowel(s[i])){
                s[i] = st[j];
                j++;
            }
        }
        return s;
    }
};