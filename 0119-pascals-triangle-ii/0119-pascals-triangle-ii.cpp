class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>v(rowIndex+1);
        for(int i=0;i<=rowIndex;i++)
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
        return v[rowIndex];
    }
};