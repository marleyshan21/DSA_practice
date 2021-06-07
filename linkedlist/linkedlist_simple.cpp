//https://www.programiz.com/dsa/linked-list

#include<bits/stdc++.h>
using namespace std;

//Node creation
class Node{
    public:
        int value;
        Node* next;
};

int main(){
    Node* head;
    Node* one = NULL;
    Node* two = NULL;
    Node* three = NULL;

    //allocate 3 nodes in the heap
    one = new Node();
    two = new Node();
    three = new Node();

    //Value assignment
    one->value = 1;
    two->value = 2;
    three->value = 3;

    //Connect the nodes
    one->next = two;
    two->next = three;
    three->next = NULL;

    //print the values
    head = one;
    while(head!=NULL){
        printf("%d ", head->value);
        head = head->next;
    } 

    cout<<endl;
}
