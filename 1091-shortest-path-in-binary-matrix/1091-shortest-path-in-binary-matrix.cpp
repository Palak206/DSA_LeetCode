struct Point{
    int x, y, cnt;
};

class Solution {
public:
    int dx[8] = {1,1,1,-1,-1,-1,0,0};//orthodox
    int dy[8] = {1,0,-1,1,-1,0,1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1)
            return -1;
        
        int row =  grid.size();
        int col =  grid[0].size();
        //bfs
        
        queue<Point> q;
        q.push({0,0,1}); // x,y,initi
         //visited
        
        grid[0][0] = -1;
        
        while(!q.empty()){
            Point p = q.front();
            q.pop();
            
            if(p.x == row-1 && p.y == col-1)
                return p.cnt;
            
            //orthodirection
            for(int i=0 ; i<8 ; i++){
                int x = p.x+dx[i];
                int y = p.y+dy[i];
                
                if(x>=0 && y>=0 && x<row && y<col && grid[x][y]==0){
                    q.push({x,y,p.cnt+1});
                    grid[x][y] = -1;
                }
            }
        }
        return -1;
    }
};