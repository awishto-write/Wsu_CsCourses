# CptS 355 - Spring 2023 - Assignment 3 - Python

# Please include your name and the names of the students with whom you discussed any of the problems in this homework
# Name: Naomi Dion-Gokan
# Collaborators: 

debugging = False
def debug(*s): 
     if debugging: 
          print(*s)

from functools import reduce

## problem 1(a) - aggregate_log  - 5%

# The keys of the dictionary are the course numbers and the values are the dictionaries which 
# include the number of hours you studied on a particular day of the week.  
# The function aggregate_log  adds up the number of hours you studied on each day of the week and 
# returns the summed values as a dictionary. The keys in the resulting dictionary are the days of 
# the week(abbreviated) and the values should be the total number of hours you have studied on that day.

def aggregate_log(dict1):
    dictionary1 = dict()  # Iniatialization of the new dictionary
    
    # Technically we iterate through our input parameter dictionary (the key and value)
    for (info2, info) in dict1.items():
         
         # Now, we iterate through the sub-dictionary(info) that is the value of the big
         # dictionary(dict1) and go through (the key and value)
         for (weekDay, hour) in info.items(): 
              
     # our objective is to represent our result like the value of dict1
     # We attributed the result dictionary of a weekDay to correspond to us getting the
     # values of the weekday and adding all the hours without repeating the same day name
     # but taking account always the values
               dictionary1[weekDay] = dictionary1.get(weekDay, 0) + hour
               
    # return dictionary1  # it works but it is not the desired order for the days
    return dict(sorted(dictionary1.items()))

                 #-----------#

## problem 1(b) - combine_dict– 6%

# A function combine_dict which combines two given study  logs and returns the merged 
# dictionary. The values of the common keys should be summed in the resulting dictionary.

def combine_dict(dict1, dict2):
     
    combinedDict = {}
    
    # The same idea as question 1.b, however we consider elements from both
    # dictionary as we iterate them and we do not sort the resulting dictionary
    
    for info in (dict1, dict2):
         for (weekDay, hour) in info.items():
               combinedDict[weekDay] = combinedDict.get(weekDay, 0) + hour
               
    return combinedDict  # it works but it is not the desired order for the days

                #-----------#

## problem 1(c) - merge_logs– 12%
    
# # A function merge_logs which takes a list of course log dictionaries and returns a dictionary which 
# # includes the combined logs for each class, i.e., the logs of each class should be merged to a 
# # single dictionary. You should use combine_dict (from part (b)) in your solution.  

def merge_logs(listOfDict):
   
   #from copy import copy, deepcopy
   
   mergedDict = dict()   
     
      # we iterate through the main dictionary of the class
   for info in listOfDict:    
         
         # if weekDay occurs multiple times, it does append the values when they have the same day
          # Now, we iterate through the key of the dictionary 
       for (x, y) in info.items():        # dealing with course and week info
            z = mergedDict.get(x, {})
            mergedDict[x] = combine_dict(z, y)
                          
   return mergedDict       

                   #-----------#
 
## problem 2(a) - most_hours – 15%   # Similar to question 3 from Lab3

# Consider the combined log output in problem 1(c). You would like to find the course with the 
# maximum total study time. Write a function “most_hours” that takes the log_input data as input
# and returns the course having the maximum total hours. 

# Your function definition should not use loops or recursion but use the Python map, reduce, and/or 
# filter functions. You may define and call helper (or anonymous) functions, however your helper 
# functions should not use loops or recursion. 
# If you are using reduce, make sure to import it from functools.  

                 # One way to solve it
# def most_hours_helper(d):
#      return reduce( (lambda x,y: x + y) , d.values())

# def most_hours(data):
#    totalHoursPerCourse = map( (lambda x: (x[0] , most_hours_helper(x[1]) ) ) , data.items() )
#    mostHours_and_course = reduce ( (lambda x,y : x if x[1] > y[1] else y ), list(totalHoursPerCourse))
#    return mostHours_and_course # return a tuple

              # We will use the other way to solve it

def most_hours(data):
   
   # That function gets the total hours per every course
   most_hours_helper = lambda info : reduce( (lambda x,y: x + y) , info.values())
   
   totalHoursPerCourse = list ( map( (lambda x: (x[0] , most_hours_helper(x[1]) ) ) , data.items() ) )

   # we return a tuple  mostCases_and_course
   return reduce ( (lambda x,y : x if x[1] > y[1] else y ), (totalHoursPerCourse))

                  #-----------#

## problem 2(b) - filter_log – 15%

