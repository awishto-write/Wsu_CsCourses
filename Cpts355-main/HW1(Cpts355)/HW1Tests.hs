
{- Example of using the HUnit unit test framework.  See  http://hackage.haskell.org/package/HUnit for additional documentation.
To run the tests type "run" at the Haskell prompt.  -} 

module HW1Tests
    where

import Test.HUnit
import Data.Char
import Data.List (sort)
import HW1

-- P1(a) count tests  

p1a_test4 :: Test
p1a_test4 = TestCase (assertEqual "count-test4"
                                 1
                                 (count 'o' "count") )
p1a_test5 :: Test
p1a_test5 = TestCase (assertEqual "count-test5"
                                 2
                                 (count [10,20] [[10,20],[30,40],[10,20],[30,40]]) )


-- P1(b) diff tests

p1b_test4 = TestCase (assertEqual "diff-test4"
                                 []
                                 (sort $ diff [] [1,2,3,4,5,7,7]) )
p1b_test5 = TestCase (assertEqual "diff-test5"
                                 [4,5,6,7,8,9]
                                 (sort $ diff [9,8,7,6,5,4] [] ) )                                

-- P1(c) bag_diff tests

p1c_test5 = TestCase (assertEqual "bag_diff-test4"
                                 (sort "Hippopotomonstrosesquippedaliophbia" )
                                 (sort $ bag_diff "Hippopotomonstrosesquippedaliophobia" "o") )
p1c_test6 = TestCase (assertEqual "bag_diff-test6"
                                 []
                                 (sort $ bag_diff [7] [6,5,4,3,7,7,7,7,7,2,1] ) )                                 

-- P2  everyN tests

p2_test5 = TestCase (assertEqual "everyN-test5"
                                  [(70,80), (150,160)]
                                  (everyN [(10,20),(30,40),(50,60),(70,80),(90,100),(110,120),(130, 140), (150,160)] 4) )

p2_test6 = TestCase (assertEqual "everyN-test6"
                                 ""
                                 (everyN "zebra" 7))                              

-- P3(a) make_sparse tests

p3a_test5 = TestCase (assertEqual "make_sparse-test5"
                                  [0,0,0,0,-50,-200]
                                  (make_sparse [(4,-50),(5,-200)]) )
p3a_test6 = TestCase (assertEqual "make_sparse-test6"
                                  [1,3,5,7,9]
                                  (make_sparse [(0,1),(1,3),(2,5),(3,7),(4,9)]) )

--P3(b) compress tests

p3b_test5 = TestCase (assertEqual "compress-test5"
                                  [(0,1),(1,3),(2,5),(3,7),(4,9)]
                                  (compress [1,3,5,7,9] ) )
p3b_test6 = TestCase (assertEqual "compress-test6"
                                  []
                                  (compress [0,0,0,0,0]) )


-- P4 added_sums tests
p4_test4 = TestCase (assertEqual "added_sums-test4"
                                  [765]
                                  (added_sums [765]) )
p4_test5 = TestCase (assertEqual "added_sums-test5"
                                  [-20.0,10.0,-30.0,40.0]
                                  (added_sums [-20.0,30.0,-40.0,70.0]) )

-- P5 find_routes tests

routes_test = [("Lentil",["Chinook", "Orchard", "Valley", "Emerald","Providence", "Stadium", "Main", "Arbor", "Sunnyside", "Fountain", "Crestview", "Wheatland", "Walmart", "Bishop", "Derby", "Dilke"]), 
   ("Wheat",["Chinook", "Orchard", "Valley", "Maple","Aspen", "TerreView", "Clay", "Dismores", "Martin", "Bishop", "Walmart", "PorchLight", "Campus"]), 
   ("Silver",["TransferStation", "PorchLight", "Stadium", "Bishop","Walmart", "Outlet", "RockeyWay","Main"]),
   ("Blue",["TransferStation", "State", "Larry", "TerreView","Grand", "TacoBell", "Chinook", "Library"]),
   ("Gray",["TransferStation", "Wawawai", "Main", "Sunnyside","Crestview", "CityHall", "Stadium", "Colorado"]),
   ("Coffee",["TransferStation", "Grand", "Main", "Visitor","Stadium", "Spark", "CUB"])]    


-- find_routes tests
p5_test4 = TestCase (assertEqual "find_routes-test4"
                                  (sort ["Coffee"])
                                  (sort $ find_routes "CUB" routes_test ) )
p5_test5 = TestCase (assertEqual "find_routes-test5"
                                  []
                                  (sort $ find_routes "Blue" routes_test ) )
                                

-- P6 group_sum tests

-- p6_test4 = TestCase (assertEqual "(group_sum-test4)"
--                                   [[10,11,12,13,14,15]]
--                                   (group_sum [10,11,12,13,14,15] 0) )
-- p6_test5 = TestCase (assertEqual "(group_sum-test5)"
--                                   [[1]]
--                                   (group_sum [1] 5) )


-- add the test cases you created to the below list. 
tests = TestList [ 
    -- for 1a
                 TestLabel "Problem 1a- test4 " p1a_test4,
                 TestLabel "Problem 1a- test5 " p1a_test5,
    -- for 1.b
                  TestLabel "Problem 1b- test4 " p1b_test4,
                   TestLabel "Problem 1b- test5 " p1b_test5,
    -- for 1.c
                   TestLabel "Problem 1c- test5 " p1c_test5,
                    TestLabel "Problem 1c- test6 " p1c_test6,               
   -- for 2
                  TestLabel "Problem 2- test5 " p2_test5,
                  TestLabel "Problem 2- test6 " p2_test6,

   -- for 3a
                   TestLabel "Problem 3a- test5 " p3a_test5,
                   TestLabel "Problem 3a- test6 " p3a_test6,

    -- for 3b
                   TestLabel "Problem 3b- test5 " p3b_test5,
                   TestLabel "Problem 3b- test6 " p3b_test6,

   --for 4
                   TestLabel "Problem 4- test5 " p4_test4,
                   TestLabel "Problem 4- test6 " p4_test5,   
  
   -- for 5
                   TestLabel "Problem 5- test4 " p5_test4,
                   TestLabel "Problem 5- test5 " p5_test5    

   -- for 6
                -- TestLabel "Problem 6- test4 " p6_test4,
                -- TestLabel "Problem 6- test5 " p6_test5   

                ]
                  
-- shortcut to run the tests
run = runTestTT  tests