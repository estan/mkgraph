all:
	g++ -std=gnu++0x -Wall -pedantic -o mkgraph mkgraph.cpp

clean:
	-@rm -rf mkgraph > /dev/null 2>&1
