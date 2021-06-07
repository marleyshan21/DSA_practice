#https://www.programiz.com/dsa/linked-list#python-code

class Node:
    def __init__(self,item):
        self.item = item
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

if __name__ == '__main__':

    linkedlist = LinkedList()
    linkedlist.head = Node(1)
    second = Node(2)
    third = Node(3)

    linkedlist.head.next = second
    second.next = third

    while linkedlist.head!=None:
        print(linkedlist.head.item)
        linkedlist.head = linkedlist.head.next