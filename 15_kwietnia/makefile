FLAGS = -g -Iinc -pedantic -Wall -std=c++11

asoc.out: obj/main.o obj/tab_asc.o obj/List.o obj/tab_hash.o
	g++ $(FLAGS) obj/main.o obj/tab_asc.o obj/List.o obj/tab_hash.o -o asoc.out
	
obj/main.o: src/main.cpp inc/tab_asc.h inc/Stoper.h inc/Queue.h inc/tab_hash.h
	g++ -c $(FLAGS) -o obj/main.o src/main.cpp

obj/tab_asc.o: src/tab_asc.cpp inc/tab_asc.h inc/tab_hash.h
	g++ -c $(FLAGS) -o obj/tab_asc.o src/tab_asc.cpp

obj/tab_hash.o: src/tab_hash.cpp inc/tab_hash.h inc/Tom.h
	g++ -c $(FLAGS) -o obj/tab_hash.o src/tab_hash.cpp
	
obj/List.o: src/List.cpp inc/List.h inc/IList.h inc/Node.h
	g++ -c $(FLAGS) -o obj/List.o src/List.cpp

clean: 
	rm -f obj/*.o
	