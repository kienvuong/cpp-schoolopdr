.PHONY: test run clean

CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib
TEST	:= test

LIBRARIES	:=
MAIN_EXEC	:= $(BIN)/main

TEST_OBJS	:= \
	$(TEST)/main.cpp \
	$(filter-out $(SRC)/main.cpp, $(wildcard $(SRC)/*.cpp))
TEST_EXEC	:= $(BIN)/run_test

all: $(MAIN_EXEC)

test: $(TEST_OBJS)
	@$(CXX) \
		$(CPP_FLAGS) \
		-I$(LIB) \
		-I$(SRC) \
		-I$(TEST) \
		-o$(TEST_EXEC) \
		$(TEST_OBJS) \
		$(TEST_SRC)
	@./$(TEST_EXEC)

run: clean all
	clear
	./$(MAIN_EXEC)

$(MAIN_EXEC): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
