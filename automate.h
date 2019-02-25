#include <deque>
#include <iostream>
#include "symbole.h"
#include "lexer.h"
using namespace std;


class Automate {
    public:
        Automate(String s);
        void decaler(int etat);
        void reduire(int regle);
        void transition();
    protected:
        deque<Symbole> symPile;
        deque<int> etatPile;
        Lexer l;
        bool accepte;
        bool error;
}