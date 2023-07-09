class Solution {
public:
    bool makeEqual(vector<string>& words) {
//         unordered_map<char,int>mp;
        
// 		for(auto i:words){
// 			for(int j=0;j<i.size();j++) 
//                 mp[i[j]]++;        
// 		}
// 		for(auto i:mp){
// 			if(i.second%words.size()!=0)
//                 return false;
// 		}
// 		return true;
      map<char, int> mp;
      int n=words.size();
      for(string word:words)
      {
          for(char w :word)
          {
              mp[w]++;
          }
      }  
      for(auto m:mp)
      {
          if(m.second%n!=0)
          return false;
      }
      return true;
    }
};