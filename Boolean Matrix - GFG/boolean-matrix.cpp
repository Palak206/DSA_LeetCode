//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        // code here
        int n= matrix.size();
        int m = matrix[0].size();
        
        bool arr_row[n];  fill(arr_row, arr_row+n , false);   // 0+n  0 is the starting index
        bool arr_col[m]; fill(arr_col, arr_col+m , false);  // 0+m  0 is the starting index
        
        for(int i=0 ; i<n ; i++){
            
            for(int j=0; j<m; j++){
                
                if(matrix[i][j] == 1){
                  arr_row[i] = true;
                  arr_col[j] = true;
               }
            
           }
            
        }
        // make row 1
        for(int i=0 ; i<n ; i++){
            if(arr_row[i]){ //that row we have to make it 1 col & row
                for(int j=0 ; j<m ; j++){
                    matrix[i][j] = 1;
                }
            }
        }
        
        //make col 1
        for(int i=0 ; i<m ; i++){
            if(arr_col[i]){ //that row we have to make it 1 col & row
                for(int j=0 ; j<n ; j++){
                    matrix[j][i] = 1;//col fix
                }
            }
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



// } Driver Code Ends