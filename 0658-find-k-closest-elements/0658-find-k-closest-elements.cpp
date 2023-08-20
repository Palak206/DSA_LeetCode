// class Solution {
// public:
//     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//        int left = 0;
//         int right = arr.size() - k;
        
//         while(left < right){ 
//             int mid = (left + right) / 2;
//             if(x-arr[mid] > arr[mid+k]-x){
//                 left = mid + 1;
//             }else {
//                 right =0 mid;
//             }
//         }
//         return vector<int>(arr.begin()+left, arr.begin()+left+k);
    
//     }
// };

//  1 2 3 4 5  we substract all the ele by x
//  2 1 0 1 2  sort 0 1 1 2 2
//we have to find closest ele we use max heap that 'll pop greater element'
// (2 ,5)
//  2 1
//  1 4
//   1 2
//   0 3
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x){
        priority_queue<pair<int , int>> pq;
        vector<int>ans;
        for(int i=0 ; i<arr.size(); i++){
            pq.push({abs(arr[i] - x), arr[i]});
            if(pq.size() > k){
                pq.pop();
            }
        }
        while(pq.size() > 0){
           ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};