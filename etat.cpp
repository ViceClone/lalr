using namespace std;
#include <iostream>
#include "etat.h"

string Etat::toString() {
    return "a state";
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
    #ifdef PRINT 
    automate.printStacks();
    #endif
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
            break;
        case FIN:
            return true;
            break;
        case EXPR:
            break;
    }
    #ifdef PRINT 
    automate.printStacks();
    #endif
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
    #ifdef PRINT 
    automate.printStacks();
    #endif
    return false;
}

bool E3::transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case INT:
            break;
        case OPENPAR:
            break;
        default:
            Symbole * s1 =  automate.popSymbole();
            int value = ((Entier*)s1)->getVal();
            delete s1;
            automate.reduction(1, new ExprEntier(value));
            break;
    }
    #ifdef PRINT 
    automate.printStacks();
    #endif
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
    #ifdef PRINT 
    automate.printStacks();
    #endif
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
    #ifdef PRINT 
    automate.printStacks();
    #endif
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
            break;
    }
    #ifdef PRINT 
    automate.printStacks();
    #endif
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
            Expr* s1 = (Expr *) automate.popSymbole();
            automate.popAndDestroySymbole();
            Expr* s2 = (Expr *) automate.popSymbole();
            automate.reduction(3, new ExprPlus(s2,s1));
            break;
    }
    #ifdef PRINT 
    automate.printStacks();
    #endif
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
            Expr * s1 = (Expr *) automate.popSymbole();
            automate.popAndDestroySymbole();
            Expr * s2 = (Expr *) automate.popSymbole();
            automate.reduction(3, new ExprMult(s2,s1));
            break;
    }
    #ifdef PRINT 
    automate.printStacks();
    #endif
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
    #ifdef PRINT 
    automate.printStacks();
    #endif
    return false;
}

string E0::toString() {
    return "0";
}

string E1::toString() {
    return "1";
}

string E2::toString() {
    return "2";
}

string E3::toString() {
    return "3";
}

string E4::toString() {
    return "4";
}

string E5::toString() {
    return "5";
}

string E6::toString() {
    return "6";
}

string E7::toString() {
    return "7";
}

string E8::toString() {
    return "8";
}

string E9::toString() {
    return "9";
}