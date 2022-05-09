'''
Created on Jul 30, 2017

@author: nafiu
'''
import sys

class stack(object):
    '''
    stack class definitions
    '''


    def __init__(self):
        self.items=list()

    def is_empty(self):
        return self.items == list()

    def push(self, value):
        self.items.append(value)

    def pop(self):
        if not self.is_empty():
            return self.items.pop()

    def size(self):
        return len(self.items)

    def peek(self):
        if not self.is_empty():
            index_=self.size()
            return self.items[index_-1]


def main():
    s=stack()

    var=list(input("Input backets:"))

    if not (var == list()):
        for i in range(len(var)):
            if var[i] == '(': s.push('(')
            else: s.pop()

        if not s.is_empty():
            print("Brackets are not balanced")
        else:
                print("Backets are balance")
    else:
        sys.exit(2)
        
def bin_main(num, base=2):
    if num == None:
        sys.exit(2)
        
        
    s=stack()
    
    bin_str=""
    
    while not num == 0:
        s.push(num%base)
        num //=base
    
    
    while not s.is_empty():
        bin_str+=str(s.pop())
    print(bin_str)
    
def postfix():
    expn=str(input("Input expression:"))
    
    while not expn == 'q':
        
        output=""
        if not expn== None:
            s=stack()
        
            for i in range(len(expn)):
                if expn[i].isdigit(): output+=str(expn[i])
                elif expn[i] == ')': 
                    while not s.peek() == '(': output+=str(s.pop()) 
                    else: s.pop()
                else:
                    s.push(expn[i])
                
            print(output)
        
        expn=str(input("Input expression:"))
            
        
if __name__ == '__main__':
    postfix()