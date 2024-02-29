#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node* &head, Node* &smaller, Node* &larger, int pivot) {
  //empty input list check
  if (head == nullptr) {
    // if it is empty, smaller and larger should also be empty
    // nullify garbage values
    smaller = nullptr;
    larger = nullptr;
    // head->next = nullptr; //head's next should also be empty
    return;
  }

  // if skips, a head exists detach it
  Node* current = head;
  head = head->next; 
  //detach head from list  and iterating to end of list 

  llpivot(head,smaller,larger,pivot); // recursive call will reach end of list before partitioning so last node will be processed first

  if (current->val <= pivot) {
    current->next = smaller; // attaching current head to smaller list
    smaller = current; // becomes head of smaller list
  }
  else if (current->val > pivot) {
    current->next = larger;
    larger = current; 
  }

}
