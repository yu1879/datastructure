/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* current = head;
        
        while(current && current->next){
            // A A B, delete 2nd A
            // 1st A->B, 1st A: current
            if(current->val == current->next->val){
                ListNode* tmp = current->next->next;
                delete current->next;
                current->next = tmp;
            }
            else{
                current = current->next;
            }
        }
        return head;
    }
};