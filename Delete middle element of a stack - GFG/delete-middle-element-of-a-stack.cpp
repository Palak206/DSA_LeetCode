//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void solve(stack<int>&s, int k ){
        if(k == 1){
            s.pop();
            return;
        }
        int temp = s.top(); //10 20 k = 3(30)
        s.pop();
        
        solve(s, k-1);// 20 30 40 50 k= 2(30)
        s.push(temp); // 10 20 40 50
        return;
    }
    
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        if(s.size() == 0){
            return;
        }
        
        int k= sizeOfStack/2+1;
        solve(s , k);
        return;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends