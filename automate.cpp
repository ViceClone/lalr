#include <iostream>
#include "automate.h"
using namespace std;

Automate::Automate(String s){
    accepte = false;
    error = false;
    l(string);
}

void Automate::reduire(int regle) {
    
}

void Automate::transition() {
    while (!(accepte || error) ) {
        Symbole next_sym = l.Consulter();
        int last_state = etatPile.back();
        switch (last_state) {
            case 0:
                if (next_sym == INT) {
                    etatPile.push_back(3);
                    symPile.push_back(INT);
                    l.Avancer();
                } else if (next_sym == OPENPAR) {
                    etatPile.push_back(2);
                    symPile.push_back(OPENPAR);
                    l.Avancer();
                } else {
                    error = true;
                }
                break;
            case 1:
                if (next_sym == PLUS) {
                    etatPile.push_back(4);
                    symPile.push_back(PLUS);
                    l.Avancer();
                } else if (next_sym == MULT) {
                    etatPile.push_back(5);
                    symPile.push_back(MULT);
                    l.Avancer();
                } else if (next_sym == FIN) {
                    accepte = true;
                } else {
                    error = true;
                }
                break;
            case 2:
                if (next_sym == INT) {
                    etatPile.push_back(3);
                    symPile.push_back(INT);
                    l.Avancer();
                } else if (next_sym == OPENPAR) {
                    etatPile.push_back(2);
                    symPile.push_back(OPENPAR);
                    l.Avancer();
                } else {
                    error = true;
                }
                break;
            case 3:
                if (next_sym == PLUS || next_sym == MULT || next_sym == CLOSEPAR || next_sym == FIN) {
                    reduire(5);
                } else {
                    error = true;
                }
                break;
            case 4:
                if (next_sym == INT) {
                    etatPile.push_back(3);
                    symPile.push_back(INT);
                    l.Avancer();
                } else if (next_sym == OPENPAR) {
                    etatPile.push_back(2);
                    symPile.push_back(OPENPAR);
                    l.Avancer();
                } else {
                    error = true;
                }
                break;
        }
    }
    
}