#------------------------------------------------------
#-- INCLUDE YOUR OWN TESTS IN THIS FILE
#------------------------------------------------------
import unittest
from HW3 import *

class HW3SampleTests(unittest.TestCase):
    "Unittest setup file. Unittest framework will run this before every test."
    def setUp(self):
        pass
    
    log_input = {'Phil103':{'Sun':5,'Mon':2},'Chem105':{'Mon':4,'Tue':3,'Fri':7},
                 'Hist200':{'Tue':2,'Wed':6},'Math220':{'Mon':3,'Thu':4,'Sat':2}}
    
    #--- Problem 1(a)----------------------------------
    
    def test_aggregate_log(self):
        #pass
        # Provide your own test here. Create your own input dictionary for this test.
        log_input = {'Phil103':{'Sun':5,'Mon':2},'Chem105':{'Mon':4,'Tue':3,'Fri':7},
                     'Hist200':{'Tue':2,'Wed':6},'Math220':{'Mon':3,'Thu':4,'Sat':2}}
        output = {'Fri': 7, 'Mon': 9, 'Sat': 2, 'Sun': 5, 'Thu': 4, 'Tue': 5, 'Wed':6}
        self.assertDictEqual(aggregate_log(log_input),output)

    
    #--- Problem 1(b)----------------------------------
    def test_combine_dict(self):
        #pass
        # Provide your own test here. Create your own input dictionary for this test .
        # You can re-use the data dictionary you created for problem-1.
        log1 = {'Sun':5,'Mon':2}
        log2 = {'Mon':4, 'Tue':3, 'Fri':7}
        output = {'Sun': 5, 'Mon': 6, 'Tue': 3, 'Fri': 7}
        self.assertDictEqual(combine_dict(log1,log2),output)
        #make sure input dictionaries are not changed. 
        self.assertDictEqual(log1, {'Sun':5,'Mon':2})
        self.assertDictEqual(log2, {'Mon':4, 'Tue':3, 'Fri':7})

    #--- Problem 1(c) ----------------------------------
    def test_merge_logs(self):
        #pass
        # Provide your own test here. Create your own input dictionary for this test .
        # You can re-use the data dictionary you created for problem-1.
        log_input1 = [{'Phil103':{'Sun':5,'Mon':2},'Chem105':{'Mon':4,'Tue':3,'Fri':7},
                'Hist200':{'Tue':2,'Wed':6},'Math220':{'Mon':3,'Thu':4,'Sat':2}},
                {'Phil103':{'Mon':3},'Chem105':{'Tue':2},'Hist200':{'Tue':1,'Sat':5},'Math220':{'Thu':2}}]
        output = {'Phil103': {'Sun': 5, 'Mon': 5}, 'Chem105': {'Mon': 4, 'Tue': 5, 'Fri': 7}, 
                  'Hist200': {'Tue': 3, 'Wed': 6, 'Sat': 5}, 'Math220': {'Mon': 3, 'Thu': 6, 'Sat': 2}}
        self.assertDictEqual(merge_logs(log_input1),output)

    #--- Problem 2(a)----------------------------------
    def test_most_hours(self):
       # pass
        # Provide your own test here. Create your own input dictionary for this test 
        output = ('Chem105', 14)
        self.assertTupleEqual(most_hours(self.log_input),output)
            
    #--- Problem 2(b) ----------------------------------
    def test_filter_log(self):
        # pass
        # Provide your own test here. Create your own input dictionary for this test
        output = sorted(['Math220'])
        self.assertListEqual(sorted(filter_log(self.log_input,"Thu", 4)),output) 

    #--- Problem 3----------------------------------
    def test_graph_cycle(self):
        # pass
        # Provide your own test here.   Create your own input graph for this test 
        
        graph1 = {'J':('K',11),'K':('M',9),'L':('P',16),'M':('N',10),'N':('L',11),
                  'O':('R',10),'P':('K',15),'Q':('P',11),'R':('Q',9)} 
        
        output = ['L', 'P', 'K', 'M', 'N', 'L']
        self.assertListEqual(graph_cycle(self.graph1,'L'),output)
        
    #--- Problem 4----------------------------------
    def test_filter_iter(self):
        # pass
        # Provide your own test here. Initialize the iterator with your own input.
        
        input = iter([17, 3, 25, -1, 10, 32, 4, 0, 43, 13])
        expected_output = [3, -1, 10, 4, 0, 13]
        actual_output = list(filter_iter(input, lambda x: x <= 13))  #convert the iterator output to list
        self.assertListEqual(actual_output, expected_output)

    #--- Problem 5----------------------------------
    def test_merge(self):
        # range(start, stop, step)
        it1 = iter(range(4, 30, 6)) # for it1, we will have 4, 10, 16, 22
        it2 = iter(range(5, 31, 6)) # for it2, we will have 5, 11, 17, 23
        output = [4, 5, 10, 11, 16, 17, 22, 23]
        self.assertListEqual(merge(it1, it2, 8), output)

if __name__ == '__main__':
    unittest.main()

