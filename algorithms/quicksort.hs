qsort :: Ord x => [x] -> [x]
qsort []     = []
qsort (x:xs) = (qsort lesser) ++ [x] ++ (qsort greater) 
    where 
        lesser  = filter (<=x) xs
        greater = filter (> x) xs
