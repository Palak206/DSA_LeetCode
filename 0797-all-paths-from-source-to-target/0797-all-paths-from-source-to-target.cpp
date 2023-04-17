class Solution {
public:
     vector<vector<int>>ans;
    void dfs(int u,vector<vector<int>>& graph,vector<int>&v ){
        if(u == graph.size() - 1){
            ans.push_back(v);
        }
        for(int i = 0 ; i<graph[u].size() ; i++){
            v.push_back(graph[u][i]);
            dfs(graph[u][i]  ,graph ,v);
            v.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>v;
        ans.clear();
        v.push_back(0);//0 to n-1
        dfs(0,graph,v);
        return ans;
    }
};