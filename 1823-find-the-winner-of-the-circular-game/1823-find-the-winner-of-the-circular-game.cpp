// index+(k-1)%n = if circular h
class Solution {
public:
    void solve(vector<int>&v , int k , int index, int& ans){
        if(v.size() == 1){
            ans = v[0];
            return;
        }
        index = (index +k)%v.size();
        v.erase(v.begin() + index); //remove that index 
        solve(v, k,index, ans);
        return;
    }
    int findTheWinner(int n, int k) {
        vector<int>v;
        for(int i=1 ; i<=n ; i++){
            v.push_back(i);
        }
        k = k-1;
        int index = 0;
        int ans = -1; //v[0]
        solve(v, k,index, ans);
        return ans;
    }
};