#pragma once

#include <deque>
#include <iostream>
#include "symbole.h"
#include "etat.h"
#include "lexer.h"

class Etat;
class Automate {
    public:
        Automate();
        ~Automate();
        void lecture(string s);
        void decalage(Symbole * s, Etat * e);
        void reduction(int n, Symbole * s);
        Symbole * popSymbole();
        void popAndDestroySymbole();
        void printStacks();
        void setError(bool errVal);
    protected:
        Lexer * lexer;
        deque<Symbole*> symStack;
        deque<Etat*> etatStack;
        bool error;
};
