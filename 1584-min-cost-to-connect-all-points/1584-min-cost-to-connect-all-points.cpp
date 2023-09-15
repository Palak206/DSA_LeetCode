class Solution {
public:
    typedef pair<int,int>P;
    
    int PrimsAlgo(vector<vector<P>> adj , int V)
    {
        // code here
        priority_queue<P, vector<P>, greater<P>> pq; //min-heap
        //{wt,node,parent} but in que {wt,node}
        
        pq.push({0,0});
        vector<bool> inMST(V, false);
        int sum =0;
        
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            
            int wt = p.first;
            int node = p.second;
            
            if(inMST[node] == true)
                 continue;
            
            inMST[node] = true; // inMST added to oue mst
            sum += wt;
            
            for(auto &tmp : adj[node]){
                
                int neighbour = tmp.first;
                int neighbour_wt = tmp.second;
                
                if(inMST[neighbour] == false){
                    //if not visited
                    pq.push({neighbour_wt, neighbour});
                }
            }
        }
        return sum;
    }
    
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        vector<vector<P>> adj(n);
        
        for(int i=0; i<n ; i++){
            for(int j=i+1; j<n ; j++){
                
                int x1 = points[i][0];
                int y1 = points[i][1];
                
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                int dis = abs(x1-x2) + abs(y1-y2);
                
                adj[i].push_back({j,dis}); // dis from i to j
                adj[j].push_back({i,dis}); // dis from j to i
            }
        }
        
        return PrimsAlgo(adj,n);
    }
};