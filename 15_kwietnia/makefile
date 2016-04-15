FLAGS = -g -Iinc -pedantic -Wall -std=c++11

przeszukanie: obj/Queue.o obj/main.o obj/List.o
	g++ $(FLAGS) $^ -o $@

kolejka: obj/Queue.o obj/List.o
	g++ $(FLAGS) $^ -o $@

stos: obj/Stack.o obj/List.o
	g++ $(FLAGS) $^ -o $@

lista: obj/List.o obj/test.o
	g++ obj/List.o obj/test.o -o lista
	
obj/main.o: src/main.cpp inc/List.h inc/Stoper.h inc/Queue.h
	g++ -c $(FLAGS) -o obj/main.o src/main.cpp
	
obj/test.o: src/test.cpp inc/List.h
	g++ -c $(FLAGS) src/test.cpp -o obj/test.o

obj/Queue.o: src/Queue.cpp inc/Queue.h 
	g++ -c $(FLAGS) -o obj/Queue.o src/Queue.cpp

obj/Stack.o: src/Stack.cpp inc/Stack.h
	g++ -c $(FLAGS) -o obj/Stack.o src/Stack.cpp

obj/List.o: src/List.cpp inc/List.h inc/IList.h
	g++ -c $(FLAGS) -o obj/List.o src/List.cpp

clean: 
	rm -f obj/*.o
