// class Solution {
// public:
//     bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
//         sort(asteroids.begin() , asteroids.end());
//         int n = asteroids.size();
//         // int sum = 0;
        
//         for(int i=0 ; i<n ; i++){
//             if(mass < asteroids[i]){
//                 return false;
                
//             }
//             else
//                 mass += asteroids[i];
//         }
//         return true;
        
//     }
// };

class Solution {
public:

    bool asteroidsDestroyed(long long mass, vector<int>& ass) {
        
        sort(ass.begin(), ass.end());

        for(int i = 0; i < ass.size(); ++i)
        {
           if(mass < ass[i]) return false;
           
           else mass += ass[i];   
        }

        return true;
    }
};



