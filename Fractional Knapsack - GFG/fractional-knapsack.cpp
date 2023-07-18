//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    
    bool static comp(Item a, Item b){
        double r1 = (double)a.value / (double)a.weight; // 60/10 = 6
        double r2 = (double)b.value / (double)b.weight; //100/20 = 5
        // 60/10 , 100/20 , 120/30 = 6, 5 ,4
        return r1 > r2;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr , arr+n , comp);
        
        int curWeight = 0;
        double finalVal = 0.0;
        
        for(int i=0; i<n ; i++){
            if(curWeight + arr[i].weight <= W){
                curWeight += arr[i].weight;
                finalVal += arr[i].value;
            }
            
            else{
                int remain = W - curWeight;// 50 - 30 = 20
                finalVal += (arr[i].value / (double)arr[i].weight)*(double)remain;
                // f =  100 + 60 + (120/3)*20 = 240.00
                break;
            }
        }
        return finalVal;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends