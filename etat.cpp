using namespace std;
#include <iostream>
#include "etat.h"

void Etat::print() const {
    cout << "a state" << endl;
}

bool E0::transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case INT:
            automate.decalage(s, new E3);
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case CLOSEPAR:
        case PLUS:
        case MULT:
        case FIN:
        case EXPR:
            automate.decalage(s, new E1);
            break;
    }
    return false;
}

bool E1::transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case INT:
        case OPENPAR:
        case CLOSEPAR:
        case PLUS:
            automate.decalage(s, new E4);
            break;
        case MULT:
            automate.decalage(s, new E5);
        case FIN:
            return true;
            break;
        case EXPR:
    }
    return false;
}

bool E2::transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case INT:
            automate.decalage(s, new E3);
            break;
        case OPENPAR:
            automate.decalage(s, new E2);
            break;
        case CLOSEPAR:
        case PLUS:
        case MULT:
        case FIN:
        case EXPR:
            automate.decalage(s, new E6);
            break;
    }
    return false;
}

bool E3::transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case INT:
            break;
        case OPENPAR:
            break;
        default:
            Entier * s1 =  (Entier *)automate.popSymbole();
            int n = s1->getVal();
            delete s1;
            automate.reduction(1, new ExprEntier(n));
            break;
    }
    return false;
}

bool E4::transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case INT:
            automate.decalage(s,new E3);
            break;
        case OPENPAR:
            automate.decalage(s,new E2);
            break;
        case CLOSEPAR:
        case PLUS:
        case MULT:
        case FIN:
        case EXPR:
            automate.decalage(s,new E7);
            break;
    }
    return false;
}

bool E5::transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case INT:
            automate.decalage(s,new E3);
            break;
        case OPENPAR:
            automate.decalage(s,new E2);
            break;
        case CLOSEPAR:
        case PLUS:
        case MULT:
        case FIN:
        case EXPR:
            automate.decalage(s,new E8);
            break;
    }
    return false;
}

bool E6::transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case INT:
        case OPENPAR:
        case CLOSEPAR:
            automate.decalage(s,new E9);
            break;
        case PLUS:
            automate.decalage(s,new E4);
            break;
        case MULT:
            automate.decalage(s,new E5);
            break;
        case FIN:
        case EXPR:
    }
    return false;
}


bool E7::transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case INT:
            break;
        case OPENPAR:
            break;
        case MULT:
            automate.decalage(s, new E5);
            break;
        case EXPR:
            break;
        default:
            s1 = (Expr *) automate.popSymbole();
            automate.popAndDestroySymbole();
            s2 = (Expr *) automate.popSymbole();
            automate.reduction(3, new ExprPlus(s2,s1));
            break;
    }
    return false;
}

bool E8::transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case INT:
            break;
        case OPENPAR:
            break;
        case EXPR:
            break;
        default:
            s1 = (Expr *) automate.popSymbole();
            automate.popAndDestroySymbole();
            s2 = (Expr *) automate.popSymbole();
            automate.reduction(3, new ExprMult(s2,s1));
            break;
    }
    return false;
}

bool E9::transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case INT:
            break;
        case OPENPAR:
            break;
        case EXPR:
            break;
        default:
            automate.popAndDestroySymbole();
            Expr * s1 = (Expr *) automate.popSymbole();
            automate.popAndDestroySymbole();
            automate.reduction(3, s1);
            break;
    }
    return false;
}
// TODO: E7, E8, E9, automate shift and reduction, 