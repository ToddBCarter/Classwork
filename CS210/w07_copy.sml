fun square x = x*x;

fun squaresum ([]) = 0
|	squaresum(x::xs) = (x*x) + squaresum(xs);

(*reverse with recursion*)
fun reverse (nil) = nil
|	reverse (x::xs) = reverse(xs) @ [x];


fun cycle ([], _) = []
|	cycle (L, 0) = L (*base case*)
|	cycle (x::xs, n) = cycle(xs @ [x], n-1);

fun semrev ([], _) = []
|	semrev (L, 0) = L
|	semrev (x::xs, n) = semrev(xs, n-1) @ [x];

fun spinthatdisc([], _) = []
|	spinthatdisc (L, 0) = reverse(L)
|	spinthatdisc(x::xs, n) = spinthatdisc(xs @ [x], n-1);

fun spin([], _) = []
|	spin (L, 0) = L
|	spin(x::xs, n) = spin(xs @ reverse([x]), n-1);