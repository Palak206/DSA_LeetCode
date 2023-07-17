// class Solution {
// public:
//     int countCharacters(vector<string>& words, string chars) {
//         vector<string> res;
//         int n= words.size();
//         int m = chars.size();
//         int i=0 , j=0;
//         int k = words[i].size();
//         int l = chars[j].size();
        
//         for(i=0; i<n ; i++){
//             for(int j=0; j<m ; j++){
//                 if(words[i][k++] == chars[j][l++])
//             }
//         }
        
//     }
// };

class Solution {
private:
    bool check(vector<int> arr1 , vector<int> arr2){
        for(int i = 0 ; i < 26 ; i++){
            if(arr1[i] < arr2[i])
                return false;
        }
        return true;
    }
    
public:
    int countCharacters(vector<string>& words, string chars) {
        int sum = 0;
        
        //find frequency of 'chars'
        vector<int> arr1(26,0);
        for(int i = 0 ; i < chars.size() ; i++)
            arr1[chars[i]-'a']++;
        
        for(int i = 0 ; i < words.size() ; i++){
            //calculate the frequency of each word.
            vector<int> arr2(26,0);
            for(int j = 0 ; j < words[i].size() ; j++){
                string m = words[i];
                arr2[m[j]-'a']++;
            }
            
            bool p = check(arr1 , arr2);
            if(p){
                sum = sum + words[i].size();
            }
        }
        return sum;
    }
};