male('Champak').
male('Jethalal').
male('Tapu').
male('Iyer').
male('Parth').

female('Sarla').
female('Daya').
female('Sonu').
female('Babita').
female('Devi').

parent('Champak','Jethalal').
parent('Sarla','Jethalal').
parent('Champak', 'Babita').
parent('Sarla','Babita').

parent('Jethalal','Tapu').
parent('Daya','Tapu').
parent('Jethalal','Sonu').
parent('Daya','Sonu').

parent('Babita','Parth').
parent('Iyer','Parth').
parent('Babita','Devi').
parent('Iyer','Devi').

father(X,Y):-male(X),parent(X,Y).
mother(X,Y):-female(X),parent(X,Y).

brother(X,Y):-male(X),father(Z,X),parent(Z,Y),X\==Y.
sister(X,Y):-female(X),father(Z,X),parent(Z,Y),X\==Y.
grandparent(X,Y):-parent(X,Z),parent(Z,Y).

grandfather(X,Y):-male(X),grandparent(X,Y).
grandmother(X,Y):-female(X),grandparent(X,Y).

uncle(X,Y):-brother(X,Z),parent(Z,Y).
aunt(X,Y):-sister(X,Z),parent(Z,Y).

niece(X,Y):-female(X),aunt(Y,X).
niece(X,Y):-female(X),uncle(Y,X).

nephew(X,Y):-male(X),aunt(Y,X).
nephew(X,Y):-male(X),uncle(Y,X).

cousin(X,Y):-aunt(Z,X),parent(Z,Y),X\==Y.
cousin(X,Y):-uncle(Z,X),parent(Z,Y), X\==Y.
