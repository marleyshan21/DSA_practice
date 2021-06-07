//https://www.programiz.com/dsa/linked-list-operations
/*
List of basic operations:
1. Traversal
2. Insertion:
    a. at the beginning
    b. at the end
    c. in the middle
3. Deletion:
    a. at the beginning
    b. at the end
    c. in the middle

*/

#include <stdio.h>
#include <iostream> 

using namespace std;

struct Node
{
    /* data */
    int item;
    struct Node* next;
};

//INSERTION
//beginning
void insert_beginning(struct Node** ref, int item){

    //Allocate memory
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    //insert item
    new_node->next = (*ref);
    new_node->item = item;

    (*ref) = new_node;
    return;
}

//insert in the middle
void insert(struct Node* prev_node, int item){
    if(prev_node == NULL){
        cout<<"prev node cannot be null"<<endl;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->next = prev_node->next;
    new_node->item = item;

    prev_node->next = new_node;
    return;

}


//insert at the end
void insert_end(struct Node** ref, int item){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    struct Node* last = (*ref);

    new_node->next = NULL;
    new_node->item = item;
    if (*ref == NULL) {
        *ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    
    last->next = new_node;

    return;


}

void deleteNode(struct Node** ref, int key){
    struct Node *temp = *ref, *prev;
    if (temp != NULL && temp->item == key) {
    *ref = temp->next;
    free(temp);
    return;
    }

    // Find the key to be deleted
    while (temp != NULL && temp->item != key) {
        prev = temp;
        temp = temp->next;

    }
    // If the key is not present
    if (temp == NULL) return;

    // Remove the node
    prev->next = temp->next;

    free(temp);
}

// Print the linked list
void printList(struct Node* node) {
  while (node != NULL) {
    cout << node->item << " ";
    node = node->next;
  }
}


// Driver program
int main() {
  struct Node* head = NULL;

  insert_beginning(&head, 1);
  insert_beginning(&head, 2);
  insert_beginning(&head, 3);
  insert_end(&head, 4);
  insert(head->next, 5);

  cout << "Linked list: ";
  printList(head);

  cout << "\nAfter deleting an element: ";
  deleteNode(&head, 3);
  printList(head);
  cout<<endl;
}

