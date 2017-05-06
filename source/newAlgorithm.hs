-- newAlgorithm.hs

let ints = [1..9]
    
let strings= ["Only","for","testing","purpose"]

map (\a -> a * a) ints

scanl (*) 1 ints

scanl (+) 0 ints
 
scanl (+) 0 . map(\a -> a * a) $ ints

scanl1 (+) . map(\a -> length a) $ strings

foldl1 (\l r -> l ++ ":" ++ r) strings

foldl (+) 0 . map (\a -> length a) $ strings






