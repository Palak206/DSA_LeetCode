class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
     
        bool f=false;
        int n=matrix.size();
        int m=matrix[0].size();
        bool r=false,c=false;
        for(int i=0;i<n;i++){
            //if the first column contains zero set c=true
            if(matrix[i][0]==0)
                c=true;
        }
        for(int i=0;i<m;i++){
            //if the first row contains zero set r=true
            if(matrix[0][i]==0)
                r=true;
        }
        for(int i=1;i<n;i++){
            //check which row and column contains zero
            //set the first element of that row or column to zero
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        
        for(int i=1;i<n;i++){
            //set the row to zero
            if(matrix[i][0]==0){
                for(int j=1;j<m;j++)
                    matrix[i][j]=0;
            }
        }
        
        for(int i=1;i<m;i++){
            //set the column to zero
            if(matrix[0][i]==0){
                for(int j=1;j<n;j++)
                    matrix[j][i]=0;
            }
        }
        
        //set the first column to zero
        if(r){
            for(int i=0;i<m;i++)
                matrix[0][i]=0;
        }
        
        //set the first row to zero
        if(c){
            for(int i=0;i<n;i++)
                matrix[i][0]=0;
        }
    
    }
};