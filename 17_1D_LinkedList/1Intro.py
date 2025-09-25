
class Node:
    def __init__(self,data,next= None):
        self.data = data
        self.next= next




# creating first node

head = Node(1)

second = Node(2)

head.next = second    # linking first node to second node

print(head.data, second.data)