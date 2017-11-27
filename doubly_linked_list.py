'''
Created on Jul 31, 2017

@author: nafiu
'''
import sys

class Node(object):
    '''
    Doubly linked list
    '''

    def __init__(self, params=None):
        self.data = params
        self.next = params
        self.prev = params

    def set_data(self, param):
        self.data = param

    def set_next(self, param=None):
        self.next = param

    def set_prev(self, param=None):
        self.prev = param

    def get_data(self):
        return self.data

    def get_next(self):
        return self.next

    def get_prev(self):
        return self.prev



class List:

    def __init__(self, param=None):

        if param != None:
            tmp = Node()

            tmp.set_data(param)
            tmp.set_next()
            tmp.set_prev(param)

            self.head = self.rear = tmp
        else:
            self.head = self.head = param

    def is_empty(self):
        return self.head == None

    def insert(self, param):

        if self.is_empty():
            tmp = Node()

            tmp.set_data(param)
            tmp.set_next()
            tmp.set_prev(param)

            self.head = self.rear = tmp

        tmp = Node()

        tmp.set_data(param)
        tmp.set_next(self.head)
        tmp.set_prev()
        self.head.set_prev(tmp)

        self.head = tmp

    def append(self, param):
        tmp = Node()

        tmp.set_data(param)
        tmp.set_next()
        tmp.set_prev(self.rear)

        self.rear.set_next(tmp)
        self.rear = tmp

    def size(self):
        curr = self.rear
        count = 0

        while curr != None:
            count += 1

            curr = curr.get_prev()
        return count

    def remove_node(self, value):

        if value == None: sys.exit()
        curr = self.rear
        prev = self.rear

        while curr != None:
            if curr.get_data() == value:
                prev.set_prev(curr.get_prev())
                curr = curr.get_prev()

                curr.set_next(prev)
                break


            prev = curr
            curr = curr.get_prev()

    def __str__(self):
        curr = self.head
        lt = list()

        while curr != None:
            lt.append(curr.get_data())
            curr = curr.get_next()
        return str(lt)

s = List()

for i in range(30):
    s.insert(i)

for i in range(6, 25):
    s.remove_node(i)

print(str(s.size()))
print(s)