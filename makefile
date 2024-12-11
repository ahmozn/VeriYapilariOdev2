all: derle calistir

derle: lib/Program.o lib/LinkedList.o lib/LinkedListNode.o lib/BST.o lib/BSTNode.o
	g++ -I ./include/ -o ./bin/Program lib/Program.o lib/LinkedList.o lib/LinkedListNode.o lib/BST.o lib/BSTNode.o

lib/Program.o: ./src/Program.cpp
	g++ -I ./include/ -c ./src/Program.cpp -o lib/Program.o

lib/LinkedList.o: ./src/LinkedList.cpp
	g++ -I ./include/ -c ./src/LinkedList.cpp -o lib/LinkedList.o

lib/LinkedListNode.o: ./src/LinkedListNode.cpp
	g++ -I ./include/ -c ./src/LinkedListNode.cpp -o lib/LinkedListNode.o

lib/BST.o: ./src/BST.cpp
	g++ -I ./include/ -c ./src/BST.cpp -o lib/BST.o

lib/BSTNode.o: ./src/BSTNode.cpp
	g++ -I ./include/ -c ./src/BSTNode.cpp -o lib/BSTNode.o

calistir:
	./bin/Program