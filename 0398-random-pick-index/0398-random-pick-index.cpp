class Solution {
public:
    vector<int>arr;
    
    Solution(vector<int>& nums) {
        arr = nums;
    }
    
    int pick(int target) {
        int n = arr.size();
        int i = rand()%n;
        if(arr[i] == target)
            return i;
        else{
            while(arr[i] != target){
                i = rand()%n;
            }
            return  i;
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */