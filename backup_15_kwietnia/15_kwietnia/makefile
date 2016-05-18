FLAGS = -g -Iinc -pedantic -Wall -std=c++11

asoc.out: obj/main.o obj/tab_asc.o obj/List.o obj/tablica.o
	g++ $(FLAGS) obj/main.o obj/tab_asc.o obj/List.o obj/tablica.o -o asoc.out
	
obj/main.o: src/main.cpp inc/tab_asc.h inc/Stoper.h inc/Queue.h
	g++ -c $(FLAGS) -o obj/main.o src/main.cpp

obj/tab_asc.o: src/tab_asc.cpp inc/tab_asc.h inc/Node.h
	g++ -c $(FLAGS) -o obj/tab_asc.o src/tab_asc.cpp

obj/List.o: src/List.cpp inc/List.h inc/IList.h inc/Node.h
	g++ -c $(FLAGS) -o obj/List.o src/List.cpp
	
obj/tablica.o: inc/tablica.h src/tablica.cpp inc/Tom.h inc/List.h inc/IList.h inc/Node.h
	g++ -c $(FLAGS) -o obj/tablica.o src/tablica.cpp

clean: 
	rm -f obj/*.o
