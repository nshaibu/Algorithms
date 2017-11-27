'''
Created on Jul 30, 2017

@author: nafiu
'''

class queue(object):
    '''
    queue abt
    '''

    def __init__(self):
        self.items=[]
        
    def size(self):
        return len(self.items)
    
    def enqueue(self, param):
        self.items.append(param)
        
    def dequeue(self):
        if not self.is_empty():
            self.items.remove(self.items[0])
        
    def is_empty(self):
        return self.items == [] 
    
    def __str__(self):
        return str(self.items)
    
s=queue()
s.enqueue("nafiu")
s.enqueue("shaibu")
s.dequeue()
s.enqueue("nafiu")
print(s)
        