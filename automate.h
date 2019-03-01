#include <deque>
#include <iostream>
#include "symbole.h"
#include "lexer.h"
#include "etat.h"
using namespace std;

class Automate {
    public:
        Automate() {}
        ~Automate();
        void lecture(string s);
        void decalage(Symbole * s, Etat * e);
        void reduction(int n, Symbole * s);
        Symbole * popSymbole();
        void popAndDestroySymbole();
        void print();
    protected:
        Lexer * lexer;
        deque<Symbole*> symStack;
        deque<Etat*> etatStack;
}