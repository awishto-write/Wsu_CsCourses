# CptS 355 - Spring 2023 - Lab 3
# Naomi Dion-Gokan

debugging = False
def debug(*s): 
     if debugging: 
          print(*s)

## problem 1 getNumCases 

# CDCdata = {'King':{'Mar':2706,'Apr':3620,'May':1860,'Jun':2157,'July':5014,'Aug':4327,'Sep':2843},  
# 'Pierce':{'Mar':460,'Apr':965,'May':522,'Jun':647,'July':2470,'Aug':1776,'Sep':1266},  
# 'Snohomish':{'Mar':1301,'Apr':1145,'May':532,'Jun':568,'July':1540,'Aug':1134,'Sep':811},  
# 'Spokane':{'Mar':147,'Apr':222,'May':233,'Jun':794,'July':2412,'Aug':1530,'Sep':1751},  
# 'Whitman' : {'Apr':7,'May':5,'Jun':19,'July':51,'Aug':514,'Sep':732, 'Oct':278} } 
 

## Define a function, getNumCases, which calculates the total number of new cases for a given list 
## of counties during a given list of months.
#It should simply iterate over the keys that appear in the given dictionary. 

def getNumCases(data,counties,months):  
      #write your code here 
      
     sumNumCases = 0
     
     for given_county in counties:
          for given_month in months:
               sumNumCases += data [given_county] [given_month]
               
     return sumNumCases

# debug(getNumCases(CDCdata,['Whitman'],['Apr','May','Jun']))
# debug(getNumCases(CDCdata,['King','Pierce'],['July','Aug']))
 
            #-----------#
       
      
## problem 2 getMonthlyCases

# Define a function getMonthlyCases that reformats the CDC data as described above. 
# To reformat the data and create a dictionary that includes the number of cases for each county,
# organized by months. (The items in the output dictionary can have arbitrary order.)

# swapping the key (counties) with the value (months)?

def getMonthlyCases(data):
    dictionary1 = {} # creation of an empty dictionary. You can also so dictionary1 = dict()
          
    # because we considered the case where month is in data and county 
    # in the value of data, we automatically considered if month and county are in data
           
          #dealing with both key and value
    for (county, info1) in data.items():     
         for (month, info2) in info1.items(): # we deal with the dictionary part of the value of the main dictionary
              if month not in dictionary1.keys():
                   dictionary1[month] = {} # we set that month to a empty dictionary if the month is not found
                   dictionary1[month][county] = info2 # we set the month as the key, the county become the value: insert those in the dictionary, without forgetting  
                                                      # the original info2 that is a part of the value of form a dictionary now with county
              
         return dictionary1         
                  
# debug(getMonthlyCases(CDCdata))
         
            #-----------#

from functools import reduce

## problem 3 mostCases 


# To find the month that had the maximum total number of new cases in all counties. 
# Your function definition should not use loops or recursion but use the Python map and reduce 
# functions. You should also use the getMonthlyCases function you defined in part(b). You may 
# define and call helper (or anonymous) functions, however your helper functions should not use loops or recursion

                          # One way to solve it
#That function gets the total cases per month  
# def mostCases_helper(d):
#      return reduce( (lambda x,y: x + y) , d.values())

# def mostCases(data):

#    monthlyCases = getMonthlyCases(data)
#    totalCasesMonthly = map( (lambda x: (x[0] , mostCases_helper(x[1]) ) ) , monthlyCases.items() )
#    mostCases_and_month = reduce ( (lambda x,y : x if x[1] > y[1] else y ), list(totalCasesMonthly))
#    return mostCases_and_month  # we return a tuple 

                  # We are going with this other way to solve it

def mostCases(data):

   monthlyCases = getMonthlyCases(data)
   
   # That function gets the total cases per month
   mostCases_helper = lambda info : reduce( (lambda x,y: x + y) , info.values())
   
   totalCasesMonthly = list (map( (lambda x: (x[0] , mostCases_helper(x[1]) ) ) , monthlyCases.items() ) )
   
   # we return a tuple  mostCases_and_month
   return reduce ( (lambda x,y : x if x[1] > y[1] else y ), (totalCasesMonthly))
   
# debug(mostCases(CDCdata))

      #-----------#

## problem 4a) searchDicts(L,k)

# dictList = [{"x":1,"y":True,"z":"found"},{"x":2},{"y":False}]
# dictList2 = [(0,{"x":0,"y":True,"z":"zero"}), (0,{"x":1}), (1,{"y":False}), (1,{"x":3, "z":"three"}), (2,{})]

# A function searchDicts that takes a list of dictionaries L and a key k as input and checks 
# each dictionary in L starting from the end of the list. If k appears in a dictionary, searchDicts 
# returns the value for key k. If k appears in more than one dictionary, it will return the one that it 
# finds first (closer to the end of the list). 

def searchDicts(L,k):  
     #write your code here
     
     # we used reversed of the list because we start at the end of the list
     for element in reversed(L): # for the keys in the reversed list
         for element_ in element: # for the current key we are on is a part of the keys
              if element_ == k: # if we see the k we are looking for and it is equal to _element
                   return element[element_] # we return the value

