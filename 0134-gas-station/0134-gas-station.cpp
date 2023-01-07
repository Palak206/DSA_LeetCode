class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        // if total_gas_sum < cost_sum so ans = -1
        // bcoz for ex we have 1 liter gas we have to go 3 km but in 1 lt we can only go for 1km
        // so thats case that was not our starting point
        
        //logic for starting index we'll do gas[i] - cost[i] if it <0 we move to i+1
        //if that's + may be starting point was that and we check it 
        // for ex in first case gas[i] = 4 , cost[i] = 1 4-1=3>1 
        //i++
        //gas = 5 cost = 2 ; 5-2 = 3
        // so total fuel = 3+3 = 6  fuel += gas[i] - cost[i]
        // remaining fuel gas[0]-cost[0] = -2 gas[1]-cost[1] = -2 gas[1]-cost[1] = -2
        // total_remaing_fuel = -6
        // 6+(-6) = 0
        // so we reach our index 3 that was our strting point so ans = 3
        if(accumulate(gas.begin() , gas.end(),0) < accumulate(cost.begin() , cost.end(),0))
            return -1;
        
        int n = gas.size();
        int remaining_fuel = 0;
        int ans=0;
        
        
        for(int i = 0 ; i<n ; i++){
            remaining_fuel += gas[i] - cost[i];
            
            if(remaining_fuel < 0){
                ans = i+1;
                remaining_fuel = 0;
            }
        }
        return ans;
    }
};