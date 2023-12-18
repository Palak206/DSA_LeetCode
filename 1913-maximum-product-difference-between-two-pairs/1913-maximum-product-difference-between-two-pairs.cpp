class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        int largest = INT_MIN, secondLarge = INT_MIN;
        int smallest = INT_MAX, secondSmallest = INT_MAX;
        
    
        for(int i=0 ; i<n ; i++){
            if(nums[i] > largest ){
                secondLarge = largest;
                largest = nums[i];
            }
            else if(nums[i] > secondLarge){
                secondLarge = nums[i];
            }
            
            if(nums[i] < smallest){
                secondSmallest = smallest;
                smallest = nums[i];
            }
            else if(nums[i] < secondSmallest){
                secondSmallest = nums[i];
            }
        }
        return (largest*secondLarge) - (smallest*secondSmallest);
    }
};