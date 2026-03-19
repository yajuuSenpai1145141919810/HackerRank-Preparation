// Easy
// One-Pass Removal of k-th Node from End
// Given the head of a singly linked list and an integer k, remove the k-th node from the end in one traversal and return the new head. 
// If k is invalid, return the original list.
// head = [5, 6, 7, 8] ,k = 3
// Output [6, 7, 8]

// 在考什麼? Fast & Slow Pointers
// 如果你要「刪除」某個節點，你必須停在它的「前一個」位置

// time complexity : O(n) 就整個掃過去一輪而已
// space complexity :O(1) 只用了兩個額外指標

/*
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 */

SinglyLinkedListNode* removeKthNodeFromEnd(SinglyLinkedListNode* head, int k) {
    
    if (!head || k < 0) return head;
    
    //建立一個dummy 解決刪除第一個點
    SinglyLinkedListNode* dummy = new SinglyLinkedListNode(0);
    dummy->next = head;
    
    SinglyLinkedListNode* fast = dummy;
    SinglyLinkedListNode* slow = dummy;

    for (int i = 0; i <= k; i++) {
        if (fast->next == nullptr) {
            delete dummy;
            return head; 
        }
        fast = fast->next;
    }

    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    SinglyLinkedListNode* nodeToDelete = slow->next;
    slow->next = slow->next->next;
    delete nodeToDelete;

    SinglyLinkedListNode* newHead = dummy->next;
    delete dummy;
    return newHead;
}
