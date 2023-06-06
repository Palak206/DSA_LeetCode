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
// class Solution {
// public:
//     bool canMakeArithmeticProgression(vector<int>& arr) {
//         int length = arr.size();
//         int min_val = INT_MAX;
//         int max_val = INT_MIN;

//         for (int num : arr) {
//             min_val = min(min_val, num);
//             max_val = max(max_val, num);
//         }

//         double diff = static_cast<double>(max_val - min_val) / (length - 1);

//         for (int i = 0; i < length; i++) {
//             double expected = min_val + i * diff;//a+id
//             bool found = false;
//             for (int num : arr) {
//                 if (abs(num - expected) < 1e-9) {
//                     found = true;
//                     break;
//                 }
//             }
//             if (!found) {
//                 return false;
//             }
//         }

//         return true;
//     }
// };


// optimal o(n) o(1)
//  we find the index location then swap it 1 3 9 5 7
//  a = 1 d = 2  a , a+d , a+2d ..... a+(n-1)d
//  9= a+id => 9 = 1+2i = i = 4(index) swap 1 3 7 5 9
//  7= a+id => 7 = 1+2i = i = 3(index) swap 1 3 5 7 9


class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        int min_val = INT_MAX;
        int max_val = INT_MIN;

        for (int num : arr) {
            min_val = min(min_val, num);
            max_val = max(max_val, num);
        }

        if((max_val - min_val) % (n-1) != 0) return false;
        int d = (max_val - min_val) / (n-1);
        
        int i=0;
        while(i<n){
            if(arr[i] == min_val + i*d) 
                i++;
            else if((arr[i] - min_val) % d != 0)
                return false;
            else{
                int pos = (arr[i] - min_val)/d;
                if(pos < i || arr[pos] == arr[i])
                    return false;
                swap(arr[i] , arr[pos]);
            }
        }

        return true;
    }
};

