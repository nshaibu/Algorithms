'''
Created on Jul 30, 2017

@author: nafiu
'''
import sys

class Deque(object):
    '''
    deque abt
    '''


    def __init__(self):
        self.items=[]

    def add_front(self, param):
        self.items.insert(0, param)

    def remove_front(self):
        if not self.is_empty():
            return self.items.remove(self.items[0])

    def add_rear(self, param):
        self.items.append(param)

    def remove_rear(self):
        if not self.is_empty():
            return self.items.pop()

    def size(self):
        return len(self.items)

    def is_empty(self):
        return self.items == []

    def __str__(self):
        return str(self.items)
    
def palindrome():
    n=input("string to check:")
    
    if n == None:
        sys.exit(1)
        
    s=Deque()
    com=""
    
    for i in n:
        s.add_rear(i)
    
    while not s.is_empty(): com+=str(s.remove_rear())
    
    if com == n:
        print("Is a palindrome")
    else:
        print("Is not palindrome")
        
if __name__ == '__main__':
    palindrome()   