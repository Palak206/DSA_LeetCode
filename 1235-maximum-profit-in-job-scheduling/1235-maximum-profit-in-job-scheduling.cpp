// // 1->3 ka profit = 50
// // 2->4 ka profit = 10
// // 3->5 ka profit = 40
// // 3->6 ka profit = 70

// // so first we take start[i] = 1 end[i] = 3 it's overlaping with s=2,e=4 
// //so we will not consider 2nd profit take, not take(dp ques min,max,optimize)
// //max(50+40 ,50+70) = 120

// //sort it according to start time
// class Solution {
// public:
//     int n;
    
//     //BINARY SEARCH
//     //l=startingpoint 
//     int getNextIndex(vector<vector<int>>& arr , int l ,int end){
//         int r = n-1;
        
//         int res = n+1 ;
        
//         while(l <= r){
//             int mid = l+(r-l)/2;
//             //start point ending se jyada otherwise overlap 
//             // if(arr[i][0] >= arr[i][1])
            
//             if(arr[mid][0] >= end){//we can take it
//                 res = mid;
//                 //if duplicates s[1,2,3,3] so i chosse that come first
//                 r = mid-1;//go left
                
//             }
//             else{
//                 l==mid+1; //overlap;
//             }
//         }
//         return res;
        
//     }
    
//     int solve(vector<vector<int>>& arr, int i){
//         if(i>=n){
//             return 0;//no profit
//         }
        
        
//         int next = getNextIndex(arr ,i+1, arr[i][1]);//ending point a[i][1]
        
//         //take = 50+solve()
//         int take = arr[i][2] + solve(arr , next);
        
//         int notTake = solve(arr, i+1);
        
//         return max(take, notTake);
//     }
    
//     int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
//         n = startTime.size();
        
//         vector<vector<int>> arr(n, vector<int>(3,0));//(strt,end,profit)
//         //push s,e,p into arr
//         for(int i=0; i<n; i++){
//             arr[i][0] = startTime[i];
//             arr[i][1] = endTime[i];
//             arr[i][2] = profit[i];
//         }
        
//         auto comp = [&](auto& vec1, auto& vec2){
//             return vec1[0] <= vec2[0];
//         };
        
//         //sort it according to start time
//         sort(arr.begin(), arr.end(), comp);
//         //we use comp or not 
//         //by deafault it sort it according to starttime
        
//         return solve(arr,0);
//     }
// };


//MEMO
class Solution {
public:
    int t[50001]; //next is changing
    int n;
    
    //BINARY SEARCH
    //l=startingpoint 
    int getNextIndex(vector<vector<int>>& arr , int l ,int end){
        int r = n-1;
        
        int res = n+1 ;
        
        while(l <= r){
            int mid = l+(r-l)/2;
            //start point ending se jyada otherwise overlap 
            // if(arr[i][0] >= arr[i][1])
            
            if(arr[mid][0] >= end){//we can take it
                res = mid;
                //if duplicates s[1,2,3,3] so i chosse that come first
                r = mid-1;//go left
                
            }
            else{
                l=mid+1; //overlap;
            }
        }
        return res;
        
    }
    
    int solve(vector<vector<int>>& arr, int i){
        if(i>=n){
            return 0;//no profit
        }
        
        if(t[i] != -1)
            return t[i];
        
        int next = getNextIndex(arr ,i+1, arr[i][1]);//ending point a[i][1]
        
        //take = 50+solve()
        int take = arr[i][2] + solve(arr , next);
        
        int notTake = solve(arr, i+1);
        
        return t[i]  = max(take, notTake);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        
        memset(t, -1, sizeof(t));
        vector<vector<int>> arr(n, vector<int>(3,0));//(strt,end,profit)
        //push s,e,p into arr
        for(int i=0; i<n; i++){
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
        }
        
        auto comp = [&](auto& vec1, auto& vec2){
            return vec1[0] <= vec2[0];
        };
        
        //sort it according to start time
        sort(arr.begin(), arr.end(), comp);
        //we use comp or not 
        //by deafault it sort it according to starttime
        
        return solve(arr,0);
    }
};