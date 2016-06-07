FLAGS = -g -Iinc -pedantic -Wall -std=c++11

tab_dyn.out: obj/Tablica.o obj/main.o
	g++ $(FLAGS) obj/Tablica.o obj/main.o -o tab_dyn.out

obj/main.o: src/Tablica.cpp inc/Tablica.hh inc/Stoper.hh
	g++ -c $(FLAGS) -o obj/main.o src/main.cpp

obj/Tablica.o: inc/Tablica.hh src/Tablica.cpp inc/ITablica.hh
	g++ -c $(FLAGS) -o obj/Tablica.o src/Tablica.cpp

clean:
	rm -f obj/*.o
