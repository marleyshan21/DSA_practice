//https://www.programiz.com/dsa/queue

// Queue operations work as follows:

// 1.two pointers FRONT and REAR
// 2.FRONT track the first element of the queue
// 3.REAR track the last element of the queue
// 4.initially, set value of FRONT and REAR to -1

// Enqueue Operation
// 5.check if the queue is full
// 6.for the first element, set the value of FRONT to 0
// 7.increase the REAR index by 1
// 8.add the new element in the position pointed to by REAR

// Dequeue Operation
// 9.check if the queue is empty
// 10.return the value pointed by FRONT
// 11.increase the FRONT index by 1
// 12.for the last element, reset the values of FRONT and REAR to -1

#include <iostream>
#define SIZE 5

using namespace std;

class Queue {

    private:
        int items[SIZE];
        int front, rear;

    public:
        Queue(){
            front = -1;
            rear = -1;
        }
    
    bool isFull(){
        if(front == 0 && rear == SIZE -1){
            return true;
        }
        return false;

    }

    bool isEmpty(){
        if(front == -1){
            return true;
        }
        return false;
    }

    void enqueue(int element){
        if(isFull()){
            cout << "Queue is full" << endl;
        }
        else {
            if(front == -1){
                front = 0;
            }
            rear++;
            items[rear] = element;
            cout<< " Inserted " << element <<endl;
        }
        

    }

    int dequeue(){
        int element;
        if(isEmpty()){
            cout<<"Queue is empty" << endl;
            return(-1);
        }
        else{
            element = items[front];

            if(front >= rear){
                front = -1;
                rear = -1;
            }
            else{
                front++;
            }
        return element;
        }
    }

    void display(){
        int i;

        if(isEmpty()){
            cout<<"Queue is empty"<<endl;

        }
        else{
            cout<<"Front index: "<<front <<endl;
            cout<<"Rear index: "<<rear <<endl;
            for(i=front; i<=rear;i++){
                cout<<items[i]<<", ";
            }
            cout<<endl;
            
        }
    }



};

int main(){
    Queue q;

    q.dequeue();
    for(int i = 0; i<=5; i++){
        q.enqueue(i);
        q.display();
    }
    q.dequeue();
    q.dequeue();
    q.display();

}

