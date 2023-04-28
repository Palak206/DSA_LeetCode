// it 's done by graph(connceted group is mention in que)'
// tars ,rsts  = similar (RaTs) {0->1} {1->0}
// rats", "arts = similar(ARts) {1->2} {2->1} so 1 group
// star is not similar with anyone ,1 grop 
// total = 1+1 = 2

// so we make a visited array [0 ,1 ,2 ,3] so we start with 0 make it visited 
// store 1 in ans visited(0)
// then visited 1 visited(1)
// then visited 2(visited 2 )
//  2 is  connected with(1) that's already visited
//  make visited 3 and store ans 1 = 1+1 =2


class Solution {
public:
    vector<int> adj[305];
    int vis[305];
    
    void dfs(int node ){
        vis[node] = 1;
        for(auto u:adj[node]){
            if(!vis[u])
                dfs(u);
        }
    }
    
    bool similar(string s , string t){
        int n= s.size();
        int c= 0;
        for(int i= 0; i<n ; i++){
            if(s[i] != t[i]){
                c++;
                if(c>2)
                    return false;
            }
        }
        return true;
    }
    
    
    int numSimilarGroups(vector<string>& strs) {
        int n= strs.size();
       
        for(int i= 0 ; i<n ; i++){
            for(int j= i+1 ; j<n ; j++){
                if(similar(strs[i] , strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
       
        int ans = 0;
        for(int i = 0 ; i<n ; i++){
             if(!vis[i]){
                 dfs(i);
                 ans++;
             }
        }
        return ans;
    } 
};