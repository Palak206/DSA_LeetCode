// class Solution {
// public:
//     bool isSafe(int row, int col ,vector<vector<char>>& board, int val ){
//         for(int i=0; i<board.size() ; i++){
//             //row check
//             if(board[row][i] == val)
//                 return false;//if same val already in the row then false
            
//             //col check
//             if(board[i][col] == val)
//                 return false;//if same val already in the col then false
            
//             //3*3 matrix check all elemnt should once
//             if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val)
//                 //check (0,0) (0,1) (0,2).... (0,8)
//                 //3*(0/3)+0/3] = 0 [3*(0/3) + 0%3] = 0+0=0 (0,0) i=0,r=0,c=0
                
//                 //[3*(0/3)+1/3]= 0 [3*(1/3)+ 1%3]= 0+1 = 1 (0,1) i=1 , r=0 , c=1
                
//                 // for i= 3 
//                 //[3*(0/3) + 3/3] = 1 [3*(1/3) + 3%3] = 0 (1,0)
//                 //we have to check 3*3 matrix
                
//                 return false;
//         }
//         return true;
//     }
    
//     bool solve(vector<vector<char>>& board){
//         int n= board[0].size();
        
//         for(int row = 0 ; row < n ; row++){
//             for(int col = 0 ; col < n ; col++){
                
//                 // if cell empty so we cn insert val
//                 if(board[row][col] == 0){
//                     for(int val = 1 ; val<=9; val++){
//                         if(isSafe(row,col,board,val)){
//                             //then push the val
//                             board[row][col] = val;
                            
//                             //recursive call
//                             bool isSolPos = solve(board);
//                             if(isSolPos)
//                                 return true;//sol possible
                            
//                             else{
//                                 //backtrack
//                                 board[row][col] = 0;//make them 0 from starting
//                             }
                                
//                         }
//                     }
//                     return false;//if not possible
//                 }
//             }
            
//         }
//         return true;
//     }
    
    
//     void solveSudoku(vector<vector<char>>& board) {
//         // vector<vector<char>>ans;
        
//         solve(board);
//     }
// };


class Solution {
public:
     bool isValid(vector < vector < char >> & board, int row, int col, char c){
       for (int i = 0; i < 9; i++) {
           if (board[i][col] == c)
             return false;
       
           if (board[row][i] == c)
             return false;
       
           if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
             return false;
       }
       return true;
     }
     
     bool solve(vector < vector < char >> & board) {
       for (int i = 0; i < board.size(); i++) {
         for (int j = 0; j < board[0].size(); j++) {
           if (board[i][j] == '.') {
             for (char c = '1'; c <= '9'; c++) {
               if (isValid(board, i, j, c)) {
                 board[i][j] = c;
     
                 if (solve(board))
                   return true;
                 else
                   board[i][j] = '.';
               }
             }
     
             return false;
           }
         }
       }
       return true;
     }
    
     void solveSudoku(vector<vector<char>>& board) {
        // vector<vector<char>>ans;
        
        solve(board);
    }	
         // for(int i= 0; i< 9; i++){
         //     for(int j= 0; j< 9; j++)
         //         cout<<board[i][j]<<" ";
         //         cout<<"\n";
         // }
         // return 0;
};