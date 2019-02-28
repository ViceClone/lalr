#include <deque>
#include <iostream>
#include "symbole.h"
#include "lexer.h"
using namespace std;

class Automate {
    public:
        Automate() {}
        ~Automate();
        void lecture(string s);
        void decalage(Symbole * s, Etat * e);
        void reduction(int n, Symbole * s);
    protected:
        Lexer lex;
        deque<Symbole*> symStack;
        deque<Etat*> etatStack;
}