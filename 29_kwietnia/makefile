FLAGS = -g -Iinc -pedantic -Wall -std=c++11

drzewo.out: obj/Drzewo.o obj/main.o
	g++ $(FLAGS) obj/Drzewo.o obj/main.o -o drzewo.out

obj/main.o: inc/Drzewo.hh src/main.cpp inc/Stoper.hh
	g++ -c $(FLAGS) -o obj/main.o src/main.cpp

obj/Drzewo.o: inc/Drzewo.hh src/Drzewo.cpp inc/Node.hh
	g++ -c $(FLAGS) -o obj/Drzewo.o src/Drzewo.cpp

clean: 
	rm -f obj/*.o
