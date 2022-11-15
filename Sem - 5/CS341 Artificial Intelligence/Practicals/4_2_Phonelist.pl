store('Ayush',1231231230,'August').
store('Jay',1425258258,'August').
store('Yash',1475456545,'January').
store('Karan',1425875465,'May').
store('Om',1478524752,'July').
store('Vraj',47545447544,'August').
store('Mit',25465582555,'August').

birth(X,Y,Z) :- store(X,Y,Z), write(month).
