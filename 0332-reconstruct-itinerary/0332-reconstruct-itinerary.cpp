// make a graph
// sort(adj me jo neighbour hai -> lexically)
// do dfs(jfk , path)
// if we cover all the cities then put that on the result
// resultpath.size = num_ticket+1 (jfk , a , jfk , b33)
class Solution {
public:
    unordered_map<string,vector<string>> adj;
    vector<string>res;
    int numTickets = 0;
    
    bool DFS( string fromAirport, vector<string> &path){
        path.push_back(fromAirport);
        
        if(path.size() == numTickets+1){
            res = path;
            return true;
        }
        
        //cycle 2nd example
        vector<string>& neighbours = adj[fromAirport];
        
        for(int i=0 ; i<neighbours.size() ; i++){
            string toAirport = neighbours[i];
            
            //remove from now
            neighbours.erase(neighbours.begin() + i);
            
            if(DFS(toAirport, path) == true)
                return true;
            
            neighbours.insert(neighbours.begin() + i, toAirport);
        }
        //if we dont find ans after the loop
        path.pop_back();
        return false;
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //grph
        numTickets = tickets.size();
        
        for(auto &t : tickets){
            string u = t[0];
            string v = t[1];
            
            adj[u].push_back(v);
        }
        
        //sorting for lexicl order
        for(auto &edges : adj){
            sort(begin(edges.second), end(edges.second));
        }
        
        vector<string>path;
        DFS("JFK" , path);
        
        return res;
    }
};