// t.c = o(nlogn) s.c = o(1)
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin() , people.end());
        // we use 2 pointer first for lower people and 3nd for heaviest people
        int  i =0 , j = n-1 , count = 0;
        
        while(i<=j){
            // lightest person + heaviest person sum <= limit
            // they can go together
            if(people[i] + people[j] <= limit){
                i++;
                j--;
            }
            // if lp+hp >= limit then heviest will go alone
            else
                j--;
            
            count++;
                
        }
        return count;
    }
};