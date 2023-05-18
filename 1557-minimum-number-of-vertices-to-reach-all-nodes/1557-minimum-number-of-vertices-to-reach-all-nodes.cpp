// THOSE Indegree is 0 we push them in the set 
// for 1st ex indegree of 0 = 0 , 3 = 0

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
         vector<bool>visited(n);
        for(auto edge : edges){
            visited[edge[1]] = 1;
            //mark 1 all the 2nd element [0,1][0,2]
        }
        vector<int> ans;
        for(int i=0 ; i<n ; i++){
            if(visited[i] == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};