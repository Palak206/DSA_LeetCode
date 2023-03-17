// class Trie {
// private : 
//     struct Node{
//     Node *links[26] ; //pointer bcoz we have to take reference of each letter
//     bool flag = false;
    
//     bool containKey(char ch){
//         return (links[ch-'a'] != NULL);
//     }
    
//     void put(char ch , Node* node){
//         links[ch-'a'] = node; // WORD EXISTED
//     }
    
//     Node* get(char ch){
//         return links[ch-'a'];
//     }
    
//     bool setEnd() {
//         flag = true;
//         return flag;// it will true at the end
//     }
    
//     bool isEnd() {
//         return flag;// it will true at the end
//     }
// };
// public:
    
//     Trie() {
//         root = new Node();
//     }
    
//     void insert(string word) {
//         //t.c = O(length)
//         Node * node = root ;
//         for(int i = 0 ; i < word.size() ; i++){
//             if(!node->containKey(word[i])){
//                 node->put(word[i] , new Node);
//             }
//             //moves to reference trie
//             node->get(word[i]);
//         }
//         node->setEnd();
//     }
    
//     bool search(string word) {
//         Node * node = root ;
//         for(int i = 0 ; i < word.length() ; i++){
//             if(!node->containKey(word[i])){
//                 return false;
//             }
//             node = node->get(word[i]);
//         }
//         //if(node->isEnd()) return true}
//         // return false
//        return node->isEnd(); 
//     }
//     //return if any word in trie that start with given prefix
//     bool startsWith(string prefix) {
//         Node * node = root ;
//         for(int i = 0 ; i<word.length() ; i++){
//             if(!node->containKey(word[i])){
//                 return false;
//             }
//             node = node->get(word[i]);
//         }
//        return true;
//     }
// };



class Trie {
private:
    struct TrieNode {
        TrieNode* arr[26];
        bool end;
        
        TrieNode() {
            memset(arr, 0, sizeof(arr));
            end = false;
        }
    };
    
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string s) {
        TrieNode* curr = root;
        int c;
        for(int i = 0; i < s.length(); i++) {
            c = s[i] - 'a';
            if(curr->arr[c] == NULL) {
                curr->arr[c] = new TrieNode();
            }
            curr = curr->arr[c];
        }
        curr->end = true;
    }
    
    bool search(string s) {
        TrieNode* curr = root;
        int c;
        for(int i = 0; i < s.length(); i++) {
            c = s[i] - 'a';
            if(curr->arr[c] == NULL) {
                return false;
            }
            curr = curr->arr[c];
        }
        return curr->end;
    }
    
    bool startsWith(string s) {
        TrieNode* curr = root;
        int c;
        for(int i = 0; i < s.length(); i++) {
            c = s[i] - 'a';
            if(curr->arr[c] == NULL) {
                return false;
            }
            curr = curr->arr[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */