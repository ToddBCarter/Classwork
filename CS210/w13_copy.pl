% Facts
female(judith).
female(esther).
female(kaitlyn).
female(aleanna).
female(mackayla).
female(thrud).
female(brunthilda).
female(lornette).
female(bano).
female(fofi).
female(anaya).
female(mayana).
female(megan).
male(howard).
male(mitchell).
male(joshua).
male(everett).
male(kyle).

parent(judith, megan).
parent(aleanna, kaitlyn).
parent(megan, esther).
parent(kyle, mackayla).
parent(joshua, mayana).
parent(howard, megan).
parent(joshua, everett).
parent(mitchell, esther).
parent(anaya, fofi).
parent(anaya, bano).
parent(lornette, thrud).
parent(lornette, brunthilda).

% Rules
father(F,Y) :- parent(F, Y), male(F).
mother(M,Y) :- parent(M, Y), female(M).
grandfather(G,Y) :- parent(G, Z), parent(Z, Y), male(G).
grandmother(G,Y) :- parent(G, Z), parent(Z, Y), female(G).
sister(X,Y) :- parent(Z, X), parent(Z, Y), female(X), \+(X=Y).
brother(X,Y) :- parent(Z, X), parent(Z, Y), male(X), \+(X=Y).
aunt(A,Y) :- sister(A, Z), parent(Z, Y).
uncle(U,Y) :- brother(U, Z), parent(Z, Y).
ancestor(A,Y) :- parent(A, Y).
ancestor(A,Y) :- parent(A, Z), ancestor(Z, Y).