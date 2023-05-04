// RDD 1st R ban D then RD, THEN D(bcoz Round) BAN R AND D LEFT SO ANS = DIRE
// RDD = so first D BAN thenn R comes in end  DR THEN D BEN R AND D IS LEFT
//if RRR all are same then we go 2nd  senario that is Announce the victory:
//round element supoose we have a1,a2,a3,a4,a5 and we pop a2 pop() so a1 'll come at the end of the array like a2 a3 a4 a5 a1 for that (i+n)

// APPROACH
// use queue1 for each senate R(graph each senate R) & find it's closest senate D(using queue for closing senate)
// then queue2 for each senate D & ban it remove from queue 
//keep on repeating(q.empty()) these step untill we found victory(only one queue is remaining whichever can be R & D)  


class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> qr,qd;
        int n= senate.length();
        
        for(int i= 0; i<n; i++){
            if(senate[i] == 'R'){
                qr.push(i);
            }
            else{
                qd.push(i);
            }
        }
        
        //until one party is entirely gone
        while(!qr.empty() && !qd.empty()){
            int r_ele = qr.front(), d_ele = qd.front();
            qr.pop() , qd.pop();
            
            if(r_ele < d_ele){
                qr.push(r_ele+n);
            }
            else{
                qd.push(d_ele+n);
            }
        }
        
        if(qr.size() > qd.size())
            return "Radiant";
        else
            return "Dire";
        
    }
};