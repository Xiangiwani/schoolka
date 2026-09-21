#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main () {

    int Number;
    int bedrag_met_btw;
    cout << "Geef producht zonder btw (btw is 21% berking) ";
    cin >> Number;

    bedrag_met_btw = Number*1.25;

    cout << "het btw van het producht is:" << bedrag_met_btw;

}
