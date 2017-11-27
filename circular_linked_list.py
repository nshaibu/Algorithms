'''
Created on Jul 31, 2017

@author: nafiu
'''

class Node(object):
    '''
    circular linked list
    '''

    def __init__(self, params=None):
        self.data = params
        self.next = params

    def set_data(self, param=None):
        self.data = param

    def set_next(self, param=None):
        self.next = param

    def get_data(self):
        return self.data

    def get_next(self):
        return self.next


class List:

    def __init__(self, param=None):

        if param != None:
            tmp=Node()

            tmp.set_data(param)
            tmp.set_next(tmp)

            self.head = tmp
        else:
            self.head = param

    def is_empty(self):
        return self.head == None

    def size(self):
        curr = self.head
        count = 0

        while curr != self.head and count == 0:
            pass

    def insert(self, param):
        tmp=Node()

        if self.is_empty():
            tmp.set_data(param)
            tmp.set_next(tmp)

            self.head = tmp

        else:
            curr = self.head

            while True:
                if curr.get_next() == self.head:
                    tmp.set_data(param)
                    tmp.set_next(self.head)

                    curr.set_next(tmp)
                    break

                curr = curr.get_next()

    def iter(self):
        curr = self.head

        while True:
            print(str(curr.get_data()))

            curr = curr.get_next()


s = List()
s.insert(45)
s.insert(78)
s.insert(23)
s.insert(85)

s.iter()
print(s.is_empty())