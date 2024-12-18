all: derle calistir

derle: lib/Program.o lib/LinkedList.o lib/LinkedListNode.o lib/BST.o lib/BSTNode.o lib/Queue.o lib/QueueNode.o lib/OuterList.o lib/OuterNode.o lib/InnerNode.o
	g++ -I ./include/ -o ./bin/Program lib/Program.o lib/LinkedList.o lib/LinkedListNode.o lib/BST.o lib/BSTNode.o lib/Queue.o lib/QueueNode.o lib/OuterList.o lib/OuterNode.o lib/InnerNode.o

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

lib/Queue.o: ./src/Queue.cpp
	g++ -I ./include/ -c ./src/Queue.cpp -o lib/Queue.o

lib/QueueNode.o: ./src/QueueNode.cpp
	g++ -I ./include/ -c ./src/QueueNode.cpp -o lib/QueueNode.o

lib/OuterList.o: ./src/OuterList.cpp
	g++ -I ./include/ -c ./src/OuterList.cpp -o lib/OuterList.o

lib/OuterNode.o: ./src/OuterNode.cpp
	g++ -I ./include/ -c ./src/OuterNode.cpp -o lib/OuterNode.o

lib/InnerNode.o: ./src/InnerNode.cpp
	g++ -I ./include/ -c ./src/InnerNode.cpp -o lib/InnerNode.o

calistir:
	./bin/Program