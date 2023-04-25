// class SmallestInfiniteSet {
// public:
//     vector<bool> v;
//     SmallestInfiniteSet() {
//         v.resize(1000,1); //1 for true
//     }
    
//     int popSmallest() {
//         for(int i = 0  ; i<1000 ; i++){
//             if(v[i] == 1){
//                 v[i] = 0;
//                 return i+1;
//             }
//         }
//         return -1;
//     }
    
//     void addBack(int num) {
//         v[num-1] = 1;
//     }
// };


class SmallestInfiniteSet {
public:
    int curr ;
    set<int>s;
    //initialize empty set
    SmallestInfiniteSet() {
        curr = 1;
    }
    
    int popSmallest() {
        if(s.size()){ // if set is not empty
            int res=*s.begin(); s.erase(res);
            return res;
        }else{
            curr++; //if set is empty
            return curr-1;
        }
    }
    
    void addBack(int num) {
        if(curr > num)
            s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */