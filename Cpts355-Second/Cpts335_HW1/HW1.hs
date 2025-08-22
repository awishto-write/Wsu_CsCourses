-- CptS 355 - Spring 2024 Assignment 1
-- Name: Naomi Dion-Gokan
-- Please include your name and the names of the students with whom you discussed any of the problems in this homework

module HW1
     where

import Data.Char (toUpper)

-- 1. exists
{-  exists which takes a “value” and a “list” as input. If the value is a member 
of the list, the function should return True. Otherwise it should return False 

Explain in a comment why the type is exists :: Eq t => t -> [t] -> Bool but not exists :: t -> [t] -> Bool 
    The type is "exists :: Eq t => t -> [t] -> Bool" because we are talking about of a function, which is an equation, 
    only using t instead of Eq t will infer that we were talking about a type of a variable or parameter.
    We use Eq to test the equality of the value given t with elements of the list [t], to compare the them.
    It helps to not bound t to a specific type such as integers, meaning it allows to have multiple types.
-}

exists :: Eq t => t -> [t] -> Bool

exists _ [] = False -- when the list is empty, return Fals; exists x [] = False the same as what is written; Used the other because VS Code says I defined x, but not used it
exists x (xs:ys) = if (x == xs) then True -- If the x value is equal to that head element of the list, return True
                   else exists x ys 
{- If the x value is not found at the head, it calls recursively exists with the tail of the list, meaning it searches for 
the x-value in the rest of the list. When not found at the end of the list: empty list, it returns false-}

-- 2. listUnion

{- Write a function listUnion that takes two lists as input and returns the union of those lists. Your
function should have type listUnion :: Eq a => [a] -> [a] -> [a].
Each value should appear in the output list only once, but the order does not matter. Please note that
the input lists may have duplicate values or there may be values that appear in both input lists. All such
duplicate values should be removed. -}

listUnion :: Eq a => [a] -> [a] -> [a]

listUnion [] x2 = x2 -- When first list is empty, return second list
listUnion x1 [] = x1 -- When second list is empty, return first list
listUnion x1 x2 = removeDuplicateValues (x1 ++ x2) -- x1 ++ x2: Appending 2 lists to create one list; Then call removeDuplicateValues after on the resulting list

-- This function will remove duplicates values from the combined list(when the 2 lists have been appending)
removeDuplicateValues :: Eq a => [a] -> [a]
removeDuplicateValues [] = [] -- When the list is empty, return an empty list

{- When the head value(x) is found in the rest of the list(xs), it removes it (deletes) that value x(leaving the 
other appearances in the list)then call removeDuplicateValues recursively on xs, so the next element becomes our head -}
removeDuplicateValues (x:xs) | exists x xs = removeDuplicateValues xs  --  or could have used instead  | x `elem` xs = removeDuplicateValues xs 
                             | otherwise = x : removeDuplicateValues xs
{- When x is not found in the rest of the list we keep it for our resulting union list(we move it there) and 
the next element becomes our head and we call recursively xs -}

-- For the test cases, the order of the function is different with sort. With sort(), it includes the order at which the first letter appeared, instead of last appeared like the way this one has been implemented.

-- 3. replace

{- Write a function replace that takes an index n, a value v, and a list L and returns a (new) list which is
the same as L, except that its nth element is v. Assume 0-based indexing for n and n≥0. (Note that n
can be greater than the length of the list L. ) -}

replace :: (Eq t1, Num t1) => t1 -> t2 -> [t2] -> [t2]

replace _ _ [] = []  -- When the list is empty, return an empty list

{- n = index, v = value, (x:xs) => (head of list, remaining of elements of the list). Could also used the logic 
with "|" and otherwise, same idea. Because we have: "0-based indexing for n", we started with "n == 0" to represent
the 0-based starting point. The v:xs creates a new list where the value that was at that specific index(index 0) is
being changed with the value v. So we have our new head with value v and the remaining list is the same, which is 
represented with (v:xs) -}
replace n v (x:xs) = if (n == 0) then v:xs 
                      else x: replace (n-1) v xs
{- In the case we are not looking for index 0. So, we want index: 1,2, etc..; We create a new list by keeping the current 
starting point/ head we have because we do not want to change those values, but only an element at an index => Represented by
(else x: ). For our second value of the new resulting list
Then, we call recursively replace with (n-1) because we want to get the index we want (reducing index 1,2,etc to 0) so are trying to 
move to the left as possible, but 1 at the time. We keep teh same v we had and that recursive call use xs because our head is x as we
started and our tail is still x. Then with the recursive call, we go into the function and reexamine the if-statement again. The process 
keep going until everything end at index 0 for true. In case a high index, we end up adding values to make up the final list. 
Example: replace 2 v (x:xs), we might get result: x: a: b; where a represents [ x: replace (2-1) v xs] and b represents [ x: replace (1-1) v xs] 
and stops because because "if (n == 0) then v:xs" became true with 1-1 = 0. Starting from replace 2 to replace 1 to replace 0, where replace 1 and 0
came from the recursive call. -}

-- 4. prereqFor

{- Assume that we store the list of CptS courses and their prerequisites as a list of tuples. The first element
of each tuple is the course name and the second element is the list of the prerequisites for that course.
Please note that a course may have an arbitrary number of prerequisites. The list can be found in the test cases file.

Assume that you are creating an application for WSU. You would like to write a Haskell function
prereqFor that takes the list of courses (similar to above) and a particular course number and
returns the list of the courses which require this course as a prerequisite.
(Hint: You can make use of exists function you defined earlier.) -}

