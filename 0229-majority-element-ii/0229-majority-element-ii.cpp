// majority element can be 2 not more than that
// T.C = O(N) + O(N) S.C = O(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n= nums.size();
        int num1 = -1 , num2 = -1 , count1 = 0 , count2 = 0;
        
        // applying the Extended Boyer Moore's Voting Algorithm:
        for(int i=0 ; i<n ; i++){
            if(nums[i] == num1)
                count1++;
            
            else if(nums[i] == num2)
                count2++;
            
            else if(count1 == 0){
                num1 = nums[i];
                count1 = 1;
            }
            
            else if(count2 == 0){
                num2 = nums[i];
                count2 = 1;
            }
            
            else{
                count1--;
                count2--;
            }
        }
        // we dont know which element has the majority element
        // to check this we count the element if it's more than [n/3]
        //then it's the majority element
        
        vector<int> ans; // list of answers

       // Manually check if the stored elements in
       // el1 and el2 are the majority elements:
        count1 = count2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == num1) 
                count1++;
            else if (nums[i] == num2) 
                count2++;
        }
        if(count1 > n/3)
            ans.push_back(num1);
        
        if(count2 > n/3)
            ans.push_back(num2);
        
        return ans;
    }
};