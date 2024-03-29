class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>adj[n];
        for(int i = 0 ; i<edges.size() ; i++){
                 int u = edges[i][0];
                 int v = edges[i][1]; // fisrt and second becoz int
             
                 adj[u].push_back(v); // directional
                 adj[v].push_back(u);
              
        }
        // vector<int>adj[n];
        //     for(auto it:edges){
        //     adj[it[0]].push_back(it[1]);
        //     adj[it[1]].push_back(it[0]);
        // }
        vector<int>vis(n,0);
        queue<int>q;
        q.push(source);
        vis[source]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto neighbour:adj[node]){
                if(!vis[neighbour]){
                    vis[neighbour]=1;
                    q.push(neighbour);
                }
                // if(destination==it){
                //     return true;
                // }

            }


        }
        if(vis[source]==1 && vis[destination]==1) 
             return true;
        return false;

    }
};