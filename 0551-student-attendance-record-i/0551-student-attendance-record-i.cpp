class Solution {
public:
   
    bool checkRecord(string s) {
        int countA=0, countL=0;
        for(int i = 0 ; i<s.length() ; i++){
            if(s[i] == 'A'){
                countA++;
                if(countA >=2)
                    return false;
             // countL = 0;
            }
            
            if(s[i] == 'L'){
                countL++;
                if(countL >= 3)
                    return false;
            }
            else countL = 0;
            
        }
        
        return true;
    //     int abs=0, late=0;
    //     for (int i=0; i<s.size(); i++){
    //         if (s[i]=='A'){
    //             abs++;
    //             if (abs>=2)return false;
    //         }
    //         if (s[i]=='L'){
    //             late++;
    //             if (late>=3)return false;
    //         }
    //         else late=0;
    //     }
    //     return true;
    // }
        
    }
};

