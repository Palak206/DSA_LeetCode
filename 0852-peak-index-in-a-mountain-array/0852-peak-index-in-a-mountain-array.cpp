// we have to find the max element in the array then we find the index of that element
// 0 10 5  2 = mountain array
// 0<10>5>2
//so it break at 10 0<10 so it 'll vreak on 10' index 1 will be the answer

// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& arr) {
//         int n = arr.size();
//         int i=0;
//         while(i < n-1 && arr[i] < arr[i+1]){
//             i++;
//         }
//         return i;
//     }
// };

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr){
        int l = 0 , r = arr.size()-1;
        
        while(l<r){
            int mid = l+(r-l)/2;
            
            if(arr[mid] < arr[mid+1]){
                l = mid+1;
            }
            else{ // a[m]>a[m+1] 10>5
                r = mid;
            }
        }
        
        return l; // return r;
        
        
    }
};