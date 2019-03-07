CPP=g++
FLAGS = -DPRINT -std=c++11
SOURCE = automate.cpp etat.cpp lexer.cpp symbole.cpp
PARSER = main2.cpp
LEXER = main.cpp

parser: $(SOURCE)
	$(CPP) -o parser $(FLAGS) $(SOURCE) $(PARSER)

lexer: $(SOURCE)
	$(CPP) -o lexer $(FLAGS) $(SOURCE) $(LEXER)

clean:
	rm -f parser lexer