class Solution {
public:
    int divide(int dividend, int divisor) {
        
        long long ans = long(dividend)/long(divisor);
        if (ans > INT_MAX)
        return INT_MAX;
        else if (ans < INT_MIN)
        return INT_MIN;
        else
        return ans;
    }
};