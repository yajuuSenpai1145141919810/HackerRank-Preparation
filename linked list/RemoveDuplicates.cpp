// Remove Consecutive Duplicates from Sorted Linked List
// Write a function "deleteDuplicates" that removes consecutive duplicate nodes in-place, 
// retaining only the first node of each code. Return the head of the resulting list.
// Input head = [1, 2, 2, 2, 3, 4, 4, 5] Output= [1, 2, 3, 4, 5]

// Time Complexity :O(n)
// Space Complexity): O(1) inplace修改

#include <iostream>
SinglyLinkedListNode* deleteDuplicates(SinglyLinkedListNode* head) {
    
    // Edge cases 建議用nullptr!
    if(head==nullptr||head->next==nullptr){
        return head;
    }

    // 因為head不能亂動 因此設定一個current來遍歷
    SinglyLinkedListNode* current=head;

    // 建議要current!=nullptr如果一次跳兩格沒寫的話可能會出錯
    while(current!=nullptr&& current->next!=nullptr){
        //別忘了用data因為他在比數值
        if(current->next->data==current->data){
            current->next=current->next->next;
        }else{
            current=current->next;
        }
    }
    return head;
}


