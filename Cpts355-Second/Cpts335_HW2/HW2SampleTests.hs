{-Haskell is available for Windows, Mac, and Linux. Here's the download page: https://www.haskell.org/downloads/.
We will be using the HUnit unit testing package in CptS 355.

Example of using the HUnit unit test framework.  See  http://hackage.haskell.org/package/HUnit for additional documentation.
To run the tests type "runTestTT tests" at the Haskell prompt.  -}

module HW2SampleTests
    where

import Test.HUnit
import Data.Char
import HW2

{- Two useful functions in the HUnit package are assertEqual and assertBool.
The arguments to 'assertEqual' are:
      a descriptive string
      the expected value
      the value being tested
The arguments to 'assertBool' are:
      a descriptive string
      the boolean value being tested
-}

p1a_test1 = TestCase (assertEqual "merge2 [2,5,6,8,9] [1,3,4,5,7,8,10]" [1,2,3,4,5,5,6,7,8,8,9,10]  (merge2 [2,5,6,8,9] [1,3,4,5,7,8,10]) )
-- Additional test cases for p1_a
p1a_test2 = TestCase (assertEqual "merge2 [-10,-7,-4,1,3,5] [0,2,3,4,5,6,9,11]" [-10,-7,-4,0,1,2,3,3,4,5,5,6,9,11]  (merge2 [-10,-7,-4,1,3,5] [0,2,3,4,5,6,9,11]) )
p1a_test3 = TestCase (assertEqual "merge2 [15,20,25,30,35,40] [7,14,21,25,32]" [7,14,15,20,21,25,25,30,32,35,40]  (merge2 [15,20,25,30,35,40] [7,14,21,25,32]) )
p1a_test4 = TestCase (assertEqual "merge2 \"abc\" \"def\"" "abcdef" (merge2 "abc" "def") ) 
p1a_test5 = TestCase (assertEqual "merge2 [] [30,31]" [30,31]  (merge2 [] [30,31]) )
p1a_test6 = TestCase (assertEqual "merge2 \"suwy\" \"noqt\"" "noqstuwy" (merge2 "suwy" "noqt") ) 

p1b_test1 = TestCase (assertEqual "merge2Tail [2,5,6,8,9] [1,3,4,5,7,8,10]" [1,2,3,4,5,5,6,7,8,8,9,10]  (merge2Tail [2,5,6,8,9] [1,3,4,5,7,8,10]) )
-- Additional test cases for p1_b
p1b_test2 = TestCase (assertEqual "merge2Tail [-10,-7,-4,1,3,5] [0,2,3,4,5,6,9,11]" [-10,-7,-4,0,1,2,3,3,4,5,5,6,9,11]  (merge2Tail [-10,-7,-4,1,3,5] [0,2,3,4,5,6,9,11]) )
p1b_test3 = TestCase (assertEqual "merge2Tail [15,20,25,30,35,40] [7,14,21,25,32]" [7,14,15,20,21,25,25,30,32,35,40]  (merge2Tail [15,20,25,30,35,40] [7,14,21,25,32]) )
p1b_test4 = TestCase (assertEqual "merge2Tail \"abc\" \"def\"" "abcdef" (merge2Tail "abc" "def") ) 
p1b_test5 = TestCase (assertEqual "merge2Tail [] [30,31]" [30,31]  (merge2Tail [] [30,31]) )
p1b_test6 = TestCase (assertEqual "merge2Tail \"suwy\" \"noqt\"" "noqstuwy" (merge2Tail "suwy" "noqt") )

p1c_test1 = TestCase (assertEqual "mergeN [[3,4],[-3,-2,-1],[1,2,5,8,9]]" [-3,-2,-1,1,2,3,4,5,8,9]  (mergeN [[3,4],[-3,-2,-1],[1,2,5,8,9]]) )
-- Additional test cases for p1_c
p1c_test2 = TestCase (assertEqual "mergeN [[-9,-7,10,25],[],[-8,19,19,24]]" [-9,-8,-7,10,19,19,24,25]  (mergeN [[-9,-7,10,25],[],[-8,19,19,24]]) )
p1c_test3 = TestCase (assertEqual "mergeN [[\"H\",\"n\"],[\"h\"],[\"n\",\"o\"],[\"k\",\"p\"]]" ["H","h","k","n","n","o","p"]  (mergeN [["H","n"],["h"],["n","o"],["k","p"]]) )

