# https://www.programiz.com/dsa/linked-list-operations
"""
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
"""

#Create a node
class Node():
    def __init__(self, item):
        self.item = item
        self.next = None

class LinkedList():
    def __init__(self):
        self.head = None
    
    ###Insertion
    
    #at the beginning
    def insert_beginning(self,item):
        new_node = Node(item)
        new_node.next = self.head
        self.head = new_node
    
    #after a node
    def insert_middle(self, node , data):

        if node is None:
            print("error")
            return
        
        new_node = Node(data)
        new_node.next = node.next
        node.next = new_node
    
    #in the end
    def insert_end(self, item):
        new_node = Node(item)

        if self.head == None:
            self.head = new_node
        
        last = self.head
        while(last.next!=None):
            last = last.next
        last.next = new_node

    ###Deletion
    def deletion(self, position):
        #if empty
        if self.head == None:
            return
        
        temp_node = self.head

        #beginning
        if position == 0:
            temp_node = self.head.next
            temp_node = None
            return
        
        for i in range(position-1):
            temp_node = temp_node.next
            if temp_node is None:
                break
        
        # If the key is not present
        if temp_node is None:
            return
        
        if temp_node.next is None:
            return

        next = temp_node.next.next
        temp_node.next = None
        temp_node.next = next

    def printList(self):
        temp_node = self.head
        while (temp_node):
            print(str(temp_node.item) + " ")
            temp_node = temp_node.next

if __name__ == '__main__':

    list = LinkedList()
    list.insert_beginning(1)
    list.insert_beginning(2)
    list.insert_beginning(3)
    list.insert_end(4)
    list.insert_middle(list.head.next, 5)

    print('Linked list:')
    list.printList()

    print("\nAfter deleting an element:")
    list.deletion(3)
    list.printList()