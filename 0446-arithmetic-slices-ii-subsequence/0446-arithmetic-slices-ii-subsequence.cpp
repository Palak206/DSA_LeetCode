//   2    4      6     8    10
//     2   1  . 4  1 . 6 1  . 8  1
//    (2,  4) .(2  6).(2, 8) .(2, 10)
// 4start 4end count++
//            .2   2 . 4  1  .  
//            .(4, 6). (4,8) .(4,10)
//          . (2,4,6). 2  3 .).(6,10)==4 2
//                   . (6,8) . (8,10)==2,1
//                (2,4,6,8) .(2,6,10)

//res = 1+2+1+3(6,8) = 7


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        
        int res = 0;
        
        unordered_map<long,int>mp[n];//int = different int = frequency of count
        
        if(n<3)
            return false;
        
        for(int i=0; i<n ; i++){
            for(int j=0; j<i; j++){
                long diff = (long)nums[j] - nums[i];
                
                auto it = mp[j].find(diff);
                
                int count_at_j = it == end(mp[j]) ? 0: it->second; 
                //count at j for difference = diff
                
                mp[i][diff] += count_at_j+1;
                
                res += count_at_j;
            }
            
        }
        
        return res;
    }
};