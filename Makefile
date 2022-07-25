CPP_COMPILER = g++
HEADER_FLAGS = -Iinclude/
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf


# Creating Server
server: build/ build/server.o
	${CPP_COMPILER} -o server.out build/server.o

build/server.o: Server/server.cpp	
	${CPP_COMPILER} -o build/server.o -c Server/server.cpp

# Creating Client One
client_one: build/  build/client_one.o build/window.o
	${CPP_COMPILER} -o client_one.out build/client_one.o build/window.o ${HEADER_FLAGS} ${LINKER_FLAGS}

build/client_one.o: Client/One/client_one.cpp
	${CPP_COMPILER} -o build/client_one.o -c Client/One/client_one.cpp ${HEADER_FLAGS} ${LINKER_FLAGS}

#Creating Client Two
client_two: build/ build/client_two.o build/window.o
	${CPP_COMPILER} -o client_two.out build/client_two.o build/window.o ${HEADER_FLAGS} ${LINKER_FLAGS}

build/client_two.o: Client/Two/client_two.cpp
	${CPP_COMPILER} -o build/client_two.o -c Client/Two/client_two.cpp ${HEADER_FLAGS} ${LINKER_FLAGS}


#Helper
build/window.o: src/window.cpp
	${CPP_COMPILER} -o build/window.o -c src/window.cpp ${HEADER_FLAGS} ${LINKER_FLAGS}

build/:
	mkdir build

clean:	
	rm -rf build
	rm *.out
