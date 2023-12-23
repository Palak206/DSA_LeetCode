class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0, y =0;
        int n = path.length();
        
        unordered_set<string> st;// for storing (x,y)
        
        string key = to_string(x) + "_" + to_string(y); 
        st.insert(key); //(0_0)
        
        for(int i=0 ; i<n ; i++){
            if(path[i] == 'E'){
                x++; // ----->
            }
            else if(path[i] == 'W'){
                x--; //<-------
            }
            else if(path[i] == 'N'){
                y++; // ^----
            }
            else{
                y--;//south
            }
            
            key = to_string(x) + "_" + to_string(y);
            if(st.find(key) != st.end()){
                return true; //past me visited ki h point
            }
            
            st.insert(key);
        }
        return false;
    }
};