class Solution {
public:
    string multiply(string num1, string num2) {
        // int n1 = atoi(num1.c_str());
        // int n2 = stoi(num2.c_str());
        // int ans;
        // ans = n1*n2;
        // return ans ;
        
        int n1 = num1.size();
    int n2 = num2.size();
    string result(n1+n2, '0');
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    for (int i = 0; i < n1; i++) {
        int carry = 0;
        for (int j = 0; j < n2; j++) {
            int digit = (result[i+j]-'0') + (num1[i]-'0')*(num2[j]-'0') + carry;
            carry = digit / 10;
            result[i+j] = (digit % 10) + '0';
        }
        if (carry > 0) {
            result[i+n2] += carry;
        }
    }
    reverse(result.begin(), result.end());
    int i = 0;
    while (i < result.size()-1 && result[i] == '0') {
        i++;
    }
    result = result.substr(i);
    return result;
   }
};