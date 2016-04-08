FLAGS = -g -Iinc -pedantic -Wall -std=c++11

lista: obj/List.o obj/test.o
	g++ obj/List.o obj/test.o -o lista
	
obj/test.o: src/test.cpp inc/List.h
	g++ -c $(FLAGS) src/test.cpp -o obj/test.o

obj/Stack.o: src/Stack.cpp inc/Stack.h
	g++ -c $(FLAGS) -o obj/Stack.o src/Stack.cpp

obj/List.o: src/List.cpp inc/List.h inc/IList.h
	g++ -c $(FLAGS) -o obj/List.o src/List.cpp

clean: 
	rm -f obj/*.o
