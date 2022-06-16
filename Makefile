COMPILER=gcc
PROGRAM=csvParser
SOURCE=csvParser.cpp
CFLAGS=-lstdc++

test:$(PROGRAM)
$(PROGRAM):$(SOURCE)
	$(COMPILER) -o $(PROGRAM) $(SOURCE) $(CFLAGS)