# debug(searchDicts(dictList,"x"))  
# debug(searchDicts(dictList,"y"))         
# debug(searchDicts(dictList,"z"))
# debug(searchDicts(dictList,"t"))
          
             #-----------#

## problem 4b) searchDicts2(tL,k)

# A function searchDicts2 that takes a list of tuples (tL) and a key k as input. Each tuple in 
# the input list includes an integer index value and a dictionary. The index in each tuple represent a 
# link to another tuple in the list (e.g. index 3 refers to the 4th tuple, i.e., the tuple at index 3 in the list)  
# searchDicts2 checks the dictionary in each tuple in tL starting from the end of the list and 
# following the indexes specified in the tuples.  


# (Note: I suggest you to provide a recursive solution to this problem.  
# Hint: Define a helper function with an additional parameter that hold the list index which will be 
# searched in the next recursive call.)  

def searchDicts2_helper(tL,k, index):  
   #write your code here 
   element = tL[index]

      # checking the dictionary at tL[indes]
   if k in element[1]: # or if k in tL[index][1]
        return element[1][k] # or tL[index][1] [k]
        
   else :
        if index == 0: # else if reached to the beginning of the list return None
           return None
        else: # else make the recursive call for index tL[index][0]
           return searchDicts2_helper(tL, k, element[0])   
      
#    if element[0] == index: # correct?
#      #if index == 0:
#            return None
#    return searchDicts2_helper(tL, k, element[0])
             
def searchDicts2(tL,k):  
   #write your code here 
   ind = len(tL) - 1 # meaning starting at the end of the list
   return searchDicts2_helper(tL, k, ind)

# debug(searchDicts2(dictList2,"x"))
# debug(searchDicts2(dictList2,"y"))
# debug(searchDicts2(dictList2,"z"))
# debug(searchDicts2(dictList2,"t"))


        #-----------#

## problem 5 - getLongest

# strings = ['1',['22',['333',['4444','55555',['666666']],'7777777'],'4444'],'22']
# pets=[['cat',['dog','horse'],['bird',['bunny','fish']]]]      
    
# Write a function, getLongest, which takes an arbitrarily nested list of strings (L) and it returns the 
# longest string in L. Note that the longest string can be found at any nesting level, so your function should 
# recursively check all sublists. You should not assume a max depth for the nesting. If there are more than 
# one string that have the max length, you should return the one that appears earlier in the list.  
             
               # This solution works, but we will use the other method
# def getLongest (L):      
#      if type(L) == str:
#         return L
#      return max([getLongest(chosen_string) for chosen_string in L])
        
         # We are going with this other way to solve it
         
def getLongest(L):  
     
     # a helper function that return longer of two given strings
     getLonger = lambda x,y: x if len(x) >= len(y) else y
     
     longest = ''
     for item in L:
          if isinstance(item,list):
               longest = getLonger(longest, getLongest(item))
          else:
               longest = getLonger(longest, item) # by reversing the order of the parameters in getLonger
                                                  # it does not return the first longest string, same applies above
               
          # if item is a list(type), make a recursive call on item and then compare the value recursive call returns
          # with the current longest, and update current longesst if longer
          # else compare with the current longest, and update current longest if longer   
               
     return longest

# debug(getLongest(strings))
# debug(getLongest (pets))
      
       #-----------#

## problem 6 - apply2nextN 

# An iterator that represents the aggregated sequence of values from an input iterator. The iterator 
# will be initialized with a combining function (op), an integer value (n) , and an input iterator (input).  
# When the iterator’s __next__() method is called, it will combine the next “n” values in the “input“  
# by applying the “op” function and it will return the combined value. The iterator should stop when it 
# reaches the end of the input sequence. If the input sequence is infinite, the apply2nextN will return an 
# infinite sequence as well.  

class apply2nextN(object): 
    #write your code here 
    def __init__(self, op, n, it):
        self.input1 = it
        self.op = op
        self.n = n
        self.current = self._getNextInput()
        
    def _getNextInput(self):
          try:
              current = self.input1._next_()
          except:
               current = None
          return current
     
    def __next__(self):
         if self.current is None:
              raise StopIteration
         
         temp_n = self.n
         total = self.current
         self.current = self._getNextInput()
         
         while(temp_n > 1):
              if(self.current is not None):
                   total = self.op(total, self.current)
              else:
                   break
              self.current = self._getNextInput()
              temp_n -= 1 # temp_n = temp_n - 1
              
         return total
     
    def __iter__(self):
     return self

# strIter =iter('aaaabbbbccccddddeeeeffffgggghhhhjjjjkkkkllllmmmm')
# iSequence = apply2nextN(lambda a,b:a+b, 4, strIter)
# debug(iSequence)

# it = apply2nextN(lambda a,b:a+b, 3, iter(range(1,32)))
# for item in it:
#           print(item)
# debug(it)

