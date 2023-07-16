// class Solution {
// public:
//     bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
//         string s1 = " " ;
//         string s2 = " " ;
        
//         for(int i=0 ; i<word1.size() ; i++){
//             s1 += word1[i];
//         }
//         for(int i=0 ; i<word2.size() ; i++){
//             s2 += word2[i];
//         }
        
//         if(s1 == s2)
//             return true;
//         return false;
        
//         // return s1 == s2;
        
//     }
// };


class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2){
        int n = word1.size();
        int m = word2.size();
        
        int w1i = 0; int i = 0;
        int w2i = 0; int j = 0;
        
        while(w1i < n && w2i < m){
            if(word1[w1i][i] != word2[w2i][j]) // means 2nd cse c != b
                return false;
            //if equal
            i++;
            j++;
            
            if(i == word1[w1i].length()){//1st test case w1i = a size = 1 = 1
                i = 0;
                w1i++; // now pointind to c
                
            }
            
            if(j == word2[w2i].length()){
                j = 0;
                w2i++; 
                
            }
            
        }
        // if we have seen whole words in the array and not find any word equal to another word then we return false
        if(w1i == n && w2i == m)
            return true;
        return false;
    }
};