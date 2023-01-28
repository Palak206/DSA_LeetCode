class SummaryRanges {
    vector<int> v;
    unordered_map<int,bool> mp;
public:
    void addNum(int value) {
	// when a new number is coming we add it to the vector v at the upper bound index of the value with unique elements which i am checking usinig unordered_map
        if(!(mp.count(value))) v.insert(upper_bound(v.begin(),v.end(),value),value) , mp[value] = true;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans = {{v[0]}};  // initializing the ans vector with the 0th elemt of the vector;
        for(int i = 1;i<v.size();i++){
            if(ans.back().back() + 1 == v[i]) { // if last elemet of the last vector of ans vector == v[i] - 1 then 
                if(ans.back().size() == 2) ans.back().back() = v[i]; // we check if the value of last vector is 2 then we simple equate the last value of the last vector = to v[i];
                else ans.back().push_back(v[i]); // else if last vector has size smaller then 2 then add v[i] to last vector of ans
            }
            else {
                if(ans.back().size() == 1) ans.back().emplace_back(ans.back()[0]); // here we are checking if the interval size is one then we make it size of two.  eg [1] = [1,1]
                ans.push_back({v[i]}); // and we add a new interval.
            }
        }
        if(ans.back().size() == 1) ans.back().emplace_back(ans.back()[0]); // checking for the last vector if its size if 1;
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */