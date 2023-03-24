class Solution {
public:
//     t0 for children
//     from = root node
//     u to v = +1
//     v to u = -1
//     visited for present node
//     if(t0 < 0) then it's backward no chage needed  (-1)
//     if(t0 > 0) then it's forward we have to make it in backward so chage needed(+1)

    int dfs(vector<vector<int>> &gr, vector<bool> &visited, int from) {
        auto change = 0;
        visited[from] = true;
        for (auto to : gr[from])
            if (!visited[abs(to)])
               change += dfs(gr, visited, abs(to)) + (to > 0);
            return change;
        }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> gr(n);
        for (auto &c : connections) {
            gr[c[0]].push_back(c[1]);
            gr[c[1]].push_back(-c[0]);  // for backward edges
        }
        return dfs(gr, vector<bool>(n) = {}, 0);
        
    }
};