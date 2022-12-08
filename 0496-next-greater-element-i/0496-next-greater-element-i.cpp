// T.C = O(N^3) S.C =O(N)
// in this approach we r traversing the array again & again from the beginning
// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> ans;
//         for(int i = 0 ; i<nums1.size(); i++){
//              for(int j = 0 ; j<nums2.size(); j++){
//                  if(nums1[i] == nums2[j]){
//                      int max_val = -1 ;
//                     for(int k=j;k<nums2.size();k++)
//                     {
//                         if(nums2[k]>nums2[j])
//                         {
//                             max_val=nums2[k];
//                             break;
//                         }   
//                     }
//                     ans.push_back(max_val);
//                 }
//              }
//         }
//         return ans;
//     }
// };

// using stack
// [4,12,5,3,1,2,5,3,1,2,4,6]
// in this approach we start from the end of the array 
// the most recent element = LIFO(last in first out)
// we 'll be creating a helping stack that'll store the element so first we start with  that
// is last element so we put it in the empty stack and now no elment is greater than this
//  so simply put -1 in the array and then moving to next element that is 4 so compare with
// stack element 6 (6>4) so put 6 in the array and put 4 on the top of the stack ansd same
// for next ele that is 2<4 so top = 2 and in array 4 is there
// then we'll move to next that is 3 so the most recent element of 3 is 1<3 so pop it into the stack and again compare with 2<3 and same then compare wit h 4>3 so top ele =  and array ele = 4 and so on.....

// MAP NUMS2 GREATER ELEMENT COMPARE WITH NUMS1

class Solution{
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            vector<int> res(nums1.size(), -1); //to be returned, initialize it with -1.
            stack<int> st;
            unordered_map<int, int> mp;
//             map<key , value>
            
//             find the next greater element of NUMS2 using STACK
            for(int i=0; i<nums2.size(); i++){
                int element = nums2[i];
                
                while(!st.empty() && element > st.top())
                {
                    //NGE of st.top() is element
		     		
                    mp[st.top()] = element;
                    st.pop();
                }
                
                st.push(element);
            }
            
           for(int i=0; i<nums1.size(); i++){
                int ele = nums1[i];
                
                if(mp.find(ele) != mp.end())
                {
                    int nge = mp[ele];
                    res[i] = nge; //push NGE of desired element
                }
                    
            }
            
            return res;
            
            } 
};