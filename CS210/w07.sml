(*
   id: cart7982

   This program has four simple functions:
   1. A square of the given parameter.
   2. A recursion that finds the sums of the squares of a list.
   3. A removal of elements from the front a list and appending to the end.
   4. The same as 3, but appending in reverse order.

   To run:
      sml w07.sml;
      square [5];

*)

fun sq x = x*x;

fun sqsum([]) = 0
|	sqsum(x::xs) = (x * x) + sqsum(xs);

fun get_n([], _) = ([], [])
|	get_n(xs, 0) = ([], xs)
|	get_n(x::xs, n) =
	let
		val (front, back) = get_n(xs, n - 1)
	in
		(x::front, back)
	end;

fun reverse(nil) = (nil)
|	reverse(x::xs) =
		reverse(xs) @ [x];

fun cycle(xs, n) =
	let
		val (front, back) = get_n(xs, n)
	in
		back @ front
	end;


fun semrev(xs, n) =
	let
		val (front, back) = get_n(xs, n)
	in
		back @ (reverse(front))
	end;


fun addToListHead(x, xs) = 
	x :: xs;

fun addToListTail(x, xs) = 
	xs @ x;

fun length x =
	if x = [] then 0
	else 1 + length (tl x);







(*
Not assignment:

fun exploder(L) =
    if null L then nil
	else (
		print (String.toString(" ") ^ Int.toString(hd L);
		exploder(hd L);  //all this to print out head of the list
	);


fun reverse L = 
	if null L = (nil);
	else reverse(tl L) @ [hd L];  //Put in the brackets, makes a list
									//basically python, really
*)