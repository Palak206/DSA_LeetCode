class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, sum = 0, ans = INT_MAX;
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while (sum >= target && i <= j) {
                sum -= nums[i];
				// Updating and minimizing the answer
                ans = min(ans, j - i + 1); // int_max = infinite
                i++;
            }
        }
		// If the ans isn't updated even once, it means that tere is no solution
		// Hence returning 0,  otherwise returning answer.
        if(ans == INT_MAX)
            return 0;
        return ans;
    }
};