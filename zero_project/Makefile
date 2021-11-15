CC=g++

INCLUDE_DIR=includes

CFLAGS = -Wall

LDFLAGS=

EXEC=exec_main

SCR=$(wildcard *.cpp) $(wildcard */*.cpp) $(wildcard */*/*.cpp) $(wildcard */*/*/*.cpp)  $(wildcard */*/*/*/*.cpp)

OBJ=$(SCR:.cpp=.o)

all:$(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CFLAGS) -I $(INCLUDE_DIR)

clean:
	rm -f *.o core
	find . -name '*.o' -delete
	

mrproper: clean
	rm -f $(EXEC)