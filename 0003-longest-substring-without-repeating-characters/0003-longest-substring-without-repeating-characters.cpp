class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> Set;
        int max = 0;
        
        int start = 0; 
        int end = 0;
        
        while(start < s.size()){
            auto it = Set.find(s[start]);  //'a'
            
            if(it == Set.end()){
                if(start-end+1 > max)
                    max = start-end+1;//length of substring
                Set.insert(s[start]);
                    start++;
                
            }
                else{
                    //pop the element like abc is a substring afterc start goes to +1 that's a , already existed so pop the end of string means fisrt character a then string look's like bca and so on
                    Set.erase(s[end]);
                    end++;
                }
            }
        
        
        
        
        return max;//the length of the substring
    }
};