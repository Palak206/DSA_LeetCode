class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int,int>mp;
        for(int x:nums){
            mp[x]++;
        }
        
        int ans = 0;
        for(auto i : mp){
            int t = i.second;
            
            //if occurance of number is 1 then we cnt find pattern
//             if(t == 1)
//                 return -1;
            
//             count += t/3;
//             if(t%3)
//                 count++;
            if(t == 1) return -1;
            else if(t == 2 || t == 3)
                ans++;
            else if(t > 3){
                int count = 0;
                int rem=0;
                
                count = t/3;
                rem = t%3;
                ans += count;
                if(rem != 0) ans++;
            }
        }
        return ans;
    }
};