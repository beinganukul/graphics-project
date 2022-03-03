NAME = main
SRC = $(wildcard *.cpp) 
BASEPATH = bin/release
OUTPUT = $(BASEPATH)/main
LDFLAGS = -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
CXXFLAGS = -std=c++14 -O3 -Wall -Wextra -m64 -I include

all: compile build 

build: $(SRC)
	$(CXX) *.o -o $(OUTPUT) -s $(LDFLAGS)

compile: $(SRC)
	$(CXX) -c $(SRC) $(CXXFLAGS)

create-output-dir:
	mkdir -p $(BASEPATH)

clean:
	rm -rf $(SRC:.cpp=.o) $(BASEPATH)
#creating makefile is actually easy
