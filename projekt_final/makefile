FLAGS = -g -Iinc -pedantic -Wall -std=c++11

prog.out: obj/main.o obj/tinyxml.o obj/tinystr.o obj/tinyxmlparser.o obj/tinyxmlerror.o obj/Graph.o obj/List.o obj/queue.o
	g++ ${FLAGS} obj/main.o obj/tinyxml.o obj/tinystr.o obj/tinyxmlparser.o obj/tinyxmlerror.o obj/Graph.o obj/List.o obj/queue.o -o prog.out

parser.out: obj/List.o obj/Graph.o obj/queue.o obj/parser.o obj/tinyxml.o obj/tinystr.o obj/tinyxmlparser.o obj/tinyxmlerror.o
	g++ ${FLAGS} obj/List.o obj/Graph.o obj/parser.o obj/tinyxml.o obj/tinystr.o obj/tinyxmlparser.o obj/tinyxmlerror.o -o parser.out

test.out: inc/queue.hh test.cpp
	g++ ${FLAGS} test.cpp -o test.out
	
obj/parser.o: src/parser.cpp inc/Graph.hh
	g++ ${FLAGS} -c src/parser.cpp -o obj/parser.o

obj/main.o: src/main.cpp inc/parser.hh inc/Graph.hh inc/queue.hh
	g++ ${FLAGS} -c src/main.cpp -o obj/main.o

obj/Graph.o: inc/IGraph.hh inc/Graph.hh src/Graph.cpp inc/List.hh inc/queue.hh
	g++ ${FLAGS} -c src/Graph.cpp -o obj/Graph.o

obj/List.o: inc/IList.hh inc/List.hh src/List.cpp
	g++ ${FLAGS} -c src/List.cpp -o obj/List.o

obj/queue.o: inc/queue.hh src/queue.cpp inc/tab.hh
	g++ ${FLAGS} -c src/queue.cpp -o obj/queue.o

obj/tinyxmlparser.o: tinyxml/tinyxmlparser.cpp
	g++ ${FLAGS} -c tinyxml/tinyxmlparser.cpp -o obj/tinyxmlparser.o

obj/tinyxmlerror.o: tinyxml/tinyxmlerror.cpp
	g++ ${FLAGS} -c tinyxml/tinyxmlerror.cpp -o obj/tinyxmlerror.o

obj/tinyxml.o: tinyxml/tinyxml.h tinyxml/tinyxml.cpp
	g++ ${FLAGS} -c tinyxml/tinyxml.cpp -o obj/tinyxml.o

obj/tinystr.o: tinyxml/tinystr.h tinyxml/tinystr.cpp
	g++ ${FLAGS} -c tinyxml/tinystr.cpp -o obj/tinystr.o

clean: 
	rm -f obj/*.o

obj:
	mkdir obj/
