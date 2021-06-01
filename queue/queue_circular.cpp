//https://www.programiz.com/dsa/circular-queue


#include <iostream>
#define SIZE 5

using namespace std;

class Queue{

    private:
        int items[SIZE], front, rear;
    
    public:
    Queue(){
        front = -1;
        rear = -1;
    }

    bool isFull(){
        if( front == 0 && rear == SIZE -1 ){
            return true;
        }
        if( front == rear + 1){
            return true;
        }
        else
            return false;

    }

    bool isempty(){

        if(front == -1 && rear == -1){
            return true;
        }
        else
            return false;

    }

    //Adding an element
    void enqueue(int element){
        
        if(isFull()){
            cout<<endl;
            cout<<"it is full" << endl;
        }

        
        else{
            

            if(front == -1){
                front = 0;}
            
            rear = (rear + 1)%SIZE;
            cout << rear;
            items[rear] = element;
            
           


        }
    }

    //Removing an element
    void dequeue(){

        if(isempty()){
            cout<<" it is empty" << endl;
        }
        else{
            if(front == rear){
                front = -1;
                rear = -1;
            }
            else{
                front = (front + 1)%SIZE;
            }
        }

    }

    void display(){
        if(isempty()){
            cout<<"its empty" << endl;
        }

        else{
            for (int i = front; i != rear; i = (i + 1) % SIZE)
                cout << items[i];
        }
        cout<<endl;     
    }
};


int main() {
  Queue q;

 
  q.dequeue();
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(5);
  q.enqueue(6);
  q.display();
  q.dequeue();
  q.display();
  q.dequeue();
  
  return 0;
}