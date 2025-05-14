% Compile: gplc w13.pl
%    Run: /   ./w13
%    sudoku([_,_,2,3, _,_,_,_, _,_,_,_, 3,4,_,_], Sol).

% To Run
% gprolog
% consult(w13).
% sudoku([_,_,2,3, _,_,_,_, _,_,_,_, 3,4,_,_], Sol).

%      Sol = [4,1,2,3,
%             2,3,4,1,
%             1,2,3,4,
%             3,4,1,2]

% Our puzzle accepts the digits 1-4, so we have to tell the program what an
% acceptabel digit is.
d(1).
d(2).
d(3).
d(4).

%This function takes 4 Variables, and confirms that each one is a digit (1-4)
%then confimrs that they are all different.
%Note: It is important that the check for them being digits comes first. (Why?)
%You need to finish this funciton.

check([A,B,C,D]):-
     d(A), d(B), d(C), d(D),
	\+(A = B), \+(B = C), \+(C = D), \+(A = C), \+(A = D), \+(B = D).

% This is the main function.
sudoku(Puzzle, Solution) :-
                  Solution = Puzzle,
                  Puzzle = [
                     S11,S12,S13,S14,
                     S21,S22,S23,S24,
                     S31,S32,S33,S34,
                     S41,S42,S43,S44
                  ],
                  check([S11,S12,S13,S14]),
                  check([S21,S22,S23,S24]),
                  check([S31,S32,S33,S34]),
                  check([S41,S42,S43,S44]),
                  check([S11,S21,S31,S41]),
                  check([S12,S22,S32,S42]),
                  check([S13,S23,S33,S43]),
                  check([S14,S24,S34,S44]).


