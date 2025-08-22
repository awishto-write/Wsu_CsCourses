import sys
from psparser import read
from psoperators import PSOperators
from colors import *

testinput1 = """
/x 4 def
/g { x stack } def
/f { /x 7 def g } def
f
"""
testinput2 = """
/x 4 def
(static_y) dup 7 120 put /x exch def
/g { x stack } def
/f { /x (dynamic_x) def g } def
f
"""
testinput3 = """
/m 50 def
/n 100 def
/egg1 {/m 25 def n} def
/chic
{ /n 1 def
/egg2 { (egg2) n stack} def
n m
egg1
m
egg2
} def
n
chic
"""
testinput4 = """
/x 10 def
/A { x } def
/C { /x 40 def A stack } def
/B { /x 30 def /A { x 2 mul } def C } def
B
"""
testinput5 = """
/x 2 def
/n 5 def
/A { 1 n -1 1 {pop x mul} for} def
/C { /n 3 def /x 40 def A stack } def
/B { /x 30 def /A { x } def C } def
B
"""
testinput6 = """
/out true def
/xand { true eq {pop false} {pop true} ifelse dup /x exch def stack} def
/myput { out dup /x exch def xand } def
/f { /out false def myput } def
false f
"""
testinput7 = """
/x 1 dict def
x /i 22 put
/A { (global) x /i get } def
/C { /x 1 dict def x /i 33 put A stack } def
/B { /x 1 dict def x /i 11 put /A { (function B) x /i get } def C } def
B
"""
testinput8 = """
/x 1 dict def
/a 10 def
/A { x /m 0 put } def
/C { /x 1 dict def x /m 9 put A a x /m get stack } def
/B { /x 1 dict def /A { x /m 99 put } def /a 5 def C } def
B
"""                                         

testinput9 = """
/a 5 def
/b 8 def
/d { b stack } def
/e { /b 17 def d } def
e
"""
testinput10 = """
/a { 7 x add } def
/b 1 def
/x b def
/d { /b 3 def x a mul stack } def
/e {
    /x b def
    /add {1 num add } def
    d
   }def
   e
""" 
testinput11 = """
/x 9 def
/y {x x x x x mul mul mul mul } def
/z {/x 11 def y /a {x} def /b {x} def stack a b } def
z
"""

tests = [testinput1,testinput2,testinput3,testinput4,testinput5,testinput6,testinput7,
         testinput8, testinput9, testinput10, testinput11]

# program start
if __name__ == '__main__':
   ps_env_s = PSOperators("static")
   ps_env_d = PSOperators("dynamic")
   testnum = 1
   for testcase in tests:
        try:
           print("\n-- TEST {} --".format(testnum))
           expr_list = read(testcase)
           print("\nSTATIC")
           # interpret using static scoping rule
           for expr in expr_list:
               expr.eval(ps_env_s)
           print("\nDYNAMIC")
           # interpret using dynamic scoping rule
           for expr in expr_list:
               expr.eval(ps_env_d)
           # clear the Stack objects
        except (SyntaxError, NameError, TypeError, Exception) as err:
            print(type(err).__name__ + ':', err)
        testnum += 1
        # clear the Stack objects
        ps_env_s.clearBoth()
        ps_env_d.clearBoth()