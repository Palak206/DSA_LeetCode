// n.of words = spaces+1
// Alice = Hello userTwooo = 1+1 = 2
// userTwo = 1+1 = 2
// userThree = 2+1 = 3
// Alice = 2+2+1 = 5
// so max(5,3,2) = 5
class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        //map<sender, no.of word
        map<string, int>mp;
        
        for(int i=0; i<messages.size(); i++){
            string str = messages[i];
            int count_space = 0;
            
            for(int i=0; i<str.size(); i++){
                if(str[i] == ' ')
                    count_space += 1;
            } 
            //storing the spaces 
             mp[senders[i]] += count_space+1;
        }
        
        int maxi = INT_MIN;
        string ans = "";
        
        for(auto it:mp){
            if(it.second >= maxi){
                maxi = it.second;
                if(it.first > ans){
                    ans = it.first;
                }
            }
        }
        return ans;
    }
};