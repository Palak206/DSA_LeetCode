//(r-1,c-1)    (r-1, c+1)
//   .    .     .
//   .    Q     .
//   .    .     .
//(r+1,c-1)   (r+1, c+1)


class Solution {
public:
    
    bool inBound(int i, int j, int n){
        if(i<0 || j<0 || i>=n || j>=n)
            return false;//out of the bound
        return true;
    }
    
    bool isSafe(int r, int c , vector<string>temp , int n){
        for(int k=0 ; k<n ; k++){
            //if queensis same row and col then cond false
            if(temp[k][c] == 'Q' || temp[r][k] == 'Q')
                return false;
        }
        
        //then check for diagonals
        for(int l=0; l<n ; l++){
            if(inBound(r-l, c-l, n) && temp[r-l][c-l] == 'Q')
                return false;
            if(inBound(r+l, c-l, n) && temp[r+l][c-l] == 'Q')
                return false;
            if(inBound(r+l, c+l, n) && temp[r+l][c+l] == 'Q')
                return false;
            if(inBound(r-l, c+l, n) && temp[r-l][c+l] == 'Q')
                return false;
        }
        return true;
    }
    
    void solve(vector<vector<string>> &ans , vector<string>temp , int n , int row){
        //if we reach at the end of the row row[4][4] 4 = n we find the ans
        if(row == n){
            ans.push_back(temp);
            return ;
        }
        
        for(int i=0  ; i<n ; i++){
            if(isSafe(row , i , temp ,n)){
                //try placing queens for each row and check we can place it or not
                temp[row][i] = 'Q';
                solve(ans ,temp,n,row+1);
                temp[row][i] = '.';
            }
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        
        //create a board
        // n= 2 . .
             // . .
        
        vector<string>temp(n,"");
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                temp[i].push_back('.');
            }
        }
        
        solve(ans ,temp , n , 0);
        return ans;
    }
};