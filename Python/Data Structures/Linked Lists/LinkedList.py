# My Linked List Implementation

class LinkedList:
    def __init__(self, head=None):
        self.head = head

    def head_insert(self, data):
        new_node = Node(data)
        if self.head:
            new_node.next = self.head
        self.head = new_node

    def tail_insert(self, data):
        new_node = Node(data)
        current = self.head
        if current:
            while current.next:
                current = current.next
            current.next = new_node
        else:
            self.head = new_node

    def print_list(self):
        cur = self.head
        while cur is not None:
            print("{} ->".format(cur.data), end=" ")
            cur = cur.next
        print("NULL")


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