p2a_test1 = TestCase (assertEqual "getInRange (-5) 5 [10,5,0,1,2,-5,-10]" [0,1,2]  (getInRange (-5) 5 [10,5,0,1,2,-5,-10]) )
p2a_test2 = TestCase (assertEqual "getInRange (-1) 1 [-2,2,3,4,5]" [] (getInRange (-1) 1 [-2,2,3,4,5]) )
-- Additional test cases for p2_a
p2a_test3 = TestCase (assertEqual "getInRange 18 31 [-4,3,7,14,21,23,25,27,31,35,37]" [21,23,25,27]  (getInRange 18 31 [-4,3,7,14,21,23,25,27,31,35,37]) )
p2a_test4 = TestCase (assertEqual "getInRange (-11) 53 [-15,-12,-11,-9,0,9,19,29,48,51,56]" [-9,0,9,19,29,48,51]  (getInRange (-11) 53 [-15,-12,-11,-9,0,9,19,29,48,51,56]) )
p2a_test5 = TestCase (assertEqual "getInRange 'g' 'x' \"abdmopuvyz\"" "mopuv"  (getInRange 'g' 'x' "abdmopuvyz") )

p2b_test1 = TestCase (assertEqual "countInRange 3 10 [[1,2,3,4],[5,6,7,8,9],[10,11]]" 6 (countInRange 3 10 [[1,2,3,4],[5,6,7,8,9],[10,11]]) )
p2b_test2 = TestCase (assertEqual "countInRange (-5) 5 [[-10,-5,-4],[0,4,5],[],[10]]" 3 (countInRange (-5) 5 [[-10,-5,-4],[0,4,5],[],[10]]) )
-- Additional test cases for p2_b
p2b_test3 = TestCase (assertEqual "countInRange (-9) 19 [[-12,-11,-9,-8],[],[2,3],[17,18],[19,20,21,22]]" 5 (countInRange (-9) 19 [[-12,-11,-9,-8],[],[2,3],[17,18],[19,20,21,22]]) )
p2b_test4 = TestCase (assertEqual "countInRange 14 27 [[1,2,14,15,16],[17,18,19,20],[23,24,25],[27,28,29]]" 9 (countInRange 14 27 [[1,2,14,15,16],[17,18,19,20],[23,24,25],[27,28,29]]) )
p2b_test5 = TestCase (assertEqual "countInRange 'g' 'x' \"abdmopuvyz\"" 5 (countInRange 'g' 'x' ["abdmopuvyz"]) )

p3a_test1 = TestCase (assertEqual "addLengths (FOOT 2) (INCH 5)" (INCH 29) (addLengths (FOOT 2) (INCH 5)) )
p3a_test2 = TestCase (assertEqual "addLengths (YARD 3) (INCH (-3))"  (INCH 105) (addLengths (YARD 3) (INCH (-3))) )
-- Additional test cases for p3_a
p3a_test3 = TestCase (assertEqual "addLengths (YARD 10) (FOOT 3)" (INCH 396) (addLengths (YARD 10) (FOOT 3)) ) 
p3a_test4 = TestCase (assertEqual "addLengths (INCH 14) (INCH (-8))" (INCH 6) (addLengths (INCH 14) (INCH (-8)))) 
p3a_test5 = TestCase (assertEqual "addLengths (FOOT 7) (YARD 10)" (INCH 444) (addLengths (FOOT 7) (YARD 10)) )

