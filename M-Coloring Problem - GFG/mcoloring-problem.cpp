//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    //1st we assign color to each & every node and check the cond
    //check always with 1st color if nodes are adjacent then change the color 
    //go backtrack if color not match 
    
    bool isSafeToAssign(int i, int j , bool graph[101][101] , int n , vector<int>& clr){
        //checking i can assign color j to node i
        //no other neighbour node of i should hve the same color
        for(int k=0 ; k<n ; k++){
            //checking negihb      check same clr
            if(graph[i][k] == 1 && clr[k] == j) return false;
        }
        
        return true;
    }
    
    bool solve(bool graph[101][101], int m, int n , int i,vector<int>& clr){
        if(i == n) return true; //reach the end node and ssigned the clr to each node
        
        for(int j=0 ; j<m; j++){
            if(isSafeToAssign(i,j,graph,n,clr)){
                clr[i] = j;
                
                if(solve(graph , m , n, i+1,clr)) return true;//recursively call for next node
                
                //clr is not able to assign so backtrack ansassign diff clr
                clr[i] = -1;
            }
        }
        return false;
        
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        
        
        vector<int> clr(n ,-1);// initialize color -1
        
        //assign a color b/w 0 to m
        return solve(graph , m , n , 0,clr);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends