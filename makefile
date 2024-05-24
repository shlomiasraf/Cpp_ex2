CXX=clang++
CXXFLAGS=-std=c++11 -Werror
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

SOURCESDemo = Algorithms.cpp BellmanFord.cpp BFS.cpp DFS.cpp Dijkstra.cpp Graph.cpp demo.cpp
SOURCESTest = Algorithms.cpp BellmanFord.cpp BFS.cpp DFS.cpp Dijkstra.cpp Graph.cpp testCounter.cpp tests.cpp
OBJECTSDemo = $(SOURCESDemo:.cpp=.o) 
OBJECTSTest = $(SOURCESTest:.cpp=.o) 

runDemo: demo
	./demo

runTest: testCounter
	./testCounter

demo: $(OBJECTSDemo)
	$(CXX) $(CXXFLAGS) $^ -o $@

testCounter: $(OBJECTSTest)
	$(CXX) $(CXXFLAGS) $^ -o $@

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

valgrind: demo testCounter
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./testCounter 2>&1 | { egrep "lost| at " || true; }

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o demo testCounter
