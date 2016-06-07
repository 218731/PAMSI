FLAGS = -g -Iinc -pedantic -Wall -std=c++11

graf.out: obj/Graf.o obj/main.o obj/Queue.o obj/List.o obj/Stack.o obj/PQueue.o
	g++ $(FLAGS) obj/Graf.o obj/main.o obj/Queue.o obj/List.o obj/Stack.o obj/PQueue.o -o graf.out

test.out: obj/PQueue.o obj/test.o
	g++ ${FLAGS} obj/PQueue.o obj/test.o -o test.out
	
generuj.out: src/generuj.cpp
	g++ $(FLAGS) src/generuj.cpp -o generuj.out

obj/test.o: src/test.cpp inc/PQueue.h
	g++ ${FLAGS} -c src/test.cpp -o obj/test.o

obj/main.o: inc/Graf.hh src/main.cpp inc/Stoper.h
	g++ -c $(FLAGS) -o obj/main.o src/main.cpp

obj/Graf.o: inc/Graf.hh src/Graf.cpp inc/IGraf.hh inc/PQueue.h inc/Stack.h
	g++ -c $(FLAGS) -o obj/Graf.o src/Graf.cpp

obj/Queue.o: src/Queue.cpp inc/Queue.h 
	g++ -c $(FLAGS) -o obj/Queue.o src/Queue.cpp
	
obj/PQueue.o: src/PQueue.cpp inc/PQueue.h 
	g++ -c $(FLAGS) -o obj/PQueue.o src/PQueue.cpp

obj/Stack.o: src/Stack.cpp inc/Stack.h
	g++ -c $(FLAGS) -o obj/Stack.o src/Stack.cpp

obj/List.o: src/List.cpp inc/List.h inc/IList.h
	g++ -c $(FLAGS) -o obj/List.o src/List.cpp
	
clean: 
	rm -f obj/*.o
