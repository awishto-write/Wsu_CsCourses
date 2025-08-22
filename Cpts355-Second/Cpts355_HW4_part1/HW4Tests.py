import sys
import io
import unittest
from HW4 import *

class HW4Tests(unittest.TestCase):
    def setUp(self):
        pass

    def testOpPush(self):
        opstack.clear()
        opPush("(Hello)")
        self.assertEqual(opstack[-1],"(Hello)")
    
    def testOpPush2(self):
        opstack.clear()
        opPush(5)
        self.assertEqual(opstack[-1],5)
        
        # Additional Tests added
    def testOpPush3(self):
        opstack.clear()
        opPush(-10)
        self.assertEqual(opstack[-1],-10)
    def testOpPush4(self):
        opstack.clear()
        opPush(5)
        opPush(7)
        self.assertEqual(len(opstack),2)
        opPop()
        opPop()
    def testOpPush5(self):
        opstack.clear()
        opPush("")
        self.assertEqual(opstack[-1],"")

    def testOpPop(self):
        opstack.clear()
        opPush(5)
        self.assertEqual(opPop(),5)
    
       # Additional Tests added
    def testOpPop2(self):
        opstack.clear()
        opPush(-10)
        self.assertEqual(opPop(),-10)
    def testOpPop3(self):
        opstack.clear()
        opPush(7.0)
        self.assertEqual(len(opstack),1)
        opPop()
    def testOpPop4(self):
        opstack.clear()
        opPush("(Milk)")
        self.assertEqual(opPop(),"(Milk)")    
        
    def testDictPush(self):
        dictstack.clear()
        dictPush({})
        self.assertEqual(dictstack[-1],{})
        
        # Additional Tests added
    def testDictPush2(self):
        dictstack.clear()
        dictPush({"Literature"})
        self.assertEqual(dictstack[-1],{"Literature"})
    def testDictPush3(self):
        dictstack.clear()
        dictPush({9.0})
        dictPush({9.0})
        self.assertEqual(len(dictstack),2)
        dictPop()
        dictPop()
    def testDictPush4(self):
        dictstack.clear()
        dictPush({76})
        self.assertEqual(dictstack[-1],{76})

    def testDictPop(self):
        dictstack.clear()
        dictPush({})
        dictPop()
        self.assertEqual(len(dictstack),0)
        
         # Additional Tests added
    def testDictPop2(self):
        dictstack.clear()
        dictPush({"Literature"})
        self.assertEqual(len(dictstack),1)
        dictPop()
    def testDictPop3(self):
        dictstack.clear()
        dictPush({'Hello'})
        dictPop()
        dictPush({'Hi'})
        self.assertEqual(len(dictstack),1)
        dictPop()

    def testDefine(self):
        dictstack.clear()
        define("/a",1)
        self.assertEqual(len(dictstack),1)
        
         # Additional Tests added
    def testDefine2(self):
        dictstack.clear()
        define("/clarisse",14)
        self.assertEqual(dictPop(),{"/clarisse":14})
    def testDefine3(self):
        dictstack.clear()
        define("/boby",3)
        dictPop()
        define("/davido",4)
        self.assertEqual(len(dictstack),1)

    def testLookup(self):
        dictstack.clear()  
        opPush("/n1")       
        opPush("(hornswaggle)")  
        psDef()
        self.assertEqual(lookup("n1"),"(hornswaggle)")
        
        # Additional Tests added
    def testLookup2(self):
        dictstack.clear()  
        opPush("/leroi")        
        psDef()
        self.assertEqual(lookup("leroi"),None)
    def testLookup3(self):
        dictstack.clear()  
        opPush("/Cpts315")       
        opPush("(clarisse)")  
        psDef()
        opPush("/Cpts355")       
        opPush("(davido)")  
        psDef()
        self.assertEqual(lookup("Cpts355"),"(davido)")
        self.assertEqual(lookup("Cpts315"),"(clarisse)")
        
    def testAdd(self):
        opstack.clear()     
        opPush(1.0)       
        opPush(2.0)       
        add()       
        self.assertEqual(opPop(),3)

    def testAdd2(self):
        opstack.clear()     
        opPush(3)
        opPush("(notanum)")
        add()       
        self.assertEqual(opPop(),"(notanum)")
        self.assertEqual(opPop(),3)
        
       # Additional Tests added
    def testAdd3(self):
        opstack.clear()     
        opPush(-5)       
        opPush(5)       
        add()       
        self.assertEqual(opPop(),0)
    def testAdd4(self):
        opstack.clear()     
        opPush(0)       
        opPush(-4)       
        add()       
        self.assertEqual(opPop(),-4)
    def testAdd5(self):
        opstack.clear()     
        opPush(3.5)       
        opPush(4.2)       
        add()       
        self.assertEqual(opPop(),7.7)

    def testSub(self):
        opstack.clear()
        opPush(3)
        opPush(2)
        sub()
        self.assertEqual(opPop(),1)
        
        # Additional Tests added
    def testSub2(self):
        opstack.clear()     
        opPush("(constitution)")
        opPush(7)
        sub()       
        self.assertEqual(opPop(),7)
        self.assertEqual(opPop(),"(constitution)")
    def testSub3(self):
        opstack.clear()     
        opPush(7.0)
        opPush(5.0)
        sub()       
        self.assertEqual(opPop(),2.0)
    
    def testMul(self):
        opstack.clear()
        opPush(3)
        opPush(2)
        mul()
        self.assertEqual(opPop(),6)
        
        # Additional Tests added
    def testMul2(self):
        opstack.clear()     
        opPush(9)
        opPush("(alice)")
        mul()       
        self.assertEqual(opPop(),"(alice)")
        self.assertEqual(opPop(),9)
    def testMul3(self):
        opstack.clear()
        opPush(5.0)
        opPush(7.0)
        mul()
        self.assertEqual(opPop(),35.0)

    def testDiv(self):
        opstack.clear()
        opPush(4)
        opPush(2)
        div()
        self.assertEqual(opPop(),2)
        
        # Additional Tests added
    def testDiv2(self):
        opstack.clear()     
        opPush(3)
        opPush("(hobby)")
        div()       
        self.assertEqual(opPop(),"(hobby)")
        self.assertEqual(opPop(),3)
    def testDiv3(self):
        opstack.clear()
        opPush(100.0)
        opPush(20.0)
        div()
        self.assertEqual(opPop(),5.0)
    
    def testMod(self):
        opstack.clear()
        opPush(3)
        opPush(2)
        mod()
        self.assertEqual(opPop(),1)
        
        # Additional Tests added
    def testMod2(self):
        opstack.clear()     
        opPush(8)
        opPush("(salutation)")
        mod()       
        self.assertEqual(opPop(),"(salutation)")
        self.assertEqual(opPop(),8)
    def testMod3(self):
        opstack.clear()
        opPush(10)
        opPush(4)
        mod()
        self.assertEqual(opPop(),2)
    def testMod4(self):
        opstack.clear()
        opPush(10.0)
        opPush(4.0)
        mod()
        self.assertEqual(opPop(),2.0)

    def testEq2(self):
        opstack.clear()
        opPush(3)
        opPush(2)
        eq()
        self.assertEqual(opPop(),False)
        
        # Additional Tests added
    def testEq3(self):
        opstack.clear()
        opPush(4.0)
        opPush(4)
        eq()
        self.assertEqual(opPop(),True)
    def testEq4(self):
        opstack.clear()
        opPush({"Literal"})
        opPush(7)
        eq()
        self.assertEqual(opPop(),False)
    def testEq5(self):
        opstack.clear()
        opPush(8.0)
        opPush(8.0)
        eq()
        self.assertEqual(opPop(),True)
    

    def testLt(self):
        opstack.clear()
        opPush(2)
        opPush(3)
        lt()
        self.assertEqual(opPop(),True)
        
        # Additional Tests added
    def testLt2(self):
        opstack.clear()
        opPush({"Literal"})
        opPush(7)
        lt()
        self.assertEqual(opPop(),False)
    def testLt3(self):
        opstack.clear()
        opPush(7.0)
        opPush(8.0)
        lt()
        self.assertEqual(opPop(),True)
    def testLt4(self):
        opstack.clear()
        opPush(9.0)
        opPush(8)
        lt()
        self.assertEqual(opPop(),False)

    def testGt2(self):
        opstack.clear()
        opPush(2)
        opPush(3)
        gt()
        self.assertEqual(opPop(),False)
        
        # Additional Tests added
    def testGt3(self):
        opstack.clear()
        opPush(7)
        opPush({"Literal"})
        gt()
        self.assertEqual(opPop(),False)
    def testGt4(self):
        opstack.clear()
        opPush(8.0)
        opPush(7.0)
        gt()
        self.assertEqual(opPop(),True)

    def testLength(self):
        opstack.clear()
        opPush("(Hello)")
        length()
        self.assertEqual(opPop(),5)
        
         # Additional Tests added
    def testLength2(self):
        opstack.clear()
        opPush("(Constitution)")
        length()
        self.assertEqual(opPop(),12)
    def testLength3(self):
        opstack.clear()
        opPush("()")
        length()
        self.assertEqual(opPop(),0)
    def testLength4(self):
        opstack.clear()
        opPush("(Jump fast)")
        length()
        self.assertEqual(opPop(),9)

    def testGet(self):
        opstack.clear()
        opPush("(CptS355)")
        opPush(0)
        get()
        self.assertEqual(opPop(),ord('C'))
        
        # Additional Tests added
    def testGet2(self):
        opstack.clear()
        opPush("(Consult)")
        opPush(3)
        get()
        self.assertEqual(opPop(),ord('s'))
    def testGet3(self):
        opstack.clear()
        opPush({"Literature"})
        opPush(0)
        get()
        self.assertEqual(opPop(),None)

    def testGetInterval(self):
        opstack.clear()
        opPush("(CptS355)")
        opPush(0)
        opPush(3)
        getinterval()
        self.assertEqual(opPop(),"(Cpt)")
        
         # Additional Tests added
    def testGetInterval2(self):
        opstack.clear()
        opPush("(Constitution)")
        opPush(6)
        opPush(6)
        getinterval()
        self.assertEqual(opPop(),"(tution)")
    def testGetInterval3(self):
        opstack.clear()
        opPush("(JumpFastGradually)")
        opPush(7)
        opPush(10)
        getinterval()
        self.assertEqual(opPop(),"(tGradually)")
    def testGetInterval4(self):
        opstack.clear()
        opPush({"Literature"})
        opPush(0)
        opPush(0)
        getinterval()
        self.assertEqual(opPop(),None)

    def testPut(self):
        opstack.clear()
        opPush("(CptS355)")
        dup()
        opPush(0)
        opPush(48)
        put()
        self.assertEqual(opPop(),"(0ptS355)")
        
         # Additional Tests added
    def testPut2(self):
        opstack.clear()
        opPush("(JumpFastGradually)")
        dup()
        opPush(9)
        opPush(57)
        put()
        self.assertEqual(opPop(),"(JumpFastG9adually)")
    def testPut3(self):
        opstack.clear()
        opPush("(Constitution)")
        dup()
        opPush(5)
        opPush(87)
        put()
        self.assertEqual(opPop(),"(ConstWtution)")
    def testPut4(self):
        opstack.clear()
        opPush({"Literature"})
        opPush(5)
        opPush(87)
        put()
        self.assertEqual(opPop(),None)

    def testDup(self):
        opstack.clear()
        opPush(3)
        dup()
        self.assertEqual(len(opstack),2)
        
         # Additional Tests added
    def testDup2(self):
        opstack.clear()
        opPush(10)
        dup()
        dup()
        dup()
        self.assertEqual(len(opstack),4)
    def testDup3(self):
        opstack.clear()
        dup()
        self.assertEqual(len(opstack),0)
    def testDup4(self):
        opstack.clear()
        opPush(5)
        dup()
        self.assertEqual(len(opstack),2)
        self.assertEqual(opPop(),5)
        self.assertEqual(opPop(),5)
    def testDup5(self):
        opstack.clear()
        opPush(10)
        dup()
        opPush("hi")
        dup()
        self.assertEqual(len(opstack),4)
        self.assertEqual(opPop(),"hi")
        self.assertEqual(opPop(),"hi")
        self.assertEqual(opPop(), 10)
        self.assertEqual(opPop(), 10)

    def testPop(self):
        opstack.clear()
        opPush(1)
        pop()
        self.assertEqual(len(opstack),0)
        
        # Additional Tests added
    def testPop2(self):
        opstack.clear()
        opPush(10)
        opPush(100)
        opPush(50)
        opPush(75)
        opPush(25)
        pop()
        self.assertEqual(len(opstack),4)
    def testPop3(self):
        opstack.clear()
        opPush(22)
        pop()
        opPush(33)
        pop()
        opPush(55)
        pop()
        opPush(44)
        opPush(77)
        self.assertEqual(len(opstack),2)
    def testPop4(self):
        opstack.clear()
        opPush(7)
        opPush(8)
        pop()
        self.assertEqual(len(opstack),1)
        self.assertEqual(opPop(), 7)
    
    def testClear(self):
        opstack.clear()
        opPush(1)
        clear()
        self.assertEqual(len(opstack),0)
    
        # Additional Tests added
    def testClear2(self):
        opstack.clear()
        opPush(10)
        opPush(20)
        clear()
        self.assertEqual(len(opstack),0)
    def testClear3(self):
        opstack.clear()
        opPush(7)
        clear()
        opPush(8)
        clear()
        self.assertEqual(len(opstack),0)
    def testClear4(self):
        opstack.clear()
        opPush(9.0)
        clear()
        opPush(11.0)
        clear()
        opPush(12.0)
        self.assertEqual(len(opstack),1)

    def testExch(self):
        opstack.clear()
        opPush(1)
        opPush(2)
        exch()
        self.assertListEqual(opstack,[2,1])
        
        # Additional Tests added
    def testExch3(self):
        opstack.clear()
        opPush(4.0)
        opPush(5.0)
        exch()
        self.assertListEqual(opstack,[5.0,4.0])
    def testExch4(self):
        opstack.clear()
        opPush(8)
        opPush(9)
        exch()
        exch()
        exch()
        exch()
        self.assertListEqual(opstack,[8,9])

    def testRoll(self):
        opstack.clear()
        opPush(1)
        opPush(2)
        opPush(3)
        opPush(4)
        opPush(2)
        opPush(3)
        roll()
        self.assertListEqual(opstack,[1,2,4,3])
        
        # Additional Tests added
    def testRoll2(self):
        opstack.clear()
        opPush(9)
        opPush(8)
        opPush(7)
        opPush(6)
        opPush(9)
        opPush(7)
        opPush(8)
        opPush(5)
        opPush(4)
        roll()
        self.assertListEqual(opstack,[9, 8, 7, 8, 7, 9, 6])
    def testRoll3(self):
        opstack.clear()
        opPush(2)
        opPush(3)
        opPush(4)
        opPush(5)
        opPush(6)
        opPush(7)
        opPush(1)
        opPush(0)
        roll()
        self.assertListEqual(opstack,[2,3,4,5,6,7])
        
    def testRoll4(self):
        opstack.clear()
        opPush("z")
        opPush("y")
        opPush("x")
        opPush("w")
        opPush(3)
        opPush(2)
        roll()
        self.assertListEqual(opstack,["z","y","w","x"])
    
    def testStack(self):
       # pass # unsure how to test print, maybe have it return instead
        text_trap = io.StringIO()
        sys.stdout = text_trap
        opstack.clear()
        opPush(2)
        opPush(3)
        stack()
        sys.stdout = sys.__stdout__
        self.assertEqual(text_trap.getvalue(), "3\n2\n")
        
         # Additional Tests added
    def testStack2(self):
       # pass # unsure how to test print, maybe have it return instead
        text_trap = io.StringIO()
        sys.stdout = text_trap
        opstack.clear()
        opPush(55.0)
        opPush(11.0)
        opPush(77.0)
        stack()
        sys.stdout = sys.__stdout__
        self.assertEqual(text_trap.getvalue(), "77.0\n11.0\n55.0\n")
    def testStack3(self):
       # pass # unsure how to test print, maybe have it return instead
        text_trap = io.StringIO()
        sys.stdout = text_trap
        opstack.clear()
        opPush(14)
        opPop()
        opPush("nice")
        stack()
        sys.stdout = sys.__stdout__
        self.assertEqual(text_trap.getvalue(), "nice\n")

    def testPsDict(self):
        opstack.clear()
        opPush(2)
        psDict()
        self.assertIsInstance(opPop(), dict)
        
         # Additional Tests added
    def testPsDict2(self):
        opstack.clear()
        opPush(5)
        psDict()
        self.assertTrue(isinstance(opstack[-1], dict)) 
        self.assertEqual(len(opstack), 1) 
    def testPsDict3(self):
        opstack.clear()
        opPush("hi")
        psDict()
        self.assertEqual(opPop(), {}) 

    def testPsDef(self):
        opstack.clear()
        dictstack.clear()
        opPush(2)
        psDict()
        begin()
        opPush("/a")
        opPush(2)
        psDef()
        self.assertEqual(dictstack[-1],{"/a":2})
        
        # Additional Tests added
    def testPsDef2(self):
        opstack.clear()
        dictstack.clear()
        dictPush({})
        opPush("/albert")
        opPush(77)
        psDef()
        dictPush({})
        opPush("/benedict")
        opPush(88.1)
        psDef()
        dictPush({})
        opPush("/celine")
        opPush(99)
        psDef()
        self.assertEqual(lookup('benedict'),88.1)
        self.assertEqual(lookup('celine'),99)
        self.assertEqual(lookup('albert'),77)
        self.assertEqual(dictstack[-1],{"/celine":99})
        self.assertEqual(dictstack[-2],{"/benedict":88.1})
        self.assertEqual(dictstack[-3],{"/albert":77})
    def testPsDef3(self):
        opstack.clear()
        dictstack.clear()
        begin()
        opPush("/clarisse")
        opPush(12.5)
        psDef()
        opPush("/bobby")
        opPush(24.5)
        psDef()
        self.assertEqual(dictstack[-1],{"/clarisse":12.5,"/bobby":24.5})
        
         # Additional Tests added
    def testBeginEnd1(self):
        opstack.clear()
        dictstack.clear()
        psDict()
        begin()
        opPush("/a")
        opPush(7)
        psDef()
        end() 
        opPush(5)
        self.assertEqual(opPop(),5)
        self.assertEqual(opPop(),None)
    def testBeginEnd2(self):
        opstack.clear()
        dictstack.clear()
        psDict()
        begin()
        opPush("/a")
        opPush(7)
        psDef()
        end() 
        begin()
        opPush("/b")
        opPush(14)
        psDef() 
        end() 
        self.assertEqual(opPop(),None)

         # Additional Tests added
    def testCopy(self):
        opstack.clear()
        dictstack.clear()
        opPush(1)
        opPush(1)
        opPush(4)
        opPush(4)
        copy()
        self.assertTrue(opPop() == 4)
    def testCopy2(self):
        opstack.clear()
        dictstack.clear()
        opPush(5)
        opPush(3)
        opPush(1)
        opPush(3)
        opPush(2)
        copy()
        self.assertTrue(opPop() == 3)
    
   # extra
   
    # def testAddExtra():
    #     opPush(1)
    #     opPush(2)
    #     add()
    #     if opPop() != 3:
    #         return False
    #     return True
    
    # def testLookupExtra():
    #     opPush("/n1")
    #     opPush(3)
    #     psDef()
    #     if lookup("n1") != 3:
    #         return False
    #     return True 



if __name__ == '__main__':
    unittest.main()