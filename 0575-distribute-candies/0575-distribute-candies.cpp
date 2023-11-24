class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        
        int eat = n/2;
        unordered_set<int>st;
        for(int i=0 ; i<n ; i++){
            st.insert(candyType[i]);
        }
        
        int size = st.size();
        
        if(size > eat)
            return eat;
        return size;
        
    }
};