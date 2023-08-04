// class Solution {
// public:
//     int maximumScore(int a, int b, int c) {
//         int maxi = max(a, b, c);
//         int mini = min(a, b, c);
//         int cnt = 0;
        
//         while(maxi){
//             maxi--;
//             mini--;
//             cnt++;
            
//             if(mini == 0){
//                 int mn = min
//             }
//         }
//     }
// };


class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int ans=0;
        priority_queue<int> pq;
        
        // pushing all three number to track the first two largest score
        // 4,6
        pq.push(a);
        pq.push(b);
        pq.push(c);
        
        // we will continue to increase the score by one 
        // until two non empty piles is present
        
        while(!pq.empty()){
            int m1;
            
            if(pq.top() > 0){
                m1 = pq.top();
                pq.pop();
            }
            //2nd largest element
            int m2;
            
            if(pq.top() > 0){
                m2 = pq.top();
                pq.pop();
            }
            else{
                break;
            }
            pq.push(m1-1);
            pq.push(m2-1);
            ans++;
            
        }
        return ans;
    }
};

