class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int curr_winner = arr[0];
        int win_count = 0;
        
        // if(k == 1)
        
        if(k >= n)
            return *max_element(arr.begin() , arr.end());
        
        
        for(int i=1 ; i<n ; i++){
            if(curr_winner > arr[i]){
                win_count++;
            }
            //if cw < arr[i]
            else {
                curr_winner = arr[i];
                win_count = 1;
            }
            
            if(win_count == k)
                return curr_winner;
        }
        return curr_winner;
    }
};