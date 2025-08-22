# CptS 355 - Spring 2024 - Assignment 3 (Python)
# Name: Naomi Dion-Gokan

debugging = False
def debug(*s): 
     if debugging: 
          print(*s)

from functools import reduce

                                    # 1) (Dictionaries)

        # a) sprintLog(sprnt) – 15%
        
# Assume a software development team follows an agile process model. During each sprint, developers keep track of the number 
# of hours they spent on each task during the sprint. They store a weekly log of their hours in a Python dictionary. 
# The keys of the dictionary are the names of the developers and the values are the dictionaries which include the task names 
# and the number of hours spent for each task. Please note that each developer may work on several tasks during a sprint and 
# multiple developers may work on the same tasks.
#  Define a function sprintLog(sprnt) which takes a dictionary of users as shown above and returns a dictionary of tasks, where 
# each task is associated with the users who worked on that taskduring the sprint.

def sprintLog (sprnt):

# swapping the key (names) with the value (task)

    dictionary1 = {} # creation of an empty dictionary. You can also so dictionary1 = dict()
          
    # because we considered the case where task is in data and names
    # in the value of data, we automatically considered if month and names are in data
           
          #dealing with both key and value
    for (name, info1) in sprnt.items():     
        for (task, info2) in info1.items(): # we deal with the dictionary part of the value of the main dictionary
            if task not in dictionary1.keys(): 
                dictionary1[task] = {} # we set that task to a empty dictionary if the task is not found
                
            # That's the else option
            dictionary1[task][name] = info2 # we set the task as the key, the name become the value: insert those in the dictionary, without forgetting  
                                                      # the original info2 that is a part of the value of form a dictionary now with name
              
    return dictionary1  
     
#debug(sprintLog(CDCdata))
# print("Question 1.a")
# print(sprintLog(hi))
# print("\n")
        
     
        # b) addSprints(sprint1, sprint2) – 10%
        
# Now define a function, addSprints(sprint1, sprint2), which takes the logs of two sprints as input and joins them. The result will be a
# joined dictionary including tasks from both dictionaries. The logs for the tasks that are common to both dictionaries will be merged. 

def addSprints(sprint1, sprint2):
    
    combinedDict = {}
    
    for info in (sprint1, sprint2): 
        for (task, info2) in info.items(): # we deal with the dictionary part of the value of the main dictionary
            
            # if task not in combinedDict.keys(): 
            if task not in combinedDict:
                combinedDict[task] = {} # we set that task to a empty dictionary if the task is not found
                 
# Update the combined sprint with hours from the current sprint ~ for (user, hours) in users_hours.items():
            for (name, info1) in info2.items(): 
                combinedDict[task][name] = combinedDict[task].get(name,0) + info1
                
    return combinedDict

        #c) addNLogs(logList) – 10%
        
# Now assume that the team recorded the log data for several sprints as a list of dictionaries. This list includes a dictionary for each
# development sprint. Define a function addNLogs which takes a list of developer sprint logs and returns a dictionary which includes the
# collection of all project tasks and the total number of hours each developer has worked on each task. Your function definition should 
# use the Python map and reduce functions as well as the sprintLog and addSprints functions you defined in part(a) and (b)

                               # rewrite the code below

def addNLogs (logList):

# Use map to convert each individual sprint log into a sprint dictionary
    sprint_dicts = list(map(sprintLog, logList))
    
    # Use reduce to apply addSprints to the list of sprint dictionaries
    return reduce(addSprints, sprint_dicts)

     
                                   # 2) Dictionaries and lists

        # a) lookupVal(L,k)– 5%
        
# Write a function lookupVal that takes a list of dictionaries L and a key k as input and checks each dictionary in L starting from 
# the end of the list. If k appears in a dictionary, lookupVal returns the value for key k. If k appears in more than one dictionary, 
# it will return the one that it finds first (closer to the end of the list).

def lookupVal(L,k):
     
    # we used reversed of the list because we start at the end of the list
    for element in reversed(L): # for the keys in the reversed list
        for element_ in element: # for the current key we are on is a part of the keys
            if element_ == k: # if we see the k we are looking for and it is equal to element_
                return element[element_] # we return the value
            
L1 = [{"x":1,"y":True,"z":"found"},{"x":2},{"y":False}]
L4=[{"Lion":"Roar","Dog":13,"Cat":False},{"Tiger":2, "Elephant":20},{"Dog":11,"Husky":True}]

