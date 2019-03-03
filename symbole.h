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
      virtual bool isTerminal();
      virtual void Affiche();
      virtual string toString();
   protected:
      int ident;
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT), valeur(v) { }
      ~Entier() { }
      int getVal();
      virtual void Affiche();
      virtual string toString();
   protected:
      int valeur;
};

class Expr : public Symbole {
   public:
      Expr() : Symbole(EXPR){}
      virtual ~Expr() {}
      bool isLeaf();
      virtual string toString();
   protected:
      bool leaf = false;
};

class ExprBin : public Expr {
   public:
      ExprBin(Expr * e1, Expr* e2) : Expr(), expr1(e1), expr2(e2) {}
      virtual ~ExprBin() {}
      bool isMult();
      virtual string toString();
   protected:
      Expr * expr1;
      Expr * expr2;
      bool mult;
};

class ExprMult : public ExprBin {
   public:
      ExprMult(Expr * e1, Expr* e2) : ExprBin(e1,e2) {mult = true;}
      virtual ~ExprMult() {}
      virtual string toString();
};

class ExprPlus : public ExprBin {
   public:
      ExprPlus(Expr * e1, Expr* e2) : ExprBin(e1,e2) {mult = false;}
      virtual ~ExprPlus() {}
      virtual string toString();
};

class ExprEntier : public Expr {
   public:
      ExprEntier(int n) : Expr() {
         leaf = true;
         val = n;
      }
      virtual ~ExprEntier() {}
      virtual string toString();
   protected:
      int val;
};