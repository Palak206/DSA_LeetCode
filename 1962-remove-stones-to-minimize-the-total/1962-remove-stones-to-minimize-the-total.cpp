// class Solution {
// public:
//     int minStoneSum(vector<int>& piles, int k) {
        
//         sort(piles.begin() , piles.end());
//         int count = INT_MAX;
//         // vector<int> ans(piles.size());
//          int temp = piles[0]-piles[0]/2;
        
//         for(int i = 0 ; i<piles.size() ; i++){
//              count = min(count , piles[i]);
//             return count;
//         }
//         for(int i = k ; i>0 ; i--){
           
//             if(temp<=piles[i])
//                 {
//                     piles[i] = piles[i]-piles[i]/2;
//                     // k--;
//                 }
            
//         }
//         int sum = 0;
//         for(int i = 0 ; i<piles.size() ; i++){
//             sum = sum + count+piles[i];
//         }
//         return sum;
//     }
// };

/* class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        while(k>0)
        {
            sort(piles.begin(),piles.end(),greater<int>());
            int temp = piles[0]-piles[0]/2;
            for(int i=0;i<piles.size();i++)
            {
                if(k==0)
                    break;
                if(temp<=piles[i])
                {
                    piles[i] = piles[i]-piles[i]/2;
                    k--;
                }
                else if(temp>piles[i])
                    break;
            }    
        }
        int sum =0;
        for(int i=0;i<piles.size();i++)
        {
            sum += piles[i];
        }
        return sum;
    }
};
*/


class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int sum = accumulate(piles.begin() , piles.end() , 0);
        priority_queue<int> pq(piles.begin() , piles.end());
//         priority queue means max value that is top most
        while(!pq.empty() && k--){
            int curr = pq.top();  //curr = 9  curr = 5 
             pq.pop();
            
            sum -= floor(curr/2); // 18 - f(9/2) = 18-4=14  , 14-f(5/2) = 12
            curr -= floor(curr/2);  // 9-f(9/2) = 5 , 5-5/2 = 3
            
            pq.push(curr);
            
            
        }
        return sum;
    
    
     }
};