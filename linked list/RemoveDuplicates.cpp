// Remove Consecutive Duplicates from Sorted Linked List
// Write a function "deleteDuplicates" that removes consecutive duplicate nodes in-place, 
// retaining only the first node of each code. Return the head of the resulting list.
// Input head = [1, 2, 2, 2, 3, 4, 4, 5] Output= [1, 2, 3, 4, 5]

SinglyLinkedListNode* deleteDuplicates(SinglyLinkedListNode* head) {
    //edge cases
    if(head==nullptr||head->next==nullptr){
        return head;
    }
    SinglyLinkedListNode* current=head;
    while(current!=nullptr&& current->next!=nullptr){
        if(current->next->data==current->data){
            current->next=current->next->next;
        }else{
            current=current->next;
        }
    }
    return head;
}


