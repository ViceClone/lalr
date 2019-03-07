using namespace std;
#include <iostream>
#include <deque>
#include "automate.h"

Automate::Automate() {
    etatStack.push_back(new E0);
    error = false;
}

Automate::~Automate() {
    for (int i=0; i < symStack.size(); ++i) {
        delete symStack[i];
    }

    for (int i=0; i < etatStack.size(); ++i) {
        delete etatStack[i];
    }

    delete lexer;
}

void Automate::decalage(Symbole * s, Etat * e) {
    symStack.push_back(s);
    etatStack.push_back(e);
    if (s->isTerminal()) {
        lexer->Avancer();
    }
}

void Automate::reduction(int n, Symbole * s) {
    for (int i=0; i<n; i++) {
        delete (etatStack.back());
        etatStack.pop_back();
    }
    etatStack.back()->transition(*this, s);
}

Symbole * Automate::popSymbole() {
    Symbole * s = symStack.back();
    symStack.pop_back();
    return s;
}

void Automate::popAndDestroySymbole() {
    delete (symStack.back());
    symStack.pop_back();
}

void Automate::setError(bool errVal) {
    error = errVal;
}

void Automate::lecture(string str) {
    lexer = new Lexer(str);
    error = false;
    bool stop = false;
    do {
        Symbole * s = lexer->Consulter();
        stop = etatStack.back()->transition(*this, s);
    } while (!stop);

    if (!error) {
        cout << "Calc: " << symStack.back()->getValue() << endl;
    } else {
        cout << "An error occured." << endl;
    }
    
}

//TODO printStacks

void Automate::printStacks() {
    cout << "State Stack: ";
    for (int i=0; i<etatStack.size(); i++) {
        cout << etatStack[i]->toString() << "  ";
    }
    cout << endl;
    cout << "Symbol Stack: ";
    for (int i=0; i<symStack.size(); i++) {
        cout << symStack[i]->toString() << "  ";
    }
    cout << endl;
    cout << "----------------" << endl;
}