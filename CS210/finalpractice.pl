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
female(heather).
female(judy).
female(miranda).
female(penny).
female(mary).

male(howard).
male(mitchell).
male(joshua).
male(everett).
male(kyle).
male(buck).
male(bill).
male(biff).
male(hank).
male(jimbo).

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

parent(miranda, penny).
parent(miranda, mary).
parent(miranda, buck).
parent(bill, judy).
parent(hank, mary).
parent(buck, miranda).
parent(megan, buck).
parent(bill, hank).
parent(hank, joshua).


% Rules


father(F, X) :- 
	parent(F, X), male(F).

mother(M, X) :- 
	parent(M, X), female(M).

brother(B, X) :- 
	parent(P, B), parent(P, X), male(B), \+(X = B).

sister(S, X) :- 
	parent(P, S), parent(P, X), female(S), \+(X = S).

fullbrother(B, X) :- 
	father(F, B), father(F, X), mother(M, B), mother(M, X), male(B),
	\+(B = X).

fullsister(S, X) :- 
	father(F, S), father(F, X), mother(M, S), mother(M, X), female(S),
	\+(S = X).

halfsibling(H, X) :- 
	parent(P1, H), parent(P2, H), parent(P1, X), parent(P3, X),
	\+(P1 = P2), \+(P2 = P3), \+(P1 = P3).

grandmother(GM, X) :- 
	 mother(GM, P), mother(P, X).

grandfather(GF, X) :- 
	father(GF, P), father(P, X).

uncle(U, X) :- 
	parent(G, U), parent(G, F), parent(F, X), male(U),
	\+(G = U), \+(U = F), \+(U = X), \+(G = F).

aunt(A, X) :- 
	mother(M, X), fullsister(M, A).

