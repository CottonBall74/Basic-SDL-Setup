CXX = g++

CXXFLAGS = -Wall -g -Iinclude -std=c++14
sdlFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

FILES = src/*.cpp

NAME = something


exec: build
	./bin/something.out

build: $(FILES)
	$(CXX) $(CXXFLAGS) $(sdlFLAGS) $(FILES) -o bin/something.out

run:
	./bin/something.out

clean:
	rm -rf bin/*.out