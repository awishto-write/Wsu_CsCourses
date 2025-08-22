-- CptS 355 - Spring 2024 Assignment 2
-- Naomi Dion-Gokan
-- Please include your name and the names of the students with whom you discussed any of the problems in this homework
{-# OPTIONS_GHC -Wno-overlapping-patterns #-}
module HW2
where
import GHC.Exts (the)
import Control.Monad (when)
import System.Posix (getWorkingDirectory)
import qualified GHC.TypeLits as Lengths

      -- 1- merge2 & merge2Tail & mergeN - 22%

   -- a) merge2
{-The function merge2 takes two lists of integers, l1 and l2, each already in ascending order, and returns a merged list
that is also in ascending order. The resulting list should include the elements from both lists and may include duplicates. -}

merge2 :: Ord a => [a] -> [a] -> [a]

       -- Base cases
merge2 [] l2 = l2   -- when the first list is empty, return the second list
merge2 l1 [] = l1   -- when the second list is empty return the first list
merge2 [] [] = []  -- when both list are empty, return an empty list;

merge2 (x:xs) (y:ys) 
     | x <= y = x : merge2 xs (y:ys)  -- When x > y or x = y
     | otherwise = y : merge2 (x:xs) ys -- When x greater than y

{- When the first element "x" of the first list is < or = to the first element of the second list, it adds x to the 
resulting merged list and do a recursive call with the rest of the first list "xs" and (y:ys). However, when x > y, 
it adds y to the resulting merged list and do a recursive call with the full (whatever is left) first list (x:xs) 
and the remaining rest of the second list (ys) -}

     -- b) merge2Tail 
{- Re-write the merge2 function from part (a) as a tail-recursive function. Name your function merge2Tail.
(Hint: In your bases case(s), use revAppend (which we defined in class) to add the reverse of the accumulated 
merged list to the other list.) -}

   -- That function is given in lecture, it reverse a list
revAppend :: [a] -> [a] -> [a]
revAppend [] acc = acc
revAppend (x:xs) acc = revAppend xs (x:acc)

merge2_helper :: Ord a => [a] -> [a] -> [a] -> [a]
merge2_helper [] [] acc = acc -- When both lists are empty, we retun the accumulated list
merge2_helper [] l2 acc = revAppend l2 acc   -- when the first list is empty, it adds the reverse elements of l2 at the
-- beginning of the acc, but one at the time (check revAppend), if l2 = [1,2], it would add like: 1:acc then 2:1:acc
merge2_helper l1 [] acc = revAppend l1 acc   -- when the second list is empty, same idea like when the first list only is empty, but we change l2 with l1

merge2_helper (x:xs)(y:ys) acc | x <= y = merge2_helper xs (y:ys) (x:acc)  -- When x > y or x = y
                               | otherwise = merge2_helper (x:xs) ys (y:acc) -- When x greater than y
{- For the two last lines above where the guards are; They are a little similar as merge2 function above (last 2 lines), however, with an addition to the 
accumulated list "acc" and small change; For x <= y, it does a recursive call with the rest of the first list "xs" , the full second list (y:ys) and (x:acc)
while having x as the first element of the acc list; For x > y, it does a recursive call with the rest of the full second list (x:xs), the rest of the second 
list "ys" and (y:acc) while having y as the first element of the acc list; In both cases, they end up reverse the elements of the list that added to the
acc list, both lines end up technically having the same concept, but with different elements.
    When finishing up with the reversing call and going to the non-recursive call (where revAppend is used), we end up having a list in descending order. 
-}

merge2Tail :: Ord a => [a] -> [a] -> [a] 
merge2Tail l1 l2 = reverse(merge2_helper l1 l2 [])
{- To solve the issue of the resulting list of merge2_helper, we use reverse to have get our ascending list. This function calls merge2_helper 
with 2 lists and an empty list. Eventually, merge2_helper does its things. We could have had it first then have a where clause to add merge2_helper, 
but it still does what we want.-}


     -- c) mergeN
{- Using your merge2 function defined above and the foldl (or foldr) function, define mergeN, which takes a list of lists, 
each already in ascending order, and returns a new list containing all of the elements in sublists in ascending order. Provide 
an answer using foldl (or foldr); without using explicit recursion. The type of mergeN should be one of the following:
mergeN :: Ord a => [[a]] -> [a] or mergeN :: (Foldable t, Ord a) => t [a] -> [a] -}

