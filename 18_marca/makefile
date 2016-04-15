FLAGS = -g -Iinc -pedantic -Wall -std=c++11

tab_dyn: obj/tablica.o obj/main.o
	g++ $(FLAGS) obj/tablica.o obj/main.o -o tab_dyn

obj/main.o: src/tablica.cpp inc/tablica.h
	g++ -c $(FLAGS) -o obj/main.o src/main.cpp

obj/tablica.o: inc/tablica.h src/tablica.cpp
	g++ -c $(FLAGS) -o obj/tablica.o src/tablica.cpp

clean: rm -f obj/*.o
