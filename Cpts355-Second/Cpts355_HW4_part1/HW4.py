# Naomi Dion-Gokan 
# Cpts 355 - Spring 2024 
# Assignment 4 - Part 1

#------------------------- 10% -------------------------------------
# The operand stack: define the operand stack and its operations
opstack = []  #assuming top of the stack is the end of the list

# Now define the helper functions to push and pop values on the opstack
# (i.e, add/remove elements to/from the end of the Python list)
# Remember that there is a Postscript operator called "pop" so we choose
# different names for these functions.
# Recall that `#pass` in python is a no-op: replace it with your code.

def opPop():

    if len(opstack) > 0:
        
        x = opstack[len(opstack) - 1]
        opstack.pop(len(opstack) - 1)
        return x
        
    else:
        print("Error: opPop - Operand stack is empty")
    # opPop should return the popped value.
    # The pop() function should call opPop to pop the top value from the opstack, but it will ignore the popped value.

def opPush(value):
    opstack.append(value)   # Insert the value to the stack

#-------------------------- 20% -------------------------------------
# The dictionary stack: define the dictionary stack and its operations
dictstack = []  #assuming top of the stack is the end of the list

# now define functions to push and pop dictionaries on the dictstack, to
# define name, and to lookup a name

def dictPop():
    # dictPop pops the top dictionary from the dictionary stack.
    if len(dictstack) > 0:
        x = dictstack[len(dictstack) - 1]
        dictstack.pop(len(dictstack) - 1) 
        return x
            
    else:
        print("Error: dictPop - dictstack is empty")


def dictPush(d):
    dictstack.append(d)
    #dictPush pushes the dictionary ‘d’ to the dictstack.
    #Note that, your interpreter will call dictPush only when Postscript
    #“begin” operator is called. “begin” should pop the empty dictionary from
    #the opstack and push it onto the dictstack by calling dictPush.

def define(name, value):
    if dictstack == []:   # If the dictstack is empty
            
        otherDict = {} # Creation of a empty dictionary
        otherDict[name] = value   # then adds the name:value to that the new empty dictionary
        dictPush(otherDict)  # adding the new dictionary that is updated to dictstack
           
    else:  #if dictstack != []:   # When the dictstack is not empty
        dictstack[len(dictstack)-1][name] = value  # update the top of dictstack
    #add name:value pair to the top dictionary in the dictionary stack.
    #Keep the '/' in the name constant.
    #Your psDef function should pop the name and value from operand stack and
    #call the “define” function.

def lookup(name):
    name = '/' + name
    for item in reversed(dictstack):  # searching at the top of the dictstack
        if name in item:  # checking if the name in dickstack
            return item[name]  #get the value of name
        
    print("Name not found!")
    return None 
              
    # return the value associated with name
    # What is your design decision about what to do when there is no definition for “name”? If “name” is not defined, your program should not break, but should give an appropriate error message.


#--------------------------- 10% -------------------------------------
# Arithmetic and comparison operators: add, sub, mul, div, mod, eq, lt, gt
# Make sure to check the operand stack has the correct number of parameters
# and types of the parameters are correct.
        
def add():    
    if len(opstack) > 1:
        op1 = opPop()  # pop the top value off the operand stack
        op2 = opPop()   # pop the top value off the operand stack
            
        if (isinstance(op1,int) or isinstance(op1,float)) and (isinstance(op2,int) or isinstance(op2,float)): #  if(type(op1) == type(op2)):
            opPush(op1 + op2)
        else: #  else ~  if (type(op1) != type(op2))
            opPush(op2) 
            opPush(op1)
    else:
        print("Error: add expects 2 operands")
    
def sub():
    if len(opstack) > 1:
        op1 = opPop() # pop the top value off the operand stack
        op2 = opPop() # pop the top value off the operand stack
        
        if (isinstance(op1,int) or isinstance(op1,float)) and (isinstance(op2,int) or isinstance(op2,float)):
            opPush(op2 - op1)
        else:
            #print("Error: sub - one of the operands is not a number value")
            opPush(op2)    
            opPush(op1)         
    else:
        print("Error: sub expects 2 operands")

def mul():
    if len(opstack) > 1:
        op1 = opPop() # pop the top value off the operand stack
        op2 = opPop() # pop the top value off the operand stack
        
        if (isinstance(op1,int) or isinstance(op1,float)) and (isinstance(op2,int) or isinstance(op2,float)):   
            opPush(op1 * op2)
        else:
            #print("Error: mul - one of the operands is not a number value")
            opPush(op2)      
            opPush(op1)             
    else:
        print("Error: mul expects 2 operands")

