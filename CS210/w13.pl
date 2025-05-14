% Rules
father(F,Y) :- parent(F, Y), male(F).
mother(M,Y) :- parent(M, Y), female(M).
grandfather(G,Y) :- parent(G, Z), parent(Z, Y), male(G).
grandmother(G,Y) :- parent(G, Z), parent(Z, Y), female(G).
sister(X,Y) :- parent(Z, X), parent(Z, Y), female(X).
brother(X,Y) :- parent(Z, X), parent(Z, Y), male(X).
aunt(A,Y) :- sister(A, Z), parent(Z, Y).
uncle(U,Y) :- brother(U, Z), parent(Z, Y).
ancestor(A,Y) :- parent(A, Y).
ancestor(A,Y) :- parent(A, Z), ancestor(Z, Y).