// que = 0 1 2  4 5 7
// in actual = 0 1 2 3 4 5 6 7
// 3,6 are missing
// 1st 0->2 , 3 missing
// 2nd 4->5 .  missing
// 3rd 7

class Solution {
public:
    vector<string> summaryRanges(vector<int>& arr) {
        int n = arr.size(); 
        vector<string> ans; 
        
        string temp = ""; // temproray string that stores all possible answer
        
        for(int i = 0; i < n; i++) 
        {
            int j = i; // declare anthor pointer that will move
            
            // run that pointer until our range is not break
            while(j + 1 < n && arr[j + 1] == arr[j] + 1)
            {
                j++;
            }
            
            // if j > i, that means we got our range more than one element
            if(j > i)
            {
                temp += to_string(arr[i]); // first store starting point
                temp += "->"; // then store arrow, as question wants it
                temp += to_string(arr[j]); // and lastly store the end point
            }
            else // we got only one element as range 7
            {
                temp += to_string(arr[i]); // then store that element in temp
            }
            
            ans.push_back(temp); // push one possible answer string to our answer
            temp = ""; // again reintiliaze temp for new possible answers
            i = j; // and move i to j for a fresh start
        }
        
        return ans; 
    }
};