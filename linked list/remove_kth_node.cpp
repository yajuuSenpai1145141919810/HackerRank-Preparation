// One-Pass Removal of k-th Node from End

// 在考什麼? Fast & Slow Pointers

// time complexity : O(n) 就整個掃過去一輪而已
// space complexity :O(1) 只用了兩個額外指標
// 使用dummy node ,解決刪除或修改的節點剛好是head 時，程式會因為找不到「前一個節點」而當掉或需要寫額外判斷的問題。

/*
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 */

//這個head可以有head->data head->next 等
SinglyLinkedListNode* removeKthNodeFromEnd(SinglyLinkedListNode* head, int k) {
    // 1. 基本邊界檢查：如果 list 為空，直接回傳
    if (head == nullptr) return nullptr;

    // Dummy Node
    // 要記的 * 跟 new 不要忘了!!
    // 原本只有：[5] -> [6] -> [7] -> [8] -> NULL 
    // 變成  [0] --head--> [5] -> [6] -> [7] -> [8] -> NULL
    SinglyLinkedListNode* dummy = new SinglyLinkedListNode(0);
  
    //用next把head跟dummy連上
    dummy->next = head; 

    // Fast & Slow Pointers
    SinglyLinkedListNode* fast = head;
    SinglyLinkedListNode* slow = dummy;

    // 4. 快指標 (fast) 先走 k 步
    for (int i = 0; i < k; i++) {
        if (fast == nullptr) {
            // 如果 k 超過 list 長度，題目要求回傳原列表
            // 記得清理 dummy 記憶體避免 leak (雖然在面試練習中通常還好)
            delete dummy;
            return head;
        }
        fast = fast->next;
    }

    // 5. 同時移動 fast 和 slow
    // 當 fast 走到 NULL 時，slow 剛好會停在「待刪除節點的前一個」
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    // 6. 執行刪除動作
    if (slow->next != nullptr) {
        SinglyLinkedListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next; // 跳過目標節點，完成刪除
        // delete nodeToDelete; // 釋放被刪除節點的記憶體
    }

    // 7. 回傳新的頭部
    // 即使原本的 head 被刪掉了，dummy->next 也會指向正確的新 head
    SinglyLinkedListNode* newHead = dummy->next;
    delete dummy; // 刪除我們自己建立的虛擬節點
    return newHead;
}
