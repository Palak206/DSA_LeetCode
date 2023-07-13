// so the question is saying before taking course bi we have to take course ai
//  ai -> bi so this is a directed graph there is a loop(deadlock ,cycle)
//so we  use topological sort if there is a cycle then it's false
class Solution {
public:
    bool topoSort(int s,vector<bool> &visited,vector<bool> &curr_visited, vector<int>adjList[] ){
        visited[s] = true;
        curr_visited[s] = true;
        
        // vector<int>data = neighbour;
            for(auto neighbour : adjList[s]){
                  if(!visited[neighbour]){
                      if(topoSort(neighbour, visited, curr_visited, adjList)){
                          return true;
                      }
                  }
                else if(visited[neighbour] && curr_visited[neighbour] ){
                    return true;
                }
              }
              // whenever we go back to the node we push
              //  that node in the stack
             curr_visited[s] = false;
             return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n= numCourses;
        vector<bool> visited(n ,false) ,curr_visited(n,false);
        
        vector<int>adjList[n];
        for(int i = 0; i<prerequisites.size() ; i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
           //directed acyclic graph
           adjList[u].push_back(v);
        }
        for(int i = 0; i<n ; i++){
            if(!visited[i]){
                if(topoSort(i,visited,curr_visited,adjList)){
                      return false;//if cycle present
                }
            }
                
        }
        return true;

    }
};