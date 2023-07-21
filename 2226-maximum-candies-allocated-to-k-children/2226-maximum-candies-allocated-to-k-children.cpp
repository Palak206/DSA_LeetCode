// // class Solution {
// // public:
// //     int maximumCandies(vector<int>& candies, long long k) {
// //         int n = candies.size();
        
// //         long long sum = 0;
        
// //         for(int i=0 ; i<n ; i++){
// //             sum += candies[i];// 5+8+6/3 = 6 we can dive 6 , 6 , 6 in 3 children
// //         }
        
// //         long long l = 0, r = sum/k;//(max)
        
// //         long long ans = 0;
        
// //         while(l<r){
// //             long long mid = (l+r)/2;//6/2 = 3
// //             if(mid == 0) return 0;
// //             long long cnt = 0;
// //             for(int i=0 ; i<n; i++){
// //                 long long x = candies[i];
// //                 cnt += (x/mid); //cnt = 5
// //             }
// //             if(cnt >= k){
// //                 ans = max(ans,mid); //max(0,)
// //                 l = mid-1;
// //             }
// //             else
// //                 r = mid;
                
// //         }
// //         return ans;
        
// //     }
// // };


class Solution {
public:
 
    bool possible(vector<int> candies,long long int k,long long int m){
        long long int cnt=0;
        for(int i=0;i<candies.size();++i){
            cnt+=candies[i]/m;
        }
 
        return cnt>=k;
    }
 
 
    int maximumCandies(vector<int>& candies, long long k) {
 
        long long int ans=0;
        long long int l=1,h=1e18;
        while(l<=h){
            long long int mid = l + (h-l)/2;
            if(possible(candies,k,mid)){ //if max candies can dvided in k children
                ans=mid;
                l=mid+1;
            }
 
            else //go right
                h=mid-1;
        }
 
        return ans;
    }
};