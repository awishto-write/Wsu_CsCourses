import re

# Naomi Dion-Gokan 
# Cpts 355 - Spring 2024 
# Assignment 5

#------------------------- 10% -------------------------------------
# The operand stack: define the operand stack and its operations
opstack = []  #assuming top of the stack is the end of the list

# Now define the helper functions to push and pop values on the opstack
# (i.e, add/remove elements to/from the end of the Python list)
# Remember that there is a Postscript operator called "pop" so we choose different names for these functions.

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
#     # dictPush pushes the dictionary ‘d’ to the dictstack.
#     # Note that, your interpreter will call dictPush only when Postscript
#     # “begin” operator is called. “begin” should pop the empty dictionary from
#     # the opstack and push it onto the dictstack by calling dictPush.

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
    name1 = '/' + name
    for item in reversed(dictstack):  # searching at the top of the dictstack
        if item.get(name1): # if we found the name 
            return item.get(name1) # return the value of name
    return None  # Name not found!

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
            print("Error: div - one of the operands is not a number value")
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
            print("Error: mod - one of the operands is not a number value")
            opPush(op2)      
            opPush(op1)             
    else:
        print("Error: mod expects 2 operands")

def eq():
    if len(opstack) > 1:
        op1 = opPop()
        op2 = opPop()

           # if they are equal or not
        if(op1 == op2):
            opPush(True)
        else:
            opPush(False)
            
    else:
        print("Error: eq expects 2 operands")

def lt():
    if len(opstack) > 1:
        op2 = opPop() 
        op1 = opPop() # bottom value
        # When doing the test case and using pushing, the fist value pushed will the bottom value
                
                # Checking if the bottom value is less than the second
        if (isinstance(op1,int) and isinstance(op2,int)) or (isinstance(op1,float) and isinstance(op2,float)):   
            if(op1 < op2):
                opPush(True)
            else:
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
           
            if (index_name >= 0 and index_name < len(value) - 2):
                value_to_push1 = value[index_name + 1]  # Getting the value of that string value element
                asciiValue_toPush = ord(value_to_push1)  # Getting the ascii value of the value of the element 
                opPush(asciiValue_toPush) # Pushing that value into the stack
            else:
               print("Index is out of bounds")
               
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
        if ((index_name + count) > len(value)): # Making sure the count is not out of the bound o the string
            print("The count is out of range of the string")
            return   
        else:
            return
    else:
        print("Error: getinterval - Operand stack is not sufficient, expects 3 operands")

def put():
    if len(opstack) > 2: 
        item = opPop() # character value
        index_name = opPop()  # index name
        value = opPop()   # a string value 
        v_value = value[:index_name + 1] + chr(item) + value[index_name + 2:]
        a = []
           
                  # In case of a string value element
        if isinstance(value, str) and isinstance(index_name, int):   
            for i in range(len(opstack)):  # In range ~ within bounds
                j = opPop()
                if isinstance(j,str) and id(j) == id(value): # When j is a string and also the id of j is the same as value
                    j = v_value # Update the values
                a.append(j) # Add j to the empty list
                
            for i in range(len(a)): # if i in within the range of the len of a
                opPush(a.pop())     
           
           # Dealing with dictionary value
        if len(dictstack) > 0:
            for i in range(len(dictstack)): # In range ~ within bounds
                d = dictstack[-1-i]
                for key,v in d.items(): # Looking through the key and value of the dictionary 
                    if id(v) == id(value): # checking if the id of the string value is the same as the id of the value of the dictstack
                        d[key] = v_value   # Update the values
        else:
            print("The element value does not have a type string or dictionary type")  
    else:
        print("Error: put - Operand stack is not sufficient, expects 3 operands")

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
            count_number = count_number + 1  # incrementing the count_number  # count_number += 1
    else:
        print("Error: copy - Operand stack is insufficient")

def pop():
    if (len(opstack) > 0):
        opPop() # Popping
    else:
        print("Error: pop - not enough arguments")
        
def exch():
    # Pop the top two elements in opstack
    op1 = opPop()
    op2 = opPop()
    # push back those elements in opstack, by putting op1 first and op2 second, it makes op2 the new top
    opPush(op1)
    opPush(op2)

def roll():
    if len(opstack) > 0:
        x = opPop() # Popping ~ The number of elements to roll
        y = opPop() # Popping ~ The index of the top element top to roll
        
        if isinstance(y, int) and isinstance(x, int) and y < len(opstack) and y > 0: # Checking if x and y are integers and the correct range for y
            z = opstack[0-y:] # Setting the last element of the stack
            if x > 0: # When x is > 0 : positive 
                for a in range(x): # When a is in the range of elements to roll
                    b = z.pop(-1)
                    z.insert(0, b) # Inserting the last element(b) at the beginning(index 0) of the stack, which shifts the position of all the other elements up 1 index too
            
            else: # When x is < 0 : negative
                for a in range(abs(x)):  # When a is in the range of elements to roll ~ Use of abs because we are dealing with negative numbers
                    b = z.pop(0)
                    z.append(b) # Add the first element (b) at the end of the stack, which shifts the position of all the other elements down 1 index too
            for c in range(0,y):
                opPop() # Popping
            for d in z:
                opPush(d) # Push d into the stack
    else:
        print("Error for Roll")

def stack():
    if len(opstack) > 0:
        for item_op in reversed(opstack):
            print(item_op)
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
    else:
        print("Error: psDef excepts 2 operands")
        
##   Part 2 Work 

                       # ------- if/ifelse Operators --------------     
def psIf():
    if len(opstack) > 1:
        op1 = opPop()  # Pop a code array object
        op2 = opPop()  # Pop a boolean value
        
        # For the if operator, the code-array is interpreted only if the “condition” argument for if operator is true. 
        if((isinstance(op1, list)) and (isinstance(op2, bool))):
            if (op2 == True):
                interpretSPS(op1) # Interpret the code array object
        else:
            print("Error, absence of a code array value and a bool value")
    else:
            print("Error: If requires two operands")

def psIfelse():   
    if len(opstack) > 2:  
        op1 = opPop()  # Pop a code array object   # top?
        op2 = opPop()  # Pop a code array object   # bottom?
        op3 = opPop()  # Pop a boolean value
        # For the ifelse operator, if the “condition argument is true, first code-array is interpreted, 
        # otherwise the second code-array is evaluated  
        
        # In that case, op2 is the first elment pushed first, so, that's why it is in the first if
        if ((isinstance(op1, list)) and (isinstance(op2, list)) and (isinstance(op3, bool))):
            if (op3 == True):
                interpretSPS(op2) # Interpret a code array object
            else:
                interpretSPS(op1) # Interpret a code array object
        else:
                print("Error, absence of two code array values and a bool value")
    else:
            print("Error: Ifelse requires three operands")

                        #------- Loop Operators --------------
def psFor(): 
    if len(opstack) > 3:
        op1 = opPop()  # Pop a code array object
        end_ind = opPop()  # Pop the end index  # int
        inc_ind = opPop()  # Pop the increment index  # int
        begin_ind= opPop()  # Pop the begin index   int 
        
    #  If it is the body part of a for operator, it is recursively interpreted as part of the evaluation  
    #  of the for loop. At each iteration of the for loop the loop index is pushed onto the stack
        if((isinstance(op1, list)) and (isinstance(end_ind, int)) and (isinstance(inc_ind, int)) and (isinstance(begin_ind, int))):
            for i in range(begin_ind, inc_ind + end_ind, inc_ind): # (begin, end+ , increment)
                opPush(i) # Push i into the stack
                interpretSPS(op1) # Interpret the code array object
        else:
            print("Error, absence of one code array value the end index (end), the increment (inc), and the begin index (begin) ") 
    else:
        print("Error: For requires four operands")
        
        
                                ## Part 2 skeleton 
def tokenize(s):
    return re.findall("/?[a-zA-Z()][a-zA-Z0-9_()]*|[-]?[0-9]+|[}{]+|%.*|[^ \t\n]", s)

#clear opstack and dictstack
def clear():
    del opstack[:]
    del dictstack[:]

# Our dictionary for our operation functions
cs = {"add":add, "sub":sub, "mul":mul, "div":div, "mod":mod, "eq":eq, "lt":lt, "gt":gt, "length":length, "get":get,
        "getinterval":getinterval, "put":put, "dup":dup, "copy":copy, "pop":pop, "clear":clear, "exch":exch,
        "roll":roll, "stack":stack, "dict":psDict, "begin":begin, "end":end, "def":psDef, "for":psFor,
        "if":psIf, "ifelse":psIfelse}
  
def functionTransform(it):
    try:
       return int(it) # Convert it to an integer value
    except:
        if (it == "true"):
            return True   # Return the bool value True
        elif (it == "false"):
            return False   # Return the bool value False
        else:
            return it   # Return the value of the element
        
# complete this function
# The it argument is an iterator.
# The sequence of return characters should represent a list of properly nested
# tokens, where the tokens between '{' and '}' is included as a sublist. If the
# parenteses in the input iterator is not properly nested, returns False.
def groupMatching2(it):
    res = []
    for c in it:
        if c == '}':
            return res
        elif c =='{':
            # Note how we use a recursive call to group the tokens inside the
            # inner matching parenthesis.
            # Once the recursive call returns the code array for the inner
            # paranthesis, it will be appended to the list we are constructing
            # as a whole.
            res.append(groupMatching2(it))
        else:
            res.append(functionTransform(c))
    return False


# Complete this function
# Function to parse a list of tokens and arrange the tokens between { and } braces
# as code-arrays.
# Properly nested parentheses are arranged into a list of properly nested lists.
def parse(L):
    res = []
    it = iter(L)
    for c in it:
        if c =='}':  #non matching closing paranthesis; return false since there is
                    # a syntax error in the Postscript code.
            return False
        elif c =='{':
            res.append(groupMatching2(it))
        else:
            res.append(functionTransform(c))
    return res

# Write the necessary code here; again write
# auxiliary functions if you need them. This will probably be the largest
# function of the whole project, but it will have a very regular and obvious
# structure if you've followed the plan of the assignment.
def interpretSPS(code):  # code is a code array
    for i in code:
        if(isinstance(i, int) or isinstance(i, bool) or isinstance(i, list)): # Checking if the type of i is either int, bool or list
            opPush(i) # Push i into the stack
                
        elif i in cs.keys(): # When we found the call of the functions listed in operators
            cs[i]() # We call directly the function matching 
        
        elif isinstance(i, str): # Checking if i has for type of string
            if i[0] == '/':  # Name
                opPush(i) # Push i into the stack
            else:
                search = lookup(i)
                if search == None: 
                    opPush(i)  # Push i into the stack
                elif isinstance(search, list): # Checking if i has for type of list
                    interpretSPS(search)  # Interpreting code array
                else:
                    opPush(search)  # Push search into the stack
        
# Copy this to your HW5.py file>
def interpreter(s): # s is a string
    interpretSPS(parse(tokenize(s)))