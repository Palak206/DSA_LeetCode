class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> counts(k,0);
        int  sum = 0 ;
        for( int i: nums){
            sum += (i%k + k)%k;
            counts[sum % k]++;
        }  
        int res = counts[0];
        for(int c: counts)
            res += (c*(c-1))/2;
        return res;
    }
};