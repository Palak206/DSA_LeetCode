class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int maxi=0,div=divisors[0];
        for(int i=0;i<divisors.size();i++)
        {
            int count=0;
            for(int j=0;j<nums.size();j++)
            {
                if(nums[j]%divisors[i]==0)
                {
                    count++;
                }
            }
            if(count>=maxi)
            {
                if(count==maxi)
                {
                    div=min(div,divisors[i]);
                }
                else
                {
                    maxi=count;
                    div=divisors[i];
                } 
            }
        }    
        return div;
    }
};