// class Solution {
// public:
//     bool canMakeArithmeticProgression(vector<int>& arr) {
//         int n= arr.size();
//         sort(arr.begin() ,arr.end());
        
//         int diff = arr[1]- arr[0];
        
//         for(int i=2 ; i<n ; i++){
//             if(arr[i] - arr[i-1] != diff)
//                 return false;
//         }
//         return true;
        
//     }
// };

// A+(n-1)d , a is min value [1,3,9,5,7]
// max v = a+(n-1)d = 9
// 1+(5-1)d = 9
// d = 9-1/5-1 = max-min/n-1 = 2

// T.C & S.C = O(N)
//  find the diff 
// and check the diff value exxist in the array or not
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int length = arr.size();
        int min_val = INT_MAX;
        int max_val = INT_MIN;

        for (int num : arr) {
            min_val = min(min_val, num);
            max_val = max(max_val, num);
        }

        double diff = static_cast<double>(max_val - min_val) / (length - 1);

        for (int i = 0; i < length; i++) {
            double expected = min_val + i * diff;//a+id
            bool found = false;
            for (int num : arr) {
                if (abs(num - expected) < 1e-9) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }

        return true;
    }
};