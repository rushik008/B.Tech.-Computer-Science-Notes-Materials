meeting(ram,kishan).
meeting(kishan,ram).
meeting(lakhan,balram).

brothers(X,Y):-
meeting(X,Y),
meeting(Y,X),write('yes they are brothers').

friendship(X,Y):-
meeting(Y,X),write('they are friends').

friendship(X,Y):-
meeting(X,Y),write('they are friends').
