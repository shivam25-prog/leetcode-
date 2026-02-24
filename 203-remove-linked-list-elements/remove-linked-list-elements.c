/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    while (head != NULL && head->val == val) {
        head = head->next;
    }
    
    struct ListNode* prev = NULL;
    struct ListNode* temp = head;
    while(temp != NULL){
        if(temp->val == val){
            prev->next = temp->next;
        }else{
            prev = temp;
        }
        temp = temp->next;
    }
    return head;
}