mergeN :: Ord a => [[a]] -> [a] 

mergeN [[]] = []  -- Base Case  -- It takes our list of list and makes it a list
mergeN (x:xs) = foldl merge2 x xs

{- For the second line(mergeN (x:xs) = foldl merge2 x xs), we call foldl with merge2 and separely with the first element of list and the
of the list; foldl would do its work from left to right so from our first to last element. Let's call the list of list: lL; In mergeN, every list in 
the list of list is considered as one element of the list lL; It is is like, we have one list lL with elements (that are lists).
Example: [[3,4],[-3,-2,-1],[1,2,5,8,9]], In this first order call of the work, [3,4] would be x, [[-3,-2,-1],[1,2,5,8,9]] would be 
xs, then after executing the second line of code, we get [-3,-2,-1,3,4]; Then, for our second call [-3,-2,-1,3,4] becomes x and 
[1,2,5,8,9] becomes xs. 
      Then, we end up with [-3,-2,-1,1,2,3,4,5,8,9], the good thing is that merge2 results in a list, so when
we finish executing the last of mergeN here, our resulting list is already a list to return and not a lits of a list.
In this case, using "foldr merge2 x xs" woudl have also work because merge2 is handling keeping elements in a sorting order and using 
x that is the first element of the list as last element of the list in the context of foldr keeps the order the same (mainly because
we have a list situation, doing "foldr merge2 xs x" would have given us type error). Even if we had the luxury to work from the last 
element to the first element using foldr, it would end up with the same result because of merge2.
      So foldl lets merge2 does its work, but chooses the order at which the work is executed.
  -}

     -- 2 - getInRange & countInRange - 18% 

  -- a) getInRange
{- Define a function getInRange which takes two integer values, v1 and v2, and a list iL, and returns
the values in iL which are greater than v1 and less than v2 (exclusive). Your function shouldn’t need
a recursion but should use a higher order function (map, foldr/foldl, or filter). You may need
to define additional helper function(s), which are also not recursive. -}

getInRange :: Ord a => a -> a -> [a] -> [a]

getInRange _ _ [] = []  -- Base case
getInRange v1 v2 iL = filter (\value ->  value > v1 && value < v2 ) iL
{- We want specific elements, so we make sure of the filter because it has for role: keeps certain elements from the list and removes 
the rest; Therefore, we use filter and indicates the focus of the values we want to ahve based on the list -}


   -- b)countInRange
{- Using getInRange function you defined in part(a) and without using explicit recursion, define a function
countInRange which takes two integer values, v1 and v2, and a nested list iL, and returns the total number 
of values in iL which are greater than v1 and less than v2 (exclusive). Your function shouldn’t need a recursion
but should use a higher order function (map, foldr/foldl, or filter). You may need to define additional helper
function(s), which are also not recursive. You are expected to be able to complete this task without simply 
merging the nested lists into a single list, i.e. donot use the functions defined in problem 1. Instead, 
expect to make multiple uses of map, foldr/foldl, and/or filter. -}

countInRange :: Ord a => a -> a -> [[a]] -> Int 

countInRange v1 v2 iL = foldl (+) 0 (map length( map(getInRange v1 v2) iL))

