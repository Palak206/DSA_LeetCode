// when it's your turn do your best (MAX)
// when it's your opponent turn expect the worst from the result (MIN)
//       (i+1 , j)p2 -> i+1+1 , (i+2 , j) p1
//     /           \           (i+1 , j-1) p2
// p1(i-j)
//     \  (i , j-1)p2 -i- (i+1 , j-1)
//              j-1  \     (i , j-2)
            //        i      j
            //       [1, 5 , 2]= 8
            //   2+1 /         \2+1 = 3
            // 2 (5, 2)        (1 , 5) 1

// we have 2 choices we can use memoriazation t.c = O(2^N)
class Solution {
public:
    int t[23][23];
    int solve(int i , int j, vector<int>& nums ){
        
        if(i>j)
            return 0;
        
        if(i == j){
            return nums[i];
        }
        
        if(t[i][j] != -1)
            return t[i][j];
        
        int take_i = nums[i] + min(solve(i+2, j, nums), solve(i+1,j-1,nums));
        //worst expect
        int take_j = nums[j] + min(solve(i, j-2, nums), solve(i+1,j-1,nums));
        
        //we have to return best so consider player 1
        return max(take_i, take_j);
        
    }
    bool PredictTheWinner(vector<int>& nums) {
        memset(t , -1 , sizeof(t));
        int n= nums.size();
        
        int total_score = 0;
        
        for(int i=0 ;i<n ; i++){
            total_score += nums[i];
        }
        
        int player1_score = solve(0, n-1 , nums); // 3
        
        int player2_score = total_score - player1_score; //8-3
        
        return player1_score >= player2_score;
        
    }
};