# debug(lookupVal(L1,"x"))  
# debug(lookupVal(L1,"y"))  
# debug(lookupVal(L1,"z"))  
# debug(lookupVal(L1,"t"))  

#print("Question 2.a")
# print(lookupVal(L1,"x"))
# print(lookupVal(L1,"y"))
# print(lookupVal(L1,"z"))
# print(lookupVal(L1,"t"))

# print(lookupVal(L4,"Dog"))
# print(lookupVal(L4,"Husky"))
# print(lookupVal(L4,"Elephant"))
# print(lookupVal(L4,"Lion"))
# print(lookupVal(L4,"Tiger"))
# print(lookupVal(L4,"Crab"))

#print("\n")

L2 = [(0,{"x":0,"y":True,"z":"zero"}), (0,{"x":1}), (1,{"y":False}), (1,{"x":3, "z":"three"}), (2,{})]

    
        # b) lookupVal2(tL,k) – 10%
        
# Write a function lookupVal2 that takes a list of tuples (tL) and a key k as input. Each tuple in the input list includes 
# an integer index value and a dictionary. The index in each tuple represent a link to another tuple in the list (e.g. index
# 3 refers to the 4th tuple, i.e., the tuple at index 3 in the list)lookupVal2 checks the dictionary in each tuple in tL 
# starting from the end of the list and following the indexes specified in the tuples.

# (Note: I suggest you to provide a recursive solution to this problem.
# Hint: Define a helper function with an additional parameter that hold the list index which will be
# searched in the next recursive call.)
            
       
 # Helper function for lookupVal2(tL,k)
def lookupVal2_helper(tL,k, index):  
    element = tL[index]
    
    # if k in tL[index][index]:
    #     return tL[index][index][k]
    
      # checking the dictionary at tL[index]
    if k in element[1]: # or if k in tL[index][1]    # When k is that dictionary
        return element[1][k] # or tL[index][1][k]    # Return the value of k
        
    else :
        if index == 0: # else if reached to the beginning of the list return None
           return None
        else: # else make the recursive call for index tL[index][0]
           return lookupVal2_helper(tL, k, element[0])  
       
def lookupVal2(tL,k): 
    index = len(tL) - 1 # meaning starting at the end of the list
    return lookupVal2_helper(tL, k, index) # Our search starts from the end of the list 

# debug(lookupVal2(L2,"x"))
# debug(lookupVal2(L2,"y"))
# debug(lookupVal2(L2,"z"))
# debug(lookupVal2(L2,"t"))

# print(lookupVal2(L2,"x"))
# print(lookupVal2(L2,"y"))
# print(lookupVal2(L2,"z"))
# print(lookupVal2(L2,"t"))
#print("\n")

    
                                   # 3) (Lists) unzip – 12%

# Write a function unzip that calculates the reverse of the zip operation. unzip takes a list of 3-tuples, L, as input and 
# returns a tuple of lists, where each list includes the first, second, or third element from each tuple, respectively. 
# Give a solution using higher order functions (map, reduce or filter), without using loops.

def unzip(L):

   # The content of each tuple ~  | Be considred as functions for our map
    element1 = lambda tuple: tuple[0] # First element of the tuple we see
    element2 = lambda tuple: tuple[1] # Second element of the tuple we see
    element3 = lambda tuple: tuple[2] # Third element of the tuple we see
    
   # Each list we form
    list1 = list(map(element1, L)) # First list we see
    list2 = list(map(element2, L))  # First list we see
    list3 = list(map(element3, L))  # First list we see
    
    finalTuple = (list1, list2, list3) # Creation of a tuple of all the lists
    
    return finalTuple
    
# For this example, it takes all the first elements: 1, 2,.. integer type; then the second: a, b,... charcater type
# Thne takes the third elements, {1:"a"}, {2:"b"}, ... dictionary type
# print(unzip ([(1,"a",{1:"a"}),(2,"b",{2:"b"}),(3,"c",{3:"c"}),(4,"d",{4:"d"})]))   
   
            
                                   # 4) (Recursion) numPaths(m,n,blocks) – 10%

# Consider a robot in a mXn grid who is only capable of moving right or down in the grid (can’t move left, up or diagonal). 
# The robot starts at the top left corner, (1,1), and is supposed to reach to the bottom right corner: (m,n). Some of the cells in
# the grid are blocked and the robot is not allowed to visit those cells. 
# Write a function numPaths that takes the grid length and
# width (i.e., m,n) and the list of the blocked cells (blocks) as argument and returns the number of different paths the robot can
# take from the start to the end. Give an answer using recursion. (A correct solution without recursion will be worth half the points.

