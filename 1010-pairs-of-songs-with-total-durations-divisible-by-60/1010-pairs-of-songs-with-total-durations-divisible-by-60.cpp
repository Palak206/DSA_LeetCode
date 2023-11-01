// time limit exceed
// class Solution {
// public:
//     int numPairsDivisibleBy60(vector<int>& time) {
//         int n= time.size();
//         int count = 0;
        
//         for(int i=0; i<n; i++){
//             for(int j=i+1 ; j<n ; j++){
//                 if((i < j && time[i] + time[j]) % 60 == 0)
//                     count++;
                
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time){
        int count=0;
        vector<int>v(60,0);
        for(int i=0;i<time.size();i++)
        {
            int a=time[i]%60;
            if(a==0)
                count+=v[0];
            else
                count+=v[60-a];
            v[a]++;
        }
        return count;
    }
};