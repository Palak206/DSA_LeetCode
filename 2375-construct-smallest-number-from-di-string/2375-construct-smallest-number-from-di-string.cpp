// if pattern size is n then answer size n+1
class Solution {
public:
    bool check(vector<char>&v , string pattern){
        for(int i=0 ; i<pattern.size(); i++){
            if(pattern[i] == 'I' && v[i+1]>v[i]){
                //1 2 = 2> 1
                continue;
            }
            else if(pattern[i] == 'D' && v[i+1]<v[i]){
                //12354 = IIID
                continue;
            }
            else{
                return 0;
            }
        }
        return 1;
    }
    string smallestNumber(string pattern) {
        int n= pattern.size();
        vector<char>v;
        
        for(int i=1; i<=n+1; i++){
            v.push_back(i+'0'); //n=5 12456
        }
        
        while(1){
            if(check(v,pattern)){ //if satisfy the cond
                string ans;
                for(int i=0; i<v.size() ; i++){
                    ans.push_back(v[i]);
                }
                return ans;
            }
            //if not satisfy the we return next permutation
            next_permutation(v.begin() , v.end());
        }
    }
};