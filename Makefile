CC=g++
CFLAGS=-Wall -std=c++11
SRC=src
OBJ=obj
SRCS=$(wildcard $(SRC)/*.cpp)
OBJS=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))

all: $(OBJ) prog infix

$(OBJ):
	mkdir $(OBJ)

$(OBJ)/%.o: $(SRC)/%.cpp $(SRC)/%.hpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

prog: $(OBJ)/stack.o $(OBJ)/parser.o $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $@ $^

infix: $(OBJ)/stack.o $(OBJ)/parser.o $(SRC)/infix.cpp
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS) prog infix