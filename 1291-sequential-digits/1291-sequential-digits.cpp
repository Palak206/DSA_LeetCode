//BFS QUEUE ALWAYS IN DIGIT QUESTION
//1 next greter 1+1=2
//we cant take 9 bcoz it's next greater is 10 910 9>1
//1 2 3 4 5 6 7 8
//12 23 34 45 56 67 78 89
//123 234 345 456 567 678 789

//take 1%10 1+1=2 (1*10+2=12)
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int>q;
        for(int i=1; i<=8; i++){
            q.push(i);
        }
        
        vector<int>res;
        
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            
            if(temp >= low && temp <= high){
                //we found the answer
                res.push_back(temp);
            }
            
            int last_digit = temp%10;
            if(last_digit +1 <= 9){
                q.push(temp*10+(last_digit + 1));
                //1*10+(1+1) = 12
            }
        }
        return res;
        
    }
};