{- Dissection: getInRange v1 v2 iL => X; map(X) => Y ; map length (Y) => Z
     In summary, map(getInRange v1 v2) iL => map(X), map length( map(getInRange v1 v2) iL) => map length (Y)
       Let's use those letters to represent work

~ fold (+) 0 help us sums up, adds up, counts the number of elements we get from doing work Z; (+) is the operation/funtion
   of foldl; 0 is the number at which we start the sum and work Z is the list of foldl
~ work X return values in iL which are greater than v1 and less than v2 (exclusive); So, with work X, we end up with one list,
    so with type [], instead of what [[]] that was passed. The work is done by dealing with one list at the time.
~ work Y helps us get the desired type [[a]] of countInRange
      We know map is represented by (a -> b) -> [a] -> [b] and returns a list constructed by appling a function (the first argument)
  to all items in a list passed as the second argument. So, we create a list to put the result of work X, ending up with a list of a list
   which is [[]]
~ work Z is made of a composition of both map and length, we execute the length process first; however, we know that the previous step
  (work Y) ends up with a [[]], but length takes []; That's where the importaance of having "map length" comes from and not "map(length)".
   With map length, "map" in front of "length" assures that "length" only deals with the sublist [] (which is a list) and not [[]].
   So, we get the length of the list [] and map automtically create a list that includes the length result (which is an integer).
   Therefore, work Z results in a list of int.

             Let's take example: countInRange (-9) 19 [[-12,-11,-9,-8],[],[2,3],[17,18],[19,20,21,22]]
 We know that each sublist get evaluated individually
work X will give: [-8] for [-12,-11,-9,-8], work Y will give: [[-8]], work Z will give [1] where length gave 1 map length [1]
Then the fold part sum up to 1, we do the same for every sublist and add the final resut to the previous result -}

     -- 3 - addLengths & addAllLengths - 18% 

-- Define the following Haskell datatype which represent the US customary length units:
data LengthUnit = INCH Int | FOOT Int | YARD Int
                  deriving (Show, Read, Eq)

      -- a) addLengths
{- Define a Haskell function addLengths that takes two LengthUnit values and calculates the sum
of those in INCH s. (Note that 1 foot = 12 inches and 1 yard = 36 inches) -}

addLengths :: LengthUnit -> LengthUnit -> LengthUnit

-- Thinking about all the possible scenarios of conversions of all the other units into Inches
addLengths (INCH x) (INCH y) = INCH (x + y) -- There are both INCH, so we add them up
addLengths (INCH x) (YARD y) = INCH (x + y * 36) -- One is INCH, so we keep; The other is YARD so we convert to INCH and we add the values
addLengths (INCH x) (FOOT y) = INCH (x + y * 12) -- One is INCH, so we keep; The other is FOOT so we convert to INCH and we add the values

addLengths (YARD x) (YARD y) = INCH (x * 36 + y * 36) -- Both are YARD, so we convert them  individually to INCH and add them up together
addLengths (YARD x) (INCH y) = INCH (x * 36 + y) -- One is INCH, so we keep; The other is YARD so we convert to INCH and we add the values
addLengths (YARD x) (FOOT y) = INCH (x * 36 + y * 12) -- One is YARD, the other is FOOT, so we convert them individually in INCH and add them up

addLengths (FOOT x) (FOOT y) = INCH ( x * 12 + y * 12) -- Both are FOOT, so we convert them individually to INCH and add them up together
addLengths (FOOT x) (INCH y) = INCH ( x * 12 + y)  -- One is INCH, so we keep; The other is FOOT so we convert to INCH and we add the values
addLengths (FOOT x) (YARD y) = INCH ( x * 12 + y * 36)  -- One is YARD, the other is FOOT, so we convert them individually in INCH and add them up

       -- b) addAllLengths
{- Now, define a Haskell function addAllLengths that takes a nested list of LengthUnit values and
calculates the sum of those in inches. Your function shouldn’t need a recursion but should use functions
“map” and “foldr (or foldl)”. You may define additional helper functions which are not
recursive. The type of the addAllLengths function should be one of the following:
addAllLengths :: Foldable t => [t LengthUnit] -> LengthUnit OR addAllLengths :: [[LengthUnit]] -> LengthUnit
(Hint: The base for fold needs to be a LengthUnit value.) -}

addAllLengths :: Foldable t => [t LengthUnit] -> LengthUnit

addAllLengths [] = (INCH 0) -- Base case
addAllLengths lst = foldl addLengths (INCH 0) (map (foldl addLengths (INCH 0)) lst)


{-      Adding all values of every addLenghts call(being represented by [])
   Dissection: foldl addLengths (INCH 0) (map (foldl addLengths (INCH 0)) lst) represents A; 
(map (foldl addLengths (INCH 0)) lst) represents B; foldl addLengths (INCH 0)) lst represents C

    For our work A, foldl takes a function addLengths, applying addLengths on work B, starting by INCH 0 (starting the sum of addLengths by INCH 0)
