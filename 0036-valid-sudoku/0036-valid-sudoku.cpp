class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rowcase[9][9] = {0};
        int colcase[9][9] = {0};
        int gridcase[9][9] ={0};
        
        for(int i=0 ; i<board.size() ; i++){
            for(int j = 0; j<board[0].size() ; j++){
                // if it's a number
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0';
                    
                    int k= i/3*3+j/3;
                    //k denotes grid number
                    
                    //check for the 3 case
                    if(rowcase[i][num-1]++ || colcase[j][num-1]++ 
                       || gridcase[k][num-1]++ )
                        return false;
                }
            }
        }
        return true;
    }
};