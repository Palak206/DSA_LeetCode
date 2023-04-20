// class Solution {
// public:
//     void dfs(string s, string d, unordered_map<string,vector<pair<string , double>>> m ,unordered_map<string , int> &visited , double &ans,double temp){
//         if(visited.count(s)){
//             return;
//         }
//         if(s==d){ //source = destination
//             ans = temp;
//             return ;
            
//         }
//         for(auto x:m[s]){
//              dfs(x.first,d,m,visited,ans ,temp*x.second);
//         }
//         return ;
//     }
    
    
//     vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
//         //first we create a graph   a
// //                                2/
//         //                         b _3_ c
//         // a/b*b/c = c/a
//         unordered_map<string,vector<pair<string , double>>>m;
//         for(int i = 0 ; i<equations.size() ; i++){
//             m[equations[i][0]].push_back({equations[i][1] , values[i]}); // for a/b
//             m[equations[i][1]].push_back({equations[i][0] , 1.0/values[i]}); 
//             // for b/a = 1/2 directional
//         }
//         vector<double>finalAns;
//         for(int i = 0 ; i<queries.size() ; i++){
//             string source = queries[i][0]; //a
//             string destination = queries[i][1]; // c
            
//             unordered_map<string , int> visited;
//             double ans = -1.0;
//             double temp = 1;
            
//             if(m.count(source)){ 
//                 //means [x,x] source node x is not present any where so don't call dfs
//                 // simply ans = -1.0
//                 dfs(source,destination, m,visited, ans,temp);
//                 finalAns.push_back(ans);
//             }
            
//         }
//         return finalAns;
//     }
// };


class Solution {
private: vector<double>res;
         unordered_map<string,vector<pair<string,double>> >mp;
         unordered_set<string>s;

public:
    void dfs(string s, string d,double &ans,unordered_map<string,int>&vis,double temp)
    { //cout<<temp<<endl;
        if(vis.count(s))
        return;
        if(s==d)
        {// cout<<s<<endl;
            ans=temp;
            return;
        }
        auto i=mp[s];
        vis[s]=1;
        for(auto x:i)
        {
            
            dfs(x.first,d,ans,vis,temp*x.second);
        }
        return;
    }
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {
   mp.clear();
   res.clear();
   s.clear();
   for(int i=0;i<e.size();i++)
   {
       mp[e[i][0]].push_back({e[i][1],v[i]});
       mp[e[i][1]].push_back({e[i][0],1.0/v[i]});
       s.insert(e[i][0]);
       s.insert(e[i][1]);

   }    
    for(int i=0;i<q.size();i++)
    {
        double ans=-1.0,temp=1;
      unordered_map<string,int>vis;
      if((s.find(q[i][0])!=s.end()) || (s.find(q[i][1])!=s.end()))
        dfs(q[i][0],q[i][1],ans,vis,temp);
        res.push_back(ans);
    }
    
    return res;
    }
};