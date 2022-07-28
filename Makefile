CPP_COMPILER = g++
HEADER_FLAGS = -Iinclude/
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

# Running server client_one and client_two simutaneoulsy
run:
	./client_one.out &
	./client_two.out &
	./server.out

# Building client_two client_one server at once
all:
	make server
	make client_one
	make client_two
	git restore *.txt
	clear
	#Console was cleared


# Creating Server
server: build/ build/server.o
	${CPP_COMPILER} -o server.out build/server.o

build/server.o: Server/server.cpp	
	${CPP_COMPILER} -o build/server.o -c Server/server.cpp

# Creating Client One
client_one: build/  build/client_one.o build/window.o build/texture.o
	${CPP_COMPILER} -o client_one.out build/client_one.o build/window.o build/texture.o ${HEADER_FLAGS} ${LINKER_FLAGS}

build/client_one.o: Client/One/client_one.cpp
	${CPP_COMPILER} -o build/client_one.o -c Client/One/client_one.cpp ${HEADER_FLAGS} ${LINKER_FLAGS}

#Creating Client Two
client_two: build/ build/client_two.o build/window.o 
	${CPP_COMPILER} -o client_two.out build/client_two.o build/window.o build/texture.o ${HEADER_FLAGS} ${LINKER_FLAGS}

build/client_two.o: Client/Two/client_two.cpp
	${CPP_COMPILER} -o build/client_two.o -c Client/Two/client_two.cpp ${HEADER_FLAGS} ${LINKER_FLAGS}


#Helper

client_one_run:
	make client_one
	clear
	./client_one.out

client_two_run:
	make client_two
	clear
	./client_two.out

build/window.o: src/window.cpp
	${CPP_COMPILER} -o build/window.o -c src/window.cpp ${HEADER_FLAGS} ${LINKER_FLAGS}

build/texture.o: src/texture.cpp
	${CPP_COMPILER} -o build/texture.o -c src/texture.cpp ${HEADER_FLAGS} ${LINKER_FLAGS}

build/:
	mkdir build

clean:	
	rm -rf build
	rm *.out
