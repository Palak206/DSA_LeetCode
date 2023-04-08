// // We use flood fill algorithm


class Solution {
public:
    void flood_fill(vector<vector<int>>& grid, int i, int j, vector <pair<int, int>> &r)
    {
        // crossing the boundaries
        // if the particular is water(0) then we return as it is
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j]==0)
            return;
        grid[i][j] = 0;//keep marking sell 0
        r.push_back(make_pair(i,j));
        flood_fill(grid, i+1, j, r);// down-ward
        flood_fill(grid, i-1, j, r); // up
        flood_fill(grid, i, j-1, r); // right
        flood_fill(grid, i, j+1, r); //left
        return;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int count = 0;
        //coordinate of x
        vector <pair<int, int>> x;
        vector <pair<int, int>> y;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[i].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    count++;
                    if(count == 1)
                    {
                        flood_fill(grid, i, j, x);   
                    }
                    if(count == 2)
                    {
                        flood_fill(grid, i, j, y);   
                    }   
                }
            }
        }
        //finding the min distance [ex-2] (0,1)[1] (2,2)[1] = 2+1-1 = 2
        int min_dist = INT_MAX;
        for(int i=0; i<x.size(); i++)
        {
            for(int j=0; j<y.size(); j++)
            {
                int dist = abs(x[i].first - y[j].first) + abs(x[i].second - y[j].second) - 1;
                if(dist < min_dist)
                    min_dist = dist;
            }
        }
        return min_dist;
    }
};