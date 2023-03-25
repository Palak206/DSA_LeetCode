class Solution{
    public:
        int maxProduct(vector<string>& words){
            vector<int>state(words.size());
            int ans = 0;
            for(int  i = 0 ; i<words.size() ; i++){
                for(char c:words[i]){
                    state[i] |= 1<<(c-'a');
                    // left shift 0000
                    // a = 1<<1 ( a= 1 b=2  c= 3 d= 4)
                    // b= 1<<2
                    
                }
                for(int j = 0 ;j<i ; j++){
                    if(!(state[i]&state[j])){
                        // if the end is 0 then onl have no common letter
                        if(words[i].size()*words[j].size() > ans)
                            ans = words[i].size()*words[j].size();
                    }
                        
                }

            }
            return ans;
        }
    
};






// class Solution {
// private:
//     int length(string str,string str1){
//         int arr[26]={false};
//         for(int i=0;i<str.length();i++){
//             arr[str[i]-'a']=true;
//         }
//         for(int i=0;i<str1.length();i++){
//             if(arr[str1[i]-'a']==true){
//                 return 0;
//             }
//         }
//         return str.length()*str1.length();
//     }
// public:
//     int maxProduct(vector<string>& words) {
//         int ans=0;
//         for(int i=0;i<words.size();i++){
//             for(int j=i+1;j<words.size();j++){
//                 if(ans<(words[i].length()*words[j].length())){
//                 ans=max(ans,length(words[i],words[j]));
//                 }
//             }
//         }
            
//         return ans;
//     }
// };


