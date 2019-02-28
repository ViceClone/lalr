#pragma once

#include <string>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR };

const bool Terminal[] = {true, true, true, true, true, true, true, false};

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR" };

class Symbole {
   public:
      Symbole(int i) : ident(i) {  }
      virtual ~Symbole() { }
      operator int() const { return ident; }
      bool isTerminal();
      virtual void Affiche();

   protected:
      int ident;
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT), valeur(v) { }
      ~Entier() { }
      int getVal();
      virtual void Affiche();
   protected:
      int valeur;
};

class Expr : public Symbole {
   public:
      Expr() : Symbole(EXPR){}
      virtual ~Expr() {}
};

class ExprBin : public Expr {
   public:
      ExprBin(Expr * e1, Expr* e2) : Expr(), expr1(e1), expr2(e2) {}
      virtual ~ExprBin() {}
   protected:
      Expr * expr1;
      Expr * expr2;
};

class ExprMult : public ExprBin {
   public:
      ExprMult(Expr * e1, Expr* e2) : ExprBin(e1,e2) {}
      virtual ~ExprMult() {}
};

class ExprPlus : public ExprBin {
   public:
      ExprPlus(Expr * e1, Expr* e2) : ExprBin(e1,e2) {}
      virtual ~ExprPlus() {}
};

class ExprEntier : public Expr {
   public:
      ExprEntier(int n) : Expr(), val(n) {}
      virtual ~ExprEntier() {}
   protected:
      int val;
};