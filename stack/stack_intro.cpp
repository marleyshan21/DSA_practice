// https://www.programiz.com/dsa/stack

// Steps:
// 1. A pointer called TOP is used to keep track of the top element in the stack.
// 2. When initializing the stack, we set its value to -1 so that we can check if the stack is empty by comparing TOP == -1.
// 3. On pushing an element, we increase the value of TOP and place the new element in the position pointed to by TOP.
// 4. On popping an element, we return the element pointed to by TOP and reduce its value.
// 5. Before pushing, we check if the stack is already full
// 6. Before popping, we check if the stack is already empty


#include <iostream>
#include <stdlib.h>

using namespace std;

#define MAX 10
int size = 0;


struct stack{
    int items[MAX];
    int top;
    };

typedef struct stack st;

//Creating a stack
void create_stack(st *s){
    s->top = -1;
}


//check if the stack is full
int stack_isfull(st *s){
    if(s->top == MAX-1)
        return 1;
    else
        return 0;
        }


//check if stack is empty
int stack_isempty(st *s){
    if(s->top == -1)
        return 1;
    else    
        return 0;
}

//Add elements to the stack
void stack_push(st *s, int new_item){
    // printf("new item= %d \n", new_item);
    if(stack_isfull(s)){
        printf("Stack is full \n");
    }
    else{
        
        s->top++;
        s->items[s->top] = new_item;
        size++; 
        
    }


}



//Remove element from the stack
void stack_pop(st *s){
    if(stack_isempty(s)){
        printf("stack is empty \n");
    }
    else{
        printf("Item popped= %d \n", s->items[s->top]);
        s->top--;
        size--;
    }

}

void print_stack(st *s){

    printf("Stack = [ ");
    for(int i = 0; i < size ; i++){
        cout << s->items[i] << ",";
    }
    cout << " ]" << endl;


}

int main(){
    st *s = (st *)malloc(sizeof(st));

    create_stack(s);
    for(int i = 0; i < 8; i++){
        if(!(stack_isfull(s))){
            // printf("Item pushed= %d", i);
            stack_push(s, i);
        }
    }
    print_stack(s);
    if(!(stack_isempty(s))){
        stack_pop(s);
        stack_pop(s);
    }

    print_stack(s);

}





