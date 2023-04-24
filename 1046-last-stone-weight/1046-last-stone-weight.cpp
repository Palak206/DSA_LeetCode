// BRUTE-FORCE again sorting for inserting the element
class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
   {while(stones.size()>1){
       sort(stones.begin(),stones.end());
          int a=stones[stones.size()-1]-stones[stones.size()-2];
           stones.pop_back();
           stones.pop_back();
           stones.push_back(a);
       }
        return stones[0];
    }
};




// T.C = O(NLOGN) S.C = O(N)

// class Solution {
// public:
//     int lastStoneWeight(vector<int>& stones) {
//         int n= stones.size();
//         // sort(stones.begin(),stones.end());
//         priority_queue<int>max_heap;
//         for(int i= 0; i<n ; i++){
//             max_heap.push(stones[i]);
//         }
//         int q1, q2;// for 2 heaviest stones
//         while(n > 1){//till 1 stone is left
//             q1 = max_heap.top();
//             max_heap.pop();
//             q2 = max_heap.top();
//             max_heap.pop();
//             // so now we have pop our 2 stones in the list so decrease by 2
//             n -= 2;
            
//             if(q1  > 0){//means q1 >q2 then q1- q2 , q2 destroyed
//                 max_heap.push(q1-q2);
//                 n+=1;
//             // means 1 element add in the list q1=10,q2=7(q1>q2) 
//             // so q2 destroyed ,q1= q1-q2;
//             //and q1 inseted in the list so n+=1
                
//             }
//         }
//         if(!max_heap.empty())
//             return max_heap.top();//means the left weight we return
//         //if empty s=then ret 0
//         return 0;
        
//     }
// };