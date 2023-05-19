// approach 
// red color blue color
// if a node is blue color so their neighbours should be red color
// if a node is red color so their neighbours should be blue color
// uncolored = color[node] = 0
// Blue color = color[node] = 1 se red just do -1
// Red color = color[node] = -1 se blue  -(-1)



class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> colour(n,0);//uncoloured
        
        for(int i=0 ; i<n; i++){
            if(colour[i] != 0) //traverse all the node should be (visited)
                continue;
            
            
            queue<int> q;
            q.push(i);
            colour[i] = 1;//first node is blue
            
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                
                for(int neighbour: graph[curr]){
                    if(colour[neighbour] == 0){
                        colour[neighbour] = -colour[curr];//make red from blue
                        q.push(neighbour);
                    }
                    else if(colour[neighbour] != -colour[curr]){
                        return false;// means blue clr neigbour = red clr
                    }
                }
                
                
            }
        }
        return true;
    }
};