# Consider the log_input data in problem 1(a). Assume you would like to find the courses that you studies 
# for on a particular day of the week for more than some number of hours. Write a function “filter_log” 
# that takes the log_input data and returns the courses that has the given day in its log with more than 
# or equal to the required number of hours.

def helper_filter(dictt, weekDayy, hourss):
   # checking if the day is in the list and if that day has >= amount of hours
   return weekDayy in dictt and dictt[weekDayy] >= hourss
 
def filter_log(dict2, weekDay, hours):
   # fetching the result and info from the helper function
    info = filter (lambda info2 : helper_filter(info2[1], weekDay, hours) , dict2.items()) 
     
      # We return a tuple of the courses that match ouur rquirements above
    return list (map (lambda x : x[0], info))

                #-----------#
                
## problem 3 - graph_cycle – 12% 


# A recursive function, graph_cycle, which takes a graph dictionary and a starting node as input 
# and returns the sequence of nodes that form a cycle in the graph. It returns the first cycle that exists in 
# the path beginning at node “start”. The function returns the list of the cycle node labels where the 
# starting node of the cycle should be included both in the beginning and at the end.  If the graph doesn’t 
# have any cycles, it returns None.  
 
# You may define helper functions to implement your solution. Either your  graph_cycle function or 
# your helper should be recursive. 

   #  Sorry for the bad structure and format of the function, 
   # I kept having a 'maximum recursion depth exceeded' error, that's the only option that works

# That function recursively calls graphCycle_helper and return the cycle found
def graph_cycle(dict_graph, starting_node):
    
    # helper function for the main function
    def graphCycle_helper(dict_graph, starting_node, visited):
   
        next_node = dict_graph[starting_node][0]  # setting and getting the next node
    
        if next_node is None: # If that, this is the end of the list and there is no cycle
            return None
    
        if starting_node not in ls: 
           visited.append(starting_node) # add that node into the visited list of nodes
           return graphCycle_helper(dict_graph,next_node, visited)
        else:
           visited.append(starting_node)
           return visited
        
    ls = []
   # get a list of nodes that includes the loop
    loop_list = graphCycle_helper(dict_graph, starting_node,ls)
   
   # Get the start of the loop by finding the index of the last node in the list
    loop_last_index = loop_list.index(loop_list[-1])
    
   # Get the section of the list that corresponds to the list
    return (loop_list[loop_last_index: ])
     
                 #-----------#

# problem 4 - filter_iter – 15% 

# An iterator whose constructor takes a function (op) and an iterable value (it) as argument and applies op on 
# each value of the input iterator. At each call to the  next function, the iterator will return the result of (op x) 
# where x is the next value from the input sequence.  
# Your filter_iter implementation should calculate the next (op x) value as needed.
# An implementation that precomputes all values for the given iterator input and  dumps all values 
# to a list ahead of time will be worth only 5 points. 

class Numbers():
  def __init__(self,init):
    self.current = init
  def __next__(self):
    result = self.current
    self.current += 1
    return result
  def __iter__(self):
    return self

class filter_iter(object): 
         #write your code here 
    #def __init__(self, op, n, it):
    def __init__(self, it, op):
        #self.input1 = it
        self.it = it
        self.op = op
     
    def __next__(self):
       
       neext = self.it.__next__() # Initialize the next element
       if self.op(neext):   # when the next element matches the operation
         return neext  
       else:
         return self.__next__() # Go to the next element
     
    def __iter__(self):
     return self
                  #-----------#

## problem 5 - merge – 10% 

# A function merge that takes 2 iterable values  “it1” and “it2” (which are sorted sequences of  
# increasing numbers), and merges the two input sequences. merge returns the first N elements from the 
# merged sequence. The numbers in the merged sequence needs to be sorted as well. The iterator will
# remember its current position among calls to the merge function. It retrieves the next element 
# in the sequence in the subsequent calls to merge.

def merge(it1, it2, N_element):
     mergedList = []
     count = 0 # keep track of the elements that will be in the new list
     
     try:
           next_it1 = it1.__next__()
           next_it2 = it2.__next__()
           
           # count starting by 0, will help make sure that the merged
           # list does not have more elements than needed
           while(count < N_element): 
          
                if(next_it1 <= next_it2):
                   mergedList.append(next_it1) # append the element of the iterator into the list
                   next_it1 = it1.__next__()
                   
                else:
                   mergedList.append(next_it2) # append the element of the iterator into the list
                   next_it2 = it2.__next__()
                count = count + 1   # count += 1 # incrementing as elements are added to the list
   
   # If one of the input iterators raise StopIteration exception (i.e., reaches  
   # to the end of the input iterator), then, it should stop merging.
     except StopIteration:
        pass
     
     return mergedList

