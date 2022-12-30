//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    // step 1 pop k element into the queue and push it in the stack
    stack<int> s;
    for(int i = 0 ; i<k ; i++){
        int val = q.front();
        q.pop();
        s.push(val);
    }
    
    // fetch k element and push it in the queue
    while(!s.empty()){
        int val = s.top();
        s.pop();
        q.push(val);
    }
    
    // step 3 fetch n-k element and push it to the queue
    int t = q.size()-k;
    while(t--){
        int val = q.front();
        q.pop();
        q.push(val);
    }
    
    return q;
}