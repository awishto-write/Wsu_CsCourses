import unittest
from HW3 import *

class HW3tests(unittest.TestCase):
    def setUp(self):
        
              # sprintLog() inputs
        self.loginput1a1 = {'CptS355':{'Sun':5, 'Mon':2}, 'CptS360': {'Mon':4, 'Tue':3, 'Fri':7}, 'CptS321': {'Tue':2, 'Wed':6}, 'CptS322': {'Mon':3, 'Thu':4, 'Sat':2}}
        self.loginput1a2 = {'Cleveland Hall': {'SouthSide': 234, 'Hillside': 1940}, 'Dana Hall': {'SouthSide': 500, 'Northside': 379, 'Hillside': 70}, 'CUE 209': {'Hillside': 754, 'Northside': 2408} }
        self.loginput1a3 = {'CptS360': {'Sat':4, 'Tue':5, 'Fri':9}, 'CptS322': {'Thu':2, 'Mon':8, 'Sat':2}, 'CptS355': {'Tue':9, 'Wed':7}}
        self.loginput1a4 = {'Dana Hall': {'SouthSide': 432, 'Northside': 535, 'Hillside': 70}, 'CUE 209': {'SouthSide': 254, 'Northside': 192} }
            # sprintLog() outputs
        self.logoutput1a1 = {'Sun': {'CptS355': 5}, 'Mon': {'CptS355': 2, 'CptS360': 4, 'CptS322': 3}, 'Tue': {'CptS360': 3, 'CptS321': 2}, 'Fri': {'CptS360': 7}, 'Wed': {'CptS321': 6}, 'Thu': {'CptS322': 4}, 'Sat': {'CptS322': 2}}
        self.logoutput1a2 = {'SouthSide': {'Cleveland Hall': 234, 'Dana Hall': 500}, 'Hillside': {'Cleveland Hall': 1940, 'Dana Hall': 70, 'CUE 209': 754}, 'Northside': {'Dana Hall': 379, 'CUE 209': 2408}}
           
            # addSprints() inputs
        self.loginput1b1 = {'Sun': {'CptS355': 5}, 'Mon': {'CptS322': 2, 'CptS360': 4, 'CptS321': 3}, 'Tue': {'CptS322': 3, 'CptS360': 2}, 'Fri': {'CptS355': 7}, 'Wed': {'Cpts322': 6}, 'Thu': {'CptS360': 4}, 'Sat': {'CptS321': 31}}
        self.loginput1b2 = {'Sun': {'CptS360': 2}, 'Mon': {'CptS355': 85, 'Cpts322': 17}, 'Tue': {'Cpts322': 22, 'CptS360': 14}, 'Fri': {'CptS321': 43}, 'Wed': {'CptS360': 4, 'CptS355': 3}, 'Thu': {'CptS321': 2}, 'Sat': {'Cpts322': 4}}
        self.loginput1b3 = {'SouthSide': {'Cleveland Hall': 234, 'CUE 209': 754, 'Dana Hall': 500}, 'Hillside': {'Dana Hall': 10}}
        self.loginput1b4 = {'Hillside': {'Cleveland Hall': 1940, 'Dana Hall': 70}, 'Northside': {'CUE 209': 19},'SouthSide': {'CUE 209': 2408, 'Dana Hall': 379}}
            # addSprints() outputs
        self.logoutput1b12 = {'Sun': {'CptS355': 5, 'CptS360': 2}, 'Mon': {'CptS322': 2, 'CptS360': 4, 'CptS321': 3, 'CptS355': 85, 'Cpts322': 17}, 'Tue': {'CptS322': 3, 'CptS360': 16, 'Cpts322': 22}, 
                            'Fri': {'CptS355': 7, 'CptS321': 43}, 'Wed': {'Cpts322': 6, 'CptS360': 4, 'CptS355': 3}, 'Thu': {'CptS360': 4, 'CptS321': 2}, 'Sat': {'CptS321': 31, 'Cpts322': 4}}
        self.logoutput1b34 = {'SouthSide': {'Cleveland Hall': 234, 'CUE 209': 3162, 'Dana Hall': 879}, 'Hillside': {'Dana Hall': 80, 'Cleveland Hall': 1940}, 'Northside': {'CUE 209': 19}}
        
             # addNLogs() inputs
        self.loginput1c1 = [self.loginput1a1,self.loginput1a3]
        self.loginput1c2 = [self.loginput1a2,self.loginput1a4]
            # addNLogs() outputs
        self.logoutput1c1 = {'Sun': {'CptS355': 5}, 'Mon': {'CptS355': 2, 'CptS360': 4, 'CptS322': 11}, 'Tue': {'CptS360': 8, 'CptS321': 2, 'CptS355': 9}, 'Fri': {'CptS360': 16}, 'Wed': {'CptS321': 6, 'CptS355': 7}, 'Thu': {'CptS322': 6}, 'Sat': {'CptS322': 4, 'CptS360': 4}}
        self.logoutput1c2 = {'SouthSide': {'Cleveland Hall': 234, 'Dana Hall': 932, 'CUE 209': 254}, 'Hillside': {'Cleveland Hall': 1940, 'Dana Hall': 140, 'CUE 209': 754}, 'Northside': {'Dana Hall': 914, 'CUE 209': 2600}}
        
              #lookupVal() inputs    ~  #lookupVal() outputs will below   
        self.loginput2a1 = [{"Lion":"Roar","Dog":13,"Cat":False},{"Tiger":2, "Elephant":20},{"Dog":11,"Husky":True}]
        
             #lookupVal2() inputs    ~  #lookupVal2() outputs will below 
        self.loginput2b1 = [(0,{"Dog":0,"Tiger":False}), (0,{"Ele":9}), (1,{"Husky":True}), (2,{"Dog":2, "Cat":"meow"}), (3,{"Lion":"Roar"}),(4,{"Tiger":2})]
        
              # unzip() inputs
        self.loginput3_1 = [(7,"Mon",{7:"Mon"}),(8,"Non",{8:"Non"}),(9,"Oon",{9:"Oon"}),(10,"Pon",{10:"Pon"})]
        self.loginput3_2 = [("dance",11,{"dance":11}),(12,"sing",{"sing":12}),({"jump":13},"jump",13),("fly",14,{"fly":14}),("slide",15,{"slide":15})]
              # unzip() outputs
        self.logoutput3_1 = ([7, 8, 9, 10], ['Mon', 'Non', 'Oon', 'Pon'], [{7: 'Mon'}, {8: 'Non'}, {9: 'Oon'}, {10: 'Pon'}])
        self.logoutput3_2 = (['dance', 12, {'jump': 13}, 'fly', 'slide'], [11, 'sing', 'jump', 14, 15], [{'dance': 11}, {'sing': 12}, 13, {'fly': 14}, {'slide': 15}])
        
            # For iterFile 
        self.filetokens = ["Task","-","Recommend","products","to","users","based","on","their","history",".","It","implies","recommending","1000","products","to","users","based","on","products","commonly","ordered",";","commonly","ordered","together","among","users","%"]
        
            # For histogram
        self.histogram = [('Task', 1), ('-', 1), ('Recommend', 1), ('products', 3), ('to', 2), ('users', 3), ('based', 2), ('on', 2), ('their', 1), ('history', 1), ('.', 1), ('It', 1), ('implies', 1), ('recommending', 1), ('1000', 1), ('commonly', 2), ('ordered', 2), (';', 1), ('together', 1), ('among', 1), ('%', 1)]
        self.histogramExample = [('elephant', 4), ('lion', 2), ('sheep', 2), ('dragon', 1),('fish', 1)]

               # Problem 1.a
    def test_sprintLog1(self):
        self.assertDictEqual(sprintLog(self.loginput1a1),self.logoutput1a1)
    def test_sprintLog2(self):
        self.assertDictEqual(sprintLog(self.loginput1a2),self.logoutput1a2)

            # Problem 1.b
    def test_addSprints1(self):
        self.assertDictEqual(addSprints(self.loginput1b1, self.loginput1b2),self.logoutput1b12)
    def test_addSprints2(self):
        self.assertDictEqual(addSprints(self.loginput1b3, self.loginput1b4),self.logoutput1b34)

            # Problem 1.c
    def test_addNLogs1(self):
        self.assertDictEqual(addNLogs(self.loginput1c1),self.logoutput1c1)
    def test_addNLogs2(self):
        self.assertDictEqual(addNLogs(self.loginput1c2),self.logoutput1c2)

           # Problem 2.a
    def test_lookupVal_1(self):
        self.assertEqual(lookupVal(self.loginput2a1,"Dog"),11)
        self.assertEqual(lookupVal(self.loginput2a1,"Husky"),True)
        self.assertEqual(lookupVal(self.loginput2a1,"Elephant"),20)
    def test_lookupVal_2(self):
        self.assertEqual(lookupVal(self.loginput2a1,"Lion"),"Roar")
        self.assertEqual(lookupVal(self.loginput2a1,"Tiger"),2)
        self.assertEqual(lookupVal(self.loginput2a1,"Crab"),None)

         # Problem 2.b
    def test_lookupVal2_1(self):
        self.assertEqual(lookupVal2(self.loginput2b1,"Lion"),"Roar")
        self.assertEqual(lookupVal2(self.loginput2b1,"Santa"),None)
        self.assertEqual(lookupVal2(self.loginput2b1,"Ele"),9)
    def test_lookupVal2_2(self):
        self.assertEqual(lookupVal2(self.loginput2b1,"Husky"),True)
        self.assertEqual(lookupVal2(self.loginput2b1,"Tiger"),2)
        self.assertEqual(lookupVal2(self.loginput2b1,"Dog"),2)

        # Problem 3
    def test_unzip_1(self):
        self.assertEqual(unzip(self.loginput3_1),self.logoutput3_1)
    def test_unzip_2(self):
        self.assertEqual(unzip(self.loginput3_2),self.logoutput3_2)
 
        # Problem 4
    def test_numPaths_1(self):
        self.assertEqual(numPaths(4, 4, [(2, 3), (3, 2)]), 2)  
        self.assertEqual(numPaths(2, 2, []), 2)  
        
    def test_numPaths_2(self):
        self.assertEqual(numPaths(5, 5, [(2, 2), (3, 3), (4, 4)]), 10) 
        self.assertEqual(numPaths(7, 7, [(2, 3), (3, 4), (5, 6)]), 280) 
    
 
         # Problem 5.a
    def test_iterFile1(self):
        mywords = iterFile("myTestFile.txt")
        self.assertEqual(mywords.__next__(),"Task")
        self.assertEqual(mywords.__next__(),"-")
        self.assertEqual(mywords.__next__(),"Recommend")
        self.assertEqual(mywords.__next__(),"products")
        self.assertEqual(mywords.__next__(),"to")
        restofFile = []
        for word in mywords:
            restofFile.append(word)
        self.assertEqual(restofFile,self.filetokens[5:])

    def test_iterFile2(self):
        mywords = iterFile("myTestFile.txt")
        restofFile = []
        for word in mywords:
            restofFile.append(word)
        desiredLastWord = self.filetokens[-1]
        desiredPositionWord = self.filetokens[-4]
        self.assertEqual(desiredLastWord,"%")
        self.assertEqual(desiredPositionWord,"together")
        
         # Problem 5.b
    def test_wordHistogram_1(self):
        mywords = iterFile("myTestFile.txt")
        self.assertEqual(wordHistogram(mywords), self.histogram)
    def test_wordHistogram_2(self):
        emptyFile = open("empty.txt", "w")
        emptyFile.close()
        emptyFile = iterFile("empty.txt")
        histogramOfWords = wordHistogram(emptyFile)
        empty = []
        self.assertEqual(histogramOfWords, empty)
    
        
        words4 = iterFile("myExample.txt")
        histogramForWords = wordHistogram(words4)
        self.assertEqual(histogramForWords, self.histogramExample)
        
        

if __name__ == '__main__':
    unittest.main()