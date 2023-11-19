# Makefile
# Build rules for EECS 280 project 3

# Compiler
CXX ?= g++

# Compiler flags
CXXFLAGS ?= --std=c++17 -Wall -Werror -pedantic -g -Wno-sign-compare -Wno-comment

FILES := \
  Card.cpp \
  Pack.cpp \
  Blackjack.cpp \
  HigherOrLower.cpp \
  Casino.cpp \
  Roulette.cpp

# Run a regression test

# Executable name
EXECUTABLE := my_program

# Default target
all: $(EXECUTABLE)

$(EXECUTABLE): $(FILES)
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(FILES)

.PHONY: clean style

clean:
	rm -rvf $(EXECUTABLE) *.out *.exe *.dSYM *.stackdump

# Style check
CPD ?= /usr/um/pmd-6.0.1/bin/run.sh cpd
OCLINT ?= /usr/um/oclint-0.13/bin/oclint