p3b_test1 = TestCase (assertEqual "addAllLengths [[YARD 2, FOOT 1], [YARD 1, FOOT 2, INCH 10],[YARD 3]]" (INCH 262) (addAllLengths [[YARD 2, FOOT 1], [YARD 1, FOOT 2, INCH 10],[YARD 3]]) )
-- Additional test cases for p3_b
p3b_test2 = TestCase (assertEqual "addAllLengths [[INCH 9, YARD 3],[INCH 5, FOOT 8],[YARD 8, FOOT (-7)]]" (INCH 422) (addAllLengths [[INCH 9, YARD 3],[INCH 5, FOOT 8],[YARD 8, FOOT (-7)]]) )
p3b_test3 = TestCase (assertEqual "addAllLengths [[FOOT (-3),INCH 10],[INCH (-2)],[YARD 5, FOOT 4],[]]" (INCH 200) (addAllLengths [[FOOT (-3),INCH 10],[INCH (-2)],[YARD 5, FOOT 4],[]]) )

p4a_test1 = TestCase (assertEqual ("sumTree "++(show t1)) 32 (sumTree t1) )
-- Additional test cases for p4_a
p4a_test2 = TestCase (assertEqual ("sumTree "++(show treeExample2)) 128 (sumTree treeExample2) )
p4a_test3 = TestCase (assertEqual ("sumTree "++(show treeExample3)) 90 (sumTree treeExample3) )
p4a_test4 = TestCase (assertEqual ("sumTree "++(show (LEAF 5))) 5 (sumTree (LEAF 5)) )

t1_output = NODE 32 (NODE 15 (NODE 9 (LEAF 4) (LEAF 5)) (LEAF 6)) (NODE 17 (LEAF 8) (LEAF 9))
-- Additional outputs for p4_b
treeExample2_output = NODE 128 (NODE 36 (NODE 2 (LEAF (-12)) (LEAF 14)) (NODE 34 (LEAF 16) (LEAF 18))) (NODE 92 (NODE 42 (LEAF 20) (LEAF 22)) (NODE 50 (LEAF 24) (LEAF 26)))
treeExample3_output = NODE 90 (NODE 46 (NODE 28 (NODE 12 (NODE 8 (LEAF 2) (LEAF 6)) (NODE 4 (LEAF (-7)) (LEAF 11))) (LEAF 16)) (LEAF 18)) (NODE 44 (LEAF 21) (LEAF 23))

p4b_test1 = TestCase (assertEqual ("createSumTree "++ (show t1)) (t1_output) (createSumTree t1) )
-- Additional test cases for p4_b
p4b_test2 = TestCase (assertEqual ("createSumTree "++ (show treeExample2)) (treeExample2_output) (createSumTree treeExample2) )
p4b_test3 = TestCase (assertEqual ("createSumTree "++ (show treeExample3)) (treeExample3_output) (createSumTree treeExample3) )

p5_test1 = TestCase (assertEqual ("foldListTree (+) 0 "++ (show t4)) 36 (foldListTree (+) 0 t4 ) )
p5_test2 = TestCase (assertEqual ("foldListTree (++) \"\" "++ (show t5)) "School-of-Electrical-Engineering-and-Computer-Science-WSU" (foldListTree (++) "" t5) )
-- Additional test cases for p5
p5_test3 = TestCase (assertEqual ("foldListTree (++) \"\" "++ (show t6)) "Cpts355~is~the~best" (foldListTree (++) "" t6) )
p5_test4 = TestCase (assertEqual ("foldListTree (++) \"\" "++ (show t7)) "Cpts355~is~the~best~CS~course" (foldListTree (++) "" t7) )

-- Tests for problem 6
p6_test1 = TestCase (assertEqual ("sumTree "++(show tree1)) 215 (sumTree tree1) )

tree1_output = NODE 215 (NODE 61 (LEAF 15) 
                                  (NODE 46 
                                          (LEAF 14) 
                                          (NODE 32 (LEAF 13) (LEAF 19)))) 
                         (NODE 154 (NODE 84 
                                          (LEAF 27) 
                                          (NODE 57 (LEAF 26) (LEAF 31))) 
                                   (NODE 70 (LEAF 34) (LEAF 36)))

