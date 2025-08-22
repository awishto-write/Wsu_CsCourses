import sys
import io
import unittest
from HW5 import *

input1 = """
        /square {
               dup mul
        } def
        (square)
        4 square
        dup 16 eq
        {(pass)} {(fail)} ifelse
        stack
        """

input2 ="""
    (facto) dup length /n exch def
    /fact {
        0 dict begin
           /n exch def
           n 2 lt
           { 1}
           {n 1 sub fact n mul }
           ifelse
        end
    } def
    n fact stack
    """

input3 = """
        /fact {
        0 dict
                begin
                        /n exch def
                        1
                        n -1 1 { mul } for
                end
        } def
        6
        fact
        stack
    """

input4 = """
        /lt6 { 6 lt } def
        1 2 3 4 5 6 4 -3 roll
        dup dup lt6 {mul mul mul} if
        stack
        clear
    """

input5 = """
        (CptS355_HW5) 4 3 getinterval
        (355) eq
        {(You_are_in_CptS355)} if
         stack
        """

input6 = """
        /pow2 {/n exch def
               (pow2_of_n_is) dup 8 n 48 add put
                1 n -1 1 {pop 2 mul} for
              } def
        (Calculating_pow2_of_9) dup 20 get 48 sub pow2
        stack
        """

class HW5Tests(unittest.TestCase):

    def testParseInput1(self):
        print(tokenize(input1))
        print(parse(tokenize(input1)))

    def testInput1(self):
        text_trap = io.StringIO()
        sys.stdout = text_trap
        opstack.clear()
        dictstack.clear()
        interpreter(input1)
        sys.stdout = sys.__stdout__
        self.assertEqual(text_trap.getvalue(), "(pass)\n16\n(square)\n")

    def testInput2(self):
        text_trap = io.StringIO()
        sys.stdout = text_trap
        opstack.clear()
        dictstack.clear()
        interpreter(input2)
        sys.stdout = sys.__stdout__
        self.assertEqual(text_trap.getvalue(), "120\n(facto)\n")

    def testInput3(self):
        text_trap = io.StringIO()
        sys.stdout = text_trap
        opstack.clear()
        dictstack.clear()
        interpreter(input3)
        sys.stdout = sys.__stdout__
        self.assertEqual(text_trap.getvalue(), "720\n")

    def testInput4(self):
        text_trap = io.StringIO()
        sys.stdout = text_trap
        opstack.clear()
        dictstack.clear()
        interpreter(input4)
        sys.stdout = sys.__stdout__
        self.assertEqual(text_trap.getvalue(), "300\n6\n2\n1\n")
    
    def testInput5(self):
        text_trap = io.StringIO()
        sys.stdout = text_trap
        opstack.clear()
        dictstack.clear()
        interpreter(input5)
        sys.stdout = sys.__stdout__
        self.assertEqual(text_trap.getvalue(), "(You_are_in_CptS355)\n")

    def testInput06(self):
        text_trap = io.StringIO()
        sys.stdout = text_trap
        opstack.clear()
        dictstack.clear()
        interpreter(input6)
        sys.stdout = sys.__stdout__
        self.assertEqual(text_trap.getvalue(), "512\n(pow2_of_9_is)\n(Calculating_pow2_of_9)\n")


if __name__ == '__main__':
    unittest.main()