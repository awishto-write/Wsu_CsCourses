-- CptS 355 - Lab 2 (Haskell) - Spring 2023
-- Name: Naomi Dion-Gokan
-- Collaborated with: 
{-# OPTIONS_GHC -Wno-overlapping-patterns #-}
{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}
{-# HLINT ignore "Use map" #-}
{-# HLINT ignore "Eta reduce" #-}
{-# HLINT ignore "Redundant bracket" #-}

module Lab2     
    where

import Data.Char ()
import Distribution.Simple.Utils (xargs)
import Text.XHtml (base)

-- 1

{- (a) merge2 -}

{-The function merge2 takes two lists, l1 and l2, and returns a merged list where the elements from l1 
and l2 appear interchangeably.  The resulting list should include the leftovers from the longer list and it 
may include duplicates.  -}

merge2 :: [a] -> [a] -> [a]

      -- Base cases
merge2 [] l2 = l2   -- when the first list is empty, return the second list
merge2 l1 [] = l1   -- when the second list is empty return the first list
merge2 [] [] = []  -- when both list are empty, return an empty list;

{-merge the first element of the first list with the element of the first element of the 
second list and keep going in that order of lists, one at the time-}
merge2 (x:xs) (y:ys) = x : y : merge2 xs ys 
                         
 
{- (b) merge2Tail -}

{- Re-write the merge2 function from part (a) as a tail-recursive function. 
 You can use reverse or revAppend in your solution. We defined revAppend in class. -}

-- That function is really similar to the merge2, but changing some elements

merge2Tail l1 l2 = merge2_helper l1 l2 []

      where  

    -- we used reverse for the acculumative functions because without it, the order of the result is reversed
            merge2_helper [] l2 acc = reverse acc   -- when the first list is empty, return the second list
            merge2_helper l1 [] acc = reverse acc   -- when the second list is empty return the first list
            merge2_helper (x:xs)(y:ys) acc = merge2_helper xs ys ((x:y): acc)


-- {- (c) mergeN -}

-- {-Using merge2 function defined above and the foldl function, define mergeN which takes a list of 
-- lists and returns a new list containing all the elements in sublists. The sublists should be merged left to 
-- right, i.e., first two lists should be merged first and the merged list should further be merged with the 
-- third list, etc. Provide an answer using foldl; without using explicit recursion. -}

mergeN:: [[a]] -> [a]

-- the approach is to merge the first list with the second list - nope
-- consider the first list as the base, merge2 the base with the second list
-- then keep merge2 the base with every single list, then the number of lists decrease
-- until we are left with 2 lists, that merge into each other and form a final list

mergeN [[]] = []  -- Base Case
mergeN (x:xs) = foldl merge2 x xs

       -- from lab (mergeN) -- instead of the concatination (++), we used merge2

appendAll :: Foldable t => t [a] -> [a]
appendAll xs = foldl merge2 [] xs

appendAll2 :: [[a]] -> [a]
appendAll2 [] = []
appendAll2 (x:xs) = foldl merge2 x xs

--foldl1? above
appendAll3 :: Foldable t => [a] -> t [a] -> [a]
appendAll3 xs = foldl merge2 xs

-- -- 2
-- {- (a) count -}

-- {- Define a function count which takes a value and a list as input and it count the number of occurrences 
-- of the value in the input list. Your function should not need a recursion but should use a higher order 
-- function (map, foldr/foldl, or filter). Your helper functions should not be recursive as well, but 
-- they can use higher order functions. You may use the length function in your implementation. -}
 
count :: Eq a => a -> [a] -> Int

count value [] = 0 -- When we want to find the number of occurences of an empty list, return 0 

-- 1. filter the values that are equal to the given value from the list
-- 2. get the length to count the number of those values

count value xs = length $ filter (\x -> x == value) xs  -- check if that value where are in, correspond to the target value, the filter step
                                                     -- then adding the lenght, do the length step


{- (b) histogram  -}

{- The function histogram creates a histogram for a given list. The histogram will be a list of tuples 
(pairs) where the first element in each tuple is an item from the input list and the second element is the 
number of occurrences of that item in the list.  Your function shouldn’t need a recursion but should use 
a higher order function (map, foldr/foldl, or filter). Your helper functions should not be 
recursive as well, but they can use higher order functions. You may use the count function you defined 
in part (a) and eliminateDuplicates function you defined in HW1. 
 The order of the tuples in the histogram can be arbitrary.  -}

                -- eliminateDuplicates function was given in the lab
eliminateDuplicates1 :: Eq a => [a] -> [a]
eliminateDuplicates1 [] = []
eliminateDuplicates1 (x:xs) | x `elem` xs = eliminateDuplicates1 xs  
                            | otherwise = x : (eliminateDuplicates1 xs)  -- if x is the only one included in the list, we keep it

eliminateDuplicates2 :: (Foldable t, Eq a) => t a -> [a]
eliminateDuplicates2 xs = foldr helper [] xs                      
          where
               helper x base | (x `elem` base) = base -- we check if x is already in the bucket base
                             | otherwise = x : base

               -- Implementation of Histogram Function
  
histogram :: Eq a => [a] -> [(a, Int)]

histogram [] = [] -- when the list is empty, what happens, nothing right? So, why does 0 not working?

{- use map to convert a list input to a list of tuples; it takes that value and partner it with its string value

get tuples [1,2,3] -> [(1, "1") , (2, "2"), (3, "3")]
get_tuples xs = map (\x -> (x, show x)) xs; use that approach for histogram as commented below

histogram xs = map (\x -> (x, count x xs)) xs -- the value with how many times that values occurs in a tuple
however, if a value is repeated, it will included that number and its occurence, 2 times
example [1,3,3]  -> [(1,1),(3,2),(3,2)]   
Now we make use of eliminateDuplicate to solve that issue and gets the final result below -}


histogram xs = map (\x -> (x, count x xs)) (eliminateDuplicates2 xs)

-- 3                
{- (a) concatAll -}

{- Function concatAll is given a nested list of strings and it returns the concatenation of all 
strings in all sublists of the input list. Your function should not need a recursion but should use functions 
“map” and “foldr”. You may define additional helper functions which are not recursive. -}

concatAll ::  [[String]] -> String

-- nesting or combinining means that we have to use some folding: foldr or foldl
-- applying to every element of the list: we need to use map

concatAll [[]] = "" -- Base case, when the nested list of strings is empty, return an empty string

concatAll lst = concatAll_help (map concatAll_help lst)
     where 
          concatAll_help xs = foldr (++) "" xs   -- Concatination sign


{- (b) concat2Either -}               

-- {-Define a Haskell function concat2Either that takes a nested list of AnEither values and it returns 
-- an AString, which is the concatenation of all values  in all sublists of the input list. The parameter of 
-- the AnInt values should be converted to string and included in the concatenated string. You may use 
-- the show function to convert an integer value to a string.  
--     Your concat2Either function shouldn’t need a recursion but should use functions “map” and 
-- “foldr”. You may define additional helper functions which are not recursive.   -}

data AnEither  = AString String | AnInt Int
               deriving (Show, Read, Eq)
-- we either gonna have a string or an int value

-- We can use the same idea as 3.a , but we will need a "combine" implementation

concat2Either:: [[AnEither]] -> AnEither

-- write a helper either_concat that will concatanate 2 either values
-- use that helper to implement concat_eitherlist
-- use map, either_concat and concat_eitherlist to implement concat2Either

concat2Either lst = concat_eitherList (map concat_eitherList lst)

      where

          concat_eitherList xs = foldr either_concat (AString "") xs

            -- combining function; List all the possible options values that it can be
            -- we used show to convert those integers values into strings
            -- return a AString value

          either_concat (AString x) (AString y) = AString (x ++ y) 
          either_concat (AString x) (AnInt y) = AString (x ++ show y)
          either_concat (AnInt x) (AString y) = AString (show x ++ y)
          either_concat (AnInt x) (AnInt y) = AString (show x ++ show y)    

-- 4      
{-  concat2Str -}               

{- Re-define your concat2Either function so that it returns a concatenated string value instead of an 
AString value. Similar to concat2Either, the parameter of the AnInt values should be converted 
to string and included in the concatenated string.  
    Your concat2Str function shouldn’t need a recursion but should use functions “map” and 
“foldr”. You may define additional helper functions which are not recursive. -}

concat2Str :: [[AnEither]] -> String

concat2Str lst = foldr (++) "" (map concat_helper lst) -- combine the result of map into a single string

      where
              -- if we were using foldl below instead we would put the string values before the other types (AString and AnInt) and in reverse.
          concat_helper xs = foldr helper "" xs

            -- combining function; List all the possible options values that it can be
            -- we used show to convert those integers values into strings

          helper (AString y) x = y ++ x  -- a string with our value Astring
          helper (AnInt y) x = show y ++ x  -- a string with our vlaue AnInt


          -- If we wanted to use foldl, we would have used the code below
{-concat2Str lst = foldl (++) "" (map concat_helper lst) -- combine the result of map into a single string

      where

          concat_helper xs = foldl helper "" xs

          helper x (AString y) = x ++ y  -- a string with our value Astring
          helper x (AnInt y) = x ++ show y  -- a string with our vlaue AnInt     -}

-- ********** 

data Op = Add | Sub | Mul | Pow
          deriving (Show, Read, Eq)

evaluate:: Op -> Int -> Int -> Int
evaluate Add x y =  x+y
evaluate Sub   x y =  x-y
evaluate Mul x y =  x*y
evaluate Pow x y = x^y

data ExprTree a = ELEAF a | ENODE Op (ExprTree a) (ExprTree a)
                  deriving (Show, Read, Eq)
-- op means operation

-- 5 
-- {- evaluateTree -}

-- {-Write a function evaluateTree that takes a tree of type (ExprTree Int) as input and evaluates 
-- the tree from bottom-up. -}  

evaluateTree :: ExprTree Int -> Int

-- inorder traversal that we will use; Recursive Call of the left children and the right children
-- When we are the at the interior node, we evaluate the value for the left and right child, then we combine them


evaluateTree (ELEAF v) = v -- When we are at the leaf node, we return the value

-- There are multiple operations such as addition and operations, that's why we have op instead of calling a specific one
-- The right hand side has a similar format as the given one: "evaluate" above
evaluateTree (ENODE op left right) = evaluate op (evaluateTree left) (evaluateTree right) 

-- -- 6
-- {- printInfix -}

-- {-Write a function printInfix that takes a tree of type (ExprTree a) as input and prints the 
-- operands in the interior nodes and the values in the leaf nodes in “in-fix” order to a string.  The 
-- expressions lower in the tree are enclosed in parenthesis.-} 

printInfix:: Show a => ExprTree a -> String

printInfix (ELEAF v) = show v -- When we are at the leaf node, we return the value

{- Traverse the tree using the Infix order; Take the op and turn it into a string 
When we are the at the interior node, we evaluate the value for the left and right child, then we combine them
After evaluating the parent and children nodes, we append them -}

-- We tried to match the symbols order with the given result prompt, trial and error pretty much
printInfix(ENODE op t1 t2) = "(" ++ (printInfix t1) ++  " `" ++ show op ++ "` " ++ (printInfix t2) ++ ")"

-- Again she ignore the op operation as the previous question and symbols she put it
--printInfix

-- --7
-- {- createRTree -}
data ResultTree a  = RLEAF a | RNODE a (ResultTree a) (ResultTree a)
                     deriving (Show, Read, Eq)


-- {- Write a function createRTree that takes a tree of type (ExprTree Int) as input and creates a 
-- tree of type (ResultTree Int). createRTree recursively evaluates each subtree in the input tree 
-- and store the evaluated values in the corresponding nodes in the output ResultTree. -} 

createRTree :: ExprTree Int -> ResultTree Int

-- Matching the expressions/values of ExprTree into ResultTree

createRTree(ELEAF v) = RLEAF v 
createRTree (ENODE op t1 t2) = RNODE value (createRTree t1) (createRTree t2)
                     where value = evaluate op (evaluateTree t1) (evaluateTree t2) -- Similar idea as evaluateTree for ENODE
                                  