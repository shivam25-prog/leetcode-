bool isPalindrome(struct ListNode* head) {
    if (!head || !head->next) return true;

    // Step 1: Find middle with slow/fast pointers
    struct ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half starting from slow->next
    struct ListNode *secondHalf = NULL;
    struct ListNode *curr = slow->next;
    while (curr) {
        struct ListNode *nextNode = curr->next;
        curr->next = secondHalf;
        secondHalf = curr;
        curr = nextNode;
    }

    // Step 3: Compare first half vs reversed second half
    struct ListNode *p1 = head;
    struct ListNode *p2 = secondHalf;
    while (p2) {
        if (p1->val != p2->val) {
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    return true;
}