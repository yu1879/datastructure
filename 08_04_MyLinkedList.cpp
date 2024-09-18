class MyLinkedList {
    struct ListNode{
        int val;
        ListNode* next;
    };
    ListNode* head;
    ListNode* tail;
    int len;
    
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        len = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(len <= index)
            return -1;
        ListNode* current = head;
        for(int i=0;i<index;i++){
            current = current->next;
        }
        return current->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        head = new ListNode{val, head};
        len++;
        if(tail == nullptr)
            tail = head;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if(tail){
            tail->next = new ListNode{val, nullptr};
            tail = tail->next;
        }
        else{
            head = tail = new ListNode{val, nullptr};
        }
        len++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > len)
            return ;
        if(index == len)
            addAtTail(val);
        else if(index == 0)
            addAtHead(val);
        else{
            // A B C => A D B C
            ListNode* current = head;
            for(int i=1;i<index;i++){
                current = current->next;
            }
            ListNode* tmp = current->next;
            current->next = new ListNode{val, tmp};
            len++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= len)
            return;
        if(index == 0){
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
            len--;
            if(head == nullptr){
                tail = nullptr;
            }
            return ;
        }
        
        ListNode* current = head;
        // A B C D, delete C, current-> B
        // move current (index - 1) times
        for(int i=1;i<index;i++){
            current = current->next;
        }
        if(index == len-1){
            delete tail;
            current->next = nullptr;
            tail = current;
        }
        else{
            ListNode* tmp = current->next;
            current->next = current->next->next;
            delete tmp;
        }
        len--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */