// APPROACH
//  We find cycle in this graph and if node has a cycle then i's not a terminal node
// terminal node is a node there are no outgoing edges
// in the 1st ex. 5,6 are terminal node 
// so now we have to find those node those are terminited eiether on 5 or 6
// and these are 2,4 because they have no cycle they directly terminated on 5

class Solution {
public:
    bool isCycleDFS(int node, vector<bool>&visited,
    vector<bool>&dfsVisited,vector<vector<int>>& graph,vector<bool>&present_cycle){
        visited[node] = true;//true
        dfsVisited[node] = true;
           
     
             //traverse all neighbour od frontnode
        vector<int>data = graph[node];
        for(auto neighbour:data){
          if (!visited[neighbour]) {
              if(isCycleDFS(neighbour, visited, dfsVisited, graph,present_cycle)){            
                 return present_cycle[node] =  true;
              }
          }
     
          else if (visited[neighbour] && dfsVisited[neighbour]) {
               return present_cycle[node]  = true;
          }
        }
        //n0ow we have to mark those visited node to unvisited
        dfsVisited[node] = false;
         return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        
        int n = graph.size();
        vector<bool>visited(n,false);
        vector<bool>dfsVisited(n,false);
//         remove the cycle that present
        vector<bool>present_cycle(n,false);
        for(int i = 0 ; i<n ; i++){
            if(!visited[i]){
               isCycleDFS(i, visited, dfsVisited, graph,present_cycle);
                    
            }
        }
        for(int i =0 ; i<n ; i++){
            //we store those node that does not in loop/cycle
            if(!present_cycle[i])
                ans.push_back(i);
        }
        return ans;
    }
};