FLAGS = -g -Iinc -pedantic -Wall -std=c++11

asoc.out: obj/main.o obj/List.o obj/tab_asc.o
	g++ $(FLAGS) $^ -o $@
	
obj/main.o: src/main.cpp inc/tab_asc.h inc/tablica.h inc/List.h
	g++ -c $(FLAGS) -o obj/main.o src/main.cpp

obj/tab_asc.o: src/tab_asc.cpp inc/tab_asc.h inc/List.h inc/tablica.h
	g++ -c $(FLAGS) -o obj/tab_asc.o src/tab_asc.cpp

obj/List.o: src/List.cpp inc/List.h inc/IList.h inc/Node.h
	g++ -c $(FLAGS) -o obj/List.o src/List.cpp
	
obj/tablica.o: inc/tablica.h inc/Tom.h inc/List.h inc/IList.h inc/Node.h
	g++ -c $(FLAGS) -o obj/tablica.o src/tablica.h

clean: 
	rm -f obj/*.o
