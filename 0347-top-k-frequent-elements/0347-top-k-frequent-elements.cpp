class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
//         int n = nums.size();
//         unordered_set<int> st;
//         priority_queue<int> pq;
//         for(int i=0 ; i<n ; i++){
//             st[nums[i]]++;
//         }
//         for(int i=0 ; i<n ; i++){
            
//         }
          unordered_map<int,int> mp;
          priority_queue<pair<int,int>>pq;
          
          for(auto c: nums){
              mp[c]+=1;
          }
          for(auto m: mp){
              pq.push(make_pair(m.second,m.first));
          }
          vector<int>ans;
          for( int i =0;i<k ; i++){
              ans.push_back(pq.top().second);
              pq.pop();
          }
          
        return ans;
    }
};