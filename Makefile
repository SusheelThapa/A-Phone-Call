CPP_COMPILER = g++
HEADER_FLAGS = -Iinclude/
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

# Telling user to use target if target is not specified
default:
	# Please Specify Some target

# Running server client_one and client_two simutaneoulsy
run:
	make restore
	./client_one.out &
	./client_two.out &
	./server.out

# Building client_two client_one server at once
all:
	make restore 
	make server
	make client_one
	make client_two
	clear
	#Console was cleared


# Creating Server
server: build/ build/server.o build/NTC.o
	${CPP_COMPILER} -o server.out build/server.o build/NTC.o

build/server.o: Server/server.cpp
	${CPP_COMPILER} -o build/server.o -c Server/server.cpp ${HEADER_FLAGS}

# Creating Client One
client_one: build/  build/client_one.o build/window.o build/texture.o build/phone.o build/tone.o build/audio.o build/phonefile.o build/sound.o build/audio_recording.o build/phonescreen.o build/phonesound.o build/phonefont.o 
	${CPP_COMPILER} -o client_one.out build/client_one.o build/window.o build/texture.o build/phone.o build/tone.o build/audio.o build/phonefile.o build/sound.o build/phonescreen.o build/audio_recording.o build/phonesound.o build/phonefont.o  ${HEADER_FLAGS} ${LINKER_FLAGS}

build/client_one.o: Client/One/client_one.cpp
	${CPP_COMPILER} -o build/client_one.o -c Client/One/client_one.cpp ${HEADER_FLAGS} ${LINKER_FLAGS}

#Creating Client Two
client_two: build/ build/client_two.o build/window.o build/texture.o build/phone.o build/tone.o build/audio.o build/phonefile.o build/sound.o build/audio_recording.o build/phonescreen.o build/phonesound.o build/phonefont.o
	${CPP_COMPILER} -o client_two.out build/client_two.o build/window.o build/texture.o build/phone.o build/tone.o build/audio.o build/phonefile.o build/sound.o build/phonescreen.o build/audio_recording.o build/phonesound.o build/phonefont.o ${HEADER_FLAGS} ${LINKER_FLAGS}

build/client_two.o: Client/Two/client_two.cpp
	${CPP_COMPILER} -o build/client_two.o -c Client/Two/client_two.cpp ${HEADER_FLAGS} ${LINKER_FLAGS}


#Helper

client_one_run:
	make restore
	make client_one
	clear
	./client_one.out

client_two_run:
	make restore
	make client_two
	clear
	./client_two.out

build/window.o: src/Client/window.cpp include/Client/window.hpp
	${CPP_COMPILER} -o build/window.o -c src/Client/window.cpp ${HEADER_FLAGS} ${LINKER_FLAGS}

build/texture.o: src/Client/texture.cpp include/Client/texture.hpp
	${CPP_COMPILER} -o build/texture.o -c src/Client/texture.cpp ${HEADER_FLAGS} ${LINKER_FLAGS}

build/phone.o:	src/Client/phone.cpp include/Client/phone.hpp
	${CPP_COMPILER} -o build/phone.o -c src/Client/phone.cpp ${HEADER_FLAGS} ${LINKER_FLAGS}

build/tone.o: src/Client/tone.cpp include/Client/tone.hpp
	${CPP_COMPILER} -o build/tone.o -c src/Client/tone.cpp ${HEADER_FLAGS} ${LINKER_FLAGS}

build/audio.o: src/Client/audio.cpp include/Client/audio.hpp
	${CPP_COMPILER} -o build/audio.o -c src/Client/audio.cpp ${HEADER_FLAGS} ${LINKER_FLAGS}

build/phonefile.o : src/Client/phonefile.cpp include/Client/phonefile.hpp
	${CPP_COMPILER} -o build/phonefile.o -c src/Client/phonefile.cpp ${HEADER_FLAGS} ${LINKER_FLAGS}

build/:
	mkdir build

build/sound.o: src/Client/sound.cpp include/Client/sound.hpp
	${CPP_COMPILER} -o build/sound.o -c src/Client/sound.cpp ${HEADER_FLAGS} ${LINKER_FLAGS}

build/audio_recording.o: src/Client/audio_recording.cpp include/Client/audio_recording.hpp
	${CPP_COMPILER} -o build/audio_recording.o  -c src/Client/audio_recording.cpp ${HEADER_FLAGS}

build/phonescreen.o: src/Client/phonescreen.cpp include/Client/phonescreen.hpp
	${CPP_COMPILER} -o build/phonescreen.o -c src/Client/phonescreen.cpp ${HEADER_FLAGS} ${LINKER_FLAGS}

build/phonesound.o: src/Client/phonesound.cpp include/Client/phonesound.hpp
	${CPP_COMPILER} -o build/phonesound.o -c src/Client/phonesound.cpp ${HEADER_FLAGS} ${LINKER_FLAGS}

build/phonefont.o: src/Client/phonefont.cpp include/Client/phonefont.hpp
	${CPP_COMPILER} -o build/phonefont.o -c src/Client/phonefont.cpp ${HEADER_FLAGS} ${LINKER_FLAGS}


build/NTC.o: src/Server/NTC.cpp include/Server/NTC.hpp
	${CPP_COMPILER} -o build/NTC.o -c src/Server/NTC.cpp ${HEADER_FLAGS} ${LINKER_FLAGS}

clean:	
	rm -rf build
	rm *.out

restore:
	git restore Server/server.txt
	git restore Client/One/client_one.txt
	git restore Client/Two/client_two.txt
	git restore Server/logs.log
