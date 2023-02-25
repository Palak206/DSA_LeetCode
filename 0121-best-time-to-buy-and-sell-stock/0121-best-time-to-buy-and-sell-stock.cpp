class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
    int maxProfit = 0 , sum =0;
   
    for(int i=0 ; i<n-1;i++){
        sum = sum+prices[i+1]-prices[i];
       
        if(sum>maxProfit)
            maxProfit = sum ; 
        if(sum<0)
            sum =0;
        
      
    }
    return maxProfit;
    }
};