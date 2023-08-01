// class Solution {
// public:
//     bool isPrime(int n){
//         int cnt = 0;
//         if(n == 1 || n==0)
//             return false;
        
//         for(int i=2 ; i<=n/2 ; i++){
//             if(n%i == 0){
//                 return false;
                
//         }
//         return true;
//     }
    
//     vector<vector<int>> findPrimePairs(int n) {
//         vector<vector<int>> ans;
//         vector<int>v;
        
//         for(int i=0 ; i<n ; i++){
//             v.push_back(i);
//         }
        
//         for(int i=0 ; i<v.size() ; i++){
//             temp = n-i;
//             if(isPrime(v[i]) || isPrime(v[temp])){
//                 if(v[i]+v[temp] == n){
//                     v.push_back({i , temp});
//                 }
//                 else{
//                     return ;
//                 }
                    
//             }
//         }
//         return v;
        
//     }
// };

class Solution {
public:
    
     bool isPrime(int a){
        int b=sqrt(a);
        int c=2;
        while(c<=b){
        if(a%c==0) return false;
        c++;
        }
        return true;
}
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>>res;
        for(int i=2;i<=n/2;i++){
            int temp=n-i;
            if(isPrime(i) && isPrime(temp)) 
                res.push_back({i,temp});
        }
        return res;
    }
};