def div():
    if len(opstack) > 1:
        op1 = opPop() # pop the top value off the operand stack
        op2 = opPop() # pop the top value off the operand stack
        
        if (isinstance(op1,int) or isinstance(op1,float)) and (isinstance(op2,int) or isinstance(op2,float)):   
            opPush(op2 / op1) # push (op2 / op1) onto the operand stack
        else:
           # print("Error: div - one of the operands is not a number value")
            opPush(op2)      
            opPush(op1)  
    else:
        print("Error: div expects 2 operands")

def mod():
    if len(opstack) > 1:
        op1 = opPop() # pop the top value off the operand stack
        op2 = opPop() # pop the top value off the operand stack
        
        if (isinstance(op1,int) or isinstance(op1,float)) and (isinstance(op2,int) or isinstance(op2,float)):   
                opPush(op2 % op1)
        else:
            #print("Error: mod - one of the operands is not a number value")
            opPush(op2)      
            opPush(op1)             
    else:
        print("Error: mod expects 2 operands")

def eq():
    if len(opstack) > 1:
        op1 = opPop()
        op2 = opPop()
        
           # if they are equal or not
        if (isinstance(op1,int) or isinstance(op1,float)) and (isinstance(op2,int) or isinstance(op2,float)):   
            opPush(op1 == op2)
            if(op1 == op2):
                opPush(True)
            else:
                opPush(False)
            
        else:
            #print("Error: eq - one of the operands is not a number value") 
            opPush(False)
              
    else:
        print("Error: eq expects 2 operands")

def lt():
    if len(opstack) > 1:
        op2 = opPop() 
        op1 = opPop() # bottom value
        # When doing the test case and using pushing, the fist value pushed will the bottom value
                
                # Checking if the bottom value is less than the second
        if (isinstance(op1,int) or isinstance(op1,float)) and (isinstance(op2,int) or isinstance(op2,float)):   
            #opPush(op1 < op2)
            if(op1 < op2):
                opPush(True)
            else:
                opPush(False)
            
        else:
            #print("Error: lt - one of the operands is not a number value") 
            opPush(False)
   
    else:
        print("Error: lt expects 2 operands")


def gt():
    if len(opstack) > 1:
        op2 = opPop()
        op1 = opPop() # bottom value
            # When doing the test case and using pushing, the fist value pushed will the bttom value
                
                # Checking if the bottom value is greater than the second
        if (isinstance(op1,int) or isinstance(op1,float)) and (isinstance(op2,int) or isinstance(op2,float)):   
            if(op1 > op2):
                opPush(True)
            else:
                opPush(False)
            
        else:
            #print("Error: gt - one of the operands is not a number value")
            opPush(False)  
    else:
        print("Error: gt expects 2 operands")

#--------------------------- 15% -------------------------------------
# String operators: define the string operators length, get, getinterval, put
def length():
    if len(opstack) > 0:
        element_value = opPop()   # Popping an element from the stack 
                
        if(isinstance(element_value, str)):  # checking if the element has a StringValue type
            opPush(len(element_value) - 2) # regular length with extraction of ()
         # len(element_value.length) - 2 because of a string value element composition, -2 because of the size of both '(' and ')'
                 
        else:
            print("The element value does not have a type string")
                
    else:
        print("Error: length - Operand stack is not sufficient")

def get():
    if len(opstack) > 1:  
        index_name = opPop()
        value = opPop()   # a string value value 
           
                   # In case of string value element
        if isinstance(value, str) and isinstance(index_name, int):  
            value_to_push1 = value[index_name + 1]  # Getting the value of that string value element
            asciiValue_toPush = ord(value_to_push1)  # Getting the ascii value of the value of the element 
            opPush(asciiValue_toPush)
            
        if (index_name > (len(value) - 1)):
            print("Index is out of bounds")
            return
                
        else:
            print("The element value does not have a type string or the index is not of type int")
                
    else: 
        print("Error: get - opstack needs more elements, expects 2 operands")

def getinterval():
    if len(opstack) > 2:  
        count = opPop()
        index_name = opPop()  
        value = opPop()   # a string value 
           
                  # In case of string value element
        if isinstance(value, str) and isinstance(index_name, int) and isinstance(count, int):
            valueToPush = value[index_name + 1 : index_name + count + 1]
            opPush(str('(' + valueToPush+ ')'))  # Pushing the value as a string as well as including the parentheses
            
        if (index_name > (len(value) - 1) or count > (len(value) - 1)):  # Making sure we do not get out of bounds
            print("Index or count out of bounds")
            return
        if ((index_name + count) > len(value)):
            print("The count is out of range of the string")
            return
                  
        else:
            print("The element does not have a string value")
            #opPush(None)
                
    else:
        print("Error: getinterval - Operand stack is not sufficient, expects 3 operands")

