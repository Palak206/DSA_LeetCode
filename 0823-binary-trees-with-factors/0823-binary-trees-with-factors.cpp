//cond      x
//       /     \
//     y        y
//so x= y*y 4 = 2*2

//4 2 5 10
//4%2 = 0 so iske left me 2 ajyega
//                  10
// (10%2 ==0)   2        x (2*x = 10 so x = 10/2 = 5) wecheck 5 is there in the arr

// 2 4 8 
// 2 = 1
//4 =  1,1+1=2
//8 = 1, 1+2+2= 5
//total= 1+2+5 = 8

//sorting
//map
// i=1 to n
//j= 0 to n
//root= arr[i]  leftchild = arr[j] only if root%lc == 0 right = root/lc present in the arr
class Solution {
public:
    int MOD = 1e9+7;
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        
        sort(arr.begin() , arr.end());
        
        unordered_map<int , long long>mp;
        mp[arr[0]] = 1;//1 ways
        
        for(int i=1 ; i<n ; i++){
            int root = arr[i];
            mp[root] = 1;
            
            for(int j=0; j<i ; j++){ //similar to longest increasing sub
                int LC = arr[j];// only if root%lc = 0
                
                //RC = arr[i]/LC present
                if(root%LC == 0 && mp.find(arr[i]/LC) != mp.end()){
                    mp[root] += mp[LC] *mp[arr[i]/LC];
                }
            }
        }
        long res = 0;
        //map me kya h value ->no of binary tree banane ke ways
        for(auto &it : mp){
            //it.first = value it.second = wys
            res = (res + it.second) % MOD;
        }
        return res;
    }
};