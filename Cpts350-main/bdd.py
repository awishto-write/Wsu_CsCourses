import math
from pyeda.inter import *
#from pyeda.inter import expr, exprvar

"""step3.1. Obtain BDDs RR, EVEN , PRIME for the finite sets R, [even], [prime] , respectively.
Pay attention to the use of BDD variables in your BDDs. 
"""

def EVEN(n):
   return (n % 2) == 0

def PRIME(n):
    if n < 3: # The primne number does not include 3 like what is stated in the directions
        return False
    for i in range(3, int(math.sqrt(n)) + 1, 2): # The primne number does not include 3 like what is stated in the directions
        if n % i == 0:
            return False
    return True
    
# def RR(i, j):
#     return (i + 3) % 32 == (j % 32) or (i + 8) % 32 == (j % 32) 

def RR(i, j):
    condition1 = (i + 3) % 32 == (j % 32)
    condition2 = (i + 8) % 32 == (j % 32)
    return exprvar(f"RR_({i})") & exprvar(f"RR_({j})") & (condition1 | condition2)

i = 27
j = 3
result = RR(i, j)
print(result)

print(RR(27,3))

print("RR(27,3)", RR(27,3))
print("RR(16,20)", RR(16,20))
print("EVEN(14)", EVEN(14))  
print("EVEN(13)", EVEN(13))   
print("PRIME(7)", PRIME(7))
print("PRIME(2)", PRIME(2))        


""" step3.2. Compute BDD RR2 for the set R ◦ R, from BDD RR. Herein, RR2 encodes the set of
node pairs such that one can reach the other in two steps. Your code shall also verify the following
test cases:
RR2(27, 6) is true; RR2(27, 9) is false. 
"""

# def RR2(i, j):
#     if RR(i, j): # return that one case
#         return True
#     for n in range(32): # or range(0, 32)   # or return this other case
#         if RR(i,n) and RR(n,j):
#             return True
#     return False

def RR2(i, j):
    n = 32
    rr2 = expr(False)

    for x in range(n):
        for y in range(n):
            if RR(x, y):
                rr2 |= exprvar(f"RR({x}, {y})")

    return rr2.compose({f"RR({i}, {j})"})

  
print("RR2(27,6)", RR2(27,6))
print("RR2(27,9)", RR2(27,9))
print(" ")

""" step3.3. Compute the transitive closure RR2star of RR2. Herein, RR2star encodes the set of
all node pairs such that one can reach the other in a positive even number of steps.
"""

# def RR2star(i, j):
#     reach = [[False] * 32 for _ in range(32)] # 2D matrix initialization
#     #reach = [[False for _ in range(32)] for _ in range(32)]
    
#     # Use of RR2
#     for m in range(32):
#         for n in range(32):
#             reach[m][n] = RR2(m,n)
#             # if RR2(m,n):
#             #     reach[m][n] = True
                
#     # Compute the transitive closure - Floyd Warshall Algorithm
#     for o in range(32):
#         for m in range(32):
#             for n in range(32):
#                 # if not reach[m][n] and reach[m][o] and reach[o][n]:
#                    #reach[m][n] = True
#                 reach[m][n] |= (reach[m][o] and reach[o][n])
#                 #reach[m][n] = reach[m][n] or (reach[m][o] and reach[o][n])
                
#     return reach[i][j]

def RR2star(i, j):
    n = 32

    # Create BDDs for RR2
    rr2 = expr(False)
    for x in range(n):
        for y in range(n):
            if RR2(x, y):
                # Convert the indices to strings for variable names
                rr2 |= exprvar(f"({x}, {y})")

    # Compute the transitive closure using BDD operations
    reach = rr2
    for k in range(n):
        reach |= reach & (reach.compose({f"({x}, {k})": f"({i}, {j})"}) & reach.compose({f"({k}, {y})": f"({i}, {j})"}))

    # Check if the given pair (i, j) can reach each other in a positive even number of steps
    return reach.compose({f"({i}, {j})"})


print(RR2star(27,6))
print(RR2star(27,9))


