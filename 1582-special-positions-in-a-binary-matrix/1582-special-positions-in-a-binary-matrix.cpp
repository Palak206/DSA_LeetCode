class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int count = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m ; j++){
                if(mat[i][j] == 0){
                    continue;
                }
                
                bool special = true;
                //check row if has 0 aur 1
                for(int r=0; r<n ; r++){ //not special pos
                    if(r != i && mat[r][j] == 1){
                        special = false;
                        break;
                    }
                }
                
                //check col if has 0 aur 1
                for(int c=0; c<m ; c++){ //not special pos
                    if(c != j && mat[i][c] == 1){
                        special = false;
                        break;
                    }
                }
                
                if(special == true){
                    count++;
                }
                    
            }
        }
        return count;
    }
};