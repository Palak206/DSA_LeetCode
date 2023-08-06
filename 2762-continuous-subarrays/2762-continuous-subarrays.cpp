// find all the subarray of the array
// and then find the max and min of these subaarays
// if max-min <= 2 so add it otherwise don't take it

// class Solution {
// public:
//     long long continuousSubarrays(vector<int>& nums) {
//         int n = nums.size();
//         long long int ans = 0;
        
//         for(int i=0; i<n ; i++){
            
//             int mini = INT_MAX;
//             int maxi = INT_MIN;
            
//             for(int j=i ; j<n ; j++){
//                 maxi = max(maxi , nums[j]);
//                 mini = min(mini , nums[j]);
                
//                 if(maxi - mini <= 2)
//                     ans++;
//             }
//         }
//         return ans;
        
//     }
// };

// we ll solve monotonic increasing queue for slididng window
// we make two queue increasing decresing

// dec = 5 4 2 1
//inc = 1 2 4 5

// so our front will 5 for both the array then we move 4 5<4 so dec
//5 4 2! 4
//inc we pop 5
//5-4 = 1 that is valid
// so 5 to 4 size of arr 2 add 1(for 5)+2+2+3 = 8
//5-2 = 3 not valid front++ f = 4 4=2 = 2 valid size 2
// 4-4 = 0 <=2 valid size = 3
//5!  4! 2 4

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums){
        int n= nums.size();
        long long ans = 0;
        deque<int> maxq;// monotonic dec 5 3 2 1
        deque<int> minq; // m inc 1 2 5
        int l=0, r=0;//sliding window
        
        while(r<n){
            while(!maxq.empty() && nums[r] > maxq.back())
                 maxq.pop_back();
        
            while(!minq.empty() && nums[r] < minq.back())
                 minq.pop_back();
        
            //insert the element in queue
            maxq.push_back(nums[r]);
            minq.push_back(nums[r]);
            
            while(maxq.front() - minq.front() > 2){//not valid cond
                //update maxq minq and left
                if(nums[l] == maxq.front())
                    maxq.pop_front();
                
                if(nums[l] == minq.front())
                    minq.pop_front();
                
                l++;
                
            }
            ans += r-l+1;
            r++; //expand right side
        }
        
            return ans;
    }
};