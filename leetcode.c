struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy = {0, NULL};
    struct ListNode* tail = &dummy;
    
    while (list1 && list2) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    
    tail->next = list1 ? list1 : list2;
    return dummy.next;
}
// link to the problem: https://leetcode.com/problems/merge-two-sorted-lists/?envType=list
// What I learned:
// 1. Working with pointers in C takes a lot of care. I had to move them forward without breaking the links, otherwise I lose track of the list.
// 2. Using interative rather than recursive is better for memory. 
// 3. Edge cases like empty lists aren’t a big deal here, since the while loop condition already takes care of them.

// I didn't compare my code to others.