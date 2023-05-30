//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
void rotate (vector<vector<int> >& matrix);


// } Driver Code Ends
//User function template for C++

/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
void rotate(vector<vector<int> >& matrix)
{
    int n = matrix.size();
    // Your code goes here
    
    // first we find the transpose of the matrix
    for(int i=0; i<n ; i++){
        for(int j = 0 ; j<=i ; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    //swap the uppermost and lowermost row
    // n/2 bcoz of pair in 3*3 matrix index 0 pair 2 and st row as it s
    //in even no. of matrix 4*4 0 pair 3 ,1 pair 2 swap it
    for(int i =0 ; i<(n/2) ; i++){
        for(int j=0 ; j<n ; j++){
            swap(matrix[i][j] , matrix[n-1-i][j]);//n-1-i to find pair 5-1-0=4, 5-1-1= 3
        }
    }
}


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t; 
    while(t--)
    {
        int n;
        cin>>n; 
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}


// } Driver Code Ends