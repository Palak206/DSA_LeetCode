class BrowserHistory {
public:
//     make a doubly linked list to go forward and backward
    list<string> history;
//     make a pointer to go forward and backward itertor 
    list<string> ::iterator it;
    
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        it = history.begin();
    }
    
    void visit(string url) {
        //google , facebook , twitter , insta;
        // suppose u are on a facebook browser and u want to visit leetcode another from the current page so after linkedin add leetcode and remove tall the previous history after facebook
        auto del = it;
        del++;
        history.erase(del , history.end());
        history.push_back(url);
        it++;// it for to go leetcode after facebook 
    }
    
    string back(int steps) {
        while(it != history.begin() && steps--){
            it--;
        }
        return *it;
        //we have to return a string that is on the it pointer
    }
    
    string forward(int steps) {
//         history.end() is not the end node it's the after end node so do -1 to go to the end node
        while(it != (--history.end()) && steps--){
            it++;
        }
        return *it;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */