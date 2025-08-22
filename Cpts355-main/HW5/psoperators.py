# Naomi Dion-Gokan

from colors import *
from psexpressions import StringValue, DictionaryValue, CodeArrayValue

class PSOperators:
    def __init__(self, scoperule):
        #stack variables
        self.opstack = []  #assuming top of the stack is the end of the list
        self.dictstack = []  #assuming top of the stack is the end of the list
        self.scoperule = scoperule
        
        # The environment that the REPL evaluates expressions in.
        # Uncomment this dictionary in part2
        self.builtin_operators = {
            "add":self.add,
            "sub":self.sub,
            "mul":self.mul,
            "mod":self.mod,
            "eq":self.eq,
            "lt": self.lt,
            "gt": self.gt,
            "dup": self.dup,
            "exch":self.exch,
            "pop":self.pop,
            "copy":self.copy,
            "count": self.count,
            "clear":self.clear,
            "stack":self.stack,
            "dict":self.psDict,
            "string":self.string,
            "length":self.length,
            "get":self.get,
            "put":self.put,
            "getinterval":self.getinterval,
            "putinterval":self.putinterval,
            "search" : self.search,
            "def":self.psDef,
            "if":self.psIf,
            "ifelse":self.psIfelse,
            "for":self.psFor
        }
    #------- Operand Stack Helper Functions --------------
    
    """
        Helper function. Pops the top value from opstack and returns it.
    """
    def opPop(self):
        if len(self.opstack) > 0:
            x = self.opstack[len(self.opstack) - 1]
            self.opstack.pop(len(self.opstack) - 1)
            return x
        else:
            print("Error: opPop - Operand stack is empty")

    """
       Helper function. Pushes the given value to the opstack.
    """
    def opPush(self,value):
        self.opstack.append(value)

    #------- Dict Stack Helper Functions --------------
    """
       Helper function. Pops the top dictionary from dictstack and returns it.
    """  
    def dictPop(self):                 
        if len(self.dictstack) > 0:
            
             x = self.dictstack[len(self.dictstack) - 1]
             self.dictstack.pop(len(self.dictstack) - 1) 
             return x
            
        else:
            print("Error: dictPop - dictstack is empty")

    """
       Helper function. Pushes the given dictionary onto the dictstack. 
    """   
       
    def dictPush(self,d):   
       self.dictstack.append(d)

    """
       Helper function. Adds name:value pair to the top dictionary in the dictstack.
       (Note: If the dictstack is empty, first adds an empty dictionary to the dictstack then adds the name:value to that. 
    """  
                
    def define(self,name,value):  
        if self.dictstack == []:   # If the dictstack is empty
            
           self.otherDict = {} # Creation of a empty dictionary
           self.otherDict[name] = value   # then adds the name:value to that the new empty dictionary
           self.dictPush((0, self.otherDict))  # adding the new dictionary that is updated to dictstack
           
        else:  #if self.dictstack != []:   # When the dictstack is not empty
            self.dictstack[len(self.dictstack)-1][1][name] = value  # update the top of dictstack
    
    """
       Helper function. Searches the dictstack for a variable or function and returns its value. 
       (Starts searching at the top of the dictstack; if name is not found returns None and prints an error message.
        Make sure to add '/' to the begining of the name.)
    """
    def lookup(self,name):  
        name = '/' + name
                    # Check for dyanmic
        if self.scoperule == "dynamic":    
            return self.dynamic_element(name)
        
            # check for static
        elif self.scoperule == "static":  
            return self.static_element(name)
        
        print("Name not found!")
        return None 
    
    def static_element(self,name):  
        def static_helper(index):
            element = self.dictstack[index]
            if name in element[1]: # or if name in self.dictstack[index][1]
               return element[1][name] # or self.dictstack[index][1][name]
           
              #elif element[0] == index :
            elif index == 0: # else if reached to the beginning of the list return None
              print("Name not found!")
              return None
            else: # else make the recursive call for index self.dictstack[index][0]
              return static_helper(element[0])
        return static_helper((len(self.dictstack) - 1))
    
    def dynamic_element(self,name):
        # if self.scoperule == "dynamic":    
            for item in list(reversed(self.dictstack)):  # searching at the top of the dictstack
                if name in item[1]:  # checking if the name in dickstack at that index
                   return item[1][name]  #get the value of name
            print("Name not found!")
            return None 
   
    #------- Arithmetic Operators --------------

    """
       Pops 2 values from opstack; checks if they are numerical (int); adds them; then pushes the result back to opstack. 
    """  
    def add(self):   
        if len(self.opstack) > 1:
            op1 = self.opPop()
            op2 = self.opPop()
            if (isinstance(op1,int) or isinstance(op1,float)) and (isinstance(op2,int) or isinstance(op2,float)):
                self.opPush(op1 + op2)
            else:
                print("Error: add - one of the operands is not a number value")
                self.opPush(op1)
                self.opPush(op2)             
        else:
            print("Error: add expects 2 operands")

    """
       Pops 2 values from opstack; checks if they are numerical (int); subtracts them; and pushes the result back to opstack. 
    """ 
    def sub(self): 
        if len(self.opstack) > 1:
            op1 = self.opPop()
            op2 = self.opPop()
            if (isinstance(op1,int) or isinstance(op1,float)) and (isinstance(op2,int) or isinstance(op2,float)):
                self.opPush(op2 - op1)
            else:
                print("Error: sub - one of the operands is not a number value")
                self.opPush(op1)
                self.opPush(op2)             
        else:
            print("Error: sub expects 2 operands")

    """
        Pops 2 values from opstack; checks if they are numerical (int); multiplies them; and pushes the result back to opstack. 
    """
    def mul(self):   
        if len(self.opstack) > 1:
            op1 = self.opPop()
            op2 = self.opPop()
            if (isinstance(op1,int) or isinstance(op1,float)) and (isinstance(op2,int) or isinstance(op2,float)):   
                self.opPush(op1 * op2)
            else:
                print("Error: mul - one of the operands is not a number value")
                self.opPush(op1)
                self.opPush(op2)             
        else:
            print("Error: mul expects 2 operands")

    """
        Pops 2 values from stack; checks if they are int values; calculates the remainder of dividing the bottom value by the top one; 
        pushes the result back to opstack.
    """
    def mod(self):       
       if len(self.opstack) > 1:
            op1 = self.opPop()
            op2 = self.opPop()
            if (isinstance(op1,int)) and (isinstance(op2,int)):
                self.opPush(op2 % op1)
            else:
                print("Error: mod - one of the operands is not a number value")
                self.opPush(op1)
                self.opPush(op2)             
       else:
            print("Error: mod expects 2 operands")
       

    """ Pops 2 values from stacks; if they are equal pushes True back onto stack, otherwise it pushes False.
          - if they are integers or booleans, compares their values. 
          - if they are StringValue values, compares the `value` attributes of the StringValue objects;
          - if they are DictionaryValue objects, compares the objects themselves (i.e., ids of the objects).
        """
    def eq(self):   
        if len(self.opstack) > 1:
            op1 = self.opPop()
            op2 = self.opPop()
            
                    # if they are equal or not
                      
            if(isinstance(op1, StringValue)) and (isinstance(op2, StringValue)):
            #if(isinstance(op1,StringValue)):
               self.opPush(op1.value == op2.value)   # push true or false # when op2 is not in if above, value for op2 not showing
            
              # checking if they are DictionaryValue objects  # is it correct?
            elif (isinstance(op1,DictionaryValue))and (isinstance(op2,DictionaryValue)):
                  self.opPush(id(op1) == id(op2))   # use dictPush?
               
            else:
                self.opPush(op1 == op2)   # push true or false 
     # technically deal with int value or bool because we insert the values directly (not like dict/str above)
              
        else:
            print("Error: eq expects 2 operands")

    """ Pops 2 values from stacks; if the bottom value is less than the second, pushes True back onto stack, otherwise it pushes False.
          - if they are integers or booleans, compares their values. 
          - if they are StringValue values, compares the `value` attributes of them;
          - if they are DictionaryValue objects, compares the objects themselves (i.e., ids of the objects).
    """  
    def lt(self):  
        #pass
         if len(self.opstack) > 1:
            op1 = self.opPop()
            op2 = self.opPop()
                
                # Checking if the bottom value is less than the second
            
            if(isinstance(op1, StringValue) and isinstance(op2, StringValue)):
               self.opPush(op1.value < op2.value)   # push true or false 
               
             # checking if they are DictionaryValue objects  # is it correct?
            elif (isinstance(op1,DictionaryValue) and isinstance(op2,DictionaryValue)):
                  self.opPush(id(op1) < id(op2))
                  
            else:
                self.opPush(op2 < op1)   # push true or false  # technically int value or bool
                
         else:
            print("Error: lt expects 2 operands")


    """ Pops 2 values from stacks; if the bottom value is greater than the second, pushes True back onto stack, otherwise it pushes False.
          - if they are integers or booleans, compares their values. 
          - if they are StringValue values, compares the `value` attributes of them;
          - if they are DictionaryValue objects, compares the objects themselves (i.e., ids of the objects).
    """  
    def gt(self):   
       # pass
       if len(self.opstack) > 1:
            op1 = self.opPop()
            op2 = self.opPop()
                
                # Checking if the bottom value is greater than the second
            
            if(isinstance(op1, StringValue) and isinstance(op2, StringValue)):
               self.opPush(op1.value > op2.value)   # push true or false 
               
             # checking if they are DictionaryValue objects  # is it correct?
            elif (isinstance(op1,DictionaryValue) and isinstance(op2,DictionaryValue)):
                  self.opPush(id(op1) > id(op2))
                  
            else:
                self.opPush(op2 > op1)   # push true or false  # technically int value or bool
              
       else:
            print("Error: gt expects 2 operands")
        

    #------- Stack Manipulation and Print Operators --------------
    """
       This function implements the Postscript "pop operator". Calls self.opPop() to pop the top value from the opstack and discards the value. 
    """
    def pop (self):
        if (len(self.opstack) > 0):
            self.opPop()
        else:
            print("Error: pop - not enough arguments")

    """
       Prints the opstack and dictstack. The end of the list is the top of the stack. 
    """
    def stack(self):
                   # Opstack
        print(OKGREEN+"===**opstack**===")          
        #print("===**opstack**===")
        if (len(self.opstack) > 0):
           for item in reversed(self.opstack):
              print(item)
        
        print(RED+"===**dictstack**===")
        #print("===**dictstack**===")
        if (len(self.opstack) > 0):
           m = list(reversed(self.dictstack))
             # the index of dictstack and the static index
           for item in range(0,len(m)):
               #print("----",(len(m)- 1-item),"----",(m[item][0]),"----") # the index of dictstack and Static-link-index
               print(f"----{len(m) - 1 - item}----{m[item][0]}----") # the index of dictstack and Static-link-index
               for k, v in m[item][1].items():
                   print(k," ", v)  # All the elements in dict
        print("================="+ CEND)
       
    
    """
       Copies the top element in opstack.
    """
    def dup(self):              
        if len(self.opstack) > 0:
           i = self.opPop()    # initialization of the top element
           self.opPush(i)
           self.opPush(i)
           
        #    x = self.opstack[len(self.opstack) - 1]
        #    self.opstack.copy(len(self.opstack) - 1)
    
        else:
            print("Error: dup - Operand stack is empty")

    """
       Pops an integer count from opstack, copies count number of values in the opstack. 
    """
    def copy(self):  
        if len(self.opstack) > 0:  
            count = self.opstack.pop()
                
                # Initialization of elements
            count_number = 0
            stack_length = len(self.opstack)
            x = stack_length - count   # where we will start copying
            
            while(count_number < count and x < stack_length):
                self.opPush(self.opstack[ x + count_number]) # insert/copies the count number as well as the starting element
                count_number = count_number + 1  # incrementing the count_number
                # count_number += 1
             
        else:
            print("Error: copy - Operand stack is insufficient")
            
    """
        Counts the number of elements in the opstack and pushes the count onto the top of the opstack.
    """
    def count(self):
        if len(self.opstack) > 0:  # > 1?
            self.opPush(len(self.opstack))
               
        else:
            print("Error: count - Operand stack is empty")


    """
       Clears the opstack.
    """
    def clear(self):      
        #self.opstack.clear()
        self.opstack[:] = []
        
    """
       swaps the top two elements in opstack
    """
    def exch(self):   
        
        # Pop the top two elements in opstack
        op1 = self.opPop()
        op2 = self.opPop()
        
      # push back those elements in opstack, by putting op1 first and op2 second, it makes op2 the new top
        self.opPush(op1)
        self.opPush(op2)
        
    # ------- String and Dictionary creator operators --------------

    """ Creates a new empty string pushes it on the opstack.
    Initializes the characters in the new string to \0 , i.e., ascii NUL """
    def string(self):   
        
        if len(self.opstack) > 0:
           op = self.opPop()      
           
           if(isinstance(op,int)):  
                 # Creates a new empty string with StringValue type
                 
             newString = StringValue('(' + ('\0' * op) + ')')
             self.opPush(newString)  
              
           else:
                print("Error: invalid operand type")
        else:
            print("Error: count - Operand stack is empty")
        
    
    """Creates a new empty dictionary  pushes it on the opstack """
    def psDict(self):  
        
        if len(self.opstack) > 0:
            
           newDict = {}   # Create a new empty dictionary
           self.opPop()
           self.opPush(DictionaryValue(newDict))  # push newDict into opstack # the test let us know we need a DictionaryValue type
           # we know that opPush in in opstack, that's why no call of opstack
        
        else:
            print("Error: psDict - Operand stack is not sufficient")
                  
    # ------- String and Dictionary Operators --------------
    """ Pops a string or dictionary value from the operand stack and calculates the length of it. Pushes the length back onto the stack.
       The `length` method should support both DictionaryValue and StringValue values.
    """
    def length(self): 
       
        if len(self.opstack) > 0:
            element_value = self.opPop()   # Popping an element from the stack
            
            if(isinstance(element_value,DictionaryValue)):  # checking if the element has a DictionaryValue type
              self.opPush(element_value.length())  # pushing the length into the stack
                
            elif(isinstance(element_value,StringValue)):  # checking if the element has a StringValue type
                self.opPush(element_value.length() - 2 )  # regular length with extraction of ()
         # element_value.length() - 2 because of a StringValue element composition, -2 because of the size of both '(' and ')'
                 
            else:
                print("The element value does not have a type DictionaryValue or StringValue")
                
        else:
            print("Error: length - Operand stack is not sufficient")


    """ Pops either:
         -  "A (zero-based) index and an StringValue value" from opstack OR 
         -  "A `name` (i.e., a key) and DictionaryValue value" from opstack.  
        If the argument is a StringValue, pushes the ascii value of the the character in the string at the index onto the opstack;
        If the argument is an DictionaryValue, gets the value for the given `name` from DictionaryValue's dictionary value and pushes it onto the opstack
    """
    def get(self):
            
        if len(self.opstack) > 1:  
           index_name = self.opPop()
           value = self.opPop()   # a StringValue value or a DictionaryValue value
           
                   # In case of StringValue element
           if isinstance(value, StringValue) and isinstance(index_name, int):  
               value_to_push1 = value.value[index_name + 1]  # Getting the value of that StringValue element
               asciiValue_toPush = ord(value_to_push1)  # Getting the ascii value of the value of the element 
               self.opPush(asciiValue_toPush)
               
                    # In case of DictionaryValue element
           elif isinstance(value, DictionaryValue):
                value_to_push2 = value.value[index_name]   # Getting the value of that DictionaryValue element
                self.opPush(value_to_push2)
                
           else:
               print("The element does not have a StringValue or DictionaryValue type")
                
                  
        else: 
            print("Error: get - opstack needs more elements, expects 2 operands")
                  
    
    """
    Pops either:
    - "An `item`, a (zero-based) `index`, and an StringValue value from  opstack", OR
    - "An `item`, a `name`, and a DictionaryValue value from  opstack". 
    If the argument is a StringValue, replaces the character at `index` of the StringValue's string with the character having the ASCII value of `item`.
    If the argument is an DictionaryValue, adds (or updates) "name:item" in DictionaryValue's dictionary `value`.
    """
    def put(self):    
        if len(self.opstack) > 2: 
            
            item = self.opPop()
            index_name = self.opPop()  # +1
            value = self.opPop()   # a StringValue value or a DictionaryValue value
           
                  # In case of StringValue element
            if isinstance(value, StringValue) and isinstance(index_name, int):
               value.value = value.value[:index_name + 1] + chr(item) + value.value[index_name + 2:]
            
                  # In case of DictionaryValue element
            elif(isinstance(value, DictionaryValue)):
                  value.value[index_name] = item
                  
            else:
               print("The element does not have a StringValue or DictionaryValue type")
                
        else:
            print("Error: put - Operand stack is not sufficient, expects 3 operands")
           

    """
    getinterval is a string only operator, i.e., works only with StringValue values. 
    Pops a `count`, a (zero-based) `index`, and an StringValue value from  opstack, and 
    extracts a substring of length count from the `value` of StringValue starting from `index`,
    pushes the substring back to opstack as a StringValue value. 
    """ 
    def getinterval(self):
    
        if len(self.opstack) > 2:  
            
            count = self.opPop()
            index_name = self.opPop()  
            value = self.opPop()   # a StringValue value 
           
                  # In case of StringValue element
            if isinstance(value, StringValue) and isinstance(index_name, int) and isinstance(count, int):
               #valueToPush = value.value[index_name + 1 : index_name + count + 1] + value.value[]
               valueToPush = value.value[index_name + 1 : index_name + count + 1]
               self.opPush(StringValue('(' + valueToPush+ ')'))
                  
            else:
               print("The element does not have a StringValue")
                
        else:
            print("Error: getinterval - Operand stack is not sufficient, expects 3 operands")

    """
    putinterval is a string only operator, i.e., works only with StringValue values. 
    Pops a StringValue value, a (zero-based) `index`, a `substring` from  opstack, and 
    replaces the slice in StringValue's `value` from `index` to `index`+len(substring)  with the given `substring`s value. 
    """
        # This function has been originally changed from the HW4 - part1 because some test cases failed
        
    def putinterval(self):
        if len(self.opstack) > 2:  
            
            substring = self.opPop()
            index_name = self.opPop()  # +1
            value = self.opPop()   # a StringValue value 
           
                  # In case of StringValue element
            if isinstance(value, StringValue) and isinstance(index_name, int) and isinstance(substring, StringValue):
               
                # That structure is helpful because of the extra parentheses that 
                # are present appear when we do not call str
               
                value_= value.value[:index_name+1] + str(substring.value[1:-1])
                #value.value = value_  + " " +value.value[index_name + substring.length():]
                value.value = value_ + value.value[index_name + 1 + len(str(substring.value[1:-1]))]
            
            else:
               print("The elements do not have a StringValue, int and bool")
                
        else:
            print("Error: putinterval - Operand stack is not sufficient, expects 3 operands")

    """
    search is a string only operator, i.e., works only with StringValue values. 
    Pops two StringValue values: delimiter and inputstr
    if delimiter is a sub-string of inputstr then, 
       - splits inputstr at the first occurence of delimeter and pushes the splitted strings to opstack as StringValue values;
       - pushes True 
    else,
        - pushes  the original inputstr back to opstack
        - pushes False
    """
    def search(self):
        if len(self.opstack) > 1:  
            
                 # popping 
            delimeter = self.opPop()
            inputstr = self.opPop()  
            
                #  not considering the parentheses
            inputstr = inputstr.value[1:-1]
            delimeter = delimeter.value[1:-1]
            
            index = inputstr.find(delimeter)   # slipt the delimeter when finding it
            
            if index >= 0 : 
                
                       # Pushing those elements in opstack as StringValue element
                self.opPush(StringValue('(' + str(inputstr)[index + 1:] + ')'))
                self.opPush(StringValue('(' + str(inputstr)[index] + ')'))
                self.opPush(StringValue('(' + str(inputstr)[:index] + ')'))
               
                self.opPush(True)   # push True to opstack
                 
            else:
               self.opPush(StringValue('(' + inputstr + ')'))  # push the original inputstr back to opstack
               self.opPush(False)    #  push False to opstack
            
        else:
            print("Error: put - Operand stack is not sufficient, expects 2 operands")

    # ------- Operators that manipulate the dictstact --------------
    """ Pops a name and a value from stack, adds the definition to the dictionary at the top of the dictstack. """
    def psDef(self):  #correct
        if len(self.opstack) > 1:
            
            value = self.opPop()
            name = self.opPop()
            
            self.define(name,value)  
            # why self.define(value,name) isn't working? Because of the order of the pop
        
        else:
            print("Error: psDef excepts 2 operands")


    # ------- if/ifelse Operators --------------
    """ if operator
        Pops a CodeArrayValue object and a boolean value,
        if the value is True, executes (applies) the code array by calling apply.
       Will be completed in part-2. 
    """
            
    def psIf(self):
        
        if len(self.opstack) > 1:
            op1 = self.opPop()  # Pop a CodeArrayValue object
            op2 = self.opPop()  # Pop a boolean value
            if((isinstance(op1, CodeArrayValue)) and (isinstance(op2, bool))):
               if (op2 == True):
                      #   AR
                   self.dictPush(((len(self.dictstack) - 1 ), {}))
                   op1.apply(self)
                   self.dictPop()
            else:
                print("Error, absence of a CodeArrayValue and a bool value")
        else:
            print("Error: If requires two operands")
            
    """ ifelse operator
        Pops two CodeArrayValue objects and a boolean value, if the value is True, executes (applies)
        the bottom CodeArrayValue otherwise executes the top CodeArrayValue.
        Will be completed in part-2. 
    """
    def psIfelse(self):   
        
        if len(self.opstack) > 2:  # check > 1, 2
             
            op1 = self.opPop()  # Pop a CodeArrayValue object   # top?
            op2 = self.opPop()  # Pop a CodeArrayValue object   # bottom?
            op3 = self.opPop()  # Pop a boolean value
            
            if ((isinstance(op1, CodeArrayValue)) and (isinstance(op2, CodeArrayValue)) and (isinstance(op3, bool)) ):
               if (op3 == True):
                      # AR
                   self.dictPush(((len(self.dictstack) - 1 ), {}))
                   op2.apply(self)
                   self.dictPop()
               else:
                      # AR
                   self.dictPush(((len(self.dictstack) - 1 ), {}))
                   op1.apply(self)
                   self.dictPop()
            else:
                print("Error, absence of two CodeArrayValue and a bool value")  
        else:
            print("Error: Ifelse requires three operands")

    #------- Loop Operators --------------
    """
       Implements for operator.   
       Pops a CodeArrayValue object, the end index (end), the increment (inc), and the begin index (begin) and 
       executes the code array for all loop index values ranging from `begin` to `end`. 
       Pushes the current loop index value to opstack before each execution of the CodeArrayValue. 
       Will be completed in part-2. 
    """ 
    
    def psFor(self):
        
        if len(self.opstack) > 3:
            
            op1 = self.opPop()  # Pop a CodeArrayValue object
            end_ind = self.opPop()  # Pop the end index  # int
            inc_ind = self.opPop()  # Pop the increment index  # int
            begin_ind = self.opPop()  # Pop the begin index   int 
            
            if((isinstance(op1, CodeArrayValue)) and (isinstance(end_ind, int)) and (isinstance(inc_ind, int)) and (isinstance(begin_ind, int))):
                for i in range(begin_ind, inc_ind + end_ind, inc_ind): # (begin, end+ , increment)
                    self.opPush(i) 
                      # AR
                    self.dictPush(((len(self.dictstack) - 1) , {}))  # for self.scope == 'static'
                    op1.apply(self)
                    self.dictPop()
            else:
                print("Error, absence of one CodeArrayValue the end index (end), the increment (inc), and the begin index (begin) ")
        else:
            print("Error: For requires four operands")

    """ Cleans both stacks. """      
    def clearBoth(self):
        self.opstack[:] = []
        self.dictstack[:] = []

    """ Will be needed for part2"""
    def cleanTop(self):
        if len(self.opstack)>1:
            if self.opstack[-1] is None:
                self.opstack.pop()
                 