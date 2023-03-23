// we just have to sort the Kth column in decreasing order
// k = 2  ,11 9 2
int x;
class Solution {
public:
    static bool sortCol(const vector<int>&v1 ,const vector<int>&v2){
        return v1[x] > v2[x];  //decreasing order
    }  
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
         x = k;
         sort(score.begin() , score.end() , sortCol);
         return score;
    }
};

// class Solution {
// public:
//     vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
//         int n = score.size(); 
//         vector<pair<int,int>> v;
//         for(int i=0;i<n;i++)
//         {
//             v.push_back({score[i][k],i}); 
//         }
//         sort(v.begin(),v.end());           
//         reverse(v.begin(),v.end()); 
//         vector<vector<int>> ans;
//         for(auto &it : v)
//         {
//             ans.push_back(score[it.second]);
//         }
//         return ans;
//     }
// };