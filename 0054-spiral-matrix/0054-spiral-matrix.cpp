class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
    
    int top,down,L,R,dir;
    top=0;
    down=matrix.size()-1;
    L=0;
    R=matrix[0].size()-1;
    dir=0;
    int i;
    vector<int> ans;
    
    while(top<=down && L<=R)
    {
      //  left to right for dir =0
        if(dir==0)
        {
            for(i=L;i<=R;i++)
                ans.push_back(matrix[top][i]);
            top++;
        }
        else if(dir==1) //  TOP to BOTTOM for dir =1
        {
            for(i=top;i<=down;i++)
                ans.push_back(matrix[i][R]);
            R--;
        }
        else if(dir==2)// right to left for dir =2
        {
            for(i=R;i>=L;i--)
                ans.push_back(matrix[down][i]);
            down--;
        }
        else if(dir==3) // down to top dir =3
        {
            for(i=down;i>=top;i--)
                ans.push_back(matrix[i][L]);
            L++;
        }
        dir=(dir+1)%4;
    }
    return ans;

    }
       
};