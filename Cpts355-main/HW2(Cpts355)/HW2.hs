-- CptS 355 - Spring 2023 -- Homework2 - Haskell
-- Name: Naomi Dion-Gokan
-- Collaborators: 
{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}
{-# HLINT ignore "Use camelCase" #-}

module HW2
     where

{- P1 - remove_every, remove_every_tail  -}

-- (a) remove_every – 7%

{- The function takes an integer n and a list lst and 
removes the item after every nth element in the list lst.  
If n is greater than the length of the input list, no elements will be removed. If n is 0, all elements in the 
list will be deleted. You may assume that n >=0. -}

remove_every :: (Eq t, Num t) => t -> [a] -> [a]
remove_every n []  = [] 
remove_every n lst = remove_helper n lst n 
  where  
     remove_helper _ [] _ = []
     remove_helper 0 (x:xs) k = (remove_helper k xs k) 
     remove_helper n (x:xs) k = x:(remove_helper (n-1) xs k) 
 
    -- Comments the identifications of the problems and problems and how there are been fixed
{- missing cases, when it result in an empty list.
missing argument k in both cases when calling the recursive calls: should have passed 3 arguments -}

-- (b) remove_every_tail –  10%
{- Re-write the remove_every function from part (a) as a tail-recursive function.  Name your function 
remove_every_tail. -}

remove_every_tail n []  = [] 
remove_every_tail n lst = remove_helper_tail n lst n []
  where  
     remove_helper_tail _ [] _ tail = reverse tail
     remove_helper_tail 0 (x:xs) k tail = (remove_helper_tail k xs k tail) 
     remove_helper_tail n (x:xs) k tail = remove_helper_tail (n-1) xs k (x:tail) 

------------------------------------------------------
{- P2  get_outof_range and count_outof_range  -}

-- (a) get_outof_range – 6%
{- Define a function get_outof_range which takes two values, v1 and v2,  and a list “xs”, and returns 
the values in xs which are less than v1 and greater than v2 (exclusive).   Your function shouldn’t need 
a recursion but should use a higher order function (map, foldr/foldl, or filter). You may need 
to define additional helper function(s), which are also not recursive.  -}

get_outof_range _ _ [] = [] -- Base case

get_outof_range v1 v2 xs = foldr (\value ok -> if value >= v1 && value <= v2 then ok
                                               else value : ok) [] xs

-- (b) count_outof_range – 10%
{- Using get_outof_range function you defined in part(a) and without using explicit recursion, define 
a function count_outof_range which takes two integer values, v1 and v2, and a nested list “xs”, 
and returns the total number of values in xs which are less than v1 and greater than v2 (exclusive).  
Your function shouldn’t need a recursion but should use higher order function (map, foldr/foldl, 
or filter). You may need to define additional helper function(s), which are also not recursive.   -}

-- consider the base case, map the result we get from 2.a and call of that function
-- then map the lenght of the elements we mapped from the answer of 2.a
count_outof_range v1 v2 xs = foldl (+) 0 (map length( map(get_outof_range v1 v2) xs))

------------------------------------------------------
{- P3  find_routes - 10% -}
{- Rewrite the find_routes function in HW1 using higher order functions (map, foldr/foldl, or 
filter) and without using recursion. Your helper functions should not be recursive as well, but they 
can use higher order functions. Remember that find_routes takes the list of bus routes and  a stop name, and returns the list of the 
bus routes which stop at the given bus stop.  You can make use of elem function in your solution. The 
order of the elements in the output can be arbitrary. -}

find_routes :: (Foldable t1, Eq t2) => t2 -> [(a, t1 t2)] -> [a]  -- Top level-binding with type signature

find_routes _ [] = []  -- Base case -> If the list is empty, return an empty list
find_routes bus_stop c1 = foldl (\acc (x,xs) -> if bus_stop `elem` xs then (x:acc) -- when bus_stop is in xs, include the route to acc
                                              else acc) [] c1 -- acc stays the same

------------------------------------------------------
{- P4  add_lengths and add_nested_lengths -}

-- (a) add_lengths - 6%
data LengthUnit =  INCH  Int | FOOT  Int | YARD  Int 
                   deriving (Show, Read, Eq) 

{- A function add_lengths that takes two LengthUnit values  and calculates the sum 
of those in INCH s. (Note that 1 foot = 12 inches  and 1 yard = 36 inches)  -}

-- Conversion of all the other units into Inches, All the possible scenarios for conversion

add_lengths :: LengthUnit -> LengthUnit -> LengthUnit
add_lengths (INCH x) (INCH y) = INCH (x + y)
add_lengths (INCH x) (YARD y) = INCH (x + y * 36)
add_lengths (INCH x) (FOOT y) = INCH (x + y * 12)

add_lengths (YARD x) (YARD y) = INCH (x * 36 + y * 36)
add_lengths (YARD x) (INCH y) = INCH (x * 36 + y)
add_lengths (YARD x) (FOOT y) = INCH (x * 36 + y * 12)

add_lengths (FOOT x) (FOOT y) = INCH ( x * 12 + y * 12)
add_lengths (FOOT x) (INCH y) = INCH (x * 12 + y * 12)
add_lengths (FOOT x) (YARD y) = INCH (x * 12 + y * 36)

-- (b) add_nested_lengths - 10%
{- A function add_nested_lengths that takes a nested list of LengthUnit values  
and calculates the sum of those in INCH s. Your function shouldn’t need a recursion but should use 
functions “map” and “foldr (or foldl)”. You may define additional helper functions which are 
not recursive.(Hint: The base for fold needs to be a LengthUnit value. ) -}

add_nested_lengths :: Foldable t => [t LengthUnit] -> LengthUnit
add_nested_lengths [] = (INCH 0) -- Base case
add_nested_lengths lst = foldl (add_lengths) (INCH 0) (map (foldl (add_lengths) (INCH 0)) lst)

------------------------------------------------------
{- P5 sum_tree and create_sumtree -}

data Tree a = NULL | LEAF a | NODE a  (Tree a)  (Tree a)  
              deriving (Show, Read, Eq) 
--NULL value represent a missing child for a NODE.  


-- (a) sum_tree - 8%
{- A function sum_tree that takes a tree of type Tree and calculates the sum of the values stored 
in both the leaves and interior nodes. -}

-- inorder traversal that we will use; Recursive Call of the left children and the right children
-- When we are the at the interior node, we evaluate the value for the left and right child, then we combine them

sum_tree :: Num a => Tree a -> a

sum_tree NULL = 0 -- when there is no node, the sum of tree is 0
sum_tree (LEAF v) = v -- When we are at the leaf node, we return the value
sum_tree (NODE op left right) = op + (sum_tree left) + (sum_tree right)


-- (b) create_sumtree - 10%
{- A function create_sumtree takes a Tree value and returns a Tree where the interior 
nodes store the sum of the leaf and node values underneath them (including NODE’s own 
values)-}

--create_sumtree :: Tree Int -> Tree Int

-- Matching the expressions/values of ExprTree into ResultTree

create_sumtree NULL = NULL
create_sumtree (LEAF v) = LEAF v 
create_sumtree (NODE op t1 t2) = NODE value (create_sumtree t1) (create_sumtree t2)
                     where value = op + (sum_tree t1) + (sum_tree t2) -- Similar idea as evaluateTree for ENODE

------------------------------------------------------
{- P6 list_tree - 16% -}

data ListTree a = LEAFs [a] | NODEs [(ListTree a)] 
                 deriving (Show, Read, Eq) 

 
{- A function list_tree that takes a function (f), a base value (base), and a ListTree (t) and 
combines the values in the lists of the leaf notes in tree t by applying function f. (The leaves of the 
tree are scanned from left to right).  The combined values from all leaves are further combined with 
function f; list_tree is invoked as: list_tree f base t -}

-- fold the list from leaf and fold the components of listTree for each node

list_tree f base (NODEs []) = base
list_tree f base (LEAFs []) = base
list_tree f base (LEAFs x) = foldl f base x
list_tree f base (NODEs y) = foldl f base (map (list_tree f base) y)

{- Tree examples - 4%
 INCLUDE YOUR TREE EXAMPLES HERE
Create two trees of type Tree. The height of both trees should be at least 4. -}

tree_example1 = (NODE 10 (NODE 2 (LEAF 6) (NODE 6 NULL (LEAF 11))) (NODE 2 (NODE 2 (LEAF 12) (NODE 9 NULL (LEAF 15)))  NULL))

tree_example2 = (NODE 5 (NODE 15 (LEAF 9)  NULL) (NODE (-15) (NODE (-8) NULL  (NODE 15 NULL (LEAF (-8)))) (LEAF (-9))))

-- Assignment rules 3%