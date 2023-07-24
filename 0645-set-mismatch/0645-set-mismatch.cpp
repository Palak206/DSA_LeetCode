class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
//         sort(nums.begin() , nums.end());
//         int n = nums.size();
//         int res1 = -1;
//         int i;
        
//         for(i = 0 ; i<n ; i++){
//             if(nums[i] == nums[i+1])
//                 res1 = nums[i];
//                 break;
//         }
        
//         int total = n*(n+1)/2;
//         int sum =0;
//         for(i=0 ; i< n; i++){
//            sum += nums[i];
//         }
        
//         return {res1 , total-sum};
        
        int n = nums.size(),sum=0;
        unordered_set<int> s;
        int repeated_number=0;
        for(int i=0;i<n;i++)
        {
            if(s.find(nums[i])!=s.end())
            {
                repeated_number=nums[i];
            }
            else 
            {
                s.insert(nums[i]);
                sum+=nums[i];
            }
        }
        int k = n*(n+1)/2;
        return {repeated_number,k-sum};
    }
};