""" step3.4. Here comes the most difficult part. We first StatementA formally:
∀u. (P RIM E(u) → ∃v. (EV EN (v) ∧ RR2star(u, v))).
There are two quantifiers in StatementA: one is ”for each”, and the other is ”there is”. First,
from what you have learned from math216 (discrete math), ”for each” can be expressed through
”there is”. Second, ”there is” can be implemented using existential quantifier elimination method
BDD.smoothing(). As a result, the entire StatementA is a BDD without free variables and hence
it is either true or false. Return the truth value.
Many students find methods BDD.compose() and BDD.smoothing() are quite useful in the package.
"""

# def stat():
#     u = exprvar('u', 5)  # 2^5 = 32 - 0 to 31
#     v = exprvar('v', 5)

#     # Build StatementA using the provided functions and quantifiers
#     statementA = expr(True)

#     for u_val in range(32):
#         u_expr = expr(u_val)
#         exists_v = expr(False)

#         for v_val in range(32):
#             v_expr = expr(v_val)
#             exists_v |= expr(EVEN(v_val)) & RR2star(u_val, v_val)

#         statementA &= (PRIME(u_val) & exists_v)

#     return bool(statementA)

# print("Statement A results in:", stat())

      ##

# def stat():
#     u = exprvar('u', 5)   #2^5 = 32 - 0 to 31
#     v = exprvar('v', 5)

#    # Build StatementA using the provided functions and quantifiers
#     statementA = expr(True)
#     #u_expr = expr(u)
#     exists_v = expr(False)
#    # v_expr = expr(v)
      
#             #
#     # cond1 = expr(u)
#     # cond2 = expr(v)
#            #
    
#     # exists_v |= expr(EVEN(v)) & RR2star(u, v)
#     # statementA &= (PRIME(u) & exists_v)
    
#     # exists_v |= expr(EVEN(cond2)) & RR2star(cond1, cond2)
#     # statementA &= (PRIME(cond1) & exists_v)
    
#     exists_v |= expr(EVEN(v)) & RR2star(u, v)
#     statementA &= (PRIME(u) & exists_v)

#     #return is_true = bool(statementA)
#     return bool(statementA)
#     #return bool(statementA and cond1 and cond2)

# print("Statement A results in:", stat())

     ## 
     
# def stat():
#     u = exprvar('u', 5)  # 2^5 = 32 - 0 to 31
#     v = exprvar('v', 5)

#     # Build StatementA using the provided functions and quantifiers
#     statementA = expr(True)

#     for u_val in range(32):
#         u_expr = expr(u_val)
#         exists_v = expr(False)

#         for v_val in range(32):
#             v_expr = expr(v_val)
#             exists_v |= expr(EVEN(v_val)) & RR2star(u_val, v_val)

#         statementA &= (PRIME(u_val) & exists_v)

#     return bool(statementA)

# print("Statement A results in:", stat())

              ##
       
statementA = expr(True)
for u_val in range(32):
    u_expr = expr(u_val)
    
    # Implement the "there is" quantifier using OR
    exists_v = expr(False)
    for v_val in range(32):
        v_expr = expr(v_val)
        exists_v |= expr(EVEN(v_val)) & RR2star(u_val, v_val)
    
     # Combine the quantified statements with "for each" quantifier using AND
   # statementA &= (PRIME(u_val) >> exists_v)
    statementA &= (PRIME(u_val) & exists_v)

# Check if StatementA is valid
is_true = statementA.is_one()
print("Statement A results in:", is_true)

def stat():
    u = exprvar('u', 5)  # 2^5 = 32 - 0 to 31
    v = exprvar('v', 5)

    # Build StatementA using the provided functions and quantifiers
    statementA = expr(True)
        
    for u_val in range(32):
      #  u_expr = u(u_val)
        exists_v = expr(False)

        for v_val in range(32):
        #     v_expr = v(v_val)
        #     exists_v |= expr(EVEN(v_expr)) & RR2star(u_expr, v_expr)

        # statementA &= (PRIME(u_expr) & exists_v)
         
            exists_v |= expr(EVEN(v_val)) & RR2star(u_val, v_val)
        statementA &= (PRIME(u_val) & exists_v)

    return bool(statementA)

print("Statement A results in:", stat())
