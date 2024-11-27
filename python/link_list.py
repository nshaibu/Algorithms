'''
Created on Jul 30, 2017

@author: nafiu
'''
import sys

class Node(object):
    '''
    node abt
    '''
    def __init__(self):
        self.data = None
        self.next = None
        
    def set_data(self, param):
        self.data = param
        
    def set_next(self, param=None):
        self.next = param
        
    def get_next(self):
        return self.next
    
    def get_data(self):
        return self.data


class LinkedList:

    def __init__(self, params=None):
        self.head = Node()

        if not params == None:
            tmp = Node()
            tmp.set_data(params)
            tmp.set_next()

            self.head = tmp
        else:
            self.head = params

    def is_empty(self):
        return self.head == None

    def insert(self, param):
        tmp = Node()
        tmp.set_data(param)
        tmp.set_next(self.head)
        self.head = tmp
        
    def find(self, param):
        curr = self.head
        inlist = False

        while curr is not None:
            if curr.get_data() == param:
                inlist = True
                break

            curr = curr.get_next()

        return inlist
    
    def size(self):
        count = 0
        curr = self.head
        
        while curr is not None:
            count += 1
            curr = curr.get_next()
        
        return count
    
    def remove_node(self, value):
        curr = self.head
        prev = self.head
        
        if value is None:
            sys.exit(1)
            
        while curr is not None:
            if curr.get_data() == value:
                prev.set_next(curr.get_next())
            prev = curr 
            curr = curr.get_next()

    def append(self, param):
        curr = self.head
        
        if param is None:
            return None
        
        while curr is not None:
            if curr.get_next() is None:
                tmp = Node()
                tmp.set_data(param)
                tmp.set_next()
                
                curr.set_next(tmp)
                break
            
            curr = curr.get_next()
        
    def __str__(self):
        curr = self.head 
        lt = list()        
        while curr is not None:
            lt.append(curr.get_data())
            curr = curr.get_next()
        
        return str(lt)


s = LinkedList(451)
s.insert(12)
s.insert(58)
s.insert(47)
#s.remove_node(12)
s.remove_node(12)
s.append(14)
s.append(45)

print(s)