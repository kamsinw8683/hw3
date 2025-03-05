#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
    if(head == nullptr){
        smaller = nullptr;
        larger = nullptr;
        return;
    }
    Node* current = head;
    head = head->next;
    current->next = nullptr;

    llpivot(head ,smaller,larger,pivot);

    if(current ->val <= pivot){
        current->next = smaller;
        smaller = current;
    }
    else{
        current->next = larger;
        larger = current;
    }
}

