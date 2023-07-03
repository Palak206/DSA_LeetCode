class Solution {
public:
    bool buddyStrings(string s, string goal) {
       if(s.length() != goal.length() || s.length() <= 1){
           return false;
       }
        // if they are identical means s and goal are same s = aa ang goal = aa
         // sow we canswap these two number using set that 'll store unique char'
        
        if (s == goal) {
            unordered_set<char> distinctChars(s.begin(), s.end());
            return distinctChars.size() < s.length(); // we can swap it 2 times
        }
        
        vector<int> ind;
        for(int i=0 ; i<s.length() ; i++){
            if(s[i] != goal[i]){
                ind.push_back(i);
            }
        }
        
        if (ind.size() != 2) {
            return false;
        }

        swap(s[ind[0]], s[ind[1]]);
        return s == goal;
        
        }
        
    
};