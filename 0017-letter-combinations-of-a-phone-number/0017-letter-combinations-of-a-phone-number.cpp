// t.c = O(3^n)// as most of the letter has 3 choices
class Solution {
public:
    void help(int i , string& digits, string &temp,vector<string> &ans,unordered_map<char,string> &m){
        //pass by reference bcoz we don't create any copy
        // temp for strore the current word
        if(i == digits.size()){
            ans.push_back(temp);
            return;
        }
        
        string str = m[digits[i]]; //abc
        for(int j = 0 ; j<str.size() ; j++){
            temp.push_back(str[j]); // a
            help(i+1 ,digits,temp,ans,m); //d (ad) = size of digits so push in temp
            temp.pop_back();//backtrack d remove
            // after reaching to af then we don't have other option to take 
            // so backtrack again abc =  for b now we explore bd,be,bf
            // same as for c = cd,ce,cf
        }
        
        
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        
        
        vector<string> ans;
        string temp;
        if(digits.size() == 0) 
            return ans;
        help(0,digits,temp,ans,m);
        return ans;
    }
};