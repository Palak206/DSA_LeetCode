// sort(rbegin(v),rend(v)); // Sort the vector (descending)
//without reverse return nums[n-k]
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         int n = nums.size();
//         sort(nums.begin() , nums.end());
//         reverse(nums.begin() , nums.end());
//         return nums[k-1]; 
//     }
// };


// TC: O(NLOGK);  // Priority queue (k sized)
// SC: O(K);      // K elements
// class Solution {
// public:
//     int findKthLargest(vector<int>& v, int k) {
//         priority_queue<int,vector<int>,greater<int>> pq;  //Priority queue (min heap)
//         for(auto x: v){
//             pq.push(x);   // Push all elements in pq.
//             if(pq.size()>k){  // If size(pq)>k , pop the top element.
//                 pq.pop();
//             }
//         }
//         return pq.top();  // Kth largest element
//     }
    
// };

//create a priority queue and push all the element in it
// run a loop from i=k to n
// if top of pq is < nums[i] 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Create a min-heap (priority queue) with initial k elements
        priority_queue<int, vector<int>, greater<int>> pq;
        // min heap 1 2 3 4 5 6
        int n = nums.size();
        
        for (int i = 0; i < k; i++)
            pq.push(nums[i]);
        
        // Continue adding elements and maintaining the k largest elements
        for (int i = k; i < n; i++) {
            if (pq.top() < nums[i]) { // 3 2 1 5 6 4
                pq.pop();  // Remove the smallest element
                pq.push(nums[i]);  // Add the current element
            }
        }

        return pq.top();  // The kth largest element is at the top of the heap
    }
};
