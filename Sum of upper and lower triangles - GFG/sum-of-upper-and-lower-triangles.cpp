//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to return sum of upper and lower triangles of a matrix.
    vector<int> sumTriangles(const vector<vector<int> >& matrix, int n)
    {
        // code here
        vector<int>ans;
        int upper_sum=0;
        for(int i=0 ; i<n ; i++){
            for(int j=n-1 ; j>=i ; j--){
                // if(i<=j){
                    upper_sum += matrix[i][j];
                // }
                
            }
        }
        
        int lower_sum=0;

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<=i ; j++){
                // if(j <= i){
                    lower_sum += matrix[i][j];
                   
                // }
                
            }
        }
        
        ans.push_back(upper_sum);
        ans.push_back(lower_sum);
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }
        Solution ob;
        vector<int> result = ob.sumTriangles(matrix,n);
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends