class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string> m;
        for (int i=0; i<names.size(); i++){
            m[heights[i]]= names[i];
        }
        vector<string> ans;
        for (auto it= m.rbegin(); it != m.rend(); it++)ans.push_back(it->second);
        return ans;
    }
};


// class Solution {
// public:
//     vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
//         vector<pair<int,string>> v;
//         for (int i=0; i<names.size(); i++){
//             v.push_back({heights[i],names[i]});
//         }
//         sort(v.begin(),v.end());
//         vector<string> ans;
//         for (int i=v.size()-1; i>=0; i--)ans.push_back(v[i].second);
//         return ans;
//     }
// };