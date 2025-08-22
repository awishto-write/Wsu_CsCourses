import math
from pyeda.inter import * 

# 3.1

def EVEN(n):
    v = exprvar('v', 5)
    cond = (v & expr(n))
    
    return bool(cond and ((n % 2) == 0))
    

def PRIME(n):
    u = exprvar('v', 5)
    cond = (u & expr(n))
    result = True
    
    if n < 3: # The primne number does not include 3 like what is stated in the directions
        result = False
    for i in range(3, int(math.sqrt(n)) + 1, 2): # The primne number does not include 3 like what is stated in the directions
        if n % i == 0:
            result = False
    
    return bool(cond and result)   

def RR(i, j):
    u = exprvar('u', 5)   #2^5 = 32 - 0 to 31
    v = exprvar('v', 5)

    cond1 = (u & expr(i))
    cond2 = (v & expr(j))
    cond3 = ( ((i + 3) % 32) == (j % 32) )
    cond4 = ( ((i + 8) % 32) == (j % 32))

    return bool((cond1 and cond2) and (cond3 or cond4))  

print("RR(27,3)", RR(27,3))
print("RR(16,20)", RR(16,20))
print("EVEN(14)", EVEN(14))  
print("EVEN(13)", EVEN(13))   
print("PRIME(7)", PRIME(7))
print("PRIME(2)", PRIME(2))        

# 3.2

def RR2(i, j):
    u = exprvar('u', 5)   #2^5 = 32 - 0 to 31
    v = exprvar('v', 5)

    cond1 = (u & expr(i))
    cond2 = (v & expr(j))
    result = False
    
    for n in range(32):
        if RR(i, n) and RR(n, j):
            result = True
            break
        
    return bool( (cond1 and cond2) and result)

print("RR2(27,6)", RR2(27,6))
print("RR2(27,9)", RR2(27,9))

# 3.3

def RR2star(i, j):
    u = exprvar('u', 5)   #2^5 = 32 - 0 to 31
    v = exprvar('v', 5)
    cond1 = (u & expr(i))
    cond2 = (v & expr(j))
    
    reachability = [[False] * 32 for row in range(32)]
    reachability[i][j] = RR2(i, j)
    
    for n in range(32):
        reachability[i][j] |= reachability[i][n] & reachability[n][j]

    return bool( (cond1 and cond2) and (reachability[i][j]))

print("RR2star(27,6)", RR2star(27,6))
print("RR2star(27,9)", RR2star(27,9))

# 3.4

def stat():
    u = exprvar('u', 5)  # 2^5 = 32 - 0 to 31
    v = exprvar('v', 5)
    statementA = expr(True)
        
    for uValue in range(32):
        exists_v = expr(False)

        for vValue in range(32):
            cond1 = (u & expr(uValue))
            cond2 = (v & expr(vValue))
            
            exists_v |= expr(EVEN(vValue)) & RR2star(uValue, vValue)
        statementA &= (PRIME(uValue) & exists_v)

    return bool( (cond1 and cond2) and statementA)

print("Statement A results in:", stat())
   
         #
# I was planning on using more Pyeda functions and elements, but 
# almost none of them were working and I tried for days. However, Pyeda is installed
# on my device as well as pylance and python3. I am sorry.

# x0, x1, x2, x3 = pyeda.bddvars('x', 5)
# y0, y1, y2, y3 = pyeda.bddvars('y', 5)