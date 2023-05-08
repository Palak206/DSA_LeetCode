class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int sum=0;
        int i = 0 , j=0;
        while(i<n){
            sum += mat[i++][j++];
        }
        
        
        i=n-1 , j=0;

        while(i>=0){
            sum += mat[i--][j++];
        }

        if(n%2 != 0){
            return sum - mat[n/2][n/2];
        }
        return sum;
    }
};

