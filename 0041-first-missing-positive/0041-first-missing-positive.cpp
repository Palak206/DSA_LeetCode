//we don't care about NEGATIVE NO. & higher than nums.size()


// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         int n= nums.size();
//         sort(nums.begin() , nums.end());
        
//         int ans = 1;
//         for(int i = 0;i<n;i++){
//             if(nums[i]==ans)
//               ans++;
        // }
//         return ans;
//     }
// };

// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         int n=nums.size();
//         set<int>s;
//         for(int i=0;i<n;i++){
//             s.insert(nums[i]);
//         }
//         int i=1;

//         while(i<=n){
//             if(s.find(i)!=s.end()){
//                 i++;
//             }
//             else{
//                 return i;
//             }
          
//         }
//           return n+1;
//     }
// };
        
        class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            int curr_element = nums[i];
            // int chair = curr_element - 1;
            //actual position of the chair 1 2 3 4 5 6
                  //chair(position)        0 1 2 3 4 5
            
            if(curr_element>=1 && curr_element<=n){
                int chair = curr_element - 1;
                if(nums[chair] != curr_element){
                swap(nums[chair] , nums[i]);
                i--;
               //bcoz after swapping it's posssible ,
               // the no.we get that is also not on a actual position
            }
            }
            
        }
        //iterate the element
        for(int i=0;i<n;i++){
            //check elements are the currect position or not
            if(i+1 != nums[i]){// means at i=0 =>1 i=1=>2 is not there
                return i+1;
                
            }
        }
        // if everything at the right position [1 2 3 4 5 6] so ans 6+1
        return n+1;
        
    }
};