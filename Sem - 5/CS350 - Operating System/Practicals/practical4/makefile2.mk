a.out : hello1

hello1 : calculator.hh add.cpp
	g++ -o hello1 add.cpp
