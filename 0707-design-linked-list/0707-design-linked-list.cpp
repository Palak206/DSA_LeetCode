// class MyLinkedList {
// public:
//     ListNode *ptr = new ListNode(0);
//     MyLinkedList() {
        
//     }
//     /** Get the value of the index-th node in the linked list. 
//        If the index is invalid,   return -1. */
//     int get(int index) {
//         // Return -1 for invalid index
//         if(index >= size || index < 0) {
//             return -1;
//         }
//         Node* curr = head;
//         for(int i=0; i<index; i++) {
//             curr = curr->next;
//         }
//         return curr->val;
//     }
    
//     /** Append a node of value val to the last element of the linked list. */
//     void addAtHead(int val) {
//         addAtIndex(0 , val);
//     }
    
//     /** Append a node of value val to the last element of the linked list. */
//     void addAtTail(int val) {
//         addAtIndex(size , val);
//     }
    
//     //insertion
//     void addAtIndex(int index, int val) {
//         //invalid index
//         if(index >= size || index < 0) {
//             return ;
//         }
        
//         Node* curr= head;
//         Node* toAdd = new Node(val);
        
//         if(index == 0){
//             toAdd->next = curr;
//             curr = curr->next;
//         }
        
//         for(int i=0 ; i<index-1 ; i++){
//             curr = curr->next;
//         }
        
//         toAdd->next = curr->next;
//         curr->next = toAdd;
        
//     }
    
//     void deleteAtIndex(int index) {
//         Node* curr= head;
        
//         if(index == 0){
//             curr = curr->next;
//             return;
//         }
        
//         for(int i=0 ;i<index-1 ; i++){
//             curr = curr->next;
//         }
//         curr->next = curr->next->next;
//     }
// };



class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        next = NULL;
    }
};

class MyLinkedList {
public:
    int size = 0;
    Node* head = new Node(0);
    MyLinkedList() { }

    int get(int index) {
        if(index >= size) return -1;
        Node* temp = head->next;
        for(int i = 0 ; i < index ; i++) temp = temp->next;
        return temp->val;
    }

    void addAtHead(int val) {
        Node* temp = head->next;
        head->next = new Node(val);
        head->next->next = temp;
        size++;
    }
    
    void addAtTail(int val) {
        Node* temp = head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = new Node(val);
        size++;
    }

    void addAtIndex(int index, int val) {
        if(index > size) return;
        Node* temp = head;
        for(int i = 0 ; i < index ; i++) temp = temp->next;
        Node* temp1 = temp->next;
        temp->next = new Node(val);
        temp->next->next = temp1;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= size) return;
        Node* temp = head;
        for(int i = 0 ; i < index ; i++) temp = temp->next;
        Node* temp1 = temp->next;
        temp->next = temp1->next;
        temp1->next = NULL;
        size--;
        delete temp1;
    }
};



// /**
//  * Your MyLinkedList object will be instantiated and called as such:
//  * MyLinkedList* obj = new MyLinkedList();
//  * int param_1 = obj->get(index);
//  * obj->addAtHead(val);
//  * obj->addAtTail(val);
//  * obj->addAtIndex(index,val);
//  * obj->deleteAtIndex(index);
//  */