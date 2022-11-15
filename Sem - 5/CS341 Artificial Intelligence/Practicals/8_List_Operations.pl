list_member(X, [X|_]).
list_member(X, [_|TAIL]) :- list_member(X, TAIL).
list_length([],0).
list_length([_|TAIL],N) :- list_length(TAIL,N1), N is N1 + 1.
print_list([X|TAIL]) :- write(X), nl, print_list(TAIL).
list_concat([],L,L).
list_concat([X1|L1],L2,[X1|L3]) :- list_concat(L1,L2,L3).
list_delete(X, [X], []).
list_delete(X,[X|L1], L1).
list_delete(X, [Y|L2], [Y|L1]) :- list_delete(X,L2,L1).
list_insert(X,L,R) :- list_delete(X,R,L).
list_append(A,T,T) :- list_member(A,T),!.
list_append(A,T,[A|T]).
list_perm([],[]).
list_perm(L,[X|P]) :- list_delete(X,L,L1),list_perm(L1,P).
index_of(X, [X|_], 1).
index_of(X, [_|TAIL], N) :- index_of(X, TAIL, N1), N is N1+1.
element_at(X,[X|_],1).
element_at(X,[_|L],K) :- element_at(X,L,K1), K is K1 + 1.
list_divide([],[],[]).
list_divide([X],[X],[]).
list_divide([X,Y|Tail], [X|List1],[Y|List2]):- list_divide(Tail,List1,List2).
