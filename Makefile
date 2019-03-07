CPP=g++
FLAGS = -DPRINT -std=c++11
SOURCE = automate.cpp etat.cpp lexer.cpp main2.cpp symbole.cpp

main: $(SOURCE)
	$(CPP) -o main $(FLAGS) $(SOURCE)

clean:
	rm -f main