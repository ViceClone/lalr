using namespace std;
#include <iostream>
#include "automate.h"

int main() {
    Automate automate;
    cout << "input string: ";
    string s;
    cin >> s;
    automate.lecture(s);
    return 0;
}