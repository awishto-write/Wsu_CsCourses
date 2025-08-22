-- CptS 355 - Lab 1 (Haskell) - Spring 2023
-- Name: Naomi Dion-Gokan


module Lab1
     where
import Data.Time.Format.ISO8601 (dayAndTimeFormat)


-- 1.insert 

copyList [] = []
copyList (x:xs) = x:(copyList xs)

insert2 n [] = []
insert2 n (x:xs) | (n == 0) = xs
                 | otherwise = x:(insert2 (n-1) xs)

 insert n [] = []           
 insert 0 (x:xs) = xs
 insert n (x:xs) = x:(insert2 (n-1) xs )   

-- 2. insertEvery

insertEvery1 n lst = remove_helper n lst nSplit
         where
insert_helper n [] k = []
insert_helper 0 (x:xs) k = (insert_helper k xs k)
insert_helper n (x:xs) k = x:(insert_helper (n-1) xs k)

insertEvery n lst = let
 insert_helper n [] k = []
insert_helper 0 (x:xs) k = (insert_helper k xs k)
insert_helper n (x:xs) k = x:(insert_helper (n-1) xs k)

in
   insert_helper n lst

-- 3. getSales

mystorelog = [("Mon",50), ("Fri",20), ("Tue",20), ("Fri",10), ("Wed",25), ("Fri",30) ]
getSales d [] = 0
getSales d ( (day, amount):xs) | (day == d) = amount + (getSales d xs)
                               | otherwise = (getSales d xs)
                                                  
-- 4. sumSales


mysales = [("Amazon",[("Mon",30),("Wed",100),("Sat",200)]), 
         ("Etsy",[("Mon",50),("Tue",20),("Wed",25),("Fri",30)]), 
         ("Ebay",[("Tue",60),("Wed",100),("Thu",30)]), 
         ("Etsy",[("Tue",100),("Thu",50),("Sat",20),("Tue",10)])] 
 

sumSales store day [] = 0
sumSales store day ((s,log):xs) | (store == s) = (getSales day log) + (sumSales store day xs)
                                  | otherwise = (sumSales store day xs)

-- 5. split

groupby3 list = grouphelper3 list []

grouphelper3 [] buf = (reverse buf):[]
grouphelper3 (x:xs) buf | ( (length buf) == 3) = (reverse buf) : (grouphelper3 xs [x])
                        | otherwise = grouphelper3 xs (x:buf)

split c lst = shelper c lst []
      where
shelper c [] buf = (reverse buf):[]
shelper c (x:xs) buf | (c == x) = (reverse buf) : (shelper c xs [])
                        | otherwise = shelper c xs (x:buf)

-- 6. nSplit

# nSplit c n [] = []
 nSplit c n lst = nSplithelper c n lst []
        where

              nSplithelper c n [] buf | (buf == []) = []
                                 | otherwise = (reverse buf):[] 
          nSplithelper c n (x:xs) buf | (c == x) && (n>0) = (reverse buf):(nSplithelper c (n-1) xs [] )  
                                            | (c /= x) && (n>0) = nSplithelper c n xs (x:buf)     
                                            | otherwise = (x:xs) :[]