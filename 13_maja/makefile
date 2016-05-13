FLAGS = -g -Iinc -pedantic -Wall -std=c++11

graf.out: obj/Graf.o obj/main.o obj/Queue.o obj/List.o obj/Stack.o
	g++ $(FLAGS) obj/Graf.o obj/main.o obj/Queue.o obj/List.o obj/Stack.o -o graf.out
	
generuj.out: src/generuj.cpp
	g++ $(FLAGS) src/generuj.cpp -o generuj.out

obj/main.o: inc/Graf.hh src/main.cpp inc/Stoper.h
	g++ -c $(FLAGS) -o obj/main.o src/main.cpp

obj/Graf.o: inc/Graf.hh src/Graf.cpp inc/IGraf.hh inc/Queue.h inc/Stack.h
	g++ -c $(FLAGS) -o obj/Graf.o src/Graf.cpp

obj/Queue.o: src/Queue.cpp inc/Queue.h 
	g++ -c $(FLAGS) -o obj/Queue.o src/Queue.cpp

obj/Stack.o: src/Stack.cpp inc/Stack.h
	g++ -c $(FLAGS) -o obj/Stack.o src/Stack.cpp

obj/List.o: src/List.cpp inc/List.h inc/IList.h
	g++ -c $(FLAGS) -o obj/List.o src/List.cpp
	
clean: 
	rm -f obj/*.o
