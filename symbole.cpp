#include "symbole.h"
#include <iostream>

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

bool Symbole::isTerminal() {
   return Terminal[ident];
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

int Entier::getValue() {
   return valeur;
}

bool Expr::isLeaf() {
   return leaf;
}

bool ExprBin::isMult() {
   return mult;
}

string Symbole::toString() {
   return "symbole";
}

string Entier::toString() {
   return to_string(valeur);
}

string Expr::toString() {
   return "expr";
}

string ExprBin::toString() {
   return (expr1->toString() + " op " + expr2->toString());
}

string ExprMult::toString() {
   return ("expr(" + expr1->toString() + " mult " + expr2->toString() + ")");
}

string ExprPlus::toString() {
   return ("expr(" + expr1->toString() + " plus " + expr2->toString() + ")");
}

string ExprEntier::toString() {
   return "num:" +to_string(val);
}

int Symbole::getValue() {
   return -1;
}

int Expr::getValue() {
   return -1;
}

int ExprBin::getValue() {
   return -1;
}

int ExprMult::getValue() {
   return expr1->getValue()*expr2->getValue();
}

int ExprPlus::getValue() {
   return expr1->getValue()+expr2->getValue();
}

int ExprEntier::getValue() {
   return val;
}