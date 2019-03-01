using namespace std;
#include <iostream>
#include "automate.h"

class Etat {
    public:
        Etat(string n) : name(n) {}
        virtual ~Etat() {}
        virtual string toString();
        virtual bool transition(Automate & automate, Symbole * s) = 0;
    protected:
        string name;
}

class E0 : public Etat {
    public:
        E0(string n) : Etat(n) {}
        ~E0() {}
        bool transition(Automate & automate, Symbole * s);
        string toString();
}

class E1 : public Etat {
    public:
        E1(string n) : Etat(n) {}
        ~E1() {}
        bool transition(Automate & automate, Symbole * s);
        string toString();
}

class E2 : public Etat {
    public:
        E2(string n) : Etat(n) {}
        ~E2() {}
        bool transition(Automate & automate, Symbole * s);
        string toString();
}

class E3 : public Etat {
    public:
        E3(string n) : Etat(n) {}
        ~E3() {}
        bool transition(Automate & automate, Symbole * s);
        string toString();
}

class E4 : public Etat {
    public:
        E4(string n) : Etat(n) {}
        ~E4() {}
        bool transition(Automate & automate, Symbole * s);
        string toString();
}

class E5 : public Etat {
    public:
        E5(string n) : Etat(n) {}
        ~E5() {}
        bool transition(Automate & automate, Symbole * s);
        string toString();
}

class E6 : public Etat {
    public:
        E6(string n) : Etat(n) {}
        ~E6() {}
        bool transition(Automate & automate, Symbole * s);
        string toString();
}

class E7 : public Etat {
    public:
        E7(string n) : Etat(n) {}
        ~E7() {}
        bool transition(Automate & automate, Symbole * s);
        string toString();
}

class E8 : public Etat {
    public:
        E8(string n) : Etat(n) {}
        ~E8() {}
        bool transition(Automate & automate, Symbole * s);
        string toString();
}

class E9 : public Etat {
    public:
        E9(string n) : Etat(n) {}
        ~E9() {}
        bool transition(Automate & automate, Symbole * s);
        string toString();
}