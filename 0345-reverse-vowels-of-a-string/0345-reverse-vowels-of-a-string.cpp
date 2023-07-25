class Solution {
public:
    bool isVowel(char ch){
        // ch = tolower(ch);
        // return (ch =='a' || ch =='e' || ch == 'i' || ch =='o' || ch =='u' ) ;
        return (ch=='a' || ch=='A' || ch=='e' || ch=='E' || ch=='i'|| ch=='I'|| ch=='o'|| ch=='O' || ch=='u'|| ch=='U');
    }
    string reverseVowels(string s) {
        int n = s.size();
        int i=0, j= n-1;
        
        while(i<j){
            if(!isVowel(s[i])) 
                i++;
            else if(!isVowel(s[j]))
                 j--;
            else if(i<j){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            
        }
          return s;
    }
};