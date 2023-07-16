class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        unordered_map<int,int> m;
        for(auto val:arr){
            m[val]++;  // storing the element in map
        }

        unordered_set<int> s;
        for(auto val:m){
            s.insert(val.second); // storing the count in setm
        }

        if(m.size() == s.size()){ // checking if the size are same or not
            return true;
        }

        return false;
    }
};