prereqFor :: Eq t => [(a, [t])] -> t -> [a]

prereqFor [] _ = [] -- When the list is empty, return an empty list

{- We check if the element we have: c1 exits in the prereq portion of the list, when it does, 
we add that class(classes in this case) to the resulting list: final list answer.
Then, we call recursively prereqFor to move on to the next list of (classes, prereq) to search for c1, 
that next list is in part of the rest of the list(xs). So we get a new head: : we continue with the rest of the list -}
prereqFor ( (classes, prereq): xs) c1  | exists c1 prereq = classes : prereqFor xs c1 --  or instead use  | c1 `elem` prereq = classes : prereqFor xs c1
                                       | otherwise = prereqFor xs c1
{- When the element c1 does not exit in the prereq portion of the list, we call recursively prereqFor to move on to the next list of (classes, prereq)
to search for c1, that next list is in part of the rest of the list(xs). So we get a new head: we continue with the rest of the list -}

-- 5. isPalindrome

{- A palindrome is a sentence or phrase that is the same forwards and backwards, ignoring spaces,
punctuation and other special characters, and upper vs. lower case. In this problem we will consider
palindromes that include only letters, digits, and spaces but don’t include any punctuation or any special
characters — for example “a01 02 2010A”, “Yreka Bakery”, and “Doc note I dissent a fast never prevents
a fatness I diet on cod”. Assume that letters are case insensitive — for example “Madam Im Adam”
Write a Haskell function isPalindrome that takes a string as argument and that returns True if the
string is a palindrome and False otherwise.
(Note: you can make use of the following Haskell functions: reverse (for reversing a list), toUpper
(for retrieving the uppercase of a given character). -}

isPalindrome :: [Char] -> Bool
            
isPalindrome [] = True -- Base cases: [] -> empty list or "" -> empty string

{- We check if when we reverse the list, it will be the same as when it is not reversed. To do that we 
call convert all the lower cases to upper cases in the list and remove all spaces. Then when we finsh to 
do so, we check if that result is the same as the reversed of that result. If they are the same 
we return True, if they are not, we return False -}
isPalindrome x = (oddCases) == (reverse oddCases) --  used () to remember I am doing: Ex: z = [a == b]
  where
      oddCases = upperString (deleteSpace x)

{- Remove space in the list. Then we have all word together, then we reverse it. We return true when they are the same and false when not-}

{- Knowing that the components that will disturb our work are the space and upper cases. We create funtions to deal with them.
deleteSpace function deletes the space when encountered in the list and return a list of elements with no space in it. 
 Same approach as removeDuplicatesValue in Question 2 -}
deleteSpace :: [Char] -> [Char]
deleteSpace [] = []
{- When the head of the list is a space, recursively calls on the rest of the list. So because of that recursive call,
we go to the next element of the list, which because the head and do the work all over again: we check if that next 
element is a space and all the other steps in the code below -}
deleteSpace (x:xs) | x == ' ' = deleteSpace xs   
                   | otherwise = x : deleteSpace xs -- When the head is not a space, concatinate the head with the recursive call on the rest of the list

{- upperString function converts a lower case character into an upper case character. From online search, it states: 
toUpper converts a character to upper-case. Spaces, numbers and the like remain unchanged, which is helpful for our test cases -}
upperString :: [Char] -> [Char]
upperString [] = []
upperString (x:xs) = toUpper x : upperString xs 
{- Convert the head to ist upper case letter then concatinate the head with the recursive call on the rest of the list,
 so we get a new list where all the lowercase letters become upper case letters -}

-- 6. groupSumtoN

{- groupSumtoN that takes two arguments, where the first argument is an
integer (N) and the second is a list (L). The goal is to produce a result in which the elements of the
original list have been collected into ordered sub-lists each containing maximum number of consecutive
elements from L summing up to N or less (where N is the integer argument). The leftover elements (if
there are any) are included as the last sub-list with a sum less than N. If an element in the input list L is
greater than N, that element should be included in its own sublist (including that element only).-}

groupSumtoN :: (Ord a, Num a) => a -> [a] -> [[a]]

groupSumtoN _ [] = [[]] -- base case, when the list is empty, return a list of an empty list
groupSumtoN n list = helper list [] n 0 0 -- Call helper function with the base or initial elements which are the list, the empty sub-list, n, current sub-list number and the sum  

     where
          helper [] [] _ _ _ = [] -- Base case
          helper [] subList _ _ _ = (reverse subList) : [] -- Other case: sub-list is not empty, but the list is empty
          helper (x:xs) subList n num sum
{- When n <= than the head of the list(x >= n), we get a new sub-list with the head of the list(head of the list alone inside new sub-list) 
and concatinate the recursive call of helper with the rest of the list(starting with a new sub-list[])-}
             | x >= n = [x] : helper xs [] n 0 0 
             | (x + sum) > n = (reverse subList) : helper (x:xs) [] n (num + 1) 0
{- When the sum of the head of the list and the sum is > than n, we concatinate the reverse of the sub-list with the recursive call of helper 
with the result we have(starting with a new sub-list[] again) -}
             | otherwise = helper xs (x:subList) n num (sum + x)
{- When it is not any of the conditions mentioned, we add the current element(head of the list -> x) to the current sub-list and add that element 
(head of the list -> x) to the sum, which updates the sum. We do the recursive call of helper the rest of the list with the components mentioned.
Example possible cases: (x + sum) < n, x < n
 -}