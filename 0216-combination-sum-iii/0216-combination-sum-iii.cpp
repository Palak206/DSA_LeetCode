class Solution {
public:
    vector<vector<int>> res;
    
    void solve(int ind, int k, int n ,vector<int>&temp){
        if(temp.size() == k && n==0){
            res.push_back(temp);
            return;
        }
        //each number used at once
        if(temp.size() == k && n!=0)
            return;
        
        for(int i = ind ; i<=9; i++){
            temp.push_back(i);
            solve(i+1,k,n-i,temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        solve(1,k,n,temp);
        return res;
    }
};