//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
//we canot include 0 in the output bcz no. of 1 > no of 0's
class Solution{
public:	
    void solve(int ones , int zeros,int N,string op,vector<string>& ans){
        if(N == 0){
            ans.push_back(op);
            return;
        }
        
        string op1 = op;
        op1.push_back('1');
        solve(ones+1 ,zeros , N-1, op1 ,ans);
        
        if(ones > zeros){
            string op2 = op;
            op2.push_back('0');
            solve(ones ,zeros+1 , N-1, op2,ans );
        }
        return;
        
    }
	vector<string> NBitBinary(int N)
	{
	    // Your code goes here
	    vector<string> ans;
	    int zeros = 0;
	    int ones= 0;
	    
	    string op = "";
	    
	    solve(ones ,zeros, N, op , ans);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends