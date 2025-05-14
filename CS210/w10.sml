(*
   id: cart7982

   This program has two functions:
   1. member, which checks if a given element is a member of a given list.
   2. split, which breaks a list into two sublists, one of numbers greater
      than a given pivot and the other of numbers smaller.

   To run:
      sml "w10.sml"
      member (3, [1,2,3,4,5,6]);
      split (3, [1,2,3,4,5,6]);
*)

fun member (a, lst) = List.exists (fn y => y = a) lst;

fun split (a, []) = ([], [])
   | split (a, x::xs) =
      let
         val (less, greater) = split (a, xs)
      in
         if x < a then (x::less, greater)
         else if x > a then (less, x::greater)
         else (less, greater)
      end;