def numPaths(m,n,blocks):
    
    # When either the first cell (1, 1) or last cell (m, n) is blocked, the total paths is zero.
    if (1, 1) in blocks or (m, n) in blocks: 
        return 0

            # Start of def numPaths_recursive(o,p):
    def numPaths_recursive(o, p):
        
                               # Let's deal with the base cases
      # Base case Option1: When the cell we are in is blocked or is out of the boundaries - So it is invalid, we return 0 for the number of paths
      # When any one of those out of boundaries occurs, we return 0 
        if o < 1 or p < 1 or o > m or p > n or (o, p)in blocks:
            return 0 
        
      # Base case Option2: When we reached the destination (m,n) - Yeah, we got what we want, we return 1 for the number of paths
        if o == m and p == n:
            return 1
        
      # We have not gotten what we want yet, let's keep going - Recursive approach  
      # We can move to the right and we can move down, where "o + 1" represents moving to the 
      # And "p + 1" represents moving to the
        return numPaths_recursive(o + 1, p) + numPaths_recursive(o, p + 1)
              # End of def numPaths_recursive(o,p):
           
       # We start our travel process - with the numPaths_recursive() starting with the starting cell (1,1), that is at the top left corner
    return numPaths_recursive(1, 1)


#print("\n")
# print(numPaths(2, 2, [(2, 1)]))  # Output: 1
# print(numPaths(3, 3, [(2, 3)]))  # Output: 3
# print(numPaths(4, 3, [(2, 2)]))  # Output: 4
# print(numPaths(10, 3, [(2, 2), (7, 1)]))  # Output: 27


                                    # 5) Iterators

        # a) iterFile()– 25%
    
# Create an iterator that represents the sequence of words read from a text file. The iterator is initialized with the name 
# of the file and the iterator will return the next word from the file for each call to __next__(). 
# The iterator should ignore all empty lines and end of line characters.

# Important note: Your iterFile implementation should read the lines (or words) from the input text file as needed. 
# Note: this is meant to indicate that you will read a line from the file, then process that line word-by-word when 
# requested, then read the next line (if one exists) and process it word-by-word, etc. An implementation that reads 
# the complete file and dumps all words to a list all at once will be worth only 10 points.

class iterFile():

    def __init__(self, filename):
        self.filename = filename # The file we want
        self.fileTool = open(self.filename, 'r') # Open the desired file for reading
             # The fileTool to use for the functions we need
            
    def _getNextWord(self):
        word = '' # Initialization of the word - Element to return
        
        try:
            
            while True:
                char = self.fileTool.read(1)  # Initialization of the character - to read one character at once
                
                if not char: # When it is not a character
                   return word if word else None  # Return the word if it is not empty, return None when it is empty
                elif char != ' ' and char != '\n': # Check if the character is not empty and it is not a new line
                    word += char  # Add the characters together to make a word       
                elif word:  # When we have a word and it is not empty
                    return word # Return the word
                
        # If one of the input iterators raise StopIteration exception (i.e., reaches  
   # to the end of the input iterator), then, it should stop 
        except StopIteration:
           pass

    def __next__(self):
        nextWord = self._getNextWord() # Initialize nextWord
        
        if nextWord is None: # When nextWord is None
            self.fileTool.close() # Close the desired file 
            raise StopIteration
        return nextWord
    
    def __iter__(self):
        return self

        # b) wordHistogram(words)– 3%
    
# Define a function wordHistogram that takes an iterator “words” (representing a sequence of words)
# and builds a histogram showing how many times each word appears in the file. wordHistogram
# should return a list of tuples, where each tuple includes a unique word and the number of times that word appears in the file.

def wordHistogram(words):
#write your code here
    count = {} # Will be used with the dictionary tool get
    
    # Going through all the words that make up the whole iterator
    for word in words: # When we find one word in that bucket of words
        count[word] = count.get(word, 0) + 1 
           # The count of that word "count[word]" is calculated with "get.(word, 0)" where word is the word we see
           # and 0 is the starting sum of the occurence of the word, represented with (key,value) element of a dictionary
           # We add + 1 to that sum, when we encounter the word; count stores that sum
     
    # The return representation is a list of tuple (word, number of occurrences), that tuple was value was filled by count
    # We know that: ".items()" returns a view object which contains the key-value pairs of the dictionary, as tuples in a list
    # All we need then is to convert it into a list to match the return type
    word_histogram = list(count.items())
    
    return word_histogram
