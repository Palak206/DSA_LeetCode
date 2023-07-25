// we have to find the max element in the array then we find the index of that element

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int i=0;
        while(i < n-1 && arr[i] < arr[i+1]){
            i++;
        }
        return i;
    }
};