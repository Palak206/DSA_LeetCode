// using Priority queue
//TC = O(MLOGN)+O(MLOGK)+O(K)
class Solution{
 public:
     typedef pair<int,int>P;
    
      int binarySearch(vector<int>& arr, int l , int r){
          int res = -1;
          int mid;
          
          while(l<=r){
              mid = l+(r-l)/2;
              
              if(arr[mid] == 1){
                  res = mid;
                  l = mid+1; //if mid point se age bhi 1 h so l= mid+1
              }
              
              else{
                  r = mid-1;//right
              }
          }
          return res+1;//+1 bcoz we have to sent count of one
      }
    
      vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
          int m = mat.size();//rows
          int n = mat[0].size(); //col
          
          priority_queue<P> pq;//max-heap
          
          //O(m*log(n)) + O(m*log(k))
          for(int row = 0; row<m; row++){
              int num_of_ones = binarySearch(mat[row] , 0 , n-1);
              
              pq.push({num_of_ones , row});
              
              if(pq.size() > k)
                  pq.pop();
          }
          
          vector<int> res(k);
          int j= k-1;//bcoz when we pop from the pq big element left first
          while(!pq.empty()){
              P temp = pq.top();
              pq.pop();
              
              res[j] = temp.second;
              j--;
          }
          return res;
      }
};



// class Solution {
// public:
    
//     vector<int> Weakest(vector<vector<int> >& mat, int k)
//     {
       
//         int n = mat.size();
        
     
//         // count of 1 in ith row, {count,index};
//         set<pair<int,int> > s;
        
//         // set will automatically sort the pair {count, index} in ascending order.
        
//         for(int i = 0; i<n; ++i)
//         {
//             // stl function for counting frequency of 1 in current row
//             int cnt = count(mat[i].begin(),mat[i].end(),1);
//             // inserting cnt and index pair to set
//             s.insert({cnt,i});
//         }
        
//         vector<int> ans;
//         // first k weakest row is our answer 
//         for(auto i : s)
//         {
//             if(k == 0)
//                 break;
//             ans.push_back(i.second);
//             --k;
//         }
        
//         return ans;
//     }
    
    
//     vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

//         return Weakest(mat,k);
        
//     }
	
// };

// soldier(1) in each row = 2 4 1 2 5
//indices of weakest rows = 0 1 2 3 4 
//ans k= 3   [ 2, 0 , 3 ,1, 4]
// class Solution{
//  public:
//      typedef pair<int,int>P;
//       vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
//           int m = mat.size();//rows
//           int n = mat[0].size(); //col
          
//           vector<P> countOnes;//{1's count , row}
          
//           for(int row = 0; row<m; row++){
//               int num_of_ones = count(mat[row].begin(),mat[row].end(),1);
//               countOnes.push_back({num_of_ones , row});
//           }
          
//           sort(countOnes.begin() , countOnes.end());
          
//           vector<int>ans;
//           for(auto i : countOnes){
//               if(k==0)
//                   break;
//               ans.push_back(i.second);
//               k--;
//           }
          
//           return ans;
//       }
// };

//without count func using binary search bcoz decendent order h que 1 1 0 0 0
//O(mlogn)+O(mlogm)+O(k) = t.c , s.c = O(m)
// class Solution{
//  public:
//      typedef pair<int,int>P;
    
//       int binarySearch(vector<int>& arr, int l , int r){
//           int res = -1;
//           int mid;
          
//           while(l<=r){
//               mid = l+(r-l)/2;
              
//               if(arr[mid] == 1){
//                   res = mid;
//                   l = mid+1; //if mid point se age bhi 1 h so l= mid+1
//               }
              
//               else{
//                   r = mid-1;//right
//               }
//           }
//           return res+1;//+1 bcoz we have to sent count of one
//       }
    
//       vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
//           int m = mat.size();//rows
//           int n = mat[0].size(); //col
          
//           vector<P> countOnes;//{1's count , row}
          
//           for(int row = 0; row<m; row++){
//               int num_of_ones = binarySearch(mat[row] , 0 , n-1);
              
//               countOnes.push_back({num_of_ones , row});
//           }
//           sort(countOnes.begin() , countOnes.end());
          
//           vector<int> res(k);
//           for(int i=0 ; i<k ; i++){
//               res[i] = countOnes[i].second;
//           }
//           return res;
//       }
// };