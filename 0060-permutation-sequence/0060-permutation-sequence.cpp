// // T.C = O(N!)+O(NLOGN)
// class Solution {
// public:
//     void permutationHelper(string & s, int index, vector < string > & res) {
//       if (index == s.size()) {
//         res.push_back(s);
//         return;
//       }
//       for (int i = index; i < s.size(); i++) {
//         swap(s[i], s[index]);
//         permutationHelper(s, index + 1, res);
//         swap(s[i], s[index]);
//       }
//     }

//   string getPermutation(int n, int k) {
//         string s;
//         vector < string > res;
      
//         //create string
      
//         for (int i = 1; i <= n; i++) {
//           s.push_back(i + '0');
//         }
      
//         permutationHelper(s, 0, res);
      
//         //sort the generated permutations
//         sort(res.begin(), res.end());
      
//         //make k 0-based indexed to point to kth sequence
//         auto it = res.begin() + (k - 1);
//         return *it;
//      }
// };


class Solution{
    public:
         string getPermutation(int n, int k){
             //n = 4 fact = 24
             //num 1 2 3 4
             int fact = 1;
             vector<int>num;
             for(int i=1 ; i<n ; i++){
                 fact = fact*i;
                 num.push_back(i);
             }
             num.push_back(n);
             
             string ans = "";
             k = k-1;//if k = 17 start from 0
             
             while(true){
                 ans += to_string(num[k/fact]);
                 num.erase(num.begin() + k / fact);
                 if(num.size() == 0){
                     break;
                 }
                 k = k%fact;
                 fact = fact/num.size();
             }
             return ans;
         }
    
};