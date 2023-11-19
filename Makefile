# Makefile
# Build rules for EECS 280 project 3

# Compiler
CXX ?= g++

# Compiler flags
CXXFLAGS ?= --std=c++17 -Wall -Werror -pedantic -g -Wno-sign-compare -Wno-comment

# Run a regression test


.SUFFIXES:

.PHONY: clean

clean:
	rm -rvf *.out *.exe *.dSYM *.stackdump

# Style check
CPD ?= /usr/um/pmd-6.0.1/bin/run.sh cpd
OCLINT ?= /usr/um/oclint-0.13/bin/oclint
FILES := \
  Card.cpp \
  Pack.cpp \
  Blackjack.cpp \
  HigherOrLower.cpp \
  Casino.cpp \
  Roulette.cpp
CPD_FILES := \
  Card.cpp \
  Pack.cpp \
  Blackjack.cpp \
  HigherOrLower.cpp \
  Casino.cpp \
  Roulette.cpp
style :
	$(OCLINT) \
    -no-analytics \
    -rule=LongLine \
    -rule=HighNcssMethod \
    -rule=DeepNestedBlock \
    -rule=TooManyParameters \
    -rc=LONG_LINE=90 \
    -rc=NCSS_METHOD=40 \
    -rc=NESTED_BLOCK_DEPTH=4 \
    -rc=TOO_MANY_PARAMETERS=4 \
    -max-priority-1 0 \
    -max-priority-2 0 \
    -max-priority-3 0 \
    $(FILES) \
    -- -xc++ --std=c++17
	$(CPD) \
    --minimum-tokens 100 \
    --language cpp \
    --failOnViolation true \
    --files $(CPD_FILES)
	@echo "########################################"
	@echo "EECS 280 style checks PASS"