#include <iostream>
#include "lexer.h"


int main(void) {
   cout << "input string: ";
   string str;
   cin >> str;

   Lexer l(str);

   Symbole * s;
   while(*(s=l.Consulter())!=FIN) {
      s->Affiche();
      cout<<endl;
      l.Avancer();
   }
   return 0;
}

