class Queue:

    def __init__(self):
        self.queue = []

    #Add one element (enqueue)
    def enqueue(self, item):
        self.queue.append(item)

    #Remove an element (dequeue)
    def dequeue(self):
        if(len(self.queue)) < 1:
            return None
        return self.queue.pop(0)

    #display the queue
    def display(self):
        print(self.queue)

    def size(self):
        return(len(self.queue))


if __name__ == '__main__':
    q = Queue()
    for i in range(1, 6):
        q.enqueue(i)

    q.display()
    q.dequeue()
    q.display()
    q.dequeue()
    q.display()