def put():
    if len(opstack) > 2: 
        item = opPop()
        index_name = opPop()  # +1
        value = opPop()   # a string value 
           
                  # In case of a string value element
        if isinstance(value, str) and isinstance(index_name, int):
            if 0 <= index_name < len(value):  # Check if index is within bounds
                value = value[:index_name + 1] + chr(item) + value[index_name + 2:]
                opPush(value) # Pushing the value
            else:
                print("Error: Index out of range for string")   
                  
        else:
            print("The element value does not have a type string")
               
    else:
        print("Error: put - Operand stack is not sufficient, expects 3 operands")
            
                                # Try End

#--------------------------- 25% -------------------------------------
# Define the stack manipulation and print operators: dup, copy, pop, clear, exch, roll, stack
def dup():
    if len(opstack) > 0:
        i = opPop()    # initialization of the top element
        opPush(i)  # Pushing the element
        opPush(i)
    
    else:
        print("Error: dup - Operand stack is empty")


def copy():
    if len(opstack) > 0:  
        count = opstack.pop()
                
                # Initialization of elements
        count_number = 0
        stack_length = len(opstack)
        x = stack_length - count   # where we will start copying
            
        while(count_number < count and x < stack_length):
            opPush(opstack[ x + count_number]) # insert/copies the count number as well as the starting element
            count_number = count_number + 1  # incrementing the count_number
                # count_number += 1
             
    else:
        print("Error: copy - Operand stack is insufficient")

def pop():
    if (len(opstack) > 0):
        opPop() # Popping
    else:
        print("Error: pop - not enough arguments")

def clear():
    #opstack.clear()
    opstack[:] = []

def exch():
    # Pop the top two elements in opstack
    op1 = opPop()
    op2 = opPop()
        
    # push back those elements in opstack, by putting op1 first and op2 second, it makes op2 the new top
    opPush(op1)
    opPush(op2)

def roll():
    if len(opstack) > 0:
        i = opPop() # Popping
        x = opPop() # Popping
                
        if isinstance(x, int) and isinstance(i, int) and x < len(opstack) and x > 0:
            opcopy = opstack[-x:]
            opstack[-x:] = []
            
                  # The Rolling process  
            if i > 0:
                opcopy[-i:] = reversed(opcopy[-i:])
            else:
                opcopy[:] = reversed(opcopy)
            
            for item in opcopy: 
                opstack.append(item)  # Add the item to the stack
                
        else:
            print("Error for Roll")

def stack():
    if len(opstack) > 0:
        for item_op in reversed(opstack):
            print(item_op)
    # if len(dictstack) > 0:
    #     for item_di in reversed(dictstack):
    #         print(item_di)
            
    else:
        print("Stack is empty")

#--------------------------- 20% -------------------------------------
# Define the dictionary manipulation operators: psDict, begin, end, psDef
# name the function for the def operator psDef because def is reserved in Python. Similarly, call the function for dict operator as psDict.
# Note: The psDef operator will pop the value and name from the opstack and call your own "define" operator (#pass those values as parameters).
# Note that psDef()won't have any parameters.

def psDict():
    if len(opstack) > 0:
        newDict = {}   # Create a new empty dictionary
        opPop() # Pop the opstack
        opPush(dict(newDict))  # push newDict into opstack # the test let us know we need a DictionaryValue type
           # we know that opPush in in opstack, that's why no call of opstack
        
    else:
        print("Error: psDict - Operand stack is not sufficient")

def begin():
    if len(opstack) > 0:
        op = opPop()  # Pops a DictionaryValue value from opstack
        
        if(isinstance(op, dict)):  # checking if that value is a dictionary value
            dictPush(op)   #pushes it's `value` to the dictstack
        else:
            print("Error: the element value does not have a dictionary type")   
    else:
        print("Error: begin - opstack is insufficient, expects at least 1 operand")

def end():
    if len(dictstack) > 0:
        dictPop() # Pop the dictstack
    else:
        print("Error: end - dictstack is insufficient")

def psDef():
    if len(opstack) > 1:
        value = opPop()
        name = opPop()
            
        define(name,value)     # Call of the define() function
            # define(value,name) isn't working -> Because of the order of the pop
        
    else:
        print("Error: psDef excepts 2 operands")