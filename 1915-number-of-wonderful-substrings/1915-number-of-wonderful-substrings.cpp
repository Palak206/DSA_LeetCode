// class Solution {
// public:
//     long long wonderfulSubstrings(string word) {
//         long long ans=0;
//         int n=word.size();

//         for(int i=0;i<n;i++){
//             map<char,bool> mp;
//             int cnt=0;
//             for(int j=i;j<n;j++){
//                 if(mp[word[j]]==false){
//                     mp[word[j]]=true;
//                     cnt++;
//                 }
//                 else if(mp[word[j]]==true){
//                     mp[word[j]]=false;
//                     cnt--;
//                 }

//                 if(cnt<=1){
//                     ans++;
//                 }
//             }
//         }
//         return ans;
//     }
// };


// a = 001
// b = 010
// c = 100
// d = 1000

// a = 0
// ch-'a' shift krna h b-a = 1 so 1 time shift

class Solution {
public:
    typedef long long ll;
    long long wonderfulSubstrings(string word) {
        unordered_map<ll , ll> mp;
        
        mp[0] = 1;//pst me we already had seen cumilitive xor = 0
        int cum_xor = 0;
        
        ll res = 0;
        
        for(char &ch : word){
            int shift = ch-'a';
            //binary rep 1 ko left shift 1<<shift
            
            cum_xor ^= (1<<shift);
            
            res += mp[cum_xor];//all chracters are even in count
            
            
            for(char ch1 = 'a'; ch1 <= 'j'; ch1++){
                
                shift = ch1 -'a';
                
                //past me xor dekha hai k
                
                ll check_xor = (cum_xor ^ (1<<shift));
                
                res += mp[check_xor];
            }
            mp[cum_xor]++;
        }
        return res;
    }
};