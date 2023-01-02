class Solution {
public:
    void sieve(vector<int>& prime_num){
        vector<bool>prime(1001,1);
        for(int i=2;i*i<=1001;i++)
        {
            if(prime[i])
            {
                for(int j=i*i;j<=1001;j=j+i)
                {
                    prime[j]=false;
                }
            }
        }
        for(int i=2;i<=1001;i++)
        {
            if(prime[i])
            {
                prime_num.push_back(i);
            }
        }
        
    }
        
    int distinctPrimeFactors(vector<int>& nums) {
        
        vector<int>prime_num;
        sieve(prime_num);
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++)
        {
            int value=nums[i];
            int j=0;
           while(value>1){ 
               while(value>1 && j<prime_num.size() && value%prime_num[j]==0)
            {
                s.insert(prime_num[j]);
                value=value/prime_num[j];
            }
              j++;
           }
        }
        return s.size();
        
    }
};