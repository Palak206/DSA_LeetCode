//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    //arrival time count = increase departure time = decrease
    //   then max = increase
    // count = 1 0 1 2 3 2(d) 1(d) 0(d) 1(a) 2(a) 1(d) 0(d)
    //max =  1 2 3
    //sort
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr , arr+n);
    	sort(dep , dep+n);
    	
    	int count = 1;
    	int ans = 1;
    	
    	int i=1;//arrival
    	int j=0;//depature
    	
    	while(i < n && j < n){
    	    if(arr[i] <= dep[j]){
    	        count++;
    	       // maxi = max(maxi, count);
    	        i++;
    	    }
    	    else if(arr[i] > dep[j]){
    	        count--;
    	        j++;
    	    }
    	    if(count > ans){
    	        ans = count;
    	    }
    	}
    	return ans;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends