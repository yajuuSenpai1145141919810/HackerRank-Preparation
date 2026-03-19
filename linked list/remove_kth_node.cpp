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
    
    //建立一個dummy 解決刪除第一個點的難題
    SinglyLinkedListNode* dummy = new SinglyLinkedListNode(0);
    dummy->next = head;
    
    SinglyLinkedListNode* fast = dummy;
    SinglyLinkedListNode* slow = dummy;
    
    //這題最大的陷阱就是 這題的k=3實際上是倒數第四個 因此要用<=k!!
    for (int i = 0; i <= k; i++) {
        
        //K太大了
        if (fast->next == nullptr) {
            delete dummy;
            return head; 
        }
        //這邊的意思是 我fast原本只向dummy,且dummy的掛鉤目前勾著5,則 我把fast指向5
        fast = fast->next;
    }

    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    
    // 讓 nodeToDelete 指向5 不是必要的 但避免leak
    SinglyLinkedListNode* nodeToDelete = slow->next;

    //把 dummy 的鉤子拔起來，跳過 5，直接勾到後面的 6 身上
    slow->next = slow->next->next;
    delete nodeToDelete;

    SinglyLinkedListNode* newHead = dummy->next;
    delete dummy;
    return newHead;
}