p6_test2 = TestCase (assertEqual ("createSumTree "++ (show tree1)) (tree1_output) (createSumTree tree1) )
p6_test3 = TestCase (assertEqual ("foldListTree (+) 0 "++ (show listTree1)) 95 (foldListTree (+) 0 listTree1 ) )

minValue = toInteger(minBound::Int)
p6_test4 = TestCase (assertEqual ("foldListTree (max) "++ (show minValue) ++ " " ++ (show listTree1) ) 14 (foldListTree (max) (minValue) listTree1 ) )


-- Sample Tree Integer examples given in the assignment prompt; make sure to provide your own tree examples for both tree data types
-- Your trees should have minimum 3 levels.
t1 = NODE 1
         (NODE 2 (NODE 3 (LEAF 4) (LEAF 5)) (LEAF 6))
         (NODE 7 (LEAF 8) (LEAF 9))
t2 = NODE 0
          (NODE 0 (LEAF 4) (NODE 0 (LEAF 8) (LEAF 9)))
          (NODE 0 (NODE 0 (LEAF 10) (NODE 0 (LEAF 12) (LEAF 13))) (LEAF 7))

t3 = NODE 0 (NODE 0 (NODE 0 (LEAF 4) (LEAF 5)) (LEAF 6))
                (NODE 0 (LEAF 8) (LEAF 9))

-- My tree examples for Problem 4

               -- Height 3
treeExample2 = NODE 19 
     (NODE 15 (NODE 13 (LEAF (-12)) (LEAF 14)) 
              (NODE 17 (LEAF 16) (LEAF 18))) 
     (NODE 23 (NODE 21 (LEAF 20) (LEAF 22))
              (NODE 25 (LEAF 24) (LEAF 26))) 

                 -- Height 5
treeExample3 = NODE 19
     (NODE 17 (NODE 15 
                    (NODE 9 
                         (NODE 5 (LEAF 2) (LEAF 6)) 
                         (NODE 10 (LEAF (-7)) (LEAF 11))) 
                    (LEAF (16))) 
              (LEAF 18))
     (NODE 22 (LEAF 21) (LEAF 23)) 

      -- 6- Create two tree values : Tree Integer and listTree a ; Both trees should have at least 3 levels. 

{-  Create two tree values: a “Tree Integer” and a “ListTree a” (a will be substituted by the type of
the values stored in the tree). The height of both trees should be at least 3. Test your functions
sumTree, createSumTree, foldListTree with those trees. The trees you define should be
different than those that are given. See the example tests given in the file HW2SampleTests.hs -}

                -- For Tree Integer  -> Height 4  ~ Problem 6, tree to test
tree1 :: Tree Integer
tree1 = NODE 21 
      (NODE 16 (LEAF 15) 
               (NODE 17 
                    (LEAF 14) 
                    (NODE 18 (LEAF 13) (LEAF 19)) )) 
      (NODE 33 (NODE 29 (LEAF 27) (NODE 30 (LEAF 26) (LEAF 31))) 
               (NODE 35 (LEAF 34) (LEAF 36)))

              -- For ListTree a  -> Height 4  ~ Problem 6, tree to test 
listTree1 :: ListTree Integer
listTree1 = ListNODE
 [ ListNODE [ListLEAF [], 
             ListLEAF [2,3,4], 
             ListNODE
                     ([ListNODE([ListLEAF [5], ListLEAF [6]]), 
                      ListLEAF [7]]), 
             ListLEAF [] ],
   ListNODE [ListNODE([ListLEAF [8], ListLEAF []])],
   ListNODE [],
   ListNODE [ListLEAF [10,11], 
             ListNODE 
                    ([ListLEAF [12], 
                     ListNODE([ListLEAF [13], ListLEAF [14]]) ] ) ,
             ListNODE[] ]] 

t4 = ListNODE
 [ ListNODE [ ListLEAF [1,2,3],ListLEAF [4,5],ListNODE([ListLEAF [6], ListLEAF []]) ],
   ListNODE [],
   ListLEAF [7,8],
   ListNODE [ListLEAF [], ListLEAF []] ]

