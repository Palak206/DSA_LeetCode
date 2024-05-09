// class Solution {
// public:
//     long long maximumHappinessSum(vector<int>& happiness, int k) {
//         int n = happiness.size();
//         sort(happiness.begin(), happiness.end(), greater<int>()); //5 4 3 2 1
        
//         int turns = 0;
//         long long sum = 0;
        
//         for(int i=0; i<k; i++){
//             sum += max(happiness[i]-turns, 0);
            
//             turns++;
//         }
//         return sum;
//     }
// };


//priority queue

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        
        priority_queue<int> pq; //max hep
        
        for(int i=0; i<n; i++){
            pq.push(happiness[i]);
        }
        
        int turns = 0;
        long long sum = 0;
        
        for(int i=0; i<k; i++){
            sum += max(pq.top() - turns, 0);
            pq.pop();
            turns++;
        }
        return sum;
    }
};