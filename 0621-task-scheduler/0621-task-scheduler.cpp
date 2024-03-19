// first we count the fre of every character
//then choose that char tha have highest freq so use priority queue
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        for(char &ch: tasks){
            mp[ch-'A']++;
        }
        int time = 0;
        
        priority_queue<int>pq;
        
        for(int i=0; i<26; i++){
            //if freq of char > 0 so push in the q
            if(mp[i] > 0){
                pq.push(mp[i]);
            }
        }
        
        while(!pq.empty()){
            vector<int>temp;
            //1 br me n+1 task complete kr skte h
            for(int i=1; i <= n+1; i++){
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();             
                    freq--;
                    temp.push_back(freq); 
                } 
            }
            // if(freq > 0)so push in temp
            for(int &f : temp){
                if(f > 0)
                    pq.push(f);
            }
            
            /*----*/
            if(pq.empty()){
                time += temp.size(); 
            }
            else{
                time += n+1; //AB_ _ if(n=3) 3+1,3+1,2
            }
        }
        return time;
    }
};