//5 = 101
//2 = 010 ^
//^ = 111 = 7
//get 2 previous no is 2 
// 5^7 = 2
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int prev = pref[0];//5
        
        for(int i=1 ; i<pref.size(); i++){
            pref[i] ^= prev;// pref[1] = 2^5 = 7
            
            prev ^= pref[i]; // 5^7 = 2
        }
        return pref;
    }
};