Having addLengths helps make sure the result has type addLengths.
      Work C help us execute to the needed operation of addLengths, list by list, starting INCH 0 going from the the first element
   to the last element. Work B helps us have the result of work C in a list to be used in Step/Work A.
      Most of those elements are helpful to make us match the required types while getting the desire result.
-}


       -- 4 - sumTree and createSumTree - 22%

-- In Haskell, a polymorphic binary tree type with data both at the leaves and interior nodes might be represented as above: data Tree a = ...
data Tree a = LEAF a | NODE a (Tree a) (Tree a)
              deriving (Show, Read, Eq)

            -- (a) sumTree - 8%
-- Write a function sumTree that takes a tree of type Tree Integer and calculates the sum of the values stored in the leaves only. 

sumTree :: Num p => Tree p -> p 
sumTree (LEAF v) = v -- When we are at the leaf node, we return the value of that leaf node
sumTree (NODE _ left right) = (sumTree left) + (sumTree right) -- For interior nodes, we recursively sum the leaves of the left and right subtrees
{- So, we get the sum of all leaves from the left subtree and add to the sum of all the leaves from the right subtree. That second line helps us 
 deal with the whole tree, but every node individually, categorizing them by left and right subtrees. Ultimately, we get the sum for both 
subtrees at a specific level, by calling sumTree recursively, we then get back to the first line of code, which assures us to get only a leaf node value -}

           -- b) createSumTree
-- Write a function createSumTree takes a Tree Integer value and returns a Tree Integer, where the interior nodes store the sum of the leaf values underneath them. 

createSumTree :: Num a => Tree a -> Tree a 

--createSumTree a = a
createSumTree (LEAF v) = LEAF v -- When we have a leaf node, its value stay as leaf node, so we return that for our new tree
createSumTree (NODE _ t1 t2) = NODE allSum (createSumTree t1) (createSumTree t2)
                     where allSum = (sumTree t1) + (sumTree t2) 

{- At the left side tree and at the right tree: At each level, we get the sum of the leaf nodes successive level
Meaning example when having (level 0, 1, 2, 3 where 0 being the highest and 3 the lowest), at level 2, we will have the sum of
the leaf nodes of level 3 and 0 will ultimately have the sum of the leaf nodes from both left and right sides -}


       -- 5 - foldListTree - 20%

{- A polymorphic tree type with nodes of arbitrary number of children might be represented as follows
(note that the leaves store a list and interior nodes store list of “ListTree”s): -}

data ListTree a = ListLEAF [a] | ListNODE [(ListTree a)]
                  deriving (Show, Read, Eq)

{- Write a function foldListTree that takes a function (f), a base value (base), and a ListTree (t) and
combines the values in the lists of the leaf nodes in tree t by applying function f. (The leaves of the
tree are scanned from left to right).

foldListTree is invoked as: foldListTree f base t where f is the combining function of type a -> a -> a.-}

foldListTree :: (a -> a -> a) -> a -> ListTree a -> a 

{- When calling foldListTree with ListTree that is a ListNODE that has an empty list, as well as nothing "_" for function
in that case, it returns the base because we have nothing to evaluate -}
foldListTree _ base (ListNODE []) = base
{- When calling foldListTree with ListTree that is a ListLEAF that has an empty list, as well as nothing "_" for function
in that case, it returns the base because we have nothing to evaluate -}
foldListTree _ base (ListLEAF []) = base
{- When calling foldListTree with ListTree that is a ListLEAF that has a list "x" that is non empty , as well as a function f; 
in that case we apply foldl to the function f (combines the values in the lists of the leaf nodes in tree t) on the list x 
starting from the base -}
foldListTree f base (ListLEAF x) = foldl f base x
{- When calling foldListTree with ListTree that is a ListNODE that has a list "y" that is non empty , as well as a function f; 
in that case we apply foldl to the function f (combines the values in the lists of the leaf nodes in tree t) starting from the base
on the operation A. A represents "map (foldListTree f base) y", we recursively call foldListTree on the function f (combines the 
values in the lists of the leaf nodes in tree t) on the list y starting from the base. The map helping us to deal with
every sub-list of the list y -}
foldListTree f base (ListNODE y) = foldl f base (map (foldListTree f base) y)

      {- 6- Create two tree values : Tree Integer and listTree a ; Both trees should have at least 3 levels. 
           Check HW2SampleTests.hs for this question -}