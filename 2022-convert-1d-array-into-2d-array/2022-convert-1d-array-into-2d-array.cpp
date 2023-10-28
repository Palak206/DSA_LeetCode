//possible converting 1d to 2d when original.size() = m*n
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size() != m*n)
            return {};//impossible case
        
        vector<vector<int>> arr(m , vector<int>(n));//m*n size
        int k = 0;
        
        for(int i=0 ; i<m ; i++){ // 2
            for(int j=0 ; j<n ; j++){ //2
                
                arr[i][j] = original[k];
                k++;
            }
        }
        return arr;
    }
};

// a[0][0] a[0][1]     1   2
// a[1][0]  a[1][1]    3   4