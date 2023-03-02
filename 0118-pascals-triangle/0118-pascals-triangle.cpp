// Time Complexity : O(N^2). Where N is the numRows. Here total number of iterations are : N*(N+1)/2 which creates the time complexity.

// Space Complexity : O(1). Constant space. Because we are creating 2D vector output as per the demand of program.
class Solution {
public:
    vector<vector<int>> generate(int numRows) {     
        vector<vector<int>>v(numRows);
        for(int i=0;i<numRows;i++)
        {
            v[i].resize(i+1);
            //resize every row for example 0th row with size 1,2nd row with size 3..
            v[i][0]=v[i][i]=1;//fix value of first nand last element of every row as 1.
              for(int j=1;j<i;j++)
              {
                  v[i][j]=v[i-1][j-1]+v[i-1][j];
                  //finding value by adding above 2 elements.
              }
        }      
        return v;
    }
};