l1 = ListLEAF ["School","-","of","-","Electrical"]
l2 = ListLEAF ["-","Engineering","-"]
l3 = ListLEAF ["and","-","Computer","-"]
l4 = ListLEAF ["Science"]
l5 = ListLEAF ["-WSU"]
n1 = ListNODE [l1,l2]
n2 = ListNODE [n1,l3]
t5 = ListNODE [n2,l4,l5]

-- For problem 5 new test cases
l6 = ListLEAF ["Cpts355"]
l7 = ListLEAF ["~is~the~best"]
t6 = ListNODE [l6,l7]
l8 = ListLEAF ["~","CS","~","course"]
t7 = ListNODE [t6,l8]

tests = TestList [ TestLabel "Problem 1a - test1 " p1a_test1,
                   TestLabel "Problem 1a - test2 " p1a_test2,
                   TestLabel "Problem 1a - test3 " p1a_test3,
                   TestLabel "Problem 1a - test4 " p1a_test4,
                   TestLabel "Problem 1a - test5 " p1a_test5,
                   TestLabel "Problem 1a - test6 " p1a_test6,
                   
                   TestLabel "Problem 1b - test1 " p1b_test1,
                   TestLabel "Problem 1b - test2 " p1b_test2,
                   TestLabel "Problem 1b - test3 " p1b_test3,
                   TestLabel "Problem 1b - test4 " p1b_test4,
                   TestLabel "Problem 1b - test5 " p1b_test5,
                   TestLabel "Problem 1b - test6 " p1b_test6,

                   TestLabel "Problem 1c - test1 " p1c_test1,
                   TestLabel "Problem 1c - test2 " p1c_test2,
                   TestLabel "Problem 1c - test3 " p1c_test3,

                   TestLabel "Problem 2a - test1 " p2a_test1,
                   TestLabel "Problem 2a - test2 " p2a_test2,
                   TestLabel "Problem 2a - test3 " p2a_test3,
                   TestLabel "Problem 2a - test4 " p2a_test4,
                   TestLabel "Problem 2a - test5 " p2a_test5,

                   TestLabel "Problem 2b - test1 " p2b_test1,
                   TestLabel "Problem 2b - test2 " p2b_test2,
                   TestLabel "Problem 2b - test3 " p2b_test3,
                   TestLabel "Problem 2b - test4 " p2b_test4,
                   TestLabel "Problem 2b - test5 " p2b_test5,

                   TestLabel "Problem 3a - test1 " p3a_test1,
                   TestLabel "Problem 3a - test2 " p3a_test2,
                   TestLabel "Problem 3a - test3 " p3a_test3,
                   TestLabel "Problem 3a - test4 " p3a_test4,
                   TestLabel "Problem 3a - test5 " p3a_test5,

                   TestLabel "Problem 3b - test1 " p3b_test1,
                   TestLabel "Problem 3b - test2 " p3b_test2,
                   TestLabel "Problem 3b - test3 " p3b_test3,

                   TestLabel "Problem 4a - test1 " p4a_test1,
                   TestLabel "Problem 4a - test2 " p4a_test2,
                   TestLabel "Problem 4a - test3 " p4a_test3,
                   TestLabel "Problem 4a - test4 " p4a_test4,

                   TestLabel "Problem 4b - test1 " p4b_test1,
                   TestLabel "Problem 4b - test2 " p4b_test2,
                   TestLabel "Problem 4b - test3 " p4b_test3,

                   TestLabel "Problem 5 - test1 " p5_test1,
                   TestLabel "Problem 5 - test2 " p5_test2,
                   TestLabel "Problem 5 - test3 " p5_test3,
                   TestLabel "Problem 5 - test4 " p5_test4,

                  TestLabel "Problem 6 - test1 " p6_test1,
                  TestLabel "Problem 6 - test2 " p6_test2,
                  TestLabel "Problem 6 - test4 " p6_test3,
                  TestLabel "Problem 6 - test4 " p6_test4

                 ]


-- shortcut to run the tests
run = runTestTT  tests
