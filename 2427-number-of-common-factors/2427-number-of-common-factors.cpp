// class Solution {
// public:
//     int commonFactors(int a, int b) {
//         vector<int> v1;
//         vector<int>v2;
//         int count = 0;
//         for(int i=1 ; i<=a ; i++){
//             if(a%i == 0){
//                 v1.push_back(i);
//             }
                
//         }
//         for(int j=1 ; j<=b ; j++){
//             if(b%j == 0){
//                 v2.push_back(j);
//             }
                
//         }
//         // int count = 0;
//         for(int i=0; i<v1.size() ; i++){
//             for(int j=0; j<v2.size() ; j++){
//                 if(v1[i] == v2[j])
//                     count++;
//             }
//         }
//         return count;
//     }
// };

// Time complexity:O(min(a,b))
// Space complexity: O(1)

class Solution {
public:
    int commonFactors(int a, int b) {
        
        int count=0;
        int n = min(a,b);
        
        for(int i=1;i<=n;i++)
        {
            if(a%i==0 && b%i==0)
                count++;
        }
        return count;

    }
};