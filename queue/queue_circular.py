#https://www.programiz.com/dsa/circular-queue

class CircularQueue():

    def __init__(self, k):
        self.k = k
        self.queue = [None]*k
        self.head = self.tail = -1

    #insert and element in the queue
    def enqueue(self, data):

        if((self.tail + 1)%self.k == self.head):
            print("it is full")

        elif(self.head == -1):
            self.head = 0
            self.tail = 0
            self.queue[self.tail] = data
        else:
            self.tail = (self.tail + 1)%self.k
            self.queue[self.tail] = data
    
    #Delete an element 
    def dequeue(self):
        if(self.head == -1):
            print("Circular queue is empty")
        elif(self.head == self.tail):
            self.head = -1
            self.tail = -1

        else:
            temp = self.queue[self.head]
            self.head = (self.head + 1)%self.k

    def printQueue(self):
        if(self.head == -1):
            print("no element")
        
        if(self.tail >= self.head):
            for i in range(self.head, self.tail+1):
                print(str(self.queue[i]) + ", ")
        
        else:
            for i in range(self.head, self.k):
                print(str(self.queue[i]) + ", ")
            for i in range(0, self.tail + 1):
                print(str(self.queue[i] )+ ", ")


if __name__ == '__main__':
    obj = CircularQueue(5)
    obj.enqueue(1)
    obj.enqueue(2)
    obj.enqueue(3)
    obj.enqueue(4)
    obj.enqueue(5)
    obj.enqueue(6)
    print("Initial queue")
    obj.printQueue()
    obj.dequeue()
    print("After removing an element from the queue